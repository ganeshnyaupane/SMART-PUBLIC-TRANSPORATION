#include<stdio.h>
struct stop
{
	int input;
	int passtop[100];
}s[100];
int maxcount,count=0,laststop;
void main()
{
	int pstop=0,ch,i;
	for(i=0;i<100;i++)
	s[i].input=0;
	printf("Welcome to SMART PUBLIC TRANSPORTATION\n");
	printf("--------------------------------------------\n");
	printf("Enter destination id for your service:");
	scanf("%d",&laststop); 
	printf("Capacity of bus:");
	scanf("%d",&maxcount);
	while(pstop!=laststop)
	{
		printf("Enter Current stop:");
		scanf("%d",&pstop);
		if(count<=maxcount)
		{
			printf("1.pass  2.ticket: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1 : buspass(pstop);
							break;
				case 2 : ticket(pstop);
						break;
				default : printf("enter again\n");
					break;
			}
		}		
	}
}
int buspass(int pstop)
{s[pstop].input=s[pstop].input+1;
	int j=s[pstop].input;
	int output=0,i;
	printf("Enter the stop of passenger:");
	scanf("%d",&s[pstop].passtop[j]);
	if(s[pstop].passtop[j]>pstop&& s[pstop].passtop[j]<=laststop)
	{
		
	count++;
	if(s[pstop].input==1)
	{
	for( i=0;i<pstop;i++)
	{
		for(j=1;j<=s[i].input;j++)
		{
			if(s[i].passtop[j]==pstop)
			{ 
				
				output++;
			}
		}
	}
	count=count-output;
    }
	printf("%d seats are available\n",maxcount-count);
}	else
	printf("Invalid stop\n");
}

int ticket(int pstop)
{s[pstop].input=s[pstop].input+1;
	int j=s[pstop].input;
	int output=0,i;
	printf("Enter the stop of passenger:");
	scanf("%d",&s[pstop].passtop[j]);
	if(s[pstop].passtop[j]>pstop && s[pstop].passtop[j]<=laststop)
	{
	
	count++;
	if(s[pstop].input==1)
	{
	for( i=0;i<pstop;i++)
	{
		for(j=1;j<=s[i].input;j++)
		{
			if(s[i].passtop[j]==pstop)
			{ 
				
				output++;
			}
		}
	}
	count=count-output;
    }
	printf("%d seats are available\n",maxcount-count);
	printf("Thank you\n");
}
	else
	printf("Invalid stop");
}
