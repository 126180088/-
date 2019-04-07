#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double sum=0.0;  //存放运算结果
int is_num(char);
int is_ch(char);
int is_nor(char*,int);
void js(char,double);

int main()
{
	char ch[41],a[41],b[41];
	int t,i,z=0,j=0,s=0;
	double c[41];
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
			printf("对不起，你的输入有误，请重新输入\n");
		}
	}
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
			c[z]=atof(a);
			b[s]=ch[i];
			s++;
			z++;
			j=0;
		}
	}	
	sum+=c[0];
	for(i=0;i<s;i++)
	{
		js(b[i],c[i+1]);
	}
	printf("%.2f",sum);
	return 0;
}	 
/*
功能：判断一个字符串是否合法，合法返回 1，否则返回 0
作者: 黄芪炜
时间：2019.4.2
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
功能：判断一个字符是否为数字，合法返回 1，否则返回 0
作者: 黄芪炜 
时间：2019.3.22
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
功能：判断一个字符是否为运算符，合法返回 1，否则返回 0
作者: 黄芪炜
时间：2019.3.22
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
功能：对传递过来的值进行相应的计算 
作者: 黄芪炜
时间：2019.3.22
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



