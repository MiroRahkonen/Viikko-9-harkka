#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

typedef struct lines
{
	char string[MAXLEN];
	struct lines * prev;
	struct lines * next;
}LINES;

LINES *read_lines(LINES * line, FILE * stream){
	char tmp[MAXLEN];
	LINES *newNode,*line_ptr;

	while (fgets(tmp, MAXLEN, stream) != NULL) {
		if(tmp[0] == '\n'){
			break;
		}
		 if((newNode = (LINES*) malloc(sizeof(LINES))) == NULL) {
			fprintf(stderr, "ERROR: could not allocate memory\n");
			exit(1);
		}
		strcpy(newNode->string,tmp);
		if(line == NULL){			
			line = newNode;		
			line->prev = NULL;	
			line->next = NULL;
		}
		else{
			line_ptr = line;
			while(line_ptr->next != NULL){
				line_ptr = line_ptr->next;
			}
			newNode->prev = line_ptr;
			newNode->next = NULL;
			line_ptr->next = newNode;
		}	
	}
	return line;
}

void print_lines(struct lines * line, FILE * stream)
{
	struct lines * lp;
		
	lp = line;
	while(lp->next != NULL){		/*Here we go to the end of the list*/
		lp = lp->next;
	}
	while(lp->prev != NULL){	
		fprintf(stdout,"%s",lp->string);	/*Printing the list while going backwards*/
		lp = lp->prev;
	}
	fprintf(stdout,"%s",lp->string);		/*printing the last one remaining*/
	return;

}

void delete_lines(struct lines * line)
{
	LINES * lp;
	
	lp = line;
	while (lp != NULL) {
		line = lp->next;
		free(lp);
		lp = line;
	}
}

int main(void)
{
	LINES * line = NULL;
	
	line = read_lines(line, stdin);
	print_lines(line, stdout);
	delete_lines(line);
	
	return 0;
}
