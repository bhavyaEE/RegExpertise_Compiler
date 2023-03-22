#include "ast/ast_expression.hpp"


Direct_Assignment::Direct_Assignment(Node* _left, Node* _right)
    :left(_left), expression(_right){}

void Direct_Assignment::visualiser(std::ostream &os) const{
    left->visualiser(os);
    os << "is assigned to be ";
    expression->visualiser(os);
}
void Direct_Assignment::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    // left->generateRISCV(os, context, destReg);
    std::string name = left->get_variable_name();
    variable this_variable = context.get_variable(name);
    if (this_variable.isArray()){
        left->get_index(os, context, destReg);
        os << "mv x7, x" << destReg <<std::endl;
        os << "slli x7,x7,2" << std::endl;
        int offset =  this_variable.get_variable_address();
        os << "addi x7,x7," <<offset<<std::endl;
        os << "add x7,x7,s0" <<std::endl;
        expression->generateRISCV(os, context, destReg);
        os <<"sw x" << destReg << ",0(x7)"<<std::endl;
    }
    else{
        int offset =  this_variable.get_variable_address();
        expression->generateRISCV(os, context, destReg);
        context.store_word(os, destReg, offset);
    }
}


/* ------------------------------ADD -------------------------------------*/

Add_Expression :: Add_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Add_Expression::~Add_Expression(){
			delete leftop;
			delete rightop;
		}
