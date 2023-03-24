#include "ast/ast_declaration.hpp"

Declaration::Declaration(std::string _TYPE, std::vector<Node *> *_Init_Declarator_List)
    : Type(_TYPE), Init_Declarator_List(_Init_Declarator_List) {}

Declaration::~Declaration() {}

std::string Declaration::get_parameter() const
{
    for (auto Init_Declarator = Init_Declarator_List->begin(); Init_Declarator != Init_Declarator_List->end(); Init_Declarator++)
    {
        Variable_Declarator *vard_node = dynamic_cast<Variable_Declarator *>(*Init_Declarator);
        return vard_node->get_variable_name();
    }
}

void Declaration::visualiser(std::ostream &os) const
{
    os << "Declaration: " << Type << std::endl;
    for (auto Init_Declarator = Init_Declarator_List->begin(); Init_Declarator != Init_Declarator_List->end(); Init_Declarator++)
    {
        (*Init_Declarator)->visualiser(os);
    }
}
void Declaration::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    context.declare_type(Type);
    for (auto Init_Declarator = Init_Declarator_List->begin(); Init_Declarator != Init_Declarator_List->end(); Init_Declarator++)
    {
        (*Init_Declarator)->generateRISCV(os, context, destReg);
    }
}
std::string Declaration::get_data_type(Context &context) const
{
    return Type;
}

Add_Program::Add_Program(Node *_left, Node *_right)
    : left(_left), right(_right) {}

void Add_Program::visualiser(std::ostream &os) const
{
    left->visualiser(os);
    os << std::endl;
    right->visualiser(os);
    os << std::endl;
}
void Add_Program::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    left->generateRISCV(os, context, destReg);
    context.function_calling();
    right->generateRISCV(os, context, destReg);
}
