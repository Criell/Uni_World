#include	<stdio.h>
#include	<unistd.h>

int main(int ac, char **av)
{
	char name[256];
	fgets(name,256,stdin);
	int number = atoi(name);
	number++;

	FILE *fp = fopen ("nw.txt","w");
	fprintf(fp, "%i\n", number);
	fclose(fp);
}