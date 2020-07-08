#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void main()
{
char s[50];int i;
FILE *fp,*lp;
fp=fopen("noun1.txt","r");
lp=fopen("noun.txt","w");

do
{	
	fseek(fp,0,1);
	fgets(s,40,fp);
	for(i=strlen(s)-2;i<50;i++)s[i]='1';
	fputs(s,lp);
	fseek(lp,-4,1);
	fputc('\n',lp);
}while(s[0]!='1');

fseek(lp,-1,1);
fprintf(lp,"\n11111111111111111111111111111111111111111111111111");
fclose(lp);
fclose(fp);
}
