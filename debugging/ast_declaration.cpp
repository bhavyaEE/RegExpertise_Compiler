#include "ast/ast_declaration.hpp"

Declaration::Declaration(std::string _TYPE, Node* _init_declarator) 
		: TYPE(_TYPE), Init_Declarator(_init_declarator) {}

void Declaration::visualiser(std::ostream &os) const {
    // implementation here
    os << " " << "Declaration: " <<std::endl;
    Type->visualiser(os)<<std::endl;
    Init_Declarator->visualiser(os)<<std::endl;
}

void Declaration::compile_declaration(std::ostream &os, /*Context& context,*/ type declarator_type) const {
    Init_Declarator->generateRISCV(os, /*context,*/ destReg);
}
