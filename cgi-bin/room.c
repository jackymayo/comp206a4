#include <stdlib.h>
#include <stdio.h>

int main(void){
    char string[200];
    char buffer;

    int a = 0;
    int n;
    n = atoi(getenv("CONTENT_LENGTH"));
    // fgets(string,n,stdin);
    // while((buffer = getchar()) != EOF && a < n){
    //     if (a < 200){
    //         if (buffer!='+') 
    //             string[a] = buffer;
    //         else  //also need to check for percent and ampersand
    //             string[a]=' ';
    //         a++;
    //     }
    // }
    // string[a] = '\0';

    printf("%s%c%c\n","ContentType:text/html;charset=iso-8859-1",13,10);
    printf("%s", string);

    return 0;
};