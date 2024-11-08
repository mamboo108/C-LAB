#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int first,int last)
{
    int key=a[last];
    int i=first-1;
    for(int j=first;j<last;j++)
    {
        if(a[j]<=key)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[last]);
    return i+1;
}
void quicksort(int a[],int first,int last)
{
  if(first<last)
  {    
    int index=partition(a,first,last);
    quicksort(a,first,index-1);
    quicksort(a,index+1,last);
  }
}

int main()
{
    int a[10];
    int i;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("Sorted\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}




