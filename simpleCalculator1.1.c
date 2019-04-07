#include<stdio.h>
#include<string.h>

int is_number(char);
void normal(char*,int*);
int no_number(char);
void calculation(char,double,double*);


int main()
{
	char ch[41],b;
	int a,c,i=0,t;
	double sum=0;
	normal(ch,&t);
	for(i=0;i<t;i++)
	{
		if( is_number(ch[i]) )
		{
			a=ch[i]-48;
			sum+=a;
		}
		else
		{
			if( no_number(ch[i]) )
			{
				b=ch[i];
			}
			c=ch[i+1]-48;
			calculation(b,c,&sum);
			i++;
		}
	}
	printf("%.2f",sum);
	return 0;
} 

int is_number(char a)
{
	if(a>='0'&&a<='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int no_number(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void calculation(char b,double c,double*sum)
{
	switch(b)
		{
			case'+':*sum+=c;break;
			case'-':*sum-=c;break;
			case'*':*sum*=c;break;
			case'/':*sum/=c;break; 
		}
}



void normal(char*ch,int*t)
{
	int i,a=1;
	printf("请输入：");
	while(a)
	{
		gets(ch);
		*t=strlen(ch);
		if(ch[0]>='0'&&ch[0]<='9'&&is_number(ch[*t-1]) )
		{
			a=0;
		}
		else
		{
			printf("对不起，输入有误，请重新输入\n"); 
			a=1;
			continue;
		} 
		for(i=0;i<*t;i++)
		{
			if( no_number(ch[i])||is_number(ch[i]) )
			{
				a=0;
			}
			else
			{
				printf("对不起，输入有误，请重新输入\n"); 
				a=1;
				break;
			}
		}
	}

}














