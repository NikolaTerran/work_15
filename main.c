#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

int main(){
	printf("parent pid is: %d\n",getpid());
	int f = fork();
	if(f){
		f = fork();
	}
	if(!f){	//address of a pointer is random enough for me
		srand(time(NULL) + getpid());
		int i = rand();
		i = abs(i)%25+5;
		printf("child pid is: %d\n",getpid());
		printf("Gonna sleep for %d seconds\n",i);
		sleep(i);
		printf("child#%d is terminated\n",getpid());
		exit(i);
	}
	int p,status;
	p = wait(&status);
	printf("child slept for %d seconds\n",WEXITSTATUS(status));
	printf("parent is terminated\n");
	//MACRO();
	return 0;
}
