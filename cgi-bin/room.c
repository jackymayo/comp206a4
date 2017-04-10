#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void parsePlayerInventory(int[], char[]);
void getResources(FILE *, int[]);
void setResources(FILE *, int[]);
void dropCommand(int, int[], int[]);

int detectCommand(char [], int[]. int[]);
int main(void){
    // Web data from post
    // Change room to change resources
    // Change playerItem to change player resources

    char queryString[200];
    int playerItem[2];
    int room[3];
    
    FILE *file;
    file = fopen("../resources.csv", "r");
    getResources(file, room);

    char buffer;
    int a = 0;
    int n = 50;
    // Will need this later, used this temporarily while servers are down.
    // n = atoi(getenv("CONTENT_LENGTH"));
    while((buffer = getchar()) != EOF && a < n){
        if (a < 200){
            if (buffer!='+') 
                queryString[a] = buffer;
            else  
                queryString[a]=' ';
            a++;
        }
    }
    queryString[a] = '\0';

    parsePlayerInventory(playerItem, queryString);

    
    // file = fopen("../resources.csv", "w");
    // setResources(file,room);

    printf("%s%c%c\n","ContentType:text/html;charset=UTF-8",13,10);

    char c;
    file = fopen("../template.html", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    // if success print using success css
    printf("<div class=\"result success\">");
    // printf('div class="result error"');
    printf("Mana is %d\n", playerItem[0]);
    printf("Player mana is %d", playerItem[1]);
    printf("</div>");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
};

int detectCommand(char string[], int playerItem[], int room[]){
    char *pnt;
    pnt = strstr(string, "drop");
    char buffer[20];
    int i = 0;
    if (pnt != NULL){
        pnt += 5;
        while(pnt!= ' ' or pnt!= '&'){
            buffer[i++] = *pnt;
        }
        buffer[i] = '\0';
        int n = atoi(buffer);
        dropCommand(n, playerItem,room);
    }
    return -1;
}
// n is the number of gold dropped from player
void dropCommand(int n, int playerItem[], int room[]){
    int mana = n/2;
    playerItem[1] -= n;
    playerItem[0] += mana;
    room[1] += n;
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
    fclose(file);
}
void setResources(FILE * file, int room[]){
    if (file ==  NULL) perror("Error opening file");
    else {
        fprintf(file, "%d,%d,%d", room[0], room[1], room[2]);
        fclose(file);
    }
}
