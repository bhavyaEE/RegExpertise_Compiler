#pragma once

#include <string>
#include "ast_node.hpp"

/*If the function declares multiple local variables, 
additional stack space will be allocated for each variable.

If the function takes multiple arguments, space may need to be 
allocated on the stack to store each argument.

If the function makes calls to other functions,
space will be allocated on the stack for the return address 
and any arguments passed to the called function.*/

class Function_No_Arg_Definition : public Node {
    private:
        std::string Type;
        std::string Function_Name;
        Node* Function_Body;

    public: 
        Function_No_Arg_Definition(std::string type, std::string func_name, Node* funct_body);
        ~Function_No_Arg_Definition();
        void visualiser(std::ostream &os) const override;
        void generateRISCV(std::ostream &os, /*Context& context,*/int destReg) const override;

};




// class Function_With_Arg_Definition : public Node {
//     private:
//         type_specifier* Type;
//         std::string Function_Name;
//         std::vector<NodePtr>* Function_Arguments;
//         Statement* Function_Body;

//     public: 
//         Function_With_Arg_Definition(type_specifier* type, std::string func_name, std::vector<Declarator*>* func_args, Statement* funct_body);
//         ~Function_With_Arg_Definition();
//         void visualiser(std::ostream &os) const override;
//         void generateRISCV(std::ostream &dst, Context& context, int destReg) const override;

// }
