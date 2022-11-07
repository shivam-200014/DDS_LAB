#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void ins_at_pos(int pos,int data,node **ptr)
{
    //node creation
    node *new =(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    //insertion
    if(pos==1)
    {
        new->next=*ptr;
        *ptr=new;
    }
    else{
        node *temp=*ptr;
        pos-=2;
        while(pos--)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }

}

void print_list(node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void list_in_rev_o(node *head)
{
    if(head==NULL)
        return;
    else{
        node *temp=head;
        head=head->next;
        list_in_rev_o(head);
        printf("%d ",temp->data);
    }
}

int main()
{
    node *head=NULL;
    ins_at_pos(1,0,&head);
    ins_at_pos(2,5,&head);
    ins_at_pos(3,10,&head);
    ins_at_pos(1,-5,&head);
    ins_at_pos(5,15,&head);
    ins_at_pos(4,8,&head);
    list_in_rev_o(head);
    printf("\n");
    print_list(head);
}