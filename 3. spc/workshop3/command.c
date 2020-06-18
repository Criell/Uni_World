#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

main(int ac, char **av)
{
	char line[256][256];
	char *program;
	char cmd[256][256];
	char argv[256];

	while( fgets(line[i], 256, stdin) != NULL ){	
		program = strtok (line[i], " ");

		strcpy(cmd[i], program);

		while( (program = strtok (NULL, " ")) != NULL ){
			strcpy(argv, program);
			printf("%s", argv);
		} 

		i++;
	}
} 
