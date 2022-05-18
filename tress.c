#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
int info;
struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE getnode()
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
return temp;
}
NODE insert(NODE root,int item)
{
NODE temp,cur,prev;
temp=getnode();
temp->rlink=temp->llink=NULL;
temp->info=item;
if(root==NULL)
{
return temp;
}
cur=root;
while(cur!=NULL)
{
prev=cur;
if(cur->info > item)
cur=cur->llink;
else
cur=cur->rlink; 
}
if(prev->info < item)
prev->rlink=temp;
else
prev->llink=temp;
return root;
}
void search_bst(NODE root,int elem)
{
NODE cur=root;
if(cur==NULL)
{
printf("empty BST");
return;
}
while(cur!=NULL)
{
if(cur->info==elem)
{
printf("element found");
return;
}
if(cur->info > elem)
cur=cur->llink;
else
cur=cur->rlink; 
}
printf("element not found in BST");
}
void inorder(NODE root)
{
if(root==NULL)
return;
inorder(root->llink);
printf("%d",root->info);
inorder(root->rlink); 
}
void postorder(NODE root)
{
if(root==NULL)
return;
postorder(root->llink);
postorder(root->rlink);
printf("%d",root->info); 
}
void preorder(NODE root)
{
if(root==NULL)
return;
printf("%d\t",root->info);
preorder(root->llink);
preorder(root->rlink);
}
int main()
{
int i,n,elem;
NODE root;
root=getnode();
printf("enter the number of nodes : ");
scanf("%d",&n);
int ch,item;
while(1)
{
printf("\n1.insert, 2.Search bst, 3.Preorder display, 4.inorder display, 5.postorder display,6.exit");
printf("\nEnter the choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: for(i=0;i<n;i++)
        {
        printf("enter item %d : ",i);
        scanf("%d",&item);
        root=insert(root,item);
        }
        break;
case 2: printf("\nenter element to search: ");
        scanf("%d",&elem);
        search_bst(root,elem);
        break;
case 3: preorder(root);
        break;
case 4: inorder(root);
        break; 
case 5: postorder(root);
        break; 
case 6: exit(0);
   }
}
return 0;
}
