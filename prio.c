#include <stdio.h>
#define size 5 
struct pq {
    int it ;
    int pri ;
}A[size];

int front = -1;
int rear = -1;

void enq(int item,int priority) {
    int i ;
    if(front == 0 && rear == size - 1)
        printf("\nQueue Full!\n");
    else if(front == -1 && rear == -1){
        front=0;
        rear=0;
        A[rear].it = item ; 
        A[rear].pri = priority ;
    }
    else if(rear == size - 1) {
        for( i = front ; i <= rear ; i++){
            A[i-1]=A[i];
        }
        front -- ;
        rear -- ;
        for( i=rear ; i >= front ;i-- ) {
            if(A[i].pri <= priority )
                break ;
        }
        int loc = i + 1 ;
        for(i = rear ; i >= loc ; i--){
            A[i+1] = A[i] ;
        }
        A[loc].it = item ;
        A[loc].pri = priority ;
        rear = rear + 1;
    }
    else {
        int i ;
        for( i=rear ; i >=front ;i-- ) {
            if(A[i].pri < priority )
                break ;
        }
        int loc = i + 1 ;
        for(i = rear ; i >= loc ; i--){
            A[i+1] = A[i] ;
        }
        A[loc].it = item ;
        A[loc].pri = priority ;
        rear = rear + 1;
    }
}

void dequeue(){
    if (front == -1 && rear == -1 )
    {
        printf("Qeuee empty ! ");
    }
    else if (front == rear ){
        printf("Deleted item is %d",A[front].it);
        rear = -1 ;
        front = -1 ;
    }
    else
    {
        printf("Deleted item is %d",A[front].it);
        front = front + 1 ;
    }
}

void display(){
    if (front == -1 && rear == -1 )
        printf("Qeuee empty ! ");
    else{
        for(int i = front ; i <= rear ; i++){
            printf(" %d(%d)",A[i].it,A[i].pri);
        }
    }
}

int main()
{
    int choice,value,priorit ;
    do{
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.display");
        printf("\n4.exit");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the value : ");
                scanf("%d",&value);
                printf("\nEnter the pri : ");
                scanf("%d",&priorit);
                enq(value,priorit);
                break ;
            case 2:
                dequeue();
                break ;
            case 3 :
                display();
                break ;
            case 4 :
                break ;
        }
    }while(choice!=4);

}
