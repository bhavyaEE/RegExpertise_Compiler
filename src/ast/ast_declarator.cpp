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
    variable this_variable = context.new_variable(variable_name, 0);
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
    variable this_variable = context.new_variable(variable_name, 0);
    int offset = this_variable.get_variable_address();
    expression->generateRISCV(os, context, destReg);
    context.store_word(os, destReg, offset);
}


Array_Declarator :: Array_Declarator(std::string _array_name, Node* _expression)
    : array_name(_array_name), array_size_expression(_expression) {}

Array_Declarator::~Array_Declarator(){}

std::string Array_Declarator::get_array_name() const{
    return array_name;
}
int Array_Declarator::get_array_size(Context& context) const{
    if (array_size_expression != NULL){
        return array_size_expression->get_value(context);
    }
    else{
        return -1;
    }
}

void Array_Declarator::visualiser(std::ostream &os) const {
    os << "array name: "<<array_name << std::endl;
    // os << "array size: " << get_array_size()<<std::endl;
    os << "array size " ;
    array_size_expression->visualiser(os);
    os<<std::endl;
}
void Array_Declarator::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    int size = get_array_size(context); //inside bracket
    context.for_array_declaration(size);
    variable this_variable = context.new_variable(array_name, 1);
	int offset = this_variable.get_variable_address();
    for (int i = 0;i<size; i++ ){
        context.store_word(os, 0, offset+4*i);
    }

}

Function_Declarator::Function_Declarator(std::string _fname, std::vector<Node*>* _argument_list)
:  fname(_fname), argument_list(_argument_list){}

void Function_Declarator::visualiser(std::ostream &os) const {
    os << "function name: "<<fname << std::endl;
    if (argument_list != NULL){
        for(auto argument = argument_list->begin(); argument != argument_list->end(); argument++)
        {
            (*argument)->visualiser(os);
        }
    }
    os<<std::endl;
}
void Function_Declarator::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    context.store_function_name(fname);
    os << ".text" << std::endl;
    os << ".globl " << fname << std::endl;
}

