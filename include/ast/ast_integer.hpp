#pragma once


#include <string>
#include <iostream>
#include "ast_node.hpp"

class Int : public Node
{
private:
    int value;
public:
    Int(int _value);
    ~Int(){}
    void visualiser(std::ostream &os) const override;
    void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
	//type get_data_type(Context& context) const override;
	int get_value(Context& context) const override;
};

class Variable : public Node
{
	private:
		std::string variable_name;
	public:
		Variable(std::string _variable_name);
        ~Variable(){}
        // int get_value() const override;
        void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
        std::string get_variable_name() const override;
        // int get_value(Context& context) const override;
        // int get_variable_value(Context& context) const;
};

class Array : public Node{
	private:
		std::string array_name;
		Node* index;
	public:
		Array(std::string _name, Node* _index);
		~Array(){};
        std::string get_variable_name() const override;
        void get_index(std::ostream &os, Context& context, int destReg) const override;
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;

};
