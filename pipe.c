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
		perror("Requires more than 0 arguments");
		return EINVAL;
	}
	int fd[2];
	int error;
	for(int index=1;index<argc-1;index++){
		error=pipe(fd);
		if(error==-1){
			perror("Pipe failed");
			return EINVAL;
		}
		pid_t p = fork(); 
    	if(p<0){ 
     	 	perror("Fork failed "); 
      		return EINVAL;
    	} 
		if(p==0){
			close(fd[0]);
			error = dup2(fd[1],1);
			if(error==-1){
				perror("Dup2 failed");
				return EINVAL;
			}
			close(fd[1]);
			error = execlp(argv[index], argv[index], (char*)0);
			if(error==-1){
				perror("Execlp failed");
				return EINVAL;
			}
			
		}
		if(p>0){
			int child_status;
			waitpid(p,&child_status,0);
			
      		if (WEXITSTATUS(child_status)) {
        		return WEXITSTATUS(child_status);
      		}
			close(fd[1]);
			error = dup2(fd[0],0);
			if(error==-1){
				perror("Dup2 failed");
				return EINVAL;
			}
			close(fd[0]);
			
		}
	}
	error = execlp(argv[argc-1], argv[argc-1], (char*)0);
	if(error==-1){
		perror("Execlp failed");
		return EINVAL;
	}
	//execlp(argv[1], argv[1], NULL);
	return 0;
}

