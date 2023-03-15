#include "ast/ast_integer.hpp"

Int::Int(int _value) 
    : value(_value)
{}

void Int::visualiser(std::ostream &os) const{
    os << " " << "integer = " << value << std::endl;
}

void Int::generateRISCV(std::ostream &os, /*Context& context,*/ int destReg) const {
		// int stack_pointer = context.get_stack_pointer();
		// std::string destReg = "$2";

		os <<"li" << " " << "a0, " << value << std::endl;
          

		// context.store_register(os, destReg, stack_pointer);
        //needs to figure this out	
}

// type INT::get_data_type(Context& context) const { 
//     return type(INT); //need to have this in context
// }

int Int::get_value() const { 
    return value; 
}


