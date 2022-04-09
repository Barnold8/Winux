#include "../headers/INCLUDES.H"
#include "../headers/setup.h"


void mainLoop(){
    int running = 1;
    char* name,*input,*pcName;
    setup(&name,&pcName);

    while(running){
            
            setInput(&input,&name);
            running = !running;
    }

}