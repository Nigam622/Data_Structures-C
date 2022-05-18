//Program 6 Circular Queue
#include<stdio.h>
#include<stdlib.h>
int max=10;
void insert(int CQ[max],int *R,int elem,int *count)
{
if((*count)==max)
printf("queue is full");
else
{
(*count)++;
*R=((*R)+1)%max ;
CQ[*R]=elem;
}
}
void delete(int CQ[max],int *F,int *count)
{
int elem;
if((*count)==0)
printf("Queue is empty");
else
{
elem = CQ[*F];
printf("deleted element = %d",elem);
*F = ((*F)+1) % max;
(*count)--;
}
}
void display(int CQ[max],int F,int count)
{
int i;
for(i=0;i<count;i++)
{
printf("%d\t",CQ[F]);
F=(F+1)%max ;
}
}
int main()
{
      int CQ[max],ch,ele;
      int front=0;
      int count=0;
      int rear=max-1;
      while(1)
      {
      printf("\n\n1.Insert , 2.Delete , 3.Display , 4.Exit");
      printf("\nEnter the choice : ");
      scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("enter the element :");
            scanf("%d",&ele);
            insert(CQ,&rear,ele,&count);
            break;
            case 2 : delete(CQ,&front,&count);
            break;
            case 3 : display(CQ,front,count);
            break;
            default : printf("invalid input"); 
        }
      }
return 0;
}
