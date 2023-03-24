#include "ast/ast_expression.hpp"

Direct_Assignment::Direct_Assignment(Node *_left, Node *_right)
    : left(_left), expression(_right) {}

void Direct_Assignment::visualiser(std::ostream &os) const
{
    left->visualiser(os);
    os << "is assigned to be ";
    expression->visualiser(os);
}
void Direct_Assignment::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    std::string name = left->get_variable_name();
    variable this_variable = context.get_variable(name);
    if (this_variable.isArray())
    {
        left->get_index(os, context, destReg);
        os << "mv x7, x" << destReg << std::endl;
        os << "slli x7,x7,2" << std::endl;
        int offset = this_variable.get_variable_address();
        os << "addi x7,x7," << offset << std::endl;
        os << "add x7,x7,s0" << std::endl;
        expression->generateRISCV(os, context, destReg);
        os << "sw x" << destReg << ",0(x7)" << std::endl;
    }
    else
    {
        int offset = this_variable.get_variable_address();
        expression->generateRISCV(os, context, destReg);
        context.store_word(os, destReg, offset);
    }
}

Function_Call::Function_Call(std::string _function_name, std::vector<Node *> *_function_arguments)
    : function_name(_function_name), function_arguments(_function_arguments) {}

bool Function_Call::isFunction() const
{
    return 1;
}
void Function_Call::visualiser(std::ostream &os) const
{
    if (function_arguments == NULL)
    {
        os << "calling function: " << function_name << "()" << std::endl;
    }
    else
    {
        os << "Function Arguments: " << std::endl;
        for (auto argument = function_arguments->begin(); argument != function_arguments->end(); argument++)
        {
            (*argument)->visualiser(os);
        }
    }
}
void Function_Call::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int argument_registers[8] = {10, 11, 12, 13, 14, 15, 16, 17};
    int i = 0;
    if (function_arguments != NULL)
    {
        for (auto argument = function_arguments->begin(); argument != function_arguments->end(); argument++)
        {
            (*argument)->generateRISCV(os, context, destReg);
            os << "mv x" << argument_registers[i] << ",x" << destReg << std::endl;
            i++;
        }
    }
    os << "call " << function_name << std::endl;
    os << "mv x" << destReg << ",x10" << std::endl;
}

/* ------------------------------ADD -------------------------------------*/

Add_Expression ::Add_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Add_Expression::~Add_Expression()
{
    delete leftop;
    delete rightop;
}
int Add_Expression::get_value(Context &context) const
{
    return leftop->get_value(context) + rightop->get_value(context);
}
void Add_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Add expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    if (rightop->isFunction())
    {
        os << "right op is function" << std::endl;
    }
    rightop->visualiser(os);
}

void Add_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);
    if ((leftop->isFunction()) && (rightop->isFunction()))
    {
        leftop->generateRISCV(os, context, leftReg);
        os << "mv x9,x" << leftReg << std::endl;
        leftReg = 9;
        rightop->generateRISCV(os, context, rightReg);
    }
    else if (rightop->isFunction())
    {
        rightop->generateRISCV(os, context, rightReg);
        leftop->generateRISCV(os, context, leftReg);
    }
    else
    {
        leftop->generateRISCV(os, context, leftReg);
        rightop->generateRISCV(os, context, rightReg);
    }
    if ((leftop->get_data_type(context) == "float") || (rightop->get_data_type(context) == "float"))
    {
        os << "fadd.s"
           << " "
           << "f" << destReg << ",f" << leftReg << ","
           << "f" << rightReg << std::endl;
    }
    else
    {
        os << "add"
           << " "
           << "x" << destReg << ",x" << leftReg << ","
           << "x" << rightReg << std::endl;
    }

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ SUB -------------------------------------*/

Sub_Expression ::Sub_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Sub_Expression::~Sub_Expression()
{
    delete leftop;
    delete rightop;
}
int Sub_Expression::get_value(Context &context) const
{
    return leftop->get_value(context) - rightop->get_value(context);
}
void Sub_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Sub expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Sub_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    if ((leftop->isFunction()) && (rightop->isFunction()))
    {
        leftop->generateRISCV(os, context, leftReg);
        os << "mv x9,x" << rightReg << std::endl;
        leftReg = 9;
        rightop->generateRISCV(os, context, rightReg);
    }
    else if (rightop->isFunction())
    {
        rightop->generateRISCV(os, context, rightReg);
        leftop->generateRISCV(os, context, leftReg);
    }
    else
    {
        leftop->generateRISCV(os, context, leftReg);
        rightop->generateRISCV(os, context, rightReg);
    }
    if ((leftop->get_data_type(context) == "float") || (rightop->get_data_type(context) == "float"))
    {
        os << "fsub.s"
           << " "
           << "f" << destReg << ",f" << leftReg << ","
           << "f" << rightReg << std::endl;
    }
    else
    {
        os << "sub"
           << " "
           << "x" << destReg << ",x" << leftReg << ","
           << "x" << rightReg << std::endl;
    }

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ MULTIPLY -------------------------------------*/

