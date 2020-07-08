//created by harsh kavar

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct child
{
char ch;
struct child* right;
struct child* down;
};

typedef struct child child;

void main()
{
child* head = (child*)malloc(sizeof(child));
child* curr=head;
curr->right=NULL;
curr->down=NULL;
curr->ch='\0';

FILE* fp;
fp=fopen("null.txt","r");
char c=fgetc(fp);
curr->ch=c;
int l=0;
while(c!='1')
	{
		for(;curr->right!=NULL&curr->ch!=c;curr=curr->right);
		if(curr->ch==c)
			{c=getc(fp);
			if(curr->down!=NULL)
			curr=curr->down;
			else{while(curr->down==NULL&c!='\n')
				{
				l++;curr->down=(child*)malloc(sizeof(child));
				curr=curr->down;
				curr->right=NULL;
				curr->down=NULL;
				curr->ch=c;
				c=getc(fp);
				}}
			if(c=='\n')curr=head;
			}
		else
			{
			curr->right=(child*)malloc(sizeof(child));
			curr=curr->right;
			curr->ch=c;
			curr->right=NULL;
			curr->down=NULL;
			c=getc(fp);
			while(c!='\n')
				{
				curr->down=(child*)malloc(sizeof(child));
				curr=curr->down;
				curr->right=NULL;
				curr->ch=c;
				c=getc(fp);
				curr->down=NULL;
				}
			if(c=='\n')curr=head;
			}
		if(c=='\n')c=getc(fp);
	}
printf("%d",l);
curr=head;
while(curr->down!=NULL)
{printf("%c",curr->ch);curr=curr->down;}
curr=head;
char s[25];
printf("Enter:");
scanf("%[^\n]",s);
int j=0;
curr=head;
while(curr!=NULL)
	{
		for(;curr->ch!=s[j] & curr->right!=NULL;curr=curr->right);
		if(curr->ch==s[j])
			{curr=curr->down;j++;}
		else
			{break;}
	}
printf("%d %d",j,(curr->down==NULL));
if((curr->down==NULL)&strlen(s)-1==j)
{printf("yes");}
else
{printf("no");}

}
