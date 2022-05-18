#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node * link;
};
typedef  struct node * NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not Allocated");
        exit (0);
    }
   
     return x;
}

NODE insert_front(NODE last, int elem) 
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    if(last==NULL)
    {
        last=temp;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    return last;
    
}


NODE insert_rear(NODE last, int elem) 
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    if(last==NULL)
    {
        last=temp;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    return temp;
    
}

NODE delete_front(NODE last)
{
    NODE first,second;
    if(last==NULL)
    {
        printf("Empty CLL");
        return NULL;
    }
    if(last->link==last)
    {
        printf("Deleted info =%d",last->info);
        free(last);
        return NULL;
    }
    
    first=last->link;
    second=first->link;
    printf("Deleted info=%d",first->info);
    last->link=second;
    free(first);
    return last;
}    
    

NODE delete_rear(NODE last)
{
    NODE first,cur;
    if(last==NULL)
    {
        printf("Empty CLL");
        return NULL;
    }
    if(last->link==last)
    {
        printf("Deleted info =%d",last->info);
        free(last);
        return NULL;
    }
    
    first=last->link;
    cur=first->link;
    while(cur->link!=last)
    {
        cur=cur->link;
    }
    cur->link=first;
    printf("Deleted info=%d",first->info);
    free(last);
    return cur;
}    
    
void display(NODE last)
{
    NODE cur=last->link;
     if(last==NULL)
    {
        printf("Empty CLL");
        return;
    }
    while(cur->link!=NULL)
    {
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("%d",cur->info);
}

int main()
{   
    fflush(stdin);
    NODE last;
    last=getnode();
    int elem,ch;
     while(1)
     {
         printf("\n1.insert_front\n2.insert_rear\n3.delete_front\n4.delete_rear\n5.display\n6.EXIT\nEnter choice:");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1: printf("Enter elem:\n");
                     scanf("%d",&elem);
                     last=insert_front(last,elem);
                     break;
            case 2:  printf("Enter elem:\n");
                     scanf("%d",&elem);
                     last=insert_rear(last,elem);
                     break;
            case 3:  last=delete_front(last);
                     break;
            case 4:  last=delete_rear(last);
                     break;
            case 5:  printf("The CLL info are:\n");
                     display(last);
                     break;
                     
            case 6:  exit(0);
            default: printf("Enter Valid input!!!");
         }
     }
        return 0;
    
}    
    
