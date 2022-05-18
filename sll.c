//Program 7 - SLL
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
int sem,phno;
char name[20],branch[10],usn[10];
struct node*link ;
};
typedef struct node *Node;
Node getnode()
{
Node temp;
int sem,phno;
char name[20],usn[10],branch[10];
temp=(Node)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("memory not available");
exit(0);
}
printf("Enter the student details");
printf("\nName , USN , Branch, sem, Phone no. :");
scanf("%s%s%s%d%d",name,usn,branch,&temp->sem,&temp->phno);
strcpy(temp->name,name);
strcpy(temp->usn,usn);
strcpy(temp->branch,branch);
temp->link=NULL;
return temp;
}
Node insert_front(Node first)
{
Node temp;
temp=getnode();
temp->link=first;
return temp;
}
Node insert_rear(Node first)
{
Node cur,prev,temp;
temp=getnode();
if(first==NULL)
{
return temp;
}
else
{
cur=first;
prev=NULL;
while(cur!=NULL)
{
prev=cur;
cur=cur->link;
}
prev->link=temp;
return first;
}
}
Node delete_front(Node first)
{
if(first==NULL)
{
printf("SLL is empty");
return first;
}
else
{
Node next;
printf("deleted info is = %s %s %s %d %d",first->name,first-
>usn,first->branch,first->sem,first->phno);
next=first->link;
free(first);
return next;
}
}
Node delete_rear(Node first)
{
Node cur,prev=NULL;
if(first==NULL)
{
printf("SLL is empty");
return NULL;
}
else
{
Node cur;
cur = first;
while(cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
printf("\ndeleted info is = %s %s %s %d %d",cur->name,cur-
>usn,cur->branch,cur->sem,cur->phno);
prev->link=NULL;
free(cur);
return first;
}
}
void display(Node first)
{
Node cur;
if(first==NULL)
{
printf("\nNo elements in SLL");
}
else
{
cur=first;
while(cur!=NULL)
{
printf("\n%s, %s, %s, %d, %d",cur->name,cur->branch,cur-
>usn,cur->phno,cur->sem);
cur=cur->link;
}
}
}
void count(Node first)
{
Node cur;
int count=0;
cur=first;
if(first==NULL)
{
printf("there are no elements in SLL");
return;
}
else
{
while(cur!=NULL)
{
count++;
cur=cur->link;
}
printf("The number of nodes in SLL = %d",count);
}
}
int main()
{
Node first;
int ch;
first=NULL;
while(1)
{
printf("\n\n1.Insert front , 2.Insert rear , 3.Delete front , 
4.Delete rear , 5.Display , 6.Exit");
printf("\nEnter the choice : ");
scanf("%d",&ch);
switch(ch)
{
      case 1 : first = insert_front(first);
      break;
      case 2 : first = insert_rear(first);
      break;
      case 3 : first = delete_front(first);
      break;
      case 4 : first = delete_rear(first);
      break;
      case 5 : display(first);
      break;
      default : printf("invalid 
      input"); 
}
}
return 0;
}
