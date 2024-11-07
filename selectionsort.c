#include<stdio.h>
# define max 100
int n;
int a[max];
void selection()
{
    int i,temp,min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
    
    if(min!=i)
    {
    temp=a[min];
    a[min]=a[i];
    a[i]=temp;
    }
  }    
}
void input()
{
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{   printf("The Sorted array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    input();
    selection();
    display();
    return 0;
}

