#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double sum=0.0;  //���������
int is_num(char);
int is_ch(char);
int is_nor(char*,int);
void js(char,double);
int tq_num(char*,char*,double*); 

int main()
{
	char ch[41],b[41];
	double c[41];
	int t,i,s;
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
	s=tq_num(ch,b,c);
	sum=c[0];
	for(i=0;i<s-1;i++)
	{
		js(b[i],c[i+1]);
	}
	printf("%.2f",sum);
	return 0;
}	 
/*
���ܣ���ȡ�ַ����е����� 
����: �����
ʱ�䣺2019.4.6
*/
int tq_num(char ch[],char b[],double c[]) 
{
	char a[41];
	int i,s=0,j=0,t;
	t=strlen(ch);
	for(i=0;i<=t;i++)
	{
		if( is_num(ch[i])||ch[i]=='.' )
		{
			a[j]=ch[i];
			j++;
		}
		else
		{
			a[j]='\0';
			c[s]=atof(a);
			b[s]=ch[i];
			while( s!=0 && is_ch(b[s])<is_ch(b[s-1]) )
			{
				sum=c[s-1];
				js(b[s-1],c[s]);
				c[s-1]=sum;
				b[s-1]=ch[i];
				s--;
			}
			s++;
			j=0;
		}
	}
	return s;
}
/*
���ܣ��ж�һ���ַ����Ƿ�Ϸ����Ϸ����� 1�����򷵻� 0
����: �����
ʱ�䣺2019.4.2
*/	
int is_nor(char ch[],int t)
{
	int p=1;
	int i,point=0;
	for(i=0;i<t;i++)
	{
		if(is_ch(ch[i]))
		{
			break;
		}
		
	}
	if(i==t)
	{
		p=0;
	}
	for(i=0;i<t;i++)
	{
		if(!is_ch(ch[i])&&!is_num(ch[i])&&ch[i]!='.')
		{
			p=0;
			break;
		}
		if(is_ch(ch[i])&&is_ch(ch[i+1])) 
	    {
		   p=0;
	       break;
	    }
		if(ch[i]=='.')
		    point++;
		if(is_ch(ch[i])||i==t-1)
		{
		   	if(point>1)
			{
				p=0;
			    break;
			}
			point=0;
		}
		if((ch[i]=='.'&&is_ch(ch[i+1]))||(is_ch(ch[i])&&ch[i+1]=='.'))
		{
			p=0;
			break;
		}
		       
	}
	if(!is_num(ch[0])||!is_num(ch[t-1]))
	{
	    p=0;
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
ʱ�䣺2019.4.6 
ʱ�䣺2019.3.22
*/
int is_ch(char a)
{
	switch(a)
	{
		case '+':
		case '-':
		case '\0':return 1;break;
		case '*':return 2;break;
		case '/':return 3;break; 
		
		default :return 0;break;
	}
}
/*
���ܣ��Դ��ݹ�����ֵ������Ӧ�ļ��� 
����: �����
ʱ�䣺2019.3.22
*/
void js(char b,double c)
{
	switch(b)
		{
			case'+':sum+=c;break;
			case'-':sum-=c;break;
			case'*':sum*=c;break;
			case'/':sum/=c;break; 
		}
}



