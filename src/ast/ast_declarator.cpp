#include "ast/ast_declarator.hpp"

Variable_Declarator :: Variable_Declarator(std::string var_name)
    : variable_name(var_name){}

Variable_Declarator::~Variable_Declarator(){}

std::string Variable_Declarator::get_variable_name() const{
    return variable_name;
}

void Variable_Declarator::visualiser(std::ostream &os) const {
    os << "variable name: "<<variable_name << std::endl;
}
void Variable_Declarator::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    variable this_variable = context.new_variable(variable_name);
	int offset = this_variable.get_variable_address();
    context.store_word(os, 0, offset);
}


Initialisation_Variable_Declarator ::Initialisation_Variable_Declarator(std::string var_name, Node* _expression)
    : variable_name(var_name), expression(_expression){}

Initialisation_Variable_Declarator::~Initialisation_Variable_Declarator(){}


void Initialisation_Variable_Declarator::visualiser(std::ostream &os) const{
    os << "variable name: "<<variable_name << std::endl;
    expression->visualiser(os);
}
void Initialisation_Variable_Declarator::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    variable this_variable = context.new_variable(variable_name);
    int offset = this_variable.get_variable_address();
    expression->generateRISCV(os, context, destReg);
    context.store_word(os, destReg, offset);
}



