#include "ast/ast_statement.hpp"

Compound_Statement::Compound_Statement (std::vector<Node*>* _declaration_list, std::vector<Node*>* _statement_list)
	: declaration_list (_declaration_list), statement_list (_statement_list){}

void Compound_Statement::visualiser(std::ostream &os) const{
    if (statement_list != NULL)
    {
        for(auto statement = statement_list->begin(); statement != statement_list->end(); statement++)
        {
            (*statement)->visualiser(os);
        }
    }
    if (declaration_list != NULL)
    {
        for (auto declaration = declaration_list->begin(); declaration != declaration_list->end(); declaration++)
        {
            (*declaration)->visualiser(os);
        }
    }


}
void Compound_Statement::generateRISCV(std::ostream &os, Context& context, int destReg) const
{
    if (statement_list != NULL)
    {
        for(auto statement = statement_list->begin(); statement != statement_list->end(); statement++)
        {
            (*statement)->generateRISCV(os, context, destReg);
        }
    }

    if (declaration_list != NULL)
    {
        for (auto declaration = declaration_list->begin(); declaration != declaration_list->end(); declaration++)
        {
            (*declaration)->generateRISCV(os, context, destReg);
        }
    }


}

/*------------------------------------IF STATEMENT--------------------------------------*/

If_Statement :: If_Statement(Node* _condition, Node* _statement): condition(_condition), statement(_statement){}

If_Statement :: ~If_Statement(){
    delete statement; 
    delete condition; 
}

void If_Statement :: visualiser(std::ostream &os) const {
    os << "If ";
    condition->visualiser(os); 
    os << "Then ";
    statement->visualiser(os);
    os << "" << std::endl;
}

void If_Statement :: generateRISCV(std::ostream &os, Context& context, int destReg) const {
	condition->generateRISCV(os, context, destReg);
    std::string if_exit_label = context.createlabel("if_end");
	os << "beq " << " " << "x" << destReg << "," << "zero" << "," << if_exit_label << std::endl;
    statement->generateRISCV(os, context, destReg);
	os << if_exit_label << " :" << std::endl;
}
	

/*------------------------------------IF ELSE STATEMENT--------------------------------------*/

If_Else_Statement :: If_Else_Statement(Node* _condition, Node* _true_statement, Node* _else_statement)
: condition(_condition), true_statement(_true_statement), else_statement(_else_statement){}

If_Else_Statement :: ~If_Else_Statement(){
    delete true_statement; 
    delete else_statement; 
    delete condition; 
}

void If_Else_Statement :: visualiser(std::ostream &os) const{
    os << "If ";
    condition->visualiser(os); 
    os << "Then ";
    true_statement->visualiser(os);
    os << "Else ";
    else_statement->visualiser(os);
    os << std::endl;
}

void If_Else_Statement :: generateRISCV(std::ostream &os, Context& context, int destReg) const {
    condition->generateRISCV(os, context, destReg);
    std::string else_label = context.createlabel("else_branch");
    std::string if_exit_label = context.createlabel("if_end");
    os << "beq " << " " << "x" << destReg << "," << "zero" << "," << else_label << std::endl;
    true_statement->generateRISCV(os, context, destReg);
    os << "bne " << " " << "x" << destReg << "," << "zero" << "," << if_exit_label << std::endl;
    os << else_label << " :" << std::endl;
    else_statement->generateRISCV(os, context, destReg);
    os << if_exit_label << " :" << std::endl;
}



// /*------------------------------------WHILE STATEMENT--------------------------------------*/

While_Statement :: While_Statement(Node* _expression, Node* _statement): expression(_expression), statement(_statement){}

While_Statement :: ~While_Statement(){
    delete statement; 
    delete expression; 
}

void While_Statement :: visualiser(std::ostream &os) const {
    os << "While ";
    if (expression !=NULL){
        expression->visualiser(os); 
    }
    os << "Do ";
    if (statement !=NULL){
        statement->visualiser(os);
    }
    os << std::endl;
}

void While_Statement :: generateRISCV(std::ostream &os, Context& context, int destReg) const {
   
    std::string begin_while_label = context.createlabel("DO");
	std::string end_while_label = context.createlabel("END");

    os << begin_while_label << ":" << std::endl;
    if (expression !=NULL){
         expression->generateRISCV(os, context, destReg);
    }
    os << "beq" << " " << "x" << destReg << "," << "zero" << "," << end_while_label << std::endl;
    if (statement != NULL){
        statement->generateRISCV(os, context, destReg);
    }
    os << "j " << begin_while_label << std::endl;  
    os << end_while_label << " :" << std::endl;
}


// /*------------------------------------ FOR LOOP --------------------------------------*/

For_Loop :: For_Loop (Node* _initial_expression, Node* _loop_condition, Node* _increment_expression, Node* _statement) 
: initial_expression(_initial_expression), loop_condition(_loop_condition), increment_expression(_increment_expression), statement(_statement){} 

For_Loop :: ~For_Loop(){
    delete initial_expression; 
    delete loop_condition; 
    delete increment_expression; 
    delete statement; 
}

void For_Loop :: visualiser(std::ostream &os) const{
    os << "For Loop " << std::endl; 
    os << "Initial Set Condition : " ;  
    initial_expression->visualiser(os); 
    os << "Loop condition : "; 
    loop_condition->visualiser(os); 
    os << "Increment condition (if exists) : "; 
    if (statement !=NULL){
        increment_expression->visualiser(os);
    }
    os << "Statements in loop : "; 
    statement->visualiser(os); 
    os << std::endl;
}

void For_Loop :: generateRISCV(std::ostream &os, Context& context, int destReg) const{

    std::string begin_for_label = context.createlabel("FOR");
	std::string end_for_label = context.createlabel("END");
    
	
	if (initial_expression !=NULL){
         initial_expression->generateRISCV(os, context, destReg);
    }

    os << begin_for_label << ":" << std::endl; //initialise before the for loop begins

    if (loop_condition !=NULL){
         loop_condition->generateRISCV(os, context, destReg);
    }

    os << "beq" << " " << "x" << destReg << "," << "zero" << "," << end_for_label << std::endl;

    if (statement !=NULL){
         statement->generateRISCV(os, context, destReg);
    }

    if (increment_expression !=NULL){
         increment_expression->generateRISCV(os, context, destReg);
    }
    
    os << "j " << begin_for_label << std::endl; 
    os << end_for_label << ":" << std::endl; 

 }