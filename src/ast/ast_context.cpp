#include "ast/ast_context.hpp"

variable::variable(int _fp_offset, bool _isArray)
    : fp_offset(_fp_offset), isThisArray(_isArray){}

variable::~variable(){}

int variable::get_variable_address(){
    return fp_offset;
}
bool variable::isArray(){
    return isThisArray;
}
// void variable::store_value(int val){
//     value = val;
// }
// //int variable::return_variable_value(){
//     return value;
// }

variable Context::new_variable(std::string variable_name, bool isArr)
{
    frame_pointer_offset -=4; //assume integer so 4 bytes reserved for each variable
    (*variable_map)[variable_name] = new variable(frame_pointer_offset, isArr);
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
void Context::for_array_declaration(int array_size){
    frame_pointer_offset -= 4*(array_size-1);
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
    (*variable_map)[argument_name] = new variable(offset, 0);
    return *((*variable_map)[argument_name]);
}

std::string Context::createlabel(std::string inputlabelname){ 
    std::string labelname = inputlabelname + std::to_string(labelnumber++);
	return labelname; 
}
void Context::store_function_name(std::string input_name){
    function_name = input_name;
}
std::string Context::return_function_name(){
    return function_name;
}
void Context::function_calling(){
    called_functions = 1;
}
bool Context::if_called_functions(){
    return called_functions;
}