/* James Snee s3369721 Algorithms and Analysis */
/* Summer 2015 Assignment 2 - Code */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

void stack_init(stack_s * stack, size_t size){
	
	assert(stack != NULL);

	stack->size = size;
	stack->top = 0;

	if ((stack->items = malloc(sizeof(char) * size)) == NULL) {
		fprintf(stderr, "Memory allocation for stack_init failed! "
			"Aborting data entry !\n");
		exit(EXIT_FAILURE);
	}
}

void stack_push(stack_s * stack, char item){
	
	assert(stack != NULL);
	assert(stack->items != NULL);

	if (stack->size == stack->top) {
		stack->size = stack->size * 2;
		if ((stack->items = realloc(stack->items,
					sizeof(int) * stack->size)) == NULL) {
			fprintf(stderr, "Memory reallocation for stack_push failed! "
				"Aborting data entry !\n");
			exit(EXIT_FAILURE);
		}
	}
	stack->items[stack->top] = item;
	stack->top = stack->top + 1;
}

char stack_pop(stack_s * stack){
	
	char val;

	if (stack_is_empty(stack) == 1){
		printf("Error: Nothing to pop, stack is empty!\n");
	}

	assert(stack != NULL);
	assert(stack->top > 0);
	assert(stack->items != NULL);

	val = stack->items[stack->top - 1];
	stack->top = stack->top - 1;

	return val;
}

int stack_is_empty(stack_s * stack){
	
	assert(stack != NULL);

	if (stack->top <= 0)
		return 1;

	return 0;
}

void stack_free(stack_s * stack){
	
	assert(stack != NULL);

	if(stack->items) free(stack->items);
}

