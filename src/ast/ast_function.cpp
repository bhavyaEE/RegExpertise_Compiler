#include "ast/ast_function.hpp"

Function_No_Arg_Definition ::Function_No_Arg_Definition(std::string type, std::string func_name, Node *func_body)
    : Type(type), Function_Name(func_name), Function_Body(func_body) {}

Function_No_Arg_Definition::~Function_No_Arg_Definition()
{
}

void Function_No_Arg_Definition::visualiser(std::ostream &os) const
{
    os << " "
       << "Function Definition: " << std::endl;
    os << " "
       << "Function type: " << Type << std::endl;
    os << " "
       << "identifier: " << Function_Name << std::endl;
    Function_Body->visualiser(os);
}

void Function_No_Arg_Definition::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    context.store_function_name(Function_Name);
    os << ".text" << std::endl;
    os << ".globl " << Function_Name << std::endl;
    os << Function_Name << ":" << std::endl;
    os << "addi "
       << "sp,sp,-480" << std::endl;
    os << "sw ra," << 476 << "(sp)" << std::endl;
    os << "sw "
       << "s0," << 472 << "(sp)" << std::endl;
    os << "sw x9, 468(sp)" << std::endl;
    os << "addi "
       << "s0,sp," << 480 << std::endl;
    Function_Body->generateRISCV(os, context, destReg);
    os << ".function_end" << Function_Name << ":" << std::endl;
    if (Type == "float")
    {
        os << "fmv.s f10,f" << destReg << std::endl;
    }
    else
    {
        os << "mv"
           << " x10,"
           << "x" << destReg << std::endl;
    }
    os << "lw ra," << 476 << "(sp)" << std::endl;
    os << "lw "
       << "s0," << 472 << "(sp)" << std::endl;
    os << "lw x9, 468(sp)" << std::endl;
    os << "addi "
       << "sp,sp," << 480 << std::endl;
    os << "jr "
       << "ra" << std::endl;
}

Function_With_Arg_Definition ::Function_With_Arg_Definition(std::string type, std::string func_name, std::vector<Node *> *func_args, Node *func_body)
    : Type(type), Function_Name(func_name), Function_Arguments(func_args), Function_Body(func_body) {}

Function_With_Arg_Definition::~Function_With_Arg_Definition()
{
}

void Function_With_Arg_Definition::visualiser(std::ostream &os) const
{
    os << " "
       << "Function Definition: " << std::endl;
    os << " "
       << "Function type: " << Type << std::endl;
    os << " "
       << "identifier: " << Function_Name << std::endl;
    os << " "
       << "Function Arguments: " << std::endl;
    for (auto argument = Function_Arguments->begin(); argument != Function_Arguments->end(); argument++)
    {
        (*argument)->visualiser(os);
    }
    Function_Body->visualiser(os);
}

void Function_With_Arg_Definition::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    context.store_function_name(Function_Name);
    os << ".text" << std::endl;
    os << ".globl " << Function_Name << std::endl;
    os << Function_Name << ":" << std::endl;
    os << "addi "
       << "sp,sp,-480" << std::endl;
    os << "sw ra," << 476 << "(sp)" << std::endl;
    os << "sw "
       << "s0," << 472 << "(sp)" << std::endl;
    os << "sw x9, 468(sp)" << std::endl;
    os << "addi "
       << "s0,sp," << 480 << std::endl;
    int argument_registers[8] = {10, 11, 12, 13, 14, 15, 16, 17};
    for (int i = 0; i < Function_Arguments->size(); i++)
    {
        Declaration *this_arg = dynamic_cast<Declaration *>((*Function_Arguments)[i]);
        std::string type = this_arg->get_data_type(context);
        context.add_arguments(this_arg->get_parameter(), type);
        int argument_frame_pointer = context.get_fp_offset();
        if (Type == "float")
        {
            context.fstore_word(os, argument_registers[i], argument_frame_pointer);
        }
        else
        {
            context.store_word(os, argument_registers[i], argument_frame_pointer);
        }
    }
    Function_Body->generateRISCV(os, context, destReg);
    os << ".function_end" << Function_Name << ":" << std::endl;
    if (Type == "float")
    {
        os << "fmv.s f10,f" << destReg << std::endl;
    }
    else
    {
        os << "mv"
           << " x10,"
           << "x" << destReg << std::endl;
    }
    os << "lw ra," << 476 << "(sp)" << std::endl;
    os << "lw "
       << "s0," << 472 << "(sp)" << std::endl;
    os << "lw x9, 468(sp)" << std::endl;
    os << "addi "
       << "sp,sp," << 480 << std::endl;
    os << "jr "
       << "ra" << std::endl;
}
