#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    printf("Enter the element of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
    }
}

void output(int a[], int n) {
    printf("\nArray elements:\n");
    for (int i = 0; i < n; i++) { 
        printf("%d ", a[i]); 
    }
}

int maxElement(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) { 
        if (max < a[i]) 
            max = a[i]; 
    }
    return max;
}


int numberEven(int a[], int n) {
    printf("\n\nArray even value:\n");
    for (int i = 0; i < n; i++) { 
        if (a[i] % 2 == 0) { 
            printf("%-5d", a[i]); 
        }
    }
}

int main() {
    int n;
    int *a;
    printf("Enter a number off element n=");
    n = checkInput();
    a = (int *) malloc(n * sizeof (int));
    input(a, n);
    output(a, n);
    printf("\n\nArray maximum value\nThe max is %d", maxElement(a, n));
    numberEven(a, n);
    free(a);
    return 0;
}

