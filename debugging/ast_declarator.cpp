#include "ast/ast_declarator.hpp"

void Declarator::visualiser(std::ostream &os) const {
    // implementation here
    os << " " << "Declarator: " <<std::endl;
}

void Declarator::compile_declaration(std::ostream &os, /*Context& context,*/ type declarator_type) const {
    // implementation here
}

void Declarator::compile_declaration_initialisation(std::ostream &os, /*Context& context,*/ type declarator_type, Expression* expressions) const {
    // implementation here
}
