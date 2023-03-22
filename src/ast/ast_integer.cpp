#include "ast/ast_integer.hpp"

Int::Int(int _value)
    : value(_value)
{}

void Int::visualiser(std::ostream &os) const{
    os << " " << "integer = " << value << std::endl;
}

void Int::generateRISCV(std::ostream &os, Context& context, int destReg) const {
		os <<"li" << " x" << destReg << "," << " "<< value << std::endl;
}

int Int::get_value(Context& context) const {
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
int Variable::get_variable_value(Context& context) const{
    variable this_variable = context.get_variable(variable_name);
    return this_variable.return_variable_value();
}
int Variable::get_value(Context& context) const{
    int value = get_variable_value(context);
    return value;
}

Array::Array(std::string _name, Node* _index)
    :array_name(_name),  index(_index){}

std::string Array::get_variable_name() const{
    return array_name;
}
int Array::get_index(Context& context) const{
    return index->get_value(context);
}
void Array::visualiser(std::ostream &os) const{
    os << array_name << "[";
    index->visualiser(os);
    os  << "]"<<std::endl;
}
void Array::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    variable this_variable = context.get_variable(array_name);
    int array_index = index->get_value(context);
    int offset = this_variable.get_variable_address() +array_index*4;
    context.load_word(os, destReg, offset);
}
