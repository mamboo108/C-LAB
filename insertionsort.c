#include<stdio.h>
# define max 100 
int n;
int a[max];
void input()
{
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    { 
        scanf("%d",&a[i]);
    }
}
void display()
{
    printf("Sorted array is\n");
    for(int i=0;i<n;i++)
    { 
        printf("%d ",a[i]);
    }
}
void insertion()
{
    for(int i=1;i<n;i++)
    {
        int temp =a[i];
        int j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
        
    
    
}
int main()
{
    input();
    insertion();
    display();
}
