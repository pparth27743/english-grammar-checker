//created by harsh kavar

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkadjective(char str[])
{
	int count=0,length=strlen(str),limit=527,indicator=0,iteration=0;
	FILE *fp;
	fp=fopen("adjective.txt","r");
	while(indicator<length)					
		{
			char ch=getc(fp);			//first we compare first letter
			fseek(fp,-1,1);
			while((count==0 || ch==str[indicator]) && iteration<limit) //untill match first letter count remaining zero then increase by one till dosen't match 
				{						//it means count calculate how many words in the dictionary witch have first letter witch we want
					if(ch==str[indicator])
						{count++;}
					fseek(fp,25,1);			//fp move to next line
					ch=getc(fp);
					fseek(fp,-1,1);
					iteration++;
				}
			if(count==0)
				break;

			else
				{
					fseek(fp,(-25*count)+1,1); //then we pick second letter and again do this process
					limit=count;
					indicator++; //when first letter found its increase by one 
					count=0;
                    iteration=0;
				}
		}
	if(getc(fp)=='1' && indicator==length) //indicater==lenth it means all letter found
						//getc(fp)=='1' it means end of word
	return 1;

	else
	return 0;
}

