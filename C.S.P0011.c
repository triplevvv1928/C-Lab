#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int inBinCheck(char *n){
	fflush(stdin);
	gets(n);
	int i;
   	for(i = 0; i < strlen(n); i++){
		if(n[i] == 48 || n[i] == 49) continue;
		else 
			return 0;
	}
	return 1;
}

int bin2dec(char *n){
    int dec = 0;
   	int i, j;
    int length = strlen(n) - 1;
   	for(i = 0, j = length;i < strlen(n); i++, j--){
   		int temp = n[j] - 48;
   		dec += temp * pow(2,i);
	}
    return dec;
}

int inOctCheck(char *n){
	fflush(stdin);
	gets(n);
	int i;
   	for(i = 0; i < strlen(n); i++){
		if(n[i] >= 48 && n[i] <= 55) continue;
		else return 0;
	}
	return 1;
}

int oct2dec(char *n){
	int dec = 0;
    int arrCount = strlen(n) - 1;
   	int i, j;
   	for(i = 0, j = arrCount;i < strlen(n); i++, j--){
   		int temp;
		temp = n[j] - 48;		
   		dec += temp * pow(8,i);
	}
    return dec;
}

int inHexCheck(char *n){
	fflush(stdin);
	gets(n);
	int i;
	for(i = 0; i < strlen(n); i++){
		if(n[i] >= 48 && n[i] <= 57) continue;
		else if(n[i] >= 65 && n[i] <= 70) continue;
		else if(n[i] >= 97 && n[i] <= 102) continue;
		else return 0;
	}
	return 1;
}

int hex2dec(char *n){
    int dec = 0;
    int arrCount = strlen(n) - 1;
   	int i, j;
   	for(i = 0, j = arrCount;i < strlen(n); i++, j--){
   		int temp;
		if(isdigit(n[j]))
			temp = n[j] - 48;
		else if(isupper(n[j]))
			temp = n[j] - 55;
		else if(islower(n[j]))
			temp = n[j] - 87;
		
   		dec += temp * pow(16,i);
	}
    return dec;
}

int main(){
	char *n,ch;
	n=(char * ) malloc(50*sizeof(char));
	int loop = 1;
	int choice;
	while(loop){
		printf("1. Convert binary number to decimal number\n2. Convert octal number to decimal number\n3. Convert hexadecimal number to decimal number\n4. Exit\n");
		printf("Please choose number (1 - 4): ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printf("Enter binary number: ");
				while(inBinCheck(n)==0) 
					printf("\nPlease input correct form of binary!\nTry again: ");
				printf("Decimal number is: %d\n", bin2dec(n));
				break;
			case 2:
				printf("Enter octal number: ");
				while(inOctCheck(n)==0) 
					printf("\nPlease input correct form of octal!\nTry again: ");
				printf("Decimal number is: %d\n", oct2dec(n));
				break;
			case 3:
				printf("Enter hexadecimal number: ");
				while(inHexCheck(n)==0) 
					printf("\nPlease input correct form of hexadecimal!\nTry again: ");
				printf("Decimal number is: %d\n", hex2dec(n));
				break;
			case 4: 
				loop = 0;
				break;
		}
		printf("\nPress any key to continue, Esc to exit the program\n");
		ch = getchar();
		if(ch == 27)
			loop = 0;
	}
	free(n);
	return 0;
}

