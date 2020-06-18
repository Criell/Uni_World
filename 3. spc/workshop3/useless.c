#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

main(int ac, char **av)
{
if ( pipe(fd) == -1 )
	 	return 0;

	 	fgets(line, 256, stdin);
		program = strtok (line, " ");
		strcpy(cmd2, program);
		cmd2[strlen(cmd2) - 1] = '\0';
		command2 = cmd2;
		//printf("%s\n", command2);

		fgets(line, 256, stdin);
		program = strtok (line, " ");
		strcpy(cmd1, program);
		command1 = cmd1;
		//printf("%s\n", command1);

		if ( (pid = fork()) == -1 )
			return 0; 		
	   
	    if ( pid > 0 ){			/* parent will exec av[2]	*/
			close(fd[1]);	/* parent doesn't write to pipe	*/

			if ( dup2(fd[0], 0) == -1 )
				return 0; 

			close(fd[0]);	/* stdin is duped, close pipe	*/
			//execl("/bin/wc", "/bin/wc", (char*) NULL);
			execl(command1, command1, (char*) NULL);
			exit(0);
		}

		/*	 child execs av[1] and writes into pipe			*/

		close(fd[0]);		/* child doesn't read from pipe	*/

		if ( dup2(fd[1], 1) == -1 )
			return 0; 

		char* args[2];
		args[0] = command2;
		args[1] = NULL;
		execvp(command2, args);

		//execl("/bin/ls", "/bin/ls", (char*) NULL);
		close(fd[1]);		/* stdout is duped, close pipe	*/
		
		
		exit(1);
	//}
} 
