//created by parth kavar

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkarticel(char str[])
{
	if(strcmp(str,"a")==0|| strcmp(str,"an")==0 || strcmp(str,"the")==0)
        return 1;

	else
	return 0;
}

