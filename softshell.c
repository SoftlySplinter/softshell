#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

main() {

	int prompt_and_parse(char ** args) {
		static char line[100];
		printf("> ");
		
		if(gets(line) == NULL) {
			return -1;
		}

		*args++ = strtok(line, " \t");
		while(*args++ = strtok(NULL, " \t")) {
			;
		}
		return 1;
	}

	/* Deprecated */
	main() {
		char old_line[100];
		while(gets(old_line != NULL)) {
			if(fork() == 0) {
				execlp(old_line);
				printf("%s: not found\n", old_line);
				exit(1);
			} else {
				wait(0);
			}
		}		
	}

	old_main()
	{
		char *args[20];
		while(prompt_and_parse(args) > 0) {
			if(fork() == 0) {
				execvp(args[0], args);
				printf("%s: not found\n", args[0]);
				exit(1);
			} else {
				wait(0);
			}
		}
		exit(0);
	}
}

