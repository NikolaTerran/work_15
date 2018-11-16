#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

int main(){
	printf("parent pid is: %d\n",getpid());
	int f = fork();
	if(f){
		f = fork();
	}
	if(!f){
		int random = open("dev/random",O_RDONLY);
		int i;
		read(random,&i,4);
		i = (i%25)+5;
		printf("child pid is: %d\n",getpid());
		printf("i=%d\n",i);
		printf("gonna sleep for %d seconds\n",sleep(i));
		printf("child#%d is terminated\n",getpid());
		exit(i);
	}
	int p, status;
	p = wait(&status);
	//MACRO();
	return 0;
}
