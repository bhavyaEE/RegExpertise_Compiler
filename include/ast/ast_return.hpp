#pragma once

#include "ast_node.hpp"


class Return : public Node{

    public:

    Return(Node* return_expression);
    ~Return();

    void visualiser(std::ostream &os) const override;
    void generateRISCV(std::ostream &os, Context& context, int destReg) const override;

    private:
    Node* return_expression;
};