int Add_Expression::get_value(Context& context)const{
    return leftop->get_value(context)+rightop->get_value(context);
}
void Add_Expression::visualiser(std::ostream &os) const {
    os << " " << "Add expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Add_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    rightop->generateRISCV(os, context, 5);
    leftop->generateRISCV(os, context, 6);
	os << "add" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        add     a5,a4,a5
 !! Please check the lw instructions and context.offset part !!
*/


/* ------------------------------ SUB -------------------------------------*/

Sub_Expression :: Sub_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Sub_Expression::~Sub_Expression(){
			delete leftop;
			delete rightop;
		}
int Sub_Expression::get_value(Context& context)const{
    return leftop->get_value(context)-rightop->get_value(context);
}
void Sub_Expression::visualiser(std::ostream &os) const {
    os << " " << "Sub expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Sub_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    rightop->generateRISCV(os, context, 5);
    leftop->generateRISCV(os, context, 6);
	os << "sub" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        sub     a5,a4,a5
 !! Please check the lw instructions and context.offset part !!
*/


/* ------------------------------ MULTIPLY -------------------------------------*/

Multiply_Expression :: Multiply_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Multiply_Expression::~Multiply_Expression(){
			delete leftop;
			delete rightop;
		}
int Multiply_Expression::get_value(Context& context)const{
    return leftop->get_value(context)*rightop->get_value(context);
}
void Multiply_Expression::visualiser(std::ostream &os) const {
    os << " " << "Multiply expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Multiply_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
	os << "mul" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        mul     a5,a4,a5
 !! Please check the lw instructions and context.offset part !!
*/

/* ------------------------------ DIVIDE -------------------------------------*/


Divide_Expression :: Divide_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Divide_Expression::~Divide_Expression(){
			delete leftop;
			delete rightop;
		}
int Divide_Expression::get_value(Context& context)const{
    return leftop->get_value(context)/rightop->get_value(context);
}
void Divide_Expression::visualiser(std::ostream &os) const {
    os << " " << "Divide expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Divide_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
	os << "div" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        div     a5,a4,a5
 !! Please check the lw instructions and context.offset part !!
*/


/* ------------------------------ EQUAL  -------------------------------------*/

Equal_Expression :: Equal_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Equal_Expression::~Equal_Expression(){
			delete leftop;
			delete rightop;
}

void Equal_Expression::visualiser(std::ostream &os) const {
    os << " " << "Equal expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Equal_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "sub" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
    os << "seqz" << " " << "x" << destReg << ",x" << destReg << std::endl;
    os << "andi" << " " << "x" << destReg << ",x" << destReg << "," << "0xff" << std::endl;
}

/*
    The instructions from Godbolt for 'return x==y;' part of equal.c test
    Note - not identical to codegen above as Godbolt uses different registers:
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        sub     a5,a4,a5
        seqz    a5,a5
        andi    a5,a5,0xff

    !! Please check the lw instructions and context.offset part !!
*/

/* ------------------------------ NOT EQUAL  -------------------------------------*/

Not_Equal_Expression :: Not_Equal_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Not_Equal_Expression::~Not_Equal_Expression(){
			delete leftop;
			delete rightop;
		}

void Not_Equal_Expression::visualiser(std::ostream &os) const {
    os << " " << "Not Equal expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Not_Equal_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
	os << "sub" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
    os << "snez" << " " << "x" << destReg << ",x" << destReg << std::endl;
    os << "andi" << " " << "x" << destReg << ",x" << destReg << "," << "0xff" << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        sub     a5,a4,a5
        snez    a5,a5
        andi    a5,a5,0xff
*/

/* ------------------------------ Less than -------------------------------------*/

Less_Than_Expression :: Less_Than_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Less_Than_Expression::~Less_Than_Expression(){
			delete leftop;
			delete rightop;
		}

void Less_Than_Expression::visualiser(std::ostream &os) const {
    os << " " << "Less Than expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Less_Than_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "slt" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
     os << "andi" << " " << "x" << destReg << ",x" << destReg << "," << "0xff" << std::endl;

}

/*

        lw      a4,-20(s0)
        lw      a5,-24(s0)
        slt     a5,a4,a5
        andi    a5,a5,0xff

*/

/* ------------------------------ More than -------------------------------------*/

More_Than_Expression :: More_Than_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

More_Than_Expression::~More_Than_Expression(){
			delete leftop;
			delete rightop;
		}

void More_Than_Expression::visualiser(std::ostream &os) const {
    os << " " << "More Than expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void More_Than_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "sgt" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
     os << "andi" << " " << "x" << destReg << ",x" << destReg << "," << "0xff" << std::endl;

}

/*

        lw      a4,-20(s0)
        lw      a5,-24(s0)
        sgt     a5,a4,a5
        andi    a5,a5,0xff

*/

/* ------------------------------ Less equal -------------------------------------*/

Less_Equal_Expression :: Less_Equal_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Less_Equal_Expression::~Less_Equal_Expression(){
			delete leftop;
			delete rightop;
		}

void Less_Equal_Expression::visualiser(std::ostream &os) const {
    os << " " << "Less Equal expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Less_Equal_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "sgt" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl; //not sure why godbolt is giving sgt
    // should this be slt??
    os << "xori" << " " << "x" << destReg << ",x" << destReg << ",1" << std::endl;
    os << "andi" << " " << "x" << destReg << ",x" << destReg << "," << "0xff" << std::endl;

}

/*

        lw      a4,-20(s0)
        lw      a5,-24(s0)
        sgt     a5,a4,a5
        xori    a5,a5,1
        andi    a5,a5,0xff
*/

/* ------------------------------ More equal -------------------------------------*/

More_Equal_Expression :: More_Equal_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

More_Equal_Expression::~More_Equal_Expression(){
			delete leftop;
			delete rightop;
		}

void More_Equal_Expression::visualiser(std::ostream &os) const {
    os << " " << "More Equal  expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void More_Equal_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "slt" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
    os << "xori" << " " << "x" << destReg << ",x" << destReg << ",1" << std::endl;
    os << "andi" << " " << "x" << destReg << ",x" << destReg << "," << "0xff" << std::endl;

}

/*

        lw      a4,-20(s0)
        lw      a5,-24(s0)
        slt     a5,a4,a5
        xori    a5,a5,1
        andi    a5,a5,0xff
*/


/* ------------------------------ BIT AND -------------------------------------*/

Bit_And_Expression :: Bit_And_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Bit_And_Expression::~Bit_And_Expression(){
			delete leftop;
			delete rightop;
		}

void Bit_And_Expression::visualiser(std::ostream &os) const {
    os << " " << "Bitwise And expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Bit_And_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
	os << "and" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        and     a5,a4,a5
*/


/* ------------------------------ BIT OR -------------------------------------*/


Bit_Or_Expression :: Bit_Or_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Bit_Or_Expression::~Bit_Or_Expression(){
			delete leftop;
			delete rightop;
		}

void Bit_Or_Expression::visualiser(std::ostream &os) const {
    os << " " << "Bitwise Or expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Bit_Or_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
	os << "or" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        or      a5,a4,a5
*/


/* ------------------------------ BIT XOR -------------------------------------*/


Bit_Xor_Expression :: Bit_Xor_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Bit_Xor_Expression::~Bit_Xor_Expression(){
			delete leftop;
			delete rightop;
		}

void Bit_Xor_Expression::visualiser(std::ostream &os) const {
    os << " " << "Bitwise Xor expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Bit_Xor_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "xor" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/*
        lw      a4,-20(s0)
        lw      a5,-24(s0)
        xor     a5,a4,a5
*/


/* ------------------------------ LOGICAL AND -------------------------------------*/


Logic_And_Expression :: Logic_And_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Logic_And_Expression::~Logic_And_Expression(){
			delete leftop;
			delete rightop;
		}

void Logic_And_Expression::visualiser(std::ostream &os) const {
    os << " " << "Logical And expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Logic_And_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    std::string L1 = context.createlabel("L_");
	leftop->generateRISCV(os, context, destReg);
    os << "beq" << " " << "x" << destReg << "," << "zero" << "," << L1 << std::endl;
    rightop->generateRISCV(os, context, destReg);
    os << "beq" << " " << "x" << destReg << "," << "zero" << "," << L1 << std::endl;
    os << "li" << " " << "x" << destReg << "," << "1" <<  std::endl;
    os << "j .function_end" << std::endl;
    os << L1 << ":" << std::endl;
    os << "li" << " " << "x" << destReg << "," << "0" <<  std::endl;

}

/* ------------------------------ LOGICAL OR -------------------------------------*/

Logic_Or_Expression :: Logic_Or_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Logic_Or_Expression::~Logic_Or_Expression(){
			delete leftop;
			delete rightop;
		}

void Logic_Or_Expression::visualiser(std::ostream &os) const {
    os << " " << "Logical Or expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Logic_Or_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    std::string L1 = context.createlabel("L_");
     std::string L2 = context.createlabel("L_");
	leftop->generateRISCV(os, context, destReg);
    os << "bne" << " " << "x" << destReg << "," << "zero" << "," << L1 << std::endl;
    rightop->generateRISCV(os, context, destReg);
    os << "beq" << " " << "x" << destReg << "," << "zero" << "," << L2 << std::endl;
    os << L1 << ":" << std::endl;
    os << "li" << " " << "x" << destReg << "," << "1" <<  std::endl;
    os << "j .function_end" << std::endl;
    os << L2 << ":" << std::endl;
    os << "li" << " " << "x" << destReg << "," << "0" <<  std::endl;

}

/* ------------------------------ LEFT SHIFT -------------------------------------*/


Left_Shift_Expression :: Left_Shift_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Left_Shift_Expression::~Left_Shift_Expression(){
			delete leftop;
			delete rightop;
		}

void Left_Shift_Expression::visualiser(std::ostream &os) const {
    os << " " << "Left_Shift_Expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Left_Shift_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "sll" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/* ------------------------------ RIGHT SHIFT -------------------------------------*/


Right_Shift_Expression :: Right_Shift_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Right_Shift_Expression::~Right_Shift_Expression(){
			delete leftop;
			delete rightop;
		}

void Right_Shift_Expression::visualiser(std::ostream &os) const {
    os << " " << "Right_Shift_Expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Right_Shift_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
    os << "sra" << " " << "x" << destReg << ",x" << 6 << "," << "x" << 5 << std::endl;
}

/* ------------------------------ POST INC -------------------------------------*/

Post_Increment_Expression :: Post_Increment_Expression (Node* _op) : op(_op){}

Post_Increment_Expression::~Post_Increment_Expression(){
			delete op;
		}

void Post_Increment_Expression::visualiser(std::ostream &os) const {
    os << "Post_Increment_Expression: " << std::endl;
    op->visualiser(os);
}

void Post_Increment_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    op->generateRISCV(os, context, destReg);
    os << "addi" << " " << "x6,x" << destReg << ",1" << std::endl;
    context.store_word(os, 6, -20);
}
