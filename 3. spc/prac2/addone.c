#include	<stdio.h>
#include	<unistd.h>

int main(int ac, char **av)
{
	int number;
	char *buf;
	char name[256];

	if (ac > 1){

		if (strcmp(av[1],"-i") == 0){
			FILE *fp = fopen (av[2],"r");
			while( fscanf(fp, "%s", &buf) != EOF )
    	    	number = atoi(&buf) + 1;
    	    fclose(fp);
		} 
		else {
			fgets(name,256,stdin);
			number = atoi(name);
			number++;
		}

		if (strcmp(av[1],"-o") == 0){
			FILE *fp = fopen (av[2],"w");
			fprintf(fp, "%i\n", number);
			fclose(fp);
		} 
		else {
			printf("%d\n",number);
		}
	}
	else{
		fgets(name,256,stdin);
		number = atoi(name);
		number++;
		printf("%d\n",number);
	}
}