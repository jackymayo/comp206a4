include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <ctype.h>
	#include <string.h>
int isNumber (char *);
int isQuit	(char *);
int main (void){
	srand(time(NULL));
	int randomNum = rand() % 10 + 1;
	int guess = 0;
	int counter = 0;
	int limit = 3;
	char buffer [10];
	char quit [4] = "quit";
	

	printf("Guess a number between 0 and 10 in 3 tries. \n");
	printf("%d \n", randomNum);
	while (1){
		scanf("%s", buffer);
		if (isQuit(buffer)){
			printf("Thanks for playing. \n");
			exit(1);
		}
		if (! isNumber(buffer)){
			printf("Please enter a number. \n");
		}
		else{
			guess = atoi(buffer);
			counter ++; 
			if (guess == randomNum){
			if (counter == 1 ){
				printf("Buddy, you guessed it on the first try! \n");	
			}
			else{
				printf("Buddy, you guessed it! You did it in %d tries.\n", counter);
			}
			exit(1);
			}
			if (counter == limit && guess != randomNum){
			printf("You used up all your trials. The number was %d \n", randomNum);
			return 0;
			exit(1);
			}
			if (guess > randomNum){
			printf("Your number is too high, enter a new number. You have %d trials left. \n", limit - counter);
			}
			if (guess < randomNum){
			printf("Your number is too low, enter a new number. You have %d trials left. \n", limit - counter);
			}
		}
	}
}
	

int isNumber (char * buff){
	int length = strlen (buff);
	int i;
	for (i = 0; i<length; i++){
		if (!isdigit(buff[i])){
			return 0;
		}
	}
	return 1;
}
int isQuit (char * buff){
	int length = strlen (buff);
	int i;
	for (i = 0; i< length; i++){
		buff[i] = tolower(buff[i]);
	}
	if (strncmp(buff,"quit",4) == 0){
		return 1;
	}
	return 0;
}



