#include<stdio.h>
# define size 5
int stack[size];
int top =-1;
void push(int item)
{
    if(top==size-1)
    {
        printf("Memory Overflow");
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Memory Underflow");
    }
    else
    {
        int d =stack[top];
        top=top-1;
        printf("deleted element is %d",d);
    }
}

void display()
{
    if(top==-1)
    {
        printf("Memory Underflow");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}

void peek()
{
    if(top==-1)
    {
        printf("Memory Underflow");
    }
    else
    {
        printf("The element at the top is %d",stack[top]);
    }
}
int main()
{
    int opt;
    char dec;
    do
    {
        printf("Push\n");
        printf("Pop\n");
        printf("Peak\n");
        printf("display\n");
        printf("exit\n");
        printf("Enter your choice: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            {
                int item;
                printf("Enter the item ");
                scanf("%d",&item);
                push(item);
                break;
            }
            case 2:
              pop();
              break;
            case 3:
              peek();
              break;
            case 4:
              display();
              break;
            case 5:
              break;
        }
        printf("do you want to continue y/n");
        scanf(" %c",&dec);
    }
        while(opt!=5&&(dec=='y'||dec=='Y'));
        return 0;
}        
        
            
            
