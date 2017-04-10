#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void parsePlayerInventory(int[], char[]);
void getResources(int[]);
void setResources(int[]);
void printRefresh(int[]);
void printExit();
int dropCommand(int, int[], int[]);
int exitCommand(int[], int[]);
int detectCommand(char [], int[], int[]);
int main(void){
    // Web data from post
    // Change room to change resources
    // Change playerItem to change player resources

    char queryString[200];
    int playerItem[2];
    int room[3];
    

    getResources(room);

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
    int status = detectCommand(queryString, playerItem, room);
    // file = fopen("../resources.csv", "w");
    // setResources(file,room);

    printf("%s%c%c\n","ContentType:text/html;charset=UTF-8",13,10);

    // char c;
    // file = fopen("../template.html", "r");
    // if (file) {
    //     while ((c = getc(file)) != EOF)
    //         putchar(c);
    //     fclose(file);
    // }
    
    // Errors if negative
    if (status < 0){
        // printRefresh(playerItem);
        printf("<div class=\"result error\"> <h6> Error! </h6>");
        switch (status){
            case -2:
                printf("Not enough gold to drop :o\n");
                break;
            case -3:
                printf("Enter your gold you want to drop");
                break;
            default:
                printf("Invalid command.");
        }
        printf("</div>");
    }
    else{ // Successful commmands
        switch (status){
            case 1: // Drop n   
                // printRefresh(playerItem);
                printf("<div class=\"result success\"> Success! ");
                printf("Drop n successful! You now have\n");
                printf("Mana is %d\n", playerItem[0]);
                printf("Player gold is %d", playerItem[1]);
                printf("</div>");
                break;
            case 3: // Exit
                printExit();
                break;
            case 4: //
                // printRefresh(playerItem);
            default:
                break;
        }
    }
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
};

void printRefresh(int playerItem[]){
    char c;
    FILE * file;
    file = fopen("../template.html", "r");
    if (file) {
        while ((c = getc(file)) != EOF){
            if( c== '?'){
                printf("<input type=\"hidden\" name=\"inventory\"value=\"%d,%d\">", playerItem[0], playerItem[1]);
                continue;
            }
            putchar(c);
        }
        fclose(file);
    }
}
void printExit(){
    char c;
    FILE * file;
    file = fopen("../exit.html", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}
// n is the number of gold dropped from player
int dropCommand(int n, int playerItem[], int room[]){

    // Error -2: Not enough gold return 
    if ( playerItem[1] <= 0 || playerItem[1] - n < 0){
        return -2;
    }
    int mana = n/2;

    playerItem[0] += mana;
    playerItem[1] -= n;
    room[1] += n;

    return 1;

}

int exitCommand(int playerItem[], int room[]){
    room[0] += playerItem[0];
    room[1] += playerItem[1];
    setResources(room);
    return 3;
}

int detectCommand(char string[], int playerItem[], int room[]){
    char *pnt;
    pnt = strstr(string, "drop");
    if (pnt == NULL){
        pnt = strstr(string, "exit");
        if (pnt == NULL){
            pnt = strstr(string, "play");
            if (pnt == NULL){
                pnt = strstr(string, "refresh");
                if (pnt != NULL){
                    return 4;
                }
            }
        }
        else{
            exitCommand(playerItem, room);
            return 3;
        }
    }
    else {
        char buffer[20];
        int i = 0;
        pnt = pnt + 4;
        // Increment point until it reaches the spot, then use buffer to get digit
        for (; !isdigit(*pnt) && *pnt != '&' && *pnt != '\0'; pnt++);
        while(*pnt != '&' && *pnt != '\0'){
            buffer[i++] = *pnt++;
        }
        // Error -3: if n was not entered
        if (i == 0) return -3;
        buffer[i] = '\0';
        int n = atoi(buffer);
        int ret = dropCommand(n, playerItem,room);
        // Success 1: gold dropped
        return ret;
    }
    return -1;
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
void getResources(int room[]){
    FILE *file;
    file = fopen("../resources.csv", "r");
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
void setResources(int room[]){
    FILE * file;
    file = fopen("../resources.csv", "w");
    if (file ==  NULL) perror("Error opening file");
    else {
        fprintf(file, "%d,%d,%d", room[0], room[1], room[2]);
        fclose(file);
    }
}
