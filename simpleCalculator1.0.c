#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch[41],b;
	int a,c,i=0,t;
	double sum=0;
	printf("«Î ‰»Î£∫");
	gets(ch);
	t=strlen(ch);
	for(i=0;i<t;i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')
		{
			a=ch[i]-48;
			sum+=a;
		}
		else
		{	
			b=ch[i];
			c=ch[i+1]-48;
			switch(b)
			{
				case'+':sum+=c;break;
				case'-':sum-=c;break;
				case'*':sum*=c;break;
				case'/':sum/=c;break; 
			}
		}
		i++;
	}
	printf("%.2f",sum);
	return 0;
} 
