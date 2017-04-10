#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void parsePlayerInventory(int[], char[]);
void getResources(FILE *, int[]);
int main(void){
    char string[200];
    int room[3];
    char buffer;
    FILE *file;
    file = fopen("../resources.csv", "r");
    
    int a = 0;
    int n = 50;
    // n = atoi(getenv("CONTENT_LENGTH"));
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
    getResources(file, room);

    printf("%s%c%c\n","ContentType:text/html;charset=UTF-8",13,10);
    printf("Mana is %d", playerItem[0]);
    printf("Player mana is %d", playerItem[1]);

    return 0;
};
void setResources(File *file, int room[]){
    if (file ==  NULL) perror("Error opening file");
    else {
        for(int i = 0; i < )
    }
}
void getResources(FILE * file, int room[]){
    char *value;
    char buffer[100];
    const char delim[2] = ",";
    int i = 0;
    if (file ==  NULL) perror("Error opening file");
    else {
        // Parse the line of CSV
        if( fgets(buffer, 100 ,file) != NULL){
            value = strtok(buffer,delim);
            while ( value != NULL && i < 3){
                room[i++] = atoi(value);
                value = strtok(NULL,delim);
            }
        }
    }
}
void parsePlayerInventory(int item[], char string[]){
    char *point;
    // Get the location of inventory and skip to numbers
    point = strstr(string, "inventory="); 
    point = point + strlen("inventory=");

    // Parse mana
    char buffer[100];
    int j = 0;
    for(; *point != '%'; ++j){
        buffer[j] = *point;
        point++;
    }
    buffer[j] = '\0';
    item[0] = atoi(buffer);

    // Skip past %2c
    point = point + 3;
    
    // Parse gold
    j = 0;
    for(; *point != '\0' && *point !='&'; j++){
        buffer[j] = *point;
        point++;
    }
    buffer[j] = '\0';
    item[1] = atoi(buffer);
}