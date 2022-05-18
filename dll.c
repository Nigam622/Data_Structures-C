//Program 8 - DLL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int empid;
char name[20],address[20];
struct node*llink,*rlink;
};
typedef struct node*NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("memory not available");
return NULL;
}
else
return x;
}
NODE insert_front(NODE first,int empid,char name[20],char address[20])
{
NODE temp;
temp=getnode();
temp->rlink=temp->llink=NULL;
temp->empid=empid;
strcpy(temp->name,name);
strcpy(temp->address,address);
if(first==NULL)
{
return temp;
}
temp->rlink=first;
first->llink=temp;
return temp;
}
NODE insert_rear(NODE first,int empid,char name[20],char address[20])
{
NODE temp;
temp=getnode();
temp->rlink=temp->llink=NULL;
temp->empid=empid;
strcpy(temp->name,name);
strcpy(temp->address,address);
NODE cur,prev;
cur=first;
prev=NULL;
if(first==NULL)
{
return temp;
}
while(cur!=NULL)
{
prev=cur;
cur=cur->rlink;
}
prev->rlink=temp;
temp->llink=prev;
return first;
}
NODE delete_front(NODE first)
{
NODE next;
if(first==NULL)
{
return first;
}
if(first->rlink==NULL)
{
printf("\ndeleted info = %d , %s , %s",first->empid,first-
>name,first->address);
free(first);
return NULL;
}
next=first->rlink;
next->llink=NULL;
printf("\ndeleted info = %d , %s , %s",first->empid,first->name,first-
>address);
free(first);
return next;
}
NODE delete_rear(NODE first)
{
NODE cur=first,prev=NULL;
if(first==NULL)
{
printf("empty DLL");
return NULL;
}
if(first->rlink==NULL)
{
printf("\ndeleted info = %d , %s , %s",first->empid,first-
>name,first->address);
free(first);
return NULL;
}
while(cur->rlink!=NULL)
{
prev=cur;
cur=cur->rlink;
}
prev->rlink=NULL;
printf("\ndeleted info = %d , %s , %s",cur->empid,cur->name,cur-
>address);
free(cur);
return first;
}
void display(NODE first)
{
NODE cur;
cur=first;
if(first==NULL)
{
printf("empty DLL");
return;
}
while(cur!=NULL)
{
printf("\n%d , %s , %s",cur->empid,cur->name,cur->address);
cur=cur->rlink;
}
}
int main()
{
NODE first;
first=NULL;
int ch,empid;
char name[20],address[20];
while(1)
{
printf("\n\n1.Insert front, 2.Insert rear, 3.Delete front, 
4.Delete rear, 5.Display, 6.Exit");
printf("\nEnter the choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("enter the employee details : ");
scanf("%d%s%s",&empid,name,address);
first=insert_front(first,empid,name,address);
break;
case 2: printf("enter the employee details : ");
scanf("%d%s%s",&empid,name,address);
first=insert_rear(first,empid,name,address);
break; 
case 3: first=delete_front(first);
break;
case 4: first=delete_rear(first);
break;
case 5: display(first);
break;
case 6: exit(0);
default: printf("invalid 
input"); 
}
}
return 0;
}
