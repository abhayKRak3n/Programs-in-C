#include "postfix.h"




//func to evaluate 2 numbers
void do_operation(struct double_stack * stack, char op) {
	double second=double_stack_pop(stack);
	double first=double_stack_pop(stack);
	double result=0;
	switch (op) {
		case '+':
				result=first+second;
				break;
		case '-':
				result=first-second;
				break;
		case 'X':
				result=first*second;
				break;
		case '/':
				result=first/second;
				break;
		default:
				result=pow(first,second);
				break;
		}
	double_stack_push(stack,result);
}


double evaluate_postfix_expression(char ** expr, int size) {
	struct double_stack * stack = double_stack_new(size);
	double result=0;
	for (int i=0; i<size; i++) {
		if(strlen(expr[i])!=1) {
			double_stack_push(stack, atof(expr[i]));
		}

		else {
		switch (expr[i][0]) {
			case '+':
			case '-':
			case 'X':
			case '/':
			case '^': do_operation(stack,expr[i][0]);
					  break;
			default:
					double_stack_push(stack, atof(expr[i]));
					break;
			}
		}
	}

	result=double_stack_pop(stack);
	return result;
}

