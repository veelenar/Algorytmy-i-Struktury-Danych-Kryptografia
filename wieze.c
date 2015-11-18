#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stacks{

	int data;
	struct Stacks *previous;

}Stack;

Stack *Wieza1 = NULL;
Stack *Wieza2 = NULL;
Stack *Wieza3 = NULL;


Stack* Stack_init()
{
	Stack *new_stack = (Stack*)calloc(1, sizeof(Stack));

	new_stack->previous = NULL;
	new_stack->data = 0;

	return new_stack;
}

void *push(Stack* stack, char x)
{
	Stack* nowy;
	nowy = (Stack*)malloc(sizeof(Stack));

	nowy->data = x;
	nowy->previous = stack;
	stack = nowy;
	return stack;
}

void show_stack(Stack *st)
{

	if (((st->previous == NULL) || (st->data == 0))){

		printf("Stack is empty!", '\n');

	}
	else{

		while (st->previous != NULL){

			printf(" %i", st->data);
			st = st->previous;

		}

		printf(" %i", st->data);

	}

}

int *pop(Stack *stack)
{
	int x = 0;
	if (stack != NULL)
	{
		x = stack->data;
		Stack *old = stack;
		stack = (stack)->previous;
		/*free(old);*/
	}
	return stack;
}

int peek(Stack *st){
	int c;

	if (st->data == 0){

		return 0;

	}
	else{

		c = st->data;
		return c;

	}

}

bool isEmpty(Stack *st){
	int i = 0;

	if (st->data != 0){

		i++;

	}

	if (i > 0){

		return false;

	}
	else{

		return true;

	}

}

size_t size(Stack *st){
	size_t i = 0;

	if (((st->data == 0) && (st->previous == NULL))) {

		return i;

	}

	while (st->previous != NULL){

		i++;
		st = st->previous;

	}

	i++;

	return i;

}

void destroy(Stack **st){
	Stack *ph;

	while ((*st)->previous != NULL){

		ph = (*st)->previous;
		free(*st);
		*st = ph;

	}

	if ((*st)->previous == NULL){

		(*st)->data = 0;

	}

}


void Hanoi(int start, int target, int n)
{
	Stack *source = NULL;
	Stack *end = NULL;

	if (start ==1)
		source = Wieza1;
	else if (start==2)
		source = Wieza2;
	else if (start==3)
		source = Wieza3;

	
	if (target == 1)
		end = Wieza1;
	else if (target == 2)
		end = Wieza2;
	else if (target == 3)
		end = Wieza3;

	if (n == 1){

		end = push(&end, source = pop(&source));

		if (start == 1)
			Wieza1 = source;
		else if (start == 2)
			Wieza2 = source;
		else if (start == 3)
			Wieza3 = source;


		if (target == 1)
			Wieza1 = end;
		else if (target == 2)
			Wieza2 = end;
		else if (target == 3)
			Wieza3 = end;

		system("cls");

		printf("\tPierwsza Wieza:\n");
		show_stack(Wieza1);
		printf("\n\tDruga Wieza:\n");
		show_stack(Wieza2);
		printf("\n\tTrzecia Wieza:\n");
		show_stack(Wieza3);
		printf("\n\n");
	}
	else{
		int c = 6 - start - target;
		Hanoi(start, c, (n - 1));
		Hanoi(start, target, 1);
		Hanoi(c, target, (n - 1));
	}
}


int main()
{
	int start = 1;
	int target = 3;
	int n = 0;

	printf("Ile krazkow ma byc przekladanych?\n");
	scanf("%i", &n);
	Hanoi(start, target, n);
	system("pause");
	return 0;
}