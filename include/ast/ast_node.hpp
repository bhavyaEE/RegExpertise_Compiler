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
  virtual int get_value(Context& context) const {
    std::cerr << "get value when there's no value, get out" << std::endl;
    exit(1);
  }
  virtual std::string get_variable_name() const {
    std::cerr << "get variable name when there's no variable, get out" << std::endl;
    exit(1);
  }
  virtual int get_variable_address() const {
    std::cerr << "get variable address when there's no variable address, get out" << std::endl;
    exit(1);
  }
  virtual void get_index(std::ostream &os, Context& context, int destReg) const{
    std::cerr << "get array index when there's no array index, get out" << std::endl;
    exit(1);
  };
};

