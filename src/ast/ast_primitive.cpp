#include "ast/ast_primitive.hpp"

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
std::string Int::get_data_type(Context& context) const{
    return "int";
}


Variable::Variable(std::string _variable_name) : variable_name (_variable_name){}

void Variable::visualiser(std::ostream &os) const{
    os << " " << "variable = " << variable_name << std::endl;
}
void Variable::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    variable this_variable = context.get_variable(variable_name);
	int offset = this_variable.get_variable_address();
    if (this_variable.get_type_variable()=="float"){
        context.fload_word(os, destReg, offset);
    }
    else{
        context.load_word(os, destReg, offset);
    }
}
std::string Variable::get_variable_name() const{
    return variable_name;
}
std::string Variable::get_data_type(Context& context) const {
    variable this_variable = context.get_variable(variable_name);
    return this_variable.get_type_variable();
}


Array::Array(std::string _name, Node* _index)
    :array_name(_name),  index(_index){}

std::string Array::get_variable_name() const{
    return array_name;
}
void Array::get_index(std::ostream &os, Context& context, int destReg) const{
    index->generateRISCV(os, context, destReg);
}
void Array::visualiser(std::ostream &os) const{
    os << array_name << "[";
    index->visualiser(os);
    os  << "]"<<std::endl;
}
void Array::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    variable this_variable = context.get_variable(array_name);
    int offset = this_variable.get_variable_address();
    index->generateRISCV(os, context, destReg);
    os << "mv x7, x" << destReg <<std::endl;
    os << "slli x7,x7,2" << std::endl;
    os << "addi x7,x7," <<offset<<std::endl;
    os << "add x7,x7,s0" <<std::endl;
    os <<"lw x" << destReg << ",0(x7)"<<std::endl;
}

Float::Float (float _value) : value(_value) {}

void Float::visualiser(std::ostream &os) const{
    os << " " << "float = " << value << std::endl;
}

void Float::generateRISCV(std::ostream &os, Context& context, int destReg) const {
	os << "i have no idea what to do here" << std::endl;
    exit(1);
}

std::string Float::get_data_type(Context& context) const{
    return "float";
}
