#include "ast/ast_declaration.hpp"

Declaration::Declaration(std::string _TYPE, Node* _init_declarator)
    :Type(_TYPE), Init_Declarator(_init_declarator){}

Declaration::~Declaration(){}

void Declaration::visualiser(std::ostream &os) const {
    os << "Declaration: "<<Type << std::endl;
    Init_Declarator->visualiser(os);
}
void Declaration::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    Init_Declarator->generateRISCV(os, context, destReg);
}
