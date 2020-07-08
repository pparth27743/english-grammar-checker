/* Program to  organize list of words in file for search. */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void main()
{
    char s[25];int i;
    FILE *fp,*lp;
    fp=fopen("conjunction.txt","r"); //file which contains unorganized list.
    lp=fopen("conjunctions.txt","w");//output file.

    if(fp==NULL)
    {
        printf("error! File Doesn't exist.");
        EXIT_FAILURE
    }

    do
    {
        fseek(fp,1,1);
        fscanf(fp,"%[^\n]",s); //scans till new line character.
            for(i=strlen(s)-1;i<24;i++)
                s[i]='1';
        s[24]='\n';
        fprintf(lp,"%s",s); //prints in file.
        fseek(lp,-2,1);
    }
    while(s[0]!='1');
    fseek(lp,-1,1);
    fprintf(lp,"\n111111111111111111111111");
    fclose(lp);
    fclose(fp);
}
