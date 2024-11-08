#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *temp=NULL;
struct node *create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    return newnode;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
  }    
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

struct node *min(struct node *root)
{
    struct node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
struct node *search(struct node *root,int item)
{
    if(root==NULL||root->data==item)
    {
        printf("the node exists");
        return root;
    }
    else
    {
        if(item<root->data)
        {
            return search(root->left,item);
        }
        else
        {
            return search(root->right,item);
        }
    }
}

struct node *insert(struct node *root,int value)
{
    if(root==NULL)
    {
        return create(value);
    }
    else if(value<root->data)
    {
        root->left=insert(root->left,value);
        
    }
    else
    {
        root->right=insert(root->right,value);
    }
    return root;
}
struct node *delete(struct node *rot,int value)
{
    if(root==NULL)
    {
        return root;
    }
    else if(value<root->data)
    {
        root->left=delete(root->left,value);
        
    }
    else if(value>root->data)
    {
        root->right=delete(root->right,value);
        
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            root=NULL;
            return root;
        }
        if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            struct node *temp=min(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
            
        }
    }
    return root;
}
void main()
{
    int choice;
    int item;
    char y;
    do
    {
      printf("1 Create, 2 Preorder, 3 Inorder, 4 Postorder");
      printf("\n 5 Search, 6 Insertion, 7 Deletion");
      printf("\n Enter your selection: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
           printf("Enter the data: ");
           scanf("%d",&item);
           create(item);
           break;
        case 2:
           preorder(root);
           break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter the element to search: ");
            scanf("%d",&search);
            search(root,item);
            break;
        case 6:
           printf("Enter the element to insert :");
           scanf("%d",&item);
           insert(root,item);
           break;
        case 7:
           printf("Enter the element to delete: ");
           scanf("%d",&item);
           delete(root,item);
           break;
        default:
            printf("Exit....\n");
            break;
        }
        printf("Do you want to continue (y/n) : ");
        scanf(" %c", &y);

    } while (y == 'Y' || y == 'y');
}    
    




























