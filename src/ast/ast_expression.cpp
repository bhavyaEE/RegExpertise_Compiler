#include "ast/ast_expression.hpp"


Direct_Assignment::Direct_Assignment(Node* _left, Node* _right)
    :left(_left), expression(_right){}

void Direct_Assignment::visualiser(std::ostream &os) const{
    left->visualiser(os);
    os << "is assigned to be ";
    expression->visualiser(os);
}
void Direct_Assignment::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    Variable* var_node = dynamic_cast<Variable*>(left);
    std::string var_name = var_node->get_variable_name();
    variable this_variable = context.get_variable(var_name);
    int offset = this_variable.get_variable_address();
    expression->generateRISCV(os, context, destReg);
    context.store_word(os, destReg, offset);
}

/* ------------------------------ADD -------------------------------------*/

Add_Expression :: Add_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

Add_Expression::~Add_Expression(){
			delete leftop;
			delete rightop;
		}

void Add_Expression::visualiser(std::ostream &os) const {
    os << " " << "Add expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Add_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
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

void Sub_Expression::visualiser(std::ostream &os) const {
    os << " " << "Sub expression: " << std::endl;
    os << " " << "Left Op: ";
    leftop->visualiser(os);
    os << " " << "Right Op: ";
    rightop->visualiser(os);
}

void Sub_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
    leftop->generateRISCV(os, context, 6);
    rightop->generateRISCV(os, context, 5);
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


// Logic_And_Expression :: Logic_And_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

//  void Logic_And_Expression::~Logic_And_Expression(){
// 			delete leftop;
// 			delete rightop;
// 		}

// void Logic_And_Expression::visualiser(std::ostream &os) const {
//     os << " " << "Logical And expression: " << std::endl;
//     os << " " << "Left Op: " <<leftop->visualiser(os) << std::endl;
//     os << " " << "Right Op: " <<rightop->visualiser(os) << std::endl;
// }

// void Logic_And_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
//     leftop->generateRISCV(os, context, 6);
//     rightop->generateRISCV(os, context, 5);
//     //add branch labels

// }

/* ------------------------------ LOGICAL OR -------------------------------------*/

// Logic_Or_Expression :: Logic_Or_Expression (Node* left, Node* right) : leftop(left), rightop(right) {}

//  void Logic_Or_Expression::~Logic_Or_Expression(){
// 			delete leftop;
// 			delete rightop;
// 		}

// void Logic_Or_Expression::visualiser(std::ostream &os) const {
//     os << " " << "Logical Or expression: " << std::endl;
//     os << " " << "Left Op: " <<leftop->visualiser(os) << std::endl;
//     os << " " << "Right Op: " <<rightop->visualiser(os) << std::endl;
// }

// void Logic_Or_Expression::generateRISCV(std::ostream &os, Context& context, int destReg) const{
// 	leftop->generateRISCV(os, context, 6);
//     rightop->generateRISCV(os, context, 5);
//     //add branch labels

// }

//SHIFT EXPRESSIONS?
