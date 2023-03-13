#ifndef ast_literal.hpp
#define ast_literal.hpp

#include <string>
#include <iostream>


class Literal : public Expression {};
class Int
    : public Literal
{
private:
    int value;
public:
    Int(int _value)
    {}
    void visualiser(std::ostream &os) const override;
    void generateRISCV(std::ostream &dst, Context& context) const override;
	type get_data_type(Context& context) const override;
	double get_value() const override;
};

#endif
