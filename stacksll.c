#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
struct node *newnode;
void push()
{
    int item;
    printf("enter the element");
    scanf("%d",&item);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    struct node *temp=top;
    if(top==NULL)
    {
        printf("Underflow");
        
    }
    else
    {
        printf("deleted element is %d",temp->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp=top;
    if(top==NULL)
    {
        printf("memory Underflow");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int op;
    char dec;
    do
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DSIPLAY\n");
        printf("ener your choice: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
               push();
               break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
        }
    printf("do you want to continue");
    scanf(" %c",&dec);
    }while(dec=='y'||dec=='Y');
        
        
    }
    


    
