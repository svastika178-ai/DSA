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
int oneEdit(char a[],char b[])

{
	int m=strlen(a),n=strlen(b);
	int i=0,j=0,count=0;
	if(abs(m-n)>1)
	return 0;
	while(i<m&&j<n)
	{
		if(a[i]==b[j])
		{
			i++;
			j++;
		}
		else
		{
			count++;
			if(count>1)
			return 0;
			else
			{
				if(m>n)
				i++;
				else if(n>m)
				j++;
				else
				{
					i++;
					j++;
				}
			}
		}
	}
	if(i<m||j<n)
	count++;
	return 1;			
}
void suggest(char ch[])
{
	struct node *temp;
	printf("Suggestions\n");
	int i;
	for(i=0;i<SIZE;i++)
	{
		temp=table[i];
		while(temp!=NULL)
		{
			if (oneEdit(temp->word,ch)){
			printf("%s\n",temp->word);
			}
			temp=temp->next;
		}
	}
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
	suggest(ch);
	}
return 0;
}
