#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]){
    char **env_var = envp;
    char *current_var;
    int i;

    for(i=1; i<argc; i++){
        fprintf(stdout,"%s\n",argv[i]);
    }

    for(; *env_var != 0; env_var++){
        current_var = *env_var;
        fprintf(stdout,"%s\n",current_var);
    }


    return 0;
}