#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double sum=0.0;  //���������
int is_num(char);
int is_ch(char);
int is_nor(char*,int);
void js(char,int);

int main()
{
	char ch[41],a[41],b[41];
	int t,i,z=0,j=0,s=0,c[41];
	while(1)
	{
		gets(ch);
		t=strlen(ch);
		if( is_nor(ch,t) )
		{
			break;
		}
		else
		{
			printf("�Բ������������������������\n");
		}
	}
	for(i=0;i<=t;i++)
	{
		if( is_num(ch[i]) )
		{
			a[j]=ch[i];
			j++;
		}
		else
		{
			c[z]=atoi(a);
			b[s]=ch[i];
			for(;j>0;j--)
			{
				a[j]=0;
			}
			s++;
			z++;
		}
	}	
	sum+=c[0];
	for(i=0;i<z+1;i++)
	{
		js(b[i],c[i+1]);
	}
	printf("%.2f",sum);
	return 0;
}	 
/*
���ܣ��ж�һ���ַ����Ƿ�Ϸ����Ϸ����� 1�����򷵻� 0
����: �����
ʱ�䣺2019.3.22
*/	
int is_nor(char ch[],int t)
{
	int p=0;
	int i;
	if( is_num(ch[0])&&is_num(ch[t-1]) ) 
	{
		for(i=0;i<t;i++)
		{
			if( is_num(ch[i]) )
			{
				p=1;
			}
			else
			{
				if( is_ch(ch[i])&&!is_ch(ch[i+1]) )
				{
					p=1;
				}
				else
				{
					p=0;
					break;
				}
			}
		}
	}
	return p;
}
/*
���ܣ��ж�һ���ַ��Ƿ�Ϊ���֣��Ϸ����� 1�����򷵻� 0
����: ����� 
ʱ�䣺2019.3.22
*/
int is_num(char a)
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
/*
���ܣ��ж�һ���ַ��Ƿ�Ϊ��������Ϸ����� 1�����򷵻� 0
����: �����
ʱ�䣺2019.3.22
*/
int is_ch(char a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
���ܣ��Դ��ݹ�����ֵ������Ӧ�ļ��� 
����: �����
ʱ�䣺2019.3.22
*/
void js(char b,int c)
{
	switch(b)
		{
			case'+':sum+=c;break;
			case'-':sum-=c;break;
			case'*':sum*=c;break;
			case'/':sum/=c;break; 
		}
}



