#include "kStack.h"

void init(kStack *s, int k, int n){
	s->k = k;
	s->arr = malloc(sizeof(int) * k * n);
	s->top = malloc(sizeof(int) * k);
	s->top[0] = -1;
	s->n = n;
	for(int i = 1; i < k; i++){
		s->top[i] = n + s->top[i - 1];
	}
}
void push(kStack *s, int i, int num){
	if(i < 1 || i > s->k)
		return;
	if(s->top[i - 1] >= i * s->n - 1)
		return;
	s->top[i - 1] += 1;
	s->arr[s->top[i - 1]] = num;
}
int pop(kStack *s, int i){
	if(i < 1 || i > s->k)
		return INT_MIN;
	if(s->top[i - 1] < (i - 1) * s->n)
		return INT_MIN;
	int result = s->arr[s->top[i - 1]];
	s->top[i - 1]--;
	return result;
}
int peek(kStack s, int i){
	if(i < 1 || i > s.k)
		return INT_MIN;
	if(s.top[i - 1] < (i - 1) * s.n)
		return INT_MIN;
	return s.arr[s.top[i - 1]];
}
int isEmpty(kStack s, int i){
	if(i < 1 || i > s.k)
		return INT_MIN;
	return s.top[i - 1] < (i - 1) * s.n;
}
int isFull(kStack s, int i){
	if(i < 1 || i > s.k)
		return INT_MIN;
	return s.top[i - 1] >= i * s.n - 1;
}
