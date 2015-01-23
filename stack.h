/* stack.h */

#define INITIAL_STACK_SIZE 20


typedef struct {
	
	size_t size;
	int top;
	char *items;

} stack_s;

void stack_init(stack_s * stack, size_t size);
void stack_push(stack_s * stack, char item);
char stack_pop(stack_s * stack);
int stack_is_empty(stack_s * stack);
void stack_free(stack_s * stack);

