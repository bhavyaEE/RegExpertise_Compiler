#include "ast/ast_context.hpp"

variable::variable(int _fp_offset)
    : fp_offset(_fp_offset){}

variable::~variable(){}

int variable::get_variable_address(){
    return fp_offset;
}

variable Context::new_variable(std::string variable_name)
{
    frame_pointer_offset -=4; //assume integer so 4 bytes reserved for each variable
    (*variable_map)[variable_name] = new variable(frame_pointer_offset);
    return *((*variable_map)[variable_name]); //put variable on the map
}

variable Context::get_variable(std::string variable_name)
{
    // Return variable
    if((*variable_map).count(variable_name))
    {
        return *((*variable_map)[variable_name]);
    }
}

int Context::get_fp_offset(){
    return frame_pointer_offset;
}
void Context::load_word(std::ostream& os, int register_name, int memory_location)
{
    os << "lw x" << register_name << "," <<memory_location << "(s0)" << std::endl;
}
void Context::store_word(std::ostream& os, int register_name, int memory_location)
{
    os << "sw x" << register_name << "," << memory_location << "(s0)" << std::endl;
}
// void allocate_stack(){
//     frame_pointer_offset -=8;
// }
// void deallocate_stack(){
//     if (register_counter != 0)
		// 	{
		// 		frame_pointer += 8;
		// 		register_counter--;
		// 	}
// }
