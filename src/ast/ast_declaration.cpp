#include "ast/ast_declaration.hpp"

Declaration::Declaration(std::string _TYPE, Node* _init_declarator)
    :Type(_TYPE), Init_Declarator(_init_declarator){}

Declaration::~Declaration(){}

std::string Declaration::get_parameter() const{
    Variable_Declarator* vard_node = dynamic_cast<Variable_Declarator*>(Init_Declarator);
    return vard_node->get_variable_name();
}

void Declaration::visualiser(std::ostream &os) const {
    os << "Declaration: "<<Type << std::endl;
    Init_Declarator->visualiser(os);
}
void Declaration::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    Init_Declarator->generateRISCV(os, context, destReg);
}

Add_Program::Add_Program(Node* _left, Node* _right)
 : left(_left), right(_right) {}

void Add_Program::visualiser(std::ostream &os) const {
    left->visualiser(os);
    os<<std::endl;
    right->visualiser(os);
    os<<std::endl;
}
void Add_Program::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    left ->generateRISCV(os, context, destReg);
    context.function_calling();
	right->generateRISCV(os, context, destReg);
}
