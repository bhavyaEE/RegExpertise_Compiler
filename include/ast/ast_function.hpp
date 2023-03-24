#pragma once

#include <string>
#include "ast_node.hpp"
#include "ast_declaration.hpp"


class Function_No_Arg_Definition : public Node {
    private:
        std::string Type;
        std::string Function_Name;
        Node* Function_Body;

    public:
        Function_No_Arg_Definition(std::string type, std::string func_name, Node* funct_body);
        ~Function_No_Arg_Definition();
        void visualiser(std::ostream &os) const override;
        void generateRISCV(std::ostream &os, Context& context, int destReg) const override;

};


class Function_With_Arg_Definition : public Node {
    private:
        std::string Type;
        std::string Function_Name;
        std::vector<Node*>* Function_Arguments;
        Node* Function_Body;

    public:
        Function_With_Arg_Definition(std::string type, std::string func_name, std::vector<Node*>* func_args, Node* func_body);
        ~Function_With_Arg_Definition();
        void visualiser(std::ostream &os) const override;
        void generateRISCV(std::ostream &os, Context& context, int destReg) const override;

};
