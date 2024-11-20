#include<stdio.h>
#define size 13

void enqueue();
void dequeue();
void display_Q();

int queue[size];
int front = -1, rear = -1;

int main()
{
	int c;
	while(1)
	{
		printf("\n===================== QUEUE ====================\n");
		printf("\n 1.  ENQUEUE\n 2.  DEQUEUE\n 3.  DISPLAY\n 4.  EXIT\n");
		printf("\n............ ENTER YOUR CHOICE ........\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display_Q();
				break;
			case 4:
				return 0;
			default :
				printf("\n\033[31m............. ENTER VALID CHOICE ! .....\n\033[0m");
		}
	}
	return 0;
}


void enqueue()
{
	if((rear+1)%size == front)
	{
		printf("\n\033[31m.............. QUEUE IS FULL ..............\n\033[0m");
		return;
	}
	int x;
	printf("\n\033[32m........... ENTER THE VALUE .........dec %d dev = %f mod = %d\n\033[0m",(5/13), (5/13), (5%13) );
	scanf("%d",&x);
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else
	{
		printf("rear = %d before:\n",rear);
		rear = (rear+1)%size;
		printf("rear = %d after\n",rear);
		queue[rear] = x;
	}
}
void dequeue()	
{
	if(front == -1 && rear == -1)
	{
		printf("\n\033[31m.............. QUEUE IS EMPTY ..............\n\033[0m");
	}
	else if(front == rear)
	{
		printf("\n\033[32m............ %d IS DELETED ..........\n\033[0m",queue[front]);
		front = rear = -1;
	}
	else
	{
		printf("\n\033[32m............ %d IS DELETED ..........\n\033[0m",queue[front]);
		front = (front+1)%size;
	}
}
void display_Q()
{
	if(front == -1 && rear == -1)
	{
		printf("\n\033[31m.............. QUEUE IS EMPTY ..............\n\033[0m");
	}
	else
	{
		int i = front;
		printf("\n\032[34m==========================================================\n");
		while(i != rear)
		{
			printf("| %d ",queue[i]);
			i = (i+1)%size;
		}
			printf("| %d ",queue[rear]);
		printf("\n=============================================================\n\032[0m");
	}
}


