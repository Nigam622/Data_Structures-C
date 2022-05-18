//Program 3 - STACKS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int max=5;
void push(int s[4],int ele,int *top)
{
int max;
if((*top)<max-1)
{
(*top)++;
s[*top]=ele;
}
else
printf("overflow condition");
}
void pop(int s[4],int *top)
{
int max;
if((*top)!=-1)
{
printf("deleted element = %d",s[*top]);
(*top)--;
}
else
{
printf("underflow condition");
}
}
void display(int s[4],int top)
{
int i;
for(i=0;i<=top;i++)
{
printf("%d\t",s[i]);
}
}
void palindrome(int s[4],int top)
{
int flag=0,len=top+1;
int i=0,j,k;
while(top!=-1)
{
if(s[top]!=s[i])
{
flag=1;
break;
}
top--;
i++;
}
if(flag==0)
printf("it is a palindrome");
else
printf("it is not a palindrome");
top=len-1;
}
int main()
{
int s[4],top=-1,ch,ele;
while(1)
{
printf("\n\n1.PUSH , 2.POP , 3.Display, 4.Palindrome");
printf("\nEnter the choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("enter the element : ");
scanf("%d",&ele);
push(s,ele,&top);
break;
case 2: pop(s,&top);
break;
case 3: display(s,top);
break;
case 4: palindrome(s,top);
break;
default: exit(0); 
}
}
return 0;
}
