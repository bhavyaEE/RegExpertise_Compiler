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
    public:
        variable(int _fp_offset);
        ~variable();
        int get_variable_address();

};

typedef std::map<std::string, variable*> var_map;
struct Context{
    private:
        var_map* variable_map = new var_map();
        bool HasArg = false;
        int frame_pointer_offset = -16;
    public:

		variable new_variable(std::string variable_name);

		variable get_variable(std::string variable_name);

        int get_fp_offset();
        // void allocate_stack();
		// void deallocate_stack();

		void load_word(std::ostream& os, int register_name, int memory_location);

		void store_word(std::ostream& os, int register_name, int memory_location);

		// void output_load_operation(std::ostream& os, type load_type, std::string register_1, std::string register_2, int frame_offset)
		// {
		// 	os << "\t" << "lw" << "\t" << "$" << register_1 << "," << frame_offset << "($" << register_2 << ")" << std::endl;
		// }

		// // Testing
		// void output_store_operation(std::ostream& os, type load_type, std::string register_1, std::string register_2, int frame_offset)
		// {
		// 	os << "\t" << "sw" << "\t" << "$" << register_1 << "," << frame_offset << "($" << register_2 << ")" << std::endl;
		// }



};
