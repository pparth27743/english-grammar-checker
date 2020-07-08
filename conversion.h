/* Author :- Yash Mehta.
   Subject :- To convert Upper Case Sentences into Lower Case.
*/
#include<stdio.h>
#include<string.h>
int convert(char str[])
{
  	int i;
/* UPPER TO LOWER CASE CONVERSION CODE */
  	for(i=0;i<=strlen(str);i++)
    {
    		if(str[i]>=65&&str[i]<=90)
       			str[i]=str[i]+32;
  	}
 	return 0;
}
