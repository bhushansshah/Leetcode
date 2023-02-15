#include <stdio.h>
#include "kStack.h"

int main(){
	kStack s;
	init(&s, 3, 3);
	push(&s, 3, 1);
	push(&s, 3, 2);
	push(&s, 3, 3);
	/*printf("%d\n", isEmpty(s, 2));
	printf("%d\n", isEmpty(s, 1));
	printf("%d\n", pop(&s, 3));
	printf("%d\n", peek(s, 1)); */
	printf("%d\n", pop(&s, 3));
	printf("%d\n", pop(&s, 3));
	printf("%d\n", pop(&s, 3));
	printf("%d\n", pop(&s, 2));
	//push(&s, 0, 1);
	//push(&s, 0, 1);

	return 0;
}
