
#include "../headers/INCLUDES.H"

std::string getName(){
    char chars [1024];
    long unsigned int buffersize;
    std::string x;
    GetUserNameA(chars, &buffersize);
    x = std::string(chars);
    
    return x + "@Windows:~$";
}