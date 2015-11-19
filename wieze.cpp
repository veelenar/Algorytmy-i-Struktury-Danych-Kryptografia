#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stacks{

	int data;
	struct Stacks *previous;

}Stack;

extern Stack* Stack_init();

Stack *W_1 = NULL, *W_2 = NULL, *W_3 = NULL;

Stack* Stack_init(){
	Stack *nowy_Stack = (Stack*)calloc(1, sizeof(Stack));

	nowy_Stack->previous = NULL;
	nowy_Stack->data = 0;

	return nowy_Stack;
}

void push(Stack **st, int c){
	Stack *ph;
	Stack *pt;

	if (((*st)->data == '\0') || ((*st)->data == ' ')){

		(*st)->data = c;

	}
	else {

		ph = *st;
		pt = (Stack*)calloc(1, sizeof(Stack));
		*st = pt;
		(*st)->data = c;
		(*st)->previous = ph;

	}

}

void show_stack(Stack *st){

	if (((st->previous == NULL) && (st->data == 0))){

		printf("Stack Pusty \n");

	}
	else{

		while (st->previous != NULL){

			printf(" %i", st->data);
			st = st->previous;

		}

		printf(" %i\n", st->data);

	}

}

int pop(Stack **st){
	int c;

	if ((*st)->previous != NULL){

		Stack *ph = NULL;
		c = (*st)->data;
		ph = (*st)->previous;
		free(*st);
		*st = ph;
		return c;

	}
	else{

		c = (*st)->data;
		(*st)->data = 0;
		return c;

	}

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

void destroy(Stack *st){
	Stack *ph;

	while ((st)->previous != NULL){

		ph = (st)->previous;
		free(st);
		st = ph;

	}

	if ((st)->previous == NULL){

		(st)->data = 0;

	}

}


void Hanoi(int start, int target, int n)
{
	Stack *source = NULL;
	Stack *end = NULL;

	switch (start){
	case 1:{
		source = W_1;
		break;
	}
	case 2:{
		source = W_2;
		break;
	}
	case 3:{
		source = W_3;
		break;
	}
	}

	switch (target){
	case 1:{
		end = W_1;
		break;
	}
	case 2:{
		end = W_2;
		break;
	}
	case 3:{
		end = W_3;
		break;
	}
	}

	if (n == 1){

		push(&end, pop(&source));

		switch (start){

		case 1:{
			W_1 = source;
			break;
		}
		case 2:{
			W_2 = source;
			break;
		}
		case 3:{
			W_3 = source;
			break;
		}
		default:{
			break;
		}
		}

		switch (target){

		case 1:{
			W_1 = end;
			break;
		}
		case 2:{
			W_2 = end;
			break;
		}
		case 3:{
			W_3 = end;
			break;
		}
		default:{
			break;
		}
		}

		system("cls");

		printf("Pierwsza Wieza: ");
		show_stack(W_1);
		printf("\nDruga Wieza: ");
		show_stack(W_2);
		printf("\nTrzecia Wieza: ");
		show_stack(W_3);
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
	W_1 = Stack_init();
	W_2 = Stack_init();
	W_3 = Stack_init();

	int start = 1;
	int target = 3;
	int n = 0;

	printf("Ile krazkow ma byc przekladanych?\n");
	scanf("%i", &n);
	for (int i = n; i > 0; i--){
		push(&W_1, i);
	}

	printf("Pierwsza Wieza: ");
	show_stack(W_1);
	printf("\nDruga Wieza: ");
	show_stack(W_2);
	printf("\nTrzecia Wieza: ");
	show_stack(W_3);
	printf("\n\n");
	
	Hanoi(start, target, n);
	system("pause");
	return 0;
}