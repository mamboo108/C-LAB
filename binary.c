#include<stdio.h>
int binary(int a[],int n,int data)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(data==a[mid])
        {
            return mid;
        }
        else if(a[mid]<data)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}
int main()
{
    int i,j,k,n,temp;
    int a[10];
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements in the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }    
        for(j=0;j<n-1;j++)
        {
            for(k=0;k<n-j-1;k++)
            {
                if(a[k]>a[k+1])
                {
                    temp=a[k];
                    a[k]=a[k+1];
                    a[k+1]=temp;
                }
            }
        }
    
  
    
int data;
printf("Enter the element to search for: ");
scanf("%d",&data);
int result=binary(a,n,data);
if(result!=-1)
{
    printf("Element is found at %d\n",result);
    
}
else
{
    printf("Element not found in array");
    
}
}



        
    
    

    
 
