#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <ctype.h>
int total(int year){
	int total = 0;
	for(int i=0; i < year;i++){
		if(((i % 4 == 0) && (i % 100 != 0) )|| (i % 400 == 0))
			total+=366;
		else
			total+=365;		
	}	
	return total;
}	
int DayOfMonth(int day, int month, int year){
	int DayOfMonth=0;
	int i;
	for(i = 1; i <month; i++){
		if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			DayOfMonth += 31;
		else if(i == 2){
			DayOfMonth += 28;
			if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				DayOfMonth += 1;
		}
		else
			DayOfMonth += 30;
	}
	return DayOfMonth;
}
int totalofDay(int day, int month, int year){
	int totalofDay = 0;
	totalofDay = total(year) +  DayOfMonth(day,month,year) + day;
	return totalofDay;
}
void DayOfWeak(int day,int month, int year){
	int DayOfWeak = 0;
	DayOfWeak = totalofDay(day,month,year)%7;
	switch (DayOfWeak){
        case 0: printf("Friday"); break;
        case 1: printf("Saturday"); break;
        case 2: printf("Sunday"); break;
    	case 3: printf("Monday"); break;
        case 4: printf("Tuesday"); break;
        case 5: printf("Wednesday"); break;
        case 6: printf("Thursday"); break;
    }         
}
int WeakOfYear(int day,int month, int year){
	int WeakOfYear=1;
	int count = 0;
	count = totalofDay(day,month,year);
	int count1 = DayOfMonth(day,month,year) + day;
	for(int i=count1-2; i>=0; i--){
		if(( count - i) % 7 == 3)
			WeakOfYear++;
	}
	return  WeakOfYear;
}

int Check(char *n){
	int i;
   	for(i = 0; i < strlen(n); i++){
		if(n[i] >= 47 && n[i] <= 57) 
			continue;
		else 
			return 0;
	}
	return 1;
}

int main(){
	char dtm[10],y[4],ch;
	int day,month,year;
	while(1){
		printf("Enter the day(dd//mm//yyyy): ");
		fflush(stdin);
		gets(dtm);
		if(Check(dtm)==0)
			printf("Enter again!");
		else if(dtm[2] == '/' && dtm[5] == '/'){
			sscanf(dtm, "%d/%d/%s", &day, &month, y);
			if(strlen(y)==4){
				year = atoi(y);
				if(day < 1 || day > 31 || month < 1 || month > 12 || year < 0){
					printf("Enter again!!\n");
				}
				else{
					printf("Day of Year: %d", DayOfMonth(day,month,year) + day);
					printf("\nDay of Weak: ");
					DayOfWeak(day,month,year);
					printf("\nWeak of Year: %d", WeakOfYear(day,month,year));
				}
			}
			else
				printf("Enter again!");		
		}
		else{
			printf("Enter again!");
		}
		printf("\nPress any key to continue, Esc to exit the program...\n");
		ch = getchar();
		if(ch == 27)
			break;		
	}
	return 0;
}
