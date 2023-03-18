#include "ast/ast_expression.hpp"


Direct_Assignment::Direct_Assignment(Node* _left, Node* _right)
    :left(_left), expression(_right){}

void Direct_Assignment::visualiser(std::ostream &os) const{
    left->visualiser(os);
    os << "is assigned to be ";
    expression->visualiser(os);
}
void Direct_Assignment::generateRISCV(std::ostream &os, Context& context, int destReg) const {
    Variable* var_node = dynamic_cast<Variable*>(left);
    std::string var_name = var_node->get_variable_name();
    variable this_variable = context.get_variable(var_name);
    int offset = this_variable.get_variable_address();
    expression->generateRISCV(os, context, destReg);
    context.store_word(os, destReg, offset);
}
