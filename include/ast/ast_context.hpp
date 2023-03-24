// a bunch of register operations and stack operations need to implement here
#pragma once

#include <map>
#include <vector>
#include <stack>
#include <string>
#include <iostream>

#include <cmath>

class variable
{
private:
	int fp_offset;
	bool isThisArray = 0;
	std::string type = "int";
public:
	variable(int _fp_offset, bool _isArray, std::string _type);
	~variable();
	int get_variable_address();
	bool isArray();
	std::string get_type_variable();
};

typedef std::map<std::string, variable *> var_map;

struct Context
{
private:
	var_map* variable_map = new var_map();
	std::vector<var_map*> context_scope;
	int frame_pointer_offset = -16;
	std::string declaration_type = "int";

protected:
	int labelnumber = 0;
	std::string function_name = "";
	bool called_functions = 0;

public:
	variable new_variable(std::string variable_name, bool isArr, std::string type);
	variable get_variable(std::string variable_name);
	variable add_arguments(std::string argument_name, std::string type);
	void for_array_declaration(int array_size);
	void load_word(std::ostream &os, int register_name, int memory_location);
	void store_word(std::ostream &os, int register_name, int memory_location);
	void fload_word(std::ostream &os, int register_name, int memory_location);
	void fstore_word(std::ostream &os, int register_name, int memory_location);
	void store_function_name(std::string input_name);
	void function_calling();
	bool if_called_functions();
	Context();
	int left_reg;
	int right_reg;
	std::array<bool, 32> usedRegs;
	void freeReg(int reg);
	int get_fp_offset();
	int leftreg() const;
	int rightreg() const;
	void setLeftReg(int reg);
	void setRightReg(int reg);
	void enter_scope();
	void exit_scope();
	void declare_type(std::string type);
	std::string return_function_name();
	std::string createlabel(std::string inputlabelname);
	std::string get_declaration_type();
};
