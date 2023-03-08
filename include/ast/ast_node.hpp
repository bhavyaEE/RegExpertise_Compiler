#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Node;

typedef const Node *NodePtr;

class Context{
//write this


};

class Node
{
public:
    virtual ~Node()
    {}

    //! print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

    virtual void generateRISCV(std::ostream &dst, Context& context) const
    { std::cerr << "ast_node.hpp: generateRISCV not implemented" << std::endl; }
};


#endif
