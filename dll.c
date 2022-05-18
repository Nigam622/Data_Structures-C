//DLL implementation and also count both in single programm


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pf printf
#define sf scanf
#define ll long long
#define ff float
#define dd double
#define ui unsigned int
#define lli long long int
struct node{
    int info;
    struct node * llink;
    struct node * rlink; 
};
typedef struct node * NODE;

NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        pf("\nno memory available\n");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE first,int item){
    NODE temp=getnode();
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(first==NULL)
        return temp;
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE insert_rear(NODE first,int item){
    NODE temp=getnode();
    NODE curr=first;
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(first==NULL)
        return temp;
    while(curr->rlink!=NULL)
        curr=curr->rlink;
    curr->rlink=temp;
    temp->llink=curr;

    return first;
}

NODE delete_front(NODE first){
    NODE next;
    if(first==NULL){
        pf("\nempty DLL\n");
        return NULL;
    }
    if(first->rlink==NULL){
        pf("\n%d deleted\n",first->info);
        free(first);
        return NULL;
    }
    pf("\n%d deleted\n",first->info);
    // first=next->rlink;
    // first->llink=NULL;
    // free(next);
    // return first;
    next=first->rlink;
    next->llink=NULL;
    free(first);
    return next;
}

NODE delete_rear(NODE first){
    NODE curr=first,prev=NULL;
    if(first==NULL){
        pf("\nempty DLL\n");
        return NULL;
    }
    if(first->rlink==NULL){
        pf("\n%d is deleted\n",first->info);
        free(first);
        return NULL;
    }
    while(curr->rlink!=NULL){
        prev=curr;
        curr=curr->rlink;
    }
    pf("\n%d deleted\n",curr->info);
    prev->rlink=NULL;
    free(curr);
    return first;
}

void count(NODE first){
    NODE curr=first;
    int count=0;
    while(curr->rlink!=NULL){
        count++;
        curr=curr->rlink;
    }
    pf("\n%d nodes in DLL\n",count);
    return;
}

void display_dll(NODE first){
    NODE curr=first;
    if(first==NULL){
        pf("\nDLL is empty\n");
        return;
    }
    // while(curr->rlink!=NULL){
        while(curr!=NULL){
        pf("%d ",curr->info);
        curr=curr->rlink;
    }
    return;
}

int main(){
    fflush(stdin);
    int ch,item;
    NODE first=getnode();
    first->llink=NULL;
    first->rlink=NULL;
    while(1){
        pf("\nenter the choice:\n");
        pf("1.insert_front\n2.insert_rear\n3.delete_front\n4.delete_rear\n5.count nodes\n6.diaplay\n7.exit\n");
        sf("%d",&ch);
        switch(ch){
            case 1 :pf("\nenter the element:\n");
                    sf("%d",&item);
                    first=insert_front(first,item);
                    break;
            case 2: pf("\nenter the element:\n");
                    sf("%d",&item);
                    first=insert_rear(first,item);
                    break;
            case 3: first=delete_front(first);
                    break;
            case 4: first=delete_rear(first);
                    break;
            case 5: count(first);
                    break;
            case 6: display_dll(first);
                    break;
            case 7: exit(0);
            default: pf("\ninvalid choice\n");
        }
    }
    return 0;
}
