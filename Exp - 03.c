#include<stdio.h>
#include<string.h>

int main()
{
	char s[100];
	int i,flag;
	int l;
	printf("Enter a String to Check : ");
	scanf("%s",s);
	l=strlen(s);
	flag=1;
	for(i=0;i<l;i++)
	{
		if(s[i]!='0' && s[i]!='1')
		{
			flag=0;
		}
	}
	if(flag!=1)
	printf("String is Not Valid\n");
	if(flag==1)
	{
		if (s[0]=='0'&&s[l-1]=='1')
			printf("String is Accepted\n");
		else
			printf("String is Not Accepted\n");
	}
}