#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>

int main(int ac, char **av)
{	
     //Read all the lines in the file and 
    //created a string with the program and cmds
	char line[256][256];
	int i = 0;

	while( fgets(line[i], 256, stdin) != NULL ){	
		if (line[i][strlen(line[i]) - 1] == '\n')
			line[i][strlen(line[i]) - 1] = '\0';
		i++;
	}

     //variables to make the pipes
    int old_fds[2];
    int new_fds[2];
    int pid;
    char *program;
    char cmd1[256];
	int j;

    //loop every line, pike and fork
	for (j = 0; j < i; j++){

 	 if (j < i-1){
            pipe(new_fds);
        }

        pid = fork();

        if ( pid == 0) {
            // child read every token of the line and
            // make strings with the program

            program = strtok (line[j], " ");
			strcpy(cmd1, program);

            //write in the pide
            if ( j > 0 ){
                if ( dup2(old_fds[0], 0) == -1 ) 
                    return 0; 
                close(old_fds[0]); // process doesn't write to pipe
                close(old_fds[1]); // stdin is duped, close pipe
            }   

            //read from the pide
            if ( j < i-1 ){
                close(new_fds[0]);  // process doesn't read from pipe
                fflush(stdout);
                if (dup2(new_fds[1], 1) == -1 )
                    return 0;  
                close(new_fds[1]);  // stdout is duped, close pipe
            }             
            
            //execute the program
            execl(cmd1, cmd1, (char*) NULL); 
        }
        else{
            // close unused file descriptors and flush standard out
            if ( j > 0 ){
                close(old_fds[0]);
                fflush(stdout);
                close(old_fds[1]);
            }

            //make the new pipe the old one to keep the loop
            if ( j < i-1 ){
                old_fds[0] = new_fds[0];
                old_fds[1] = new_fds[1];
            }

            //wait for the process to finished
            waitpid(pid, NULL, 0);
        }
    }

    // close the last unused file descriptors and flush standard out
    close(old_fds[0]);
    fflush(stdout);
    close(old_fds[1]);
	
}