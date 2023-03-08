#include "ast/ast_literal.hpp"

INT::INT(int _value) 
    : value(_value)
{}
void visualiser(std::ostream &os) const{
    os << " " << "integer = " << value << std::endl;
}
void generateRISCV(std::ostream &dst, Context& context) const {
		// int stack_pointer = context.get_stack_pointer();
		// std::string destReg = "$2";

		// dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << value << std::endl;

		// context.store_register(dst, destReg, stack_pointer);
        //needs to figure this out	
	}

type get_data_type(Context& context) const { 
    return type(INT); //need to have this in context
}
double get_value() const { 
    return value; 
}
};

