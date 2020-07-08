/*Project Name : Part Of Speech
Author :- Harsh Kavar , Yash Mehta, Parth Patel
File name :- main.c
*/

//Included Header Files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "check adjective.h"
#include "check adverb.h"
#include "check verb.h"
#include "check interjection.h"
#include "check conjunction.h"
#include "check articel.h"
#include "check noun.h"
#include "check pronoun.h"
#include "check preposition.h"
#include "conversion.h"
//Defines Structure.
struct word
{
	struct word *pre;
	char *str;
	struct word *next;
	char pos[15];
};

typedef struct word node;

node *head=NULL;
node *curr=NULL;
node *temp=NULL;
//submain - to check from file using search functions.
void storepos(node* curr)
{
	char* s=curr->str;
	if(checkadjective(s))
	strcpy(curr->pos,"adjective");
	if(checkadverb(s))
	strcpy(curr->pos,"adverb");
	if(checkverb(s))
	strcpy(curr->pos,"verb");
	if(checkinterjection(s))
	strcpy(curr->pos,"interjection");
	if(checkconjunction(s))
	strcpy(curr->pos,"conjunction");
	if(checknoun(s))
	strcpy(curr->pos,"noun");
	if(checkarticel(s))
	strcpy(curr->pos,"articel");
	if(checkpronoun(s))
	strcpy(curr->pos,"pronoun");
	if(checkpreposition(s))
	strcpy(curr->pos,"preposition");
}

void fixedpos(node* curr)		//checking that word is only in one file if it is then call storepos
{
char *s;
s=curr->str;
if((checkadjective(s)+checkadverb(s)+checkverb(s)+checkinterjection(s)+checkconjunction(s)+checknoun(s)+checkarticel(s)+checkpronoun(s)+checkpreposition(s))<2)
storepos(curr);
}

void checkpos(char s[])			//for showing part of speech of all words withou solving conflict 
{
	printf("\n%s =>",s);
	if(checkadjective(s))
	printf("adjective & ");
	if(checkadverb(s))
	printf("adverb & ");
	if(checkverb(s))
	printf("verb & ");
	if(checkinterjection(s))
	printf("interjection & ");
	if(checkconjunction(s))
	printf("conjunction & ");
	if(checknoun(s))
	printf("noun & ");
	if(checkarticel(s))
	printf("articel & ");
	if(checkpronoun(s))
	printf("pronoun & ");
	if(checkpreposition(s))
	printf("preposition & ");
}
//Dynamic Allocation
char* dynemicallocation()
{
	char *p=NULL;
	char word[20];
	int l;
	scanf("%s",word);
	convert(word);
	l=strlen(word);
	p=(char*)malloc((l+1)*sizeof(char));
	strcpy(p,word);
	return p;
}
//Linked List.
void makelist()
{

	head = (node*)malloc(sizeof(node));  //memory allocation to head.
	curr=head;
	curr->pre=NULL;
	curr->str=dynemicallocation(); //Calls dynamic allocation function and stores address which is returned by function.
    //while loop will run till "."/"?"/"!" is found.
	while('.'!=curr->str[strlen(curr->str)-1]&& '?'!=curr->str[strlen(curr->str)-1]&&'!'!=curr->str[strlen(curr->str)-1])
	{
		temp=(node*)malloc(sizeof(node));
		temp->pre=curr;
		curr->next=temp;
		curr=temp;
		curr->str=dynemicallocation();
	}

	curr->str[strlen(curr->str)-1]='\0'; //removes ".","?","!" from last.
	curr->next=NULL;
	}
//Main Function
void main()
{
	printf("Enter your sentence witch is end with '.' :\n");
	node* curr;
	makelist();
	curr=head;
	printf("\nprinting part of speech without solving conflict\n");
	while(curr!=NULL)
	{
	    checkpos(curr->str);
	    curr=curr->next;
	}

curr=head;
while(curr!=NULL)
	{
		fixedpos(curr);
		curr=curr->next;
	}

//if whereever article is found then check next of its next if that is noun then between them is adjective otherwise next of article is noun
curr=head;
while(curr!=NULL&&checkarticel(curr->str)!=1)
{curr=curr->next;}

if(curr!=NULL)
{	
	strcpy(curr->pos,"articel");
	if(curr->next->next!=NULL)

	{
		curr=curr->next->next;
		if(checknoun(curr->str)==1)
			{
				strcpy(curr->pos,"noun");strcpy(curr->pre->pos,"adjective");
			}
		else
			{
				strcpy(curr->pre->pos,"noun");
			}
	}
	else
	{strcpy(curr->next->pos,"noun");}
}
//if there are ing in append of any word if that is in begining of sentance and after that verb, it is noun otherwise verb 
curr=head;
while(curr!=NULL)
	{
	int length;
        length=strlen(curr->str);
          if('g'==curr->str[length-1] && 'n'==curr->str[(length-1) - 1] && 'i'==curr->str[(length-1) - 2])
    {
       if(curr->pre==NULL)
            strcpy(curr->pos,"noun");
        else
            strcpy(curr->pos,"verb");
    }
	    curr=curr->next;
	}

//most probebly there are any word in the begining and after that is verb, it is noun or pronoun
curr=head;
while(curr!=NULL&&checkverb(curr->str)!=1)
{curr=curr->next;}
if(curr!=NULL)
{	
	if(curr->pre->pre==NULL)
	{
		strcpy(curr->pre->pos,"noun");
		if(checkpronoun(curr->pre->str))
			strcpy(curr->pre->pos,"pronoun");		
	}
}

//print second output
printf("\n\nprinting part of speech after solving conflict\n\n");
curr=head;
while(curr!=NULL)       
	{
	    printf("%s => %s\n",curr->str,curr->pos);
	    curr=curr->next;
	}
}

