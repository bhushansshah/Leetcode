#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct kStack{
	int *arr;
	int k;
	int n;
	int *top;
}kStack;

void init(kStack *s, int k, int n);
void push(kStack *s, int i, int num);
int pop(kStack *s, int i);
int peek(kStack s, int i);
int isEmpty(kStack s, int i);
int isFull(kStack s, int i);
