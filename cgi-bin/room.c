#include <stdlib.h>
#include <stdio.h>
#include "test.h"

int main(void){
    char string[200];
    char buffer;
    FILE *file;
    int a = 0;
    int n;
    n = atoi(getenv("CONTENT_LENGTH"));
    
    while((buffer = getchar()) != EOF && a < n){
        if (a < 200){
            if (buffer!='+') 
                string[a] = buffer;
            else  
                string[a]=' ';
            a++;
        }
    }
    string[a] = '\0';
    int playerItem[2];
    parsePlayerInventory(playerItem, string);
     
    printf("%s%c%c\n","ContentType:text/html;charset=UTF-8",13,10);
    printf("Mana is %d", playerItem[0]);
    printf("Player mana is %d", playerItem[1]);

    return 0;
};