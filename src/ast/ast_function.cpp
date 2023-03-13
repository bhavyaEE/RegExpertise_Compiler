#include "ast/ast_function.hpp"

Function_No_Arg_Definition :: Function_No_Arg_Definition(type_specifier* type, std::string func_name, Statement* func_body)
    :Type(type), Function_Name(func_name), Function_Body(func_body){}

Function_No_Arg_Definiton::~Function_No_Arg_Definiton()
{}

void Function_No_Arg_Definition::visualiser(std::ostream &os) const {
    os << " " << "Function Definition: " << std::endl;
    Type->visualiser(std::ostream &os);
    os << " " << "identifier: " <<Function_Name << std::endl;
    //statement->visualiser()
}

void Function_No_Arg_Definition::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    //a bunch of stack allocation deallocation
}

Function_With_Arg_Definition :: Function_With_Arg_Definition(type_specifier* type, std::string func_name, std::vector<Declarator*> func_args, Statement* funct_body)
 : Type(type), Function_Name(func_name), Function_Arguments(func_args), Function_Body(func_body){}

Function_With_Arg_Definition::~Function_With_Arg_Definition()
{}

void Function_With_Arg_Definition::visualiser(std::ostream &os) const {
    os << " " << "Function Definition: " << std::endl;
    Type->visualiser(std::ostream &os);
    os << " " << "identifier: " <<Function_Name << std::endl;
    os << " " << "arguments: " <<std::endl;
    for (int i = 0; i < Function_Arguments.size(); i++){
        Function_Arguments[i]->visualiser();
    }
    //statement->visualiser()
}

void Function_No_Arg_Definition::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    //a bunch of stack allocation deallocation
}


