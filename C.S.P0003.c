#include<stdio.h>
#include <stdlib.h>

int checkInput() {
	int n;  
    char term;  
    do {
        fflush(stdin); 
        char check = scanf("%d%c", &n, &term); 
        if( check != 2 || term != '\n') 
            printf("Enter again...Only accept number!!!\n");
        else if (n < 1 || n > 10) 
            printf("Invalid Number!!! Try again...\n");
        else  
            break;   
    }
    while (1);
    return n;
} 

void input(int n, int a[]){
	for(int i=0; i<n;i++){
		printf("Enter element[%d]: ", i);
		scanf("%d",&a[i]);
	}
}

void swap(int *a, int *b){
	int temp;
	temp=*a; *a=*b; *b=temp; 
}

void sort(int n, int a[]){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++){
			if(a[j]<a[i]) 
			swap(&a[i],&a[j]) ;
		}		
}

void output(int n, int a[]){
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
}

void add(int n, int *a){
	int number;
	printf("\nPlese enter new value: ");
	scanf("%d",&number);
	a = (int *) realloc(a, (n + 1) * sizeof (int));
    a[n] = number;
    n++;
    for(int i=n-1; i>0; i--){
    	if(a[i]<a[i-1]){
    		swap(&a[i], &a[i-1]);
		}
		else 
			break;
	}
	printf("The new array:\n");
    output(n,a);
}
int main() {
    int n;
    int *a;
	printf("Please enter size of array:");
	n = checkInput();
    a = (int *) malloc(n * sizeof (int));
    input(n,a);
    sort(n, a);
    printf("The array after sorting:\n");
    output(n,a);
    add(n, a);
    free(a);
    return 0;
} 

