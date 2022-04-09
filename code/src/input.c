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

void execCmd(char** string){ // NEW BUG FOUND: wholeCMD doesnt add file piping

    char * end = ">out.txt";
    char * tempStr = *string;

    int i;
    int newStrlen = strlen(tempStr)+strlen(end);

    char* wholeCMD = (char*)malloc(sizeof(char)*(newStrlen));

    for(i = 0; i < newStrlen; i++){

        if(i < strlen(tempStr)-1){
            if(tempStr[i] != 0 || tempStr[i] != 10 ){
                printf("CHAR1: %d\n",tempStr[i]);
                wholeCMD[i] = tempStr[i];
            }
        }
        else{
            if(end[i + 1-(strlen(tempStr))] != 10 || end[i+ 1-strlen(tempStr)] != 0){
                printf("CHAR2: %d\n",end[i-strlen(tempStr)]);
                wholeCMD[i] = end[i-strlen(tempStr)];
            }

            
            
            
        }
    }

    printf("ALL: %s\n",wholeCMD);

}

void mainLoop(){

    char* name,*input;
    int running = 1;
    setup(&name);                                                               // name + setup here to avoid code being ran more than once (not needed)

    while(running){

            printName(&name);
            generateStringInput(&input);           
            if(!(validityString(&input))){running = !running;}
            execCmd(&input);
            free(input);

    }
    
    
}