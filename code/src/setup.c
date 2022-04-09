#include "../headers/INCLUDES.H"

void setName(char** user){
    char* name; 
    *user = getenv("USERPROFILE");
    char* token = strtok(*user,"\\");

    while(token != NULL){
        name = token;
        token = strtok(NULL, "\\");
        
    }

    *user = name;
}

void setup(char** user){
    setName(user);
}

void printName(char** name){
    printf("%s%s",*name,"@windows:~$ ");
    
}
