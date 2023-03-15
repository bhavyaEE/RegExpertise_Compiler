#pragma once

#include <iostream>

class Node;

class Node
{
public: 
  //Node(){}
  virtual ~Node(){}
  //member functions
  virtual void visualiser(std::ostream &os) const = 0; //non-pure virtual as want to be able to print Node value
  virtual void generateRISCV(std::ostream &os, int destReg) const = 0; //pure virtual as Node does not implement generateRISC

};


