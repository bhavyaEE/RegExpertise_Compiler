#include "ast/ast_declaration.hpp"

Declaration::Declaration(type_specifier* _TYPE, Declarator* _init_declarator) 
		: TYPE(_TYPE), Init_Declarator(_init_declarator) {}

void Declaration::visualiser(std::ostream &os) const {
    // implementation here
    os << " " << "Declaration: " <<std::endl;
    Type->visualiser()<<std::endl;
    Init_Declarator->visualiser()<<std::endl;
}

void Declaration::compile_declaration(std::ostream &dst, Context& context, type declarator_type) const {
    Init_Declarator->generateRISCV(dst, context, destReg);
}
