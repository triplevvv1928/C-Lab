#include <stdio.h>
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

void input(int a[], int n) {
    printf("Input elements:\n");
    for (int i = 0; i < n; i++) { 
        printf("\tElement %d=", i + 1); 
        scanf("%d", &a[i]);
    }
}

void sumEven(int a[], int n) {
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) { 
            sum += a[i]; 
        }
    }
    printf("Sum of Even =%d", sum);
}

void sumOdd(int a[], int n) {
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {  
            sum += a[i];  
        }
    }
    printf("\nSum of Odd =%d", sum);
    printf("\n");
}


int main() {    
    int *a, n;
    printf("Sum Even Odd program");
    printf("\nEnter a number off element n=");
    n = checkInput();
   	a = (int *) malloc(n * sizeof (int));
    input(a, n);
    sumEven(a, n);
    sumOdd(a, n);
    free(a);
    return 0;
}
