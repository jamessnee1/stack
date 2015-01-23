/* James Snee s3369721 Algorithms and Analysis */
/* Summer 2015 Assignment 2 - Code */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"


int main (){
	
	stack_s *stack;
	
	int i, open = 0, close = 0;

	/*sample input*/
	char * input = "((a) + (b)) + ((c)(a))";

	stack_init(stack, INITIAL_STACK_SIZE);

	printf("Input String: %s\n", input);

	for (i = 0; i < strlen(input); i++){
		/*check for open brackets. If it is one, push to stack. 
		If it is closed, pop from stack.*/
		
		if (input[i] == '('){
			open++;
			printf("Pushing ( to stack.\n");
			stack_push(stack, '(');
		}
		else if (input[i] == ')'){
			close++;
			printf("Popping ) from stack.\n");
			stack_pop(stack);
		}
	}

	stack_free(stack);

	printf("Number of open brackets: %i. Number of close brackets: %i.\n", open, close);
	if (open == close){
		printf("Matching brackets.\n");

	}else {
		printf("Non matching brackets.\n");
	}

	return(EXIT_SUCCESS);
}
