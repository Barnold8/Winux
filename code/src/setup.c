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

void setPCName(){

}

void setup(char** user,char**PCNAME){
    setName(user);

}

void setInput(char** input,char** name){
    // printf("%s%s",*name);
    // system("pause");

}
