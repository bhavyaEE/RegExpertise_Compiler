#include "ast/ast_function.hpp"

Function_No_Arg_Definition :: Function_No_Arg_Definition(std::string type, std::string func_name, Node* func_body)
    :Type(type), Function_Name(func_name), Function_Body(func_body){}

Function_No_Arg_Definition::~Function_No_Arg_Definition()
{}

void Function_No_Arg_Definition::visualiser(std::ostream &os) const {
    os << " " << "Function Definition: " << std::endl;
    os << " " << "Function type: " <<Type << std::endl;
    os << " " << "identifier: " <<Function_Name << std::endl;
    Function_Body->visualiser(os);
}

void Function_No_Arg_Definition::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    //a bunch of stack allocation deallocation
    os << ".globl " << Function_Name << std::endl;
    // Function label
    os << Function_Name << ":" << std::endl;
    // os << "addi " << "sp,sp" << "-16" << std::endl;
    // os << "sw " << "s0,12" << "(sp)" << std::endl;
    // os << "addi " << "s0,sp" << "16" << std::endl;
    Function_Body->generateRISCV(os, context, destReg);
    os << ".function_end:" << std::endl;
    os <<"mv" << " x10," <<"x" << destReg << std::endl;
    // os << "lw " << "s0,12" << "(sp)" << std::endl;
    // os << "addi " << "sp,sp" << "16" << std::endl;
    os << "jr " << "ra" << std::endl;
}

Function_With_Arg_Definition :: Function_With_Arg_Definition(std::string type, std::string func_name, std::vector<Node*>* func_args, Node* func_body)
 : Type(type), Function_Name(func_name), Function_Arguments(func_args), Function_Body(func_body){}

Function_With_Arg_Definition::~Function_With_Arg_Definition()
{}

void Function_With_Arg_Definition::visualiser(std::ostream &os) const {
    os << " " << "Function Definition: " << std::endl;
    os << " " << "Function type: " <<Type << std::endl;
    os << " " << "identifier: " <<Function_Name << std::endl;
    os << " " << "Function Arguments: " << std::endl;
    for(auto argument = Function_Arguments->begin(); argument != Function_Arguments->end(); argument++)
        {
            (*argument)->visualiser(os);
        }
    Function_Body->visualiser(os);
}

void Function_With_Arg_Definition::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    //a bunch of stack allocation deallocation
    os << ".globl " << Function_Name << std::endl;
    // Function label
    os << Function_Name << ":" << std::endl;
    // os << "addi " << "sp,sp" << "-16" << std::endl;
    // os << "sw " << "s0,12" << "(sp)" << std::endl;
    // os << "addi " << "s0,sp" << "16" << std::endl;
    int argument_frame_pointer = -32;
	int argument_registers[4]  = {10, 11, 12, 13};
    for(int i = 0; i < Function_Arguments->size(); i++){
        argument_frame_pointer -= 4;
        context.store_word(os, argument_registers[i], argument_frame_pointer);
        Declaration* this_arg = dynamic_cast<Declaration*>((*Function_Arguments)[i]);
        context.add_arguments(this_arg->get_parameter(), argument_frame_pointer);
    }
    Function_Body->generateRISCV(os, context, destReg);
    os << ".function_end:" << std::endl;
    os <<"mv" << " x10," <<"x" << destReg << std::endl;
    // os << "lw " << "s0,12" << "(sp)" << std::endl;
    // os << "addi " << "sp,sp" << "16" << std::endl;
    os << "jr " << "ra" << std::endl;
}


