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
        else if (n < 1 || n > 9) 
            printf("Invalid Number!!! Try again...\n");
        else  
            break;   
    }
    while (1);
    return n;
} 

int main(){
	int i, choice;
	char check;
	while(1){
		choice=0;
		fflush(stdin);
		printf("Please enter a number (1 - 9): ");
		choice = checkInput();
		for(i=1; i<=10; i++){
			printf("%2d x %2d = %2d\n", choice, i, choice*i);
		}
		while(1){
			printf("\nDo you want to continue (Y/N): ");
			fflush(stdin);
			scanf("%c", &check);
			if(check=='N'||check=='n'||check=='y'||check=='Y') break;
		}
		if(check=='N'||check=='n') break;
	}	
	return 0;
}
