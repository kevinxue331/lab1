#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	// TODO: it's all yours
	if (argv[1]==NULL){
		perror("Requires more than 0 arguments /n");
		return EINVAL;
	}
	int fd[2];
	for(int index=1;i<argc-1;index++){
		int error=pipe(fd);
		if(error==-1){
			perror("Pipe failed /n");
			return EINVAL;
		}
		pid_t p = fork(); 
    	if(p<0){ 
     	 	perror("Fork failed /n"); 
      		return EINVAL;
    	} 
		if(p==0){
			close(fd[0]);
			error = dup2(fd[1],1);
			if(error==-1){
				perror("Dup2 failed /n");
				return EINVAL;
			}
			close(fd[1]);
			error = execlp(argv[index], argv[index], NULL);
			if(error==-1){
				perror("Execlp failed /n");
				return EINVAL;
			}
			
		}
		if(p>0){
			
			close(fd[1]);
			error = dup2(fd[1],1);
			if(error==-1){
				perror("Dup2 failed /n");
				return EINVAL;
			}
			close(fd[0]);
			error = wait(NULL);
			if(error==-1){
				perror("Wait failed /n");
				return EINVAL;
			}
		}
	}
	//execlp(argv[1], argv[1], NULL);
	return 0;
}
