#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int prompt_and_parse(char **args) {
	static char line[100];
	printf("$ ");
	if(gets(line) == NULL)
		return -1;

	if(strstr(line, "exit"))
		return -1;

	*args++ = strtok(line, " \t");
	while(*args++ = strtok(NULL, " \t"))
		;
	return 1;
}

int main(int argc, char** argv) {
	signal(SIGINT, SIG_IGN);
	char* args[20];
	while(prompt_and_parse(args)>0) {
		if(fork() == 0) {
			execvp(args[0], args);
			printf("%s: not found\n",args[0]);
			return 1;
		} else {
			wait(0);
		}
	}

	printf("Goodbye and thanks for all the fish\n");
	exit(0);
}
