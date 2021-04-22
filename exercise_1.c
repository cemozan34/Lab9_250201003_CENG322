#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>



void* multi(void* arg)
{
	
	int* core = (int*)arg;
	int balance = 0; // Declared as 0 for question 3.
	

	if (*core == 0){ // Deposit 
		for(int i = 0 ; i < 1 ; i++){ // Declaration is i<1 for question 3.
		
			balance += 1000; // Declaration is +1000 for question 3.
		}
		printf("%d balance for thread 1:\n",balance);	
	}
	else{ // Withdraw
		for(int i = 0 ; i < 200 ; i++){
			if(balance > 0){ // Added this line for question 3 to prevent negative balance value.
				balance -= 5 ;
			}
			
		}
		
		
		printf("%d balance for thread 2:\n",balance);

	}
		
    pthread_exit(NULL);	
}
    

/*Solutions:  1- After thread 1 balance is equal to 26000. 
	      2- After thread 2 balance is equal to 0.
	      3- Balance is equal to 1000 after thread1 and -1000 after the thread 2. So putting an if statement for thread 2 to fix balance*/


int main(int argc, char* argv[])
{
	
	pthread_t threads[2];
 	
	for (int i = 0; i < 2; i++) {
		int* p = malloc(sizeof(int));
		*p=i;
		pthread_create(&threads[i], NULL, multi, p);
	}


	// joining all threads
	for (int i = 0; i < 2; i++)
		pthread_join(threads[i], NULL);
		
	pthread_exit(NULL);

    return 0;
}




