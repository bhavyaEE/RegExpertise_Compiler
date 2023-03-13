#ifndef ast_type_specifiers.hpp
#define ast_type_specifiers.hpp

#include "ast/ast_node.hpp"

// enum type
// {
// 	typeINT,
//     typeVOID,
// 	typeFLOAT,
// 	typeSTRING,
// 	typeCHAR,
// 	typeDOUBLE
// 	//typeUNSIGNED_INT,
// 	//typeNONE
// }; 

class type_specifier : public Node
{
	public:
		type_specifier(enum type name_type);
        ~type_specifier();
		enum type get_type() const override;
        void visualiser(std::ostream &os) const override;
    protected: 
        enum type Specifier;
		
};
// class type_specifier : public Node
// {
// 	public:
// 		type_specifier(type name_type) : Specifier(name_type) {}

// 		type get_type() const { 
//             return Specifier; 
//         }
//     private: 
//         type Specifier;
		
// };