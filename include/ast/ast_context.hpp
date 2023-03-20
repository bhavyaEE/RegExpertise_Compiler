//a bunch of register operations and stack operations need to implement here
#pragma once

#include <map>
#include <vector>
#include <stack>
#include <string>
#include <iostream>

#include <cmath>


class variable{
    private:
        int fp_offset;
		int size = 0;
    public:
        variable(int _fp_offset, int _size);
        ~variable();
        int get_variable_address();
		int get_size();

};

typedef std::map<std::string, variable*> var_map;

struct Context{
    private:
        var_map* variable_map = new var_map();
        int frame_pointer_offset = -16;
    public:

		variable new_variable(std::string variable_name);

		variable get_variable(std::string variable_name);

		variable add_arguments(std::string argument_name, int offset);
        int get_fp_offset();
        // void allocate_stack();
		// void deallocate_stack();
		int for_array_declaration(int array_size);

		void load_word(std::ostream& os, int register_name, int memory_location);

		void store_word(std::ostream& os, int register_name, int memory_location);



};