Multiply_Expression ::Multiply_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Multiply_Expression::~Multiply_Expression()
{
    delete leftop;
    delete rightop;
}
int Multiply_Expression::get_value(Context &context) const
{
    return leftop->get_value(context) * rightop->get_value(context);
}
void Multiply_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Multiply expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Multiply_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    if ((leftop->isFunction()) && (rightop->isFunction()))
    {
        leftop->generateRISCV(os, context, leftReg);
        os << "mv x9,x" << rightReg << std::endl;
        leftReg = 9;
        rightop->generateRISCV(os, context, rightReg);
    }
    else if (rightop->isFunction())
    {
        rightop->generateRISCV(os, context, rightReg);
        leftop->generateRISCV(os, context, leftReg);
    }
    else
    {
        leftop->generateRISCV(os, context, leftReg);
        rightop->generateRISCV(os, context, rightReg);
    }
    if ((leftop->get_data_type(context) == "float") || (rightop->get_data_type(context) == "float"))
    {
        os << "fmul.s"
           << " "
           << "f" << destReg << ",f" << leftReg << ","
           << "f" << rightReg << std::endl;
    }
    else
    {
        os << "mul"
           << " "
           << "x" << destReg << ",x" << leftReg << ","
           << "x" << rightReg << std::endl;
    }

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ DIVIDE -------------------------------------*/

Divide_Expression ::Divide_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Divide_Expression::~Divide_Expression()
{
    delete leftop;
    delete rightop;
}
int Divide_Expression::get_value(Context &context) const
{
    return leftop->get_value(context) / rightop->get_value(context);
}
void Divide_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Divide expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Divide_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);
    if ((leftop->isFunction()) && (rightop->isFunction()))
    {
        leftop->generateRISCV(os, context, leftReg);
        os << "mv x9,x" << rightReg << std::endl;
        leftReg = 9;
        rightop->generateRISCV(os, context, rightReg);
    }
    else if (rightop->isFunction())
    {
        rightop->generateRISCV(os, context, rightReg);
        leftop->generateRISCV(os, context, leftReg);
    }
    else
    {
        leftop->generateRISCV(os, context, leftReg);
        rightop->generateRISCV(os, context, rightReg);
    }

    if ((leftop->get_data_type(context) == "float") || (rightop->get_data_type(context) == "float"))
    {
        os << "fdiv.s"
           << " "
           << "f" << destReg << ",f" << leftReg << ","
           << "f" << rightReg << std::endl;
    }
    else
    {
        os << "div"
           << " "
           << "x" << destReg << ",x" << leftReg << ","
           << "x" << rightReg << std::endl;
    }
    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ EQUAL  -------------------------------------*/

Equal_Expression ::Equal_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Equal_Expression::~Equal_Expression()
{
    delete leftop;
    delete rightop;
}

void Equal_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Equal expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Equal_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "sub"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;
    os << "seqz"
       << " "
       << "x" << destReg << ",x" << destReg << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ","
       << "0xff" << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ NOT EQUAL  -------------------------------------*/

Not_Equal_Expression ::Not_Equal_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Not_Equal_Expression::~Not_Equal_Expression()
{
    delete leftop;
    delete rightop;
}

void Not_Equal_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Not Equal expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Not_Equal_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "sub"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;
    os << "snez"
       << " "
       << "x" << destReg << ",x" << destReg << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ","
       << "0xff" << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ Less than -------------------------------------*/

Less_Than_Expression ::Less_Than_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Less_Than_Expression::~Less_Than_Expression()
{
    delete leftop;
    delete rightop;
}

void Less_Than_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Less Than expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Less_Than_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "slt"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ","
       << "0xff" << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ More than -------------------------------------*/

More_Than_Expression ::More_Than_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

More_Than_Expression::~More_Than_Expression()
{
    delete leftop;
    delete rightop;
}

void More_Than_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "More Than expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void More_Than_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "sgt"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ","
       << "0xff" << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ Less equal -------------------------------------*/

Less_Equal_Expression ::Less_Equal_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Less_Equal_Expression::~Less_Equal_Expression()
{
    delete leftop;
    delete rightop;
}

void Less_Equal_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Less Equal expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Less_Equal_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "sgt"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;
    os << "xori"
       << " "
       << "x" << destReg << ",x" << destReg << ",1" << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ","
       << "0xff" << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ More equal -------------------------------------*/

More_Equal_Expression ::More_Equal_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

More_Equal_Expression::~More_Equal_Expression()
{
    delete leftop;
    delete rightop;
}

