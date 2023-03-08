#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>



class Number
    : public Expression
{
private:
    double value;
public:
    Number(double _value)
        : value(_value)
    {}

    double getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        return value;
    }
};

class Primitive : public Expression {};
class Int
    : public Primitive
{
private:
    int value;
public:
    Int(int _value)
        : value(_value)
    {}

    virtual void generateRISCV(std::ostream &dst, Context& context) const override
		{
			int stack_pointer = context.get_stack_pointer();
			std::string destReg = "$2";

			dst << "\t" << "li" << "\t" << "\t" << "$2" << ", " << value << std::endl;

			context.store_register(dst, destReg, stack_pointer);	
		}

		virtual type get_data_type(Context& context) const override { 
            return type(INT); 
        };

		virtual double evaluate() const override { return value; };
};
#endif
