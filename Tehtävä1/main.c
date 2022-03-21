#include "functions.h"
#include "main.h"

int main(int argc, char *argv[]){
    int n1, n2, result;
    
    if(argc == 3){
        n1 = atoi(argv[1]);
        n2 = atoi(argv[2]);
        result = calculation(n1,n2);
        fprintf(stdout,"Result: %d\n",result);
    }
    else{
        fprintf(stdout,"usage: ./calculate <number 1> <number 2>\n");
    }
    return 0;
}