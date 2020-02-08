#include "infix.h"

double double_stack_peek(struct double_stack * this) { //return item at top of stack
	return *(this->items+this->top-1);
}
bool isEmpty(struct double_stack * this) { //check if stack is empty or not
	return (this->top==0);
}


//func to calc precedence of operator
	bool precedence(char first, char sec) {
	bool result=false;

	switch (first) {
		case '^': result=(sec!='^');
 			break;

		case 'X':
		case '/': if(sec!='^' && sec!= 'X' && sec != '/')
  				result=true;
  			break;
		case '+':
		case '-': result=(sec=='(');
 			break;
		default:  break;
	}
return result;
}



double evaluate_infix_expression(char ** expr, int size) {
char * result [size];
int top=0;
struct double_stack * stack = double_stack_new(size);
for (int i=0; i<size; i++) {
if(strlen(expr[i])!=1) {
result[top]=expr[i];
top++;
}
else {
if(expr[i][0]>='0' && expr[i][0]<='9') {  //if num is digit
result[top]=expr[i];
top++;
}

else if(expr[i][0]=='(') {
double_stack_push(stack,i);
}

else if(expr[i][0]==')') {
int op = double_stack_pop(stack);
while(expr[op][0]!='(') {
result[top] = expr[op];
top++;
op=double_stack_pop(stack);
}
}

else {
while(!isEmpty(stack)) {
int other = double_stack_peek(stack);
if(precedence(expr[other][0],expr[i][0])) {
result[top] = expr[other];
top++;
double_stack_pop(stack);
}

else {
break;
}
}

double_stack_push(stack,i);
}
}

}
while(!isEmpty(stack)) {
int op = double_stack_pop(stack);
result[top]=expr[op];
top++;
}
double final_result = evaluate_postfix_expression(result,top);
return final_result;
}
