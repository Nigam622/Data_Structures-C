//Program 4 - Infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
int G(char symbol)
{
switch(symbol)
{
case '+': 
case '-': return 1;
case '*':
case '/': return 3;
case '$':
case '^': return 6;
case '(': return 9;
case ')': return 0;
default: return 7;
}
}
int F(char symbol)
{
switch(symbol)
{
case '+': 
case '-': return 2;
case '*':
case '/': return 4;
case '$':
case '^': return 5;
case '(': return 0;
case '#': return -1;
 default: return 8;
}
}
void push(char s[max],int *top,char symbol)
{
if((*top)<(max-1))
{
(*top)++;
s[*top]=symbol;
}
else
printf("overflow condition");
}
char pop(char s[max],int *top)
{
char symbol;
symbol=s[*top];
(*top)--;
return symbol;
}
void infix_to_postfix(char infix[20])
{
char symbol,s[max],postfix[20] ;
int top=-1,j=0,i=0,n;
n=strlen(infix);
push(s,&top,'#');
for(i=0;i<n;i++)
{
symbol=infix[i];
while(F(s[top]) > G(symbol))
{
postfix[j++]=pop(s,&top);
}
if(F(s[top])!=G(symbol)
push(s,&top,symbol);
else
top--; 
}
while(s[top]!='#')
{
postfix[j++]=pop(s,&top);
}
postfix[j]='\0';
printf("The postfix expression is = %s",postfix);
}
int main()
{
char infix[20];
printf("enter the infix expression : ");
scanf("%s",infix);
infix_to_postfix(infix);
return 0;
}
