#pragma once

#include <iostream>
#include "ast_context.hpp"

class Node;

class Node
{
public:
  //Node(){}
  virtual ~Node(){}
  //member functions
  virtual void visualiser(std::ostream &os) const = 0; //non-pure virtual as want to be able to print Node value
  virtual void generateRISCV(std::ostream &os, Context& context, int destReg) const = 0; //pure virtual as Node does not implement generateRISC
  // virtual int get_value() const;
  // virtual std::string get_variable_name() const;
};

