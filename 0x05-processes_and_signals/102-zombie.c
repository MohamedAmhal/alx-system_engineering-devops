#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - the infinity loop
 *
 * Return: a integer
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - the main function that create the prosseced ID zombie
 *
 * Return : always 0 (the integer function)
 */

int main(void)
{
	pid_t pid;
	char i = 0;

	while (i < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			i++;
		}
		else
			exit(1);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
