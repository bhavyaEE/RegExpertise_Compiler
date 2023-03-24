#include "ast/ast_context.hpp"

variable::variable(int _fp_offset, bool _isArray, std::string _type)
    : fp_offset(_fp_offset), isThisArray(_isArray), type(_type) {}

variable::~variable() {}

int variable::get_variable_address()
{
    return fp_offset;
}
bool variable::isArray()
{
    return isThisArray;
}
std::string variable::get_type_variable(){
    return type;
}
variable Context::new_variable(std::string variable_name, bool isArr, std::string type)
{
    frame_pointer_offset -= 4; // assume integer so 4 bytes reserved for each variable
    (*variable_map)[variable_name] = new variable(frame_pointer_offset, isArr, type);
    return *((*variable_map)[variable_name]); // put variable on the map
}
variable Context::get_variable(std::string variable_name)
{
    if ((*variable_map).count(variable_name)){
        return *((*variable_map)[variable_name]);
    }
}

int Context::get_fp_offset()
{
    return frame_pointer_offset;
}
void Context::for_array_declaration(int array_size)
{
    frame_pointer_offset -= 4 * (array_size - 1);
}

void Context::load_word(std::ostream &os, int register_name, int memory_location)
{
    os << "lw x" << register_name << "," << memory_location << "(s0)" << std::endl;
}
void Context::store_word(std::ostream &os, int register_name, int memory_location)
{
    os << "sw x" << register_name << "," << memory_location << "(s0)" << std::endl;
}
void Context::fload_word(std::ostream &os, int register_name, int memory_location)
{
    os << "flw f" << register_name << "," << memory_location << "(s0)" << std::endl;
}
void Context::fstore_word(std::ostream &os, int register_name, int memory_location)
{
    os << "fsw f" << register_name << "," << memory_location << "(s0)" << std::endl;
}

variable Context::add_arguments(std::string argument_name, std::string type)
{
    frame_pointer_offset -= 4;
    (*variable_map)[argument_name] = new variable(frame_pointer_offset, 0, type);
    return *((*variable_map)[argument_name]);
}

std::string Context::createlabel(std::string inputlabelname)
{
    std::string labelname = inputlabelname + std::to_string(labelnumber++);
    return labelname;
}
void Context::store_function_name(std::string input_name)
{
    function_name = input_name;
}
std::string Context::return_function_name()
{
    return function_name;
}
void Context::function_calling()
{
    called_functions = 1;
}
bool Context::if_called_functions()
{
    return called_functions;
}

Context::Context() : usedRegs{false}, left_reg{28}, right_reg{30} {}

void Context::freeReg(int reg)
{
    usedRegs[reg] = false;
}
int Context::leftreg() const
{
    if (!usedRegs[28])
    {
        return 28;
    }
    else
        return 29;
}
int Context::rightreg() const
{
    if (!usedRegs[30])
    {
        return 30;
    }
    else
        return 31;
}
void Context::setLeftReg(int reg)
{
    usedRegs[28] = false;
    usedRegs[29] = false;
    usedRegs[reg] = true;
}
void Context::setRightReg(int reg)
{
    usedRegs[30] = false;
    usedRegs[31] = false;
    usedRegs[reg] = true;
}
void Context::enter_scope(){
    context_scope.push_back(variable_map);
    variable_map = new var_map(*variable_map);
}
void Context::exit_scope(){
    delete variable_map;
    variable_map = context_scope.back();
    if(!context_scope.empty()){
        context_scope.pop_back();
    }
}
void Context::declare_type(std::string type){
    declaration_type = type;

}
std::string Context::get_declaration_type(){
    return declaration_type;
}
