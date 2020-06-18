#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

int main(int ac, char **av)
{	
	char line[256][256];
	char *program;
	char argvs1[256][256];
	char argvs2[256][256];
	
	int i = 0;
	while (fgets(line[i], 256, stdin) != NULL ){	
		if (line[i][strlen(line[i]) - 1] == '\n')
			line[i][strlen(line[i]) - 1] = '\0';
		i++;
	}

	program = strtok (line[0], " ");
	strcpy(argvs1[0], program);	
	int n = 1;
    while( (program = strtok (NULL, " ")) != NULL ){
    	strcpy(argvs1[n], program);
        n++;
    }

    char *argv1[n+1];
    int j;

  	for ( j = 0; j < n; j++){
        argv1[j] = argvs1[j];
        printf("%s\n", argv1[j]);
    }
  	argv1[n] = NULL;

    program = strtok (line[1], " ");
	strcpy(argvs2[0], program);	
	n = 1;
    while( (program = strtok (NULL, " ")) != NULL ){
    	strcpy(argvs2[n], program);
        n++;
    }

    char *argv2[n+1];
    j;

  	for ( j = 0; j < n; j++){
        argv2[j] = argvs2[j];
        printf("%s\n", argv2[j]);
    }
  	argv2[n] = NULL;

    int fd[2];
    int pid;


    if ( pipe(fd) == -1 )
        return 0;
        
    if ( (pid = fork()) == -1 )
        return 0;       

    if ( pid == 0 ){

        //   child execs av[1] and writes into pipe         
        close(fd[0]);       // child doesn't read from pipe

        if (dup2(fd[1], 1) == -1 )
            return 0; 
        close(fd[1]);       // stdout is duped, close pipe
        execvp(argv1[0], argv1);    
    }
    else {          // parent will exec last command
        close(fd[1]);   // parent doesn't write to pipe

        if ( dup2(fd[0], 0) == -1 )
            return 0; 

        close(fd[0]);   // stdin is duped, close pipe
        execvp(argv2[0], argv2 );
    }

}