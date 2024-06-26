#include "ast/ast_return.hpp"

Return::Return(Node *return_expression) : return_expression(return_expression) {}

Return::~Return()
{
    delete return_expression;
}

void Return::visualiser(std::ostream &os) const
{
    os << " "
       << "Return ";
    if (return_expression != NULL)
    {
        return_expression->visualiser(os);
    }
    else
    {
        os << "NULL";
    }
    os << std::endl;
}

void Return::generateRISCV(std::ostream &os, Context &context, int destReg) const
{
    if (return_expression != NULL)
    {
        return_expression->generateRISCV(os, context, destReg); // change to a0??
    }
    else
    {
        os << "li x" << destReg << ","
           << " "
           << "0" << std::endl;
    }
    std::string fname = context.return_function_name();
    os << "j .function_end" << fname << std::endl;
}