void More_Equal_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "More Equal  expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void More_Equal_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "slt"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;
    os << "xori"
       << " "
       << "x" << destReg << ",x" << destReg << ",1" << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ","
       << "0xff" << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ BIT AND -------------------------------------*/

Bit_And_Expression ::Bit_And_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Bit_And_Expression::~Bit_And_Expression()
{
    delete leftop;
    delete rightop;
}

void Bit_And_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Bitwise And expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Bit_And_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "and"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ BIT OR -------------------------------------*/

Bit_Or_Expression ::Bit_Or_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Bit_Or_Expression::~Bit_Or_Expression()
{
    delete leftop;
    delete rightop;
}

void Bit_Or_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Bitwise Or expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Bit_Or_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);
    os << "or"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ BIT XOR -------------------------------------*/

Bit_Xor_Expression ::Bit_Xor_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Bit_Xor_Expression::~Bit_Xor_Expression()
{
    delete leftop;
    delete rightop;
}

void Bit_Xor_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Bitwise Xor expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Bit_Xor_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "xor"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ LOGICAL AND -------------------------------------*/

Logic_And_Expression ::Logic_And_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Logic_And_Expression::~Logic_And_Expression()
{
    delete leftop;
    delete rightop;
}

void Logic_And_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Logical And expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Logic_And_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    std::string L1 = context.createlabel("L_");
    leftop->generateRISCV(os, context, destReg);
    os << "beq"
       << " "
       << "x" << destReg << ","
       << "zero"
       << "," << L1 << std::endl;
    rightop->generateRISCV(os, context, destReg);
    os << "beq"
       << " "
       << "x" << destReg << ","
       << "zero"
       << "," << L1 << std::endl;
    os << "li"
       << " "
       << "x" << destReg << ","
       << "1" << std::endl;
    std::string fname = context.return_function_name();
    os << "j .function_end" << fname << std::endl;
    os << L1 << ":" << std::endl;
    os << "li"
       << " "
       << "x" << destReg << ","
       << "0" << std::endl;
}

/* ------------------------------ LOGICAL OR -------------------------------------*/

Logic_Or_Expression ::Logic_Or_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Logic_Or_Expression::~Logic_Or_Expression()
{
    delete leftop;
    delete rightop;
}

void Logic_Or_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Logical Or expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Logic_Or_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    std::string L1 = context.createlabel("L_");
    std::string L2 = context.createlabel("L_");
    leftop->generateRISCV(os, context, destReg);
    os << "bne"
       << " "
       << "x" << destReg << ","
       << "zero"
       << "," << L1 << std::endl;
    rightop->generateRISCV(os, context, destReg);
    os << "beq"
       << " "
       << "x" << destReg << ","
       << "zero"
       << "," << L2 << std::endl;
    os << L1 << ":" << std::endl;
    os << "li"
       << " "
       << "x" << destReg << ","
       << "1" << std::endl;
    std::string fname = context.return_function_name();
    os << "j .function_end" << fname << std::endl;
    os << L2 << ":" << std::endl;
    os << "li"
       << " "
       << "x" << destReg << ","
       << "0" << std::endl;
}

/* ------------------------------ LEFT SHIFT -------------------------------------*/

Left_Shift_Expression ::Left_Shift_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Left_Shift_Expression::~Left_Shift_Expression()
{
    delete leftop;
    delete rightop;
}

void Left_Shift_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Left_Shift_Expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Left_Shift_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);

    os << "sll"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ RIGHT SHIFT -------------------------------------*/

Right_Shift_Expression ::Right_Shift_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Right_Shift_Expression::~Right_Shift_Expression()
{
    delete leftop;
    delete rightop;
}

void Right_Shift_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Right_Shift_Expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Right_Shift_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);
    os << "sra"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ MOD -------------------------------------*/

Mod_Expression ::Mod_Expression(Node *left, Node *right) : leftop(left), rightop(right) {}

Mod_Expression::~Mod_Expression()
{
    delete leftop;
    delete rightop;
}

void Mod_Expression::visualiser(std::ostream &os) const
{
    os << " "
       << "Right_Shift_Expression: " << std::endl;
    os << " "
       << "Left Op: ";
    leftop->visualiser(os);
    os << " "
       << "Right Op: ";
    rightop->visualiser(os);
}

void Mod_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int leftReg = context.leftreg();
    int rightReg = context.rightreg();

    context.setLeftReg(leftReg);
    context.setRightReg(rightReg);

    leftop->generateRISCV(os, context, leftReg);
    rightop->generateRISCV(os, context, rightReg);
    os << "rem"
       << " "
       << "x" << destReg << ",x" << leftReg << ","
       << "x" << rightReg << std::endl;

    context.freeReg(leftReg);
    context.freeReg(rightReg);
}

