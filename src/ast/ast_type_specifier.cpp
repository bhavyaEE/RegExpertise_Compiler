#include "ast/ast_type_specifier.hpp"

type_specifier::type_specifier(type name_type)
  : Specifier(name_type)
{}

// Destructor
type_specifier::~type_specifier()
{}

enum type type_specifier::get_type() const
{
  switch(type){
    case typeINT:
      return Specifier;
    case typeFLOAT:
      return Specifier;
    case typeVOID:
      return Specifier;
    case typeSTRING:
      return Specifier;
    case typeCHAR:
      return Specifier;
    case typeDOUBLE:
      return Specifier;
    default:
      std::cerr << "unknown type not included in type_specifier" << std::endl;
      exit(1);
  }
}
void type_specifier::visualiser(std::ostream &os) const
{
  switch(type){
    case typeINT:
      os << "int";
      break;
    case typeVOID:
      os << "void";
      break;
    case typeSTRING:
      os << "string";
      break;
    case typeCHAR:
      os << "char";
      break;
    case typeFLOAT:
      os << "float";
      break;
    case typeDOUBLE:
      os << "double";
      break;
    default:
      os << "unknown type ";
  }
  os << std::endl;
}



