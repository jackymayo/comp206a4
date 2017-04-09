#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "test.h"

// Will turn into a function once testing complete.
// int main(void){
//     char string[] = "command=adsasd 2&inventory=10%2c4";
//     int item[2];
//     parsePlayerInventory(item, string);

//     printf("Mana is %d\n", item[0]);
//     printf("Gold is %d\n", item[1]);
//     return 0;
// }

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
