#include <stdlib.h>

char string[200];
char buffer;

int a = 0;
int n = atoi(getenv("CONTENT_LENGTH"));

while((bugger = getchar()) != EOF && a < n){
    if (a < 200){
        if (buffer!='+') string[a] = buffer;
        else  //also need to check for percent and ampersand
            string[a]=' ';
    }
}
string[a] = '\0';