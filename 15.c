#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
struct node
{
	char word[20];
	struct node*next;
};
struct node*table[SIZE];
int hash(char word[])
{
	int sum=0,i;
	for(i=0;word[i]!='\0';i++)
	{
		sum=sum+tolower(word[i]);
	}
	return sum%SIZE;
}
void insert(char word[])
{
	int index=hash(word);
	struct node*newnode;
	newnode=malloc(sizeof(struct node));
	strcpy(newnode->word,word);
	newnode->next=table[index];
	table[index]=newnode;
}
int search(char word[])
{
	int index=hash(word);
	struct node*temp=table[index];
	while(temp!=NULL)
	{
		if(strcmp(temp->word,word)==0)
		{
			return 1;
		}
		temp=temp->next;
	
	}
	return 0;
}

	

int main()
{
	int i,n;
	char word[20],ch[20];
	printf("Enter the number of dictionary word");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",word);
		for(int j=0;word[j]!='\0';j++)
		{
			word[j]=tolower(word[j]);
		}
		insert(word);
		
	}
	printf("Enter the word to check");
	scanf("%s",ch);
	for(int j=0;ch[j]!='\0';j++)
	{
		ch[j]=tolower(ch[j]);
	}
	if(search(ch))
	{
	printf("Word is correct\n");
	}
	else
	{
	printf("Word is incorrect\n");
	}
return 0;
}
