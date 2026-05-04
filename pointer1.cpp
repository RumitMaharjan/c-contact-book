#include<stdio.h>

int main(){
	int x = 10;
	int *p = &y;
	
	printf("Value: %d\n", y);
	printf("Address: %p\n", (void*)p);
	printf("Via pointer: %d\n", *p);
	
	*p = 99;
	
	printf("y is now: %d\n", y);
	
	return 0;
}
