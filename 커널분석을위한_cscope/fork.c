#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>


static void child()
{
char* args[] = {"/bin/echo","hello", NULL};
printf("I am a child my pid is %d.\n", getpid());
fflush(stdout);
execve("/bin/echo", args, NULL);
err(EXIT_FAILURE, "exec failed");

}


static void parent(pid_t a)
{

printf("I am a parent! My pid is %d and the pid of my child is %d.\n", getpid(), a);
exit(EXIT_SUCCESS);

}


int main()
{


pid_t res;
res = fork();
if(res==-1) err(EXIT_FAILURE, "fork failed");
if(res==0) child();
else
{
parent(res);

}

err(EXIT_FAILURE, "should not reach here");




}
