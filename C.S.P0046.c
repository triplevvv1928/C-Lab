#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int checkInput(int min, int max) {
    int number, check;
    char term;
    do {
        fflush(stdin);
        check = scanf("%d%c", &number, &term);
        if ((check == 2) && (term == '\n')) {
            if ((number >= min) && (number <= max))
                return number; 
            else
                printf("Out of range, please try again: "); 
        } else
            printf("Invalid, please try again: "); 
        }while(1);
    return number;
}

int checkPrime(int n){
	if(n<2) 
		return 0;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)	
			return 0;
	}
	return 1;
}

void displayPrime() {
	int num,i=2,count=0;
	printf("Number of primes:");
	num = checkInput(1,50);
	while(1){
		if(checkPrime(i)) {
			printf("%4d",i);
			count++;
			if(count==num) 
				break;
		}
		i++;
	}
	printf("\n");
}

int Fibonacci(int n)
{
    if (n <= 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void checkFibonacci() {
int n, check=0;
	int i;
	printf("Number tested: ");
	n = checkInput(1,1000);
	for(i=0;i<=n;i++){
    	if (Fibonacci(i) == n){
			check++;
			printf("It's a Fibonacci term.\n");
		}
	}
	if(check!=1)
		printf("It's is not a Fibonacci term.\n");
}

void sumOfDigit() {
    int sum = 0; 
    printf("Enter an integer:");
    int number = checkInput(INT_MIN, INT_MAX);
	if(number<0){
		number *=-1;
	} 
    while (number > 0) {
        sum += number % 10;    
        number = number / 10; 
    }
    printf("Sum of it's digits:%d", sum);
    printf("\n\n");
}

int main() {
    do {

        printf("1-The first primes");
        printf("\n2-Fibonacci element");
        printf("\n3-Sum of digits");
        printf("\n4-Exit");
        printf("\nChoose an option:");
        int option = checkInput(1, 4);
        if (option == 1) 
            displayPrime();
        if (option == 2) 
            checkFibonacci();
        if (option == 3)  
            sumOfDigit();
        if (option == 4)
        	exit(0);
    } while (1);
    return 0;
}
