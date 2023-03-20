#include "ast/ast_context.hpp"

variable::variable(int _fp_offset, int _size)
    : fp_offset(_fp_offset), size(_size){}

variable::~variable(){}

int variable::get_variable_address(){
    return fp_offset;
}
int variable::get_size(){
    return size;
}

variable Context::new_variable(std::string variable_name)
{
    frame_pointer_offset -=4; //assume integer so 4 bytes reserved for each variable
    (*variable_map)[variable_name] = new variable(frame_pointer_offset, 0);
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
int Context::for_array_declaration(int array_size){
    frame_pointer_offset -= 4*array_size;
}

void Context::load_word(std::ostream& os, int register_name, int memory_location)
{
    os << "lw x" << register_name << "," <<memory_location << "(s0)" << std::endl;
}
void Context::store_word(std::ostream& os, int register_name, int memory_location)
{
    os << "sw x" << register_name << "," << memory_location << "(s0)" << std::endl;
}

variable Context::add_arguments(std::string argument_name, int offset)
{
    (*variable_map)[argument_name] = new variable(offset);
    return *((*variable_map)[argument_name]);
}
