#include "../headers/INCLUDES.H"
#include "../headers/setup.h"

void generateStringInput(char** string){
    int size = 4096;                                                            // Maximum char length found in some terminals
    *string = (char*)malloc(sizeof(char)*size);
    fgets(*string,size,stdin);
    if(strlen(*string) >= size - 2){
        fprintf(stderr,"Winux only supports 4094 characters for the user.\nYou gave too many\n");
        free(*string);
        system("pause");
        exit(-1);
    }
}

int validityString(char** string){
    char* tempStr = *string;                                                    // Had to store string in temp. Dunno why this worked. 
    return (tempStr[strlen(tempStr)-1] == 10) ? 1 : -1 ;
}

void mainLoop(){

    char* name,*input;
    int running = 1;
    setup(&name);

    while(running){
            printName(&name);
            generateStringInput(&input);           
            if(!(validityString(&input))){running = !running;}
            free(input);
    }
    system("pause");
    
}