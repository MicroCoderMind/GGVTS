//Below code is to convert any string with only numbers and dot to float format
#include<stdio.h>
double convert(char *);
int num[10] = {48,49,50,51,52,53,54,55,56,57};
int main()
{
	double x;
	char floatstring[200] = {'\0'};
	scanf("%[^\n]%*c",floatstring);
	x = convert(floatstring);
	printf("%f\n",x);
}
double convert(char floatstring[200])
{
	int i,j,dotfound=0,decplace = 0,div=1;
	double floatnum=0;
	for(i=0;floatstring[i]!='\0';i++)
	{
		if (floatstring[i] == '.')
		{
			dotfound = 1;
		}
		else
		{
			for(j=0;j<10;j++)
			{
				if (floatstring[i] == num[j])
				{
					floatnum += j;
					floatnum*=10;
				}

			}
		}
		if (dotfound == 1)
		{
			decplace++;
		}
	}
	if (dotfound == 1)	
	{
		for (;decplace!=0;decplace--)
		{
			div *= 10;
		}
		floatnum/=div;
	}
	else
	{
		floatnum/=10;
	}
	return floatnum;;
}
