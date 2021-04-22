#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX 100
typedef struct string{
	char original[MAX];
	char reverse[MAX];
}structure;



void* multi(void* arg)
{
	
	char rev[MAX];
	int i,j,count=0;
	char *fileName = (char*)malloc(sizeof(char));
	fileName = (char*)arg;
	
	structure str;
	strcpy(str.original,fileName);
	
	while (fileName[count] != '\0')
	  {
	    count++;
	  }
	  j = count - 1;

	  //reversing the string by swapping
	  for (i = 0; i < count; i++)
	  {
	    rev[i] = fileName[j];
	    j--;
	  }
	  
	  strcpy(str.reverse,rev);
	
	
	printf("Thread ID: %lu\n",pthread_self());
	printf("Original string %s\n",str.original);
	printf("Reversed string %s\n",str.reverse);
	printf("\n");
	
		
    	pthread_exit(NULL);	
}
    



int main(int argc, char* argv[])
{
	
	pthread_t threads[argc-1];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	
	int i;
	for (i = 1; i < argc; i++){
		char* arguments = (char*)malloc(sizeof(argv[i])+1);
		arguments = argv[i];
		
		pthread_create(&threads[i], &attr, (void*) multi, (void*) arguments);
	}
	for (i = 1; i < argc; i++){
		
		pthread_join(threads[i], NULL);
	}
	printf("Finished\n");
	

    return 0;
}



