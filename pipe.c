#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	// TODO: it's all yours
	if (argv[1]==NULL){
		perror("Requires more than 0 arguments /n");
		return 1;
	}
	execlp(argv[1], argv[1], NULL);
	return 0;
}
