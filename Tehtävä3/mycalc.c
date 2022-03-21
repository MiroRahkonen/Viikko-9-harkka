#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *env_op;
    int i;

    env_op = getenv("OPERATOR");
    if(strcmp(env_op,"add") == 0){
        int sum = 0;
        for(i=1; i<argc;i++){
            sum += atoi(argv[i]);
        }
        fprintf(stdout,"%d\n",sum);
    }
    else if(strcmp(env_op,"multiply") == 0){
        int product = 1;
        for(i=1; i<argc;i++){
            product = product*atoi(argv[i]);
        }
        fprintf(stdout,"%d\n",product);
    }
    else{
        fprintf(stdout,"\n");
    }  

    return 0;
}