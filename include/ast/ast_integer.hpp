#ifndef ast_integer.hpp
#define ast_integer.hpp

#include <string>
#include <iostream>


//class Literal : public Expression {};
class Int
    : public Expression
{
    private:
        int value;
    public:
        Int(int _value){}
        void visualiser(std::ostream &os) const override;
        void generateRISCV(std::ostream &os, int destReg) const override;
	    // type get_data_type(Context& context) const override;
	    double get_value() const override;
};

#endif