/* ------------------------------ POST INC -------------------------------------*/

Post_Increment_Expression ::Post_Increment_Expression(Node *_op) : op(_op) {}

Post_Increment_Expression::~Post_Increment_Expression()
{
    delete op;
}

void Post_Increment_Expression::visualiser(std::ostream &os) const
{
    os << "Post_Increment_Expression: " << std::endl;
    op->visualiser(os);
}

void Post_Increment_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int tempReg = context.leftreg();

    context.setLeftReg(tempReg);

    op->generateRISCV(os, context, destReg);
    os << "addi"
       << " "
       << "x" << tempReg << ",x" << destReg << ",1" << std::endl;
    context.store_word(os, tempReg, -20);

    context.freeReg(tempReg);
}

/* ------------------------------ PRE INC -------------------------------------*/

Pre_Increment_Expression ::Pre_Increment_Expression(Node *_op) : op(_op) {}

Pre_Increment_Expression::~Pre_Increment_Expression()
{
    delete op;
}

void Pre_Increment_Expression::visualiser(std::ostream &os) const
{
    os << "Pre_Increment_Expression: " << std::endl;
    op->visualiser(os);
}

void Pre_Increment_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    op->generateRISCV(os, context, destReg);
    os << "addi"
       << " "
       << "x" << destReg << ",x" << destReg << ",1" << std::endl;
    context.store_word(os, destReg, -20);
    context.load_word(os, destReg, -20);
}

/* ------------------------------ POST DEC -------------------------------------*/

Post_Decrement_Expression ::Post_Decrement_Expression(Node *_op) : op(_op) {}

Post_Decrement_Expression::~Post_Decrement_Expression()
{
    delete op;
}

void Post_Decrement_Expression::visualiser(std::ostream &os) const
{
    os << "Post_Decrement_Expression: " << std::endl;
    op->visualiser(os);
}

void Post_Decrement_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    int tempReg = context.leftreg();

    context.setLeftReg(tempReg);

    op->generateRISCV(os, context, destReg);
    os << "addi"
       << " "
       << "x" << tempReg << ",x" << destReg << ",-1" << std::endl;
    context.store_word(os, tempReg, -20);

    context.freeReg(tempReg);
}

/* ------------------------------ PRE DEC -------------------------------------*/
Pre_Decrement_Expression ::Pre_Decrement_Expression(Node *_op) : op(_op) {}

Pre_Decrement_Expression::~Pre_Decrement_Expression()
{
    delete op;
}

void Pre_Decrement_Expression::visualiser(std::ostream &os) const
{
    os << "Pre_Decrement_Expression: " << std::endl;
    op->visualiser(os);
}

void Pre_Decrement_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{

    op->generateRISCV(os, context, destReg);
    os << "addi"
       << " "
       << "x" << destReg << ",x" << destReg << ",-1" << std::endl;
    context.store_word(os, destReg, -20);
    context.load_word(os, destReg, -20);
}

/* ------------------------------ UNARY OPS -------------------------------------*/

/* ------------------------------ NEGATION -------------------------------------*/
Negation_Expression ::Negation_Expression(Node *_op) : op(_op) {}

Negation_Expression::~Negation_Expression()
{
    delete op;
}

void Negation_Expression::visualiser(std::ostream &os) const
{
    os << "Post_Increment_Expression: " << std::endl;
    op->visualiser(os);
}

void Negation_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    op->generateRISCV(os, context, destReg);
    os << "neg"
       << " "
       << "x" << destReg << ",x" << destReg << std::endl;
}

/* ------------------------------ NOT -------------------------------------*/
Logic_Not_Expression ::Logic_Not_Expression(Node *_op) : op(_op) {}

Logic_Not_Expression::~Logic_Not_Expression()
{
    delete op;
}

void Logic_Not_Expression::visualiser(std::ostream &os) const
{
    os << "Logic_Not_Expression: " << std::endl;
    op->visualiser(os);
}

void Logic_Not_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    op->generateRISCV(os, context, destReg);
    os << "seqz"
       << " "
       << "x" << destReg << ",x" << destReg << std::endl;
    os << "andi"
       << " "
       << "x" << destReg << ",x" << destReg << ",0xff" << std::endl;
}

/* ------------------------------ BIT NOT -------------------------------------*/
Bit_Not_Expression ::Bit_Not_Expression(Node *_op) : op(_op) {}

Bit_Not_Expression::~Bit_Not_Expression()
{
    delete op;
}

void Bit_Not_Expression::visualiser(std::ostream &os) const
{
    os << "Bit_Not_Expression: " << std::endl;
    op->visualiser(os);
}

void Bit_Not_Expression::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    op->generateRISCV(os, context, destReg);
    os << "not"
       << " "
       << "x" << destReg << ",x" << destReg << std::endl;
}
