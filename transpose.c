#include<stdio.h>
int create(int s[10][10],int r,int c)
{
    printf("Enter the elements; ");
    int value,k=1;
    s[0][0]=r;
    s[0][1]=c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&value);
            if(value!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=value;
                k++;
            }
        }
    }
s[0][2]=k-1;
return k-1;
}
int sparse(int sr[][10],int s[][10],int kk,int c)
{
    int k=1;
    
    sr[0][0]=s[0][1];
    sr[0][1]=s[0][0];
    sr[0][2]=s[0][2];
    for(int i=0;i<c;i++)
    {
        for(int j=1;j<=kk;j++)
        {
            if(s[j][1]==i)
            {
                sr[k][0]=s[j][1];
                sr[k][1]=s[j][0];
                sr[k][2]=s[j][2];
                k++;
            }
        }
    }
return k-1;    
}
void display(int s[][10],int k)
{
    printf("Sparse\n");
    for(int i=0;i<k;i++)
    {
        printf("%d%d%d\n",s[i][0],s[i][1],s[i][2]);
    }    
    
}

int main()
{
    int s1[10][10],s2[10][10],r,c;
    printf("Enter the row and column size\n");
    scanf("%d%d",&r,&c);
    int k1=create(s1,r,c);
    display(s1,k1);
    printf("transpose\n");
    int k2=sparse(s2,s1,k1,c);
    display(s2,k2);
    return 0;
    
}

    
    
    
    
    
    
    

