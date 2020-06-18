#include	<stdio.h>
#include	<unistd.h>

int main(int ac, char **av)
{
	FILE *fp = fopen ("n.txt","r");
	int number;
	char *buf;
	while( fscanf(fp, "%s", &buf) != EOF ){
        number = atoi(&buf) + 1;
        printf("%d ", number);
    }
    printf("\n");

	fclose(fp);
}