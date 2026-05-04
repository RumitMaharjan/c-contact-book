#include<stdio.h>

void swap(int *a, int *b);

int main(){
	int a, b;
	int *n = &a;
	int *m = &b;
	
	printf("Enter the 1st number n: ");
	scanf("%d",&a);
	printf("Enter the 2nd number m: ");
	scanf("%d",&b);
	printf("-----------------------\n");
	printf("Swapped numbers: \n");
	
	swap(&a, &b);
	
	printf("n: %d\n", *n);
	printf("m: %d", *m);
	
	return 0;
}

void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
