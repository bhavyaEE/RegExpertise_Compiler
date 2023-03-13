#include "ast/ast_integer.hpp"

INT::INT(int _value) 
    : value(_value)
{}
void INT::visualiser(std::ostream &os) const{
    os << " " << "integer = " << value << std::endl;
}
void INT::generateRISCV(std::ostream &os, Context& context, int destReg) const {
		// int stack_pointer = context.get_stack_pointer();
		// std::string destReg = "$2";

		// os << "\t" << "li" << "\t" << "\t" << "$2" << ", " << value << std::endl;

		// context.store_register(os, destReg, stack_pointer);
        //needs to figure this out	
	}

type INT::get_data_type(Context& context) const { 
    return type(INT); //need to have this in context
}
double INT::get_value() const { 
    return value; 
}


