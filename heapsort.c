#include<stdio.h>
# define max 100
void heapify(int a[],int n,int i)
{
    int temp;
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left] > a[largest])
    {
        largest=left;
    }
    if(right<n && a[right] > a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

int main()
{
    int n;
    int i;
    int a[max];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("Sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
