/* File: fork.c */
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
	int var; /* automatic variable on the stack */
	pid_t pid;
	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		printf("write error");
	printf("before fork\n"); /* we don¡¯t flush stdout */

	if ((pid = fork()) < 0) {
		printf("fork error");
	} else if (pid == 0) { /* child */
		while (1) {
			sleep(2);	
			globvar++; /* modify variables */
			var++;
			printf("%s[%d] pid = %ld, glob = %d, var = %d\n", __func__, __LINE__, (long)getpid(), globvar,
				var);
		}
	} else {
		sleep(2); /* parent */
	}
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
		var);
	exit(0);
}
