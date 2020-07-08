//created by harsh kavar
//same as checkadjective file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkverb(char str[])
{
	int count=0,length=strlen(str),limit=31083,indicator=0,iteration=0;
	FILE *fp;
	fp=fopen("verb.txt","r");
	while(indicator<length)
		{
			char ch=getc(fp);
			fseek(fp,-1,1);
			while((count==0 || ch==str[indicator]) && iteration<limit)
				{
					if(ch==str[indicator])
						{count++;}
					fseek(fp,25,1);
					ch=getc(fp);
					fseek(fp,-1,1);
					iteration++;
				}
			if(count==0)
				break;

			else
				{
					fseek(fp,(-25*count)+1,1);
					limit=count;
					indicator++;
					count=0;
                    iteration=0;
				}
		}
	if(getc(fp)=='1' && indicator==length)
	return 1;

	else
	return 0;
}
