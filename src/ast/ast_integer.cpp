#include "ast/ast_integer.hpp"

Int::Int(int _value)
    : value(_value)
{}

void Int::visualiser(std::ostream &os) const{
    os << " " << "integer = " << value << std::endl;
}

void Int::generateRISCV(std::ostream &os, Context& context, int destReg) const {
		// int stack_pointer = context.get_stack_pointer();
		os <<"li" << " x" << destReg << "," << " "<< value << std::endl;


		// context.store_register(os, destReg, stack_pointer);
        //needs to figure this out
}

// type INT::get_data_type(Context& context) const {
//     return type(INT); //need to have this in context
// }

int Int::get_value() const {
    return value;
}

Variable::Variable(std::string _variable_name) : variable_name (_variable_name){}
void Variable::visualiser(std::ostream &os) const{
    os << " " << "variable = " << variable_name << std::endl;
}
void Variable::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    variable this_variable = context.get_variable(variable_name);
	int offset = this_variable.get_variable_address();
    context.load_word(os, destReg, offset );
}
std::string Variable::get_variable_name() const{
    return variable_name;
}
