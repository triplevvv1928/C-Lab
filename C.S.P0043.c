#include <stdio.h>
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
        else  
            break;   
    }
    while (1);
    return n;
} 

void output(int a[], int i) {
    printf("Output array: ");
    for (int j = 0; j < i; j++) { 
        printf("%d ", a[j]); 
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int c;
    c = *a;
   	*a = *b;
    *b = c;
}

void run(int *a, int n, int *i) {
    switch (n){
        case 1:{
		    int value;
			printf("Enter an integer number:");
		    value = checkInput();
		    fflush(stdin);
		    a = (int *) realloc(a, ((*i) + 1) * sizeof (int)); 
		    a[(*i)] = value;
		    (*i)++; 
		    output(a, *i);
            break;
        }
        case 2:{
		    int numberSearch;        
		    int check = 0;
		    printf("Enter an integer number to search: ");
		    numberSearch = checkInput();
		    fflush(stdin);
		    for (int j = 0; j < (*i); j++) {
		        if (a[j] == numberSearch) { 
		            check++;
		            printf("Number %d in array - This number at position: ", numberSearch); 
			        printf("%-5d\n", j + 1);
		        }
		    }
		    if (check == 0)
		        printf("This array no have this number\n");
            break;
        }
        case 3:{
		    int deleteNumber;
		    int check = 0; 
		    printf("Enter an integer number to delete: ");
		    deleteNumber = checkInput();
		    fflush(stdin);
		    for (int j = 0; j < (*i); j++) { 
		        if (a[j] == deleteNumber) { 
		            check++;
			        for (int k = j; k < (*i); k++) {
			            a[k]=a[k+1];
			        }
			        (*i)--; 
			        a = (int*)realloc(a,(*i)*sizeof(int));
			        break; 
		        }
		    }
		    if (check == 0)
		        printf("This array no have this number\n");
			else{
		    	output(a, (*i)); 
				printf("Done !!!\n");
			}
            break;
        }
        case 4:{
		    int deleteNumber;
		    int check = 0; 
		    printf("Enter an integer number to delete: ");
		    deleteNumber = checkInput();
		    fflush(stdin);
		    for (int j = 0; j < (*i); j++) { 
		        if (a[j] == deleteNumber) { 
		            check++;
		            for (int k = j; k < (*i); k++) { 
		            	a[k]=a[k+1];
		            }
		            (*i)--; 
		            a = (int*)realloc(a,*(i)*sizeof(int));
		            j--;
		        }
		    }
		    if(check == 0)
		        printf("This array no have this number\n");
		    else{
		    	output(a, (*i)); 
				printf("Done !!!\n");
			}
		    break;
        }
        case 5:{
            output(a, (*i));
            break;
        }
        case 6: {
		    int b[(*i)];
		    int j, k, q;
		    for (j = 0; j < (*i); j++) {
		        b[j] = a[j];
		    }
		    for (k = 0; k < (*i); k++) {
		        for (q = k+1; q < (*i); q++) {
		            if (b[k] > b[q]) {
		                swap(&b[k], &b[q]);
		            }
		        }
		    }
		    output(b, (*i));
            break;
        }
        case 7: {
		    int b[(*i)];
		    int j, k, q;
		    for (j = 0; j < (*i); j++) {
		        b[j] = a[j];
		    }
		    for (k = 0; k < (*i); k++) {
		        for (q = k + 1; q < (*i); q++) {
		            if (b[k] < b[q]) {
		                swap(&b[k], &b[q]);
		            }
		        }
		    }
		    output(b, (*i));
            break;
        }
        case 8:{ 
            exit(0);
            break;
        }
    }
}

void menu(int *a, int *i) {
    int option;
    do {
        printf("1- Add a value\n");
        printf("2- Search a value\n");
        printf("3- Remove the first existence of a value\n");
        printf("4- Remove all existences of a value\n");
        printf("5- Print out the array \n");
        printf("6- Sort the array in ascending order\n");
        printf("7- Sort the array in descending order\n");
        printf("8- Exit");
        printf("\n");
        printf("Option is : ");
        option = checkInput();
        fflush(stdin);
        printf("\n");
        run(a, option, i);
    } while (1);
}

int main() {
    int *a;
    int i = 0;
    a = (int*) malloc(i * sizeof (int)); 
    menu(a, &i);
    free(a);
    return 0;
}
