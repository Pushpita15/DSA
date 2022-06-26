#include<stdio.h>
#include<stdlib.h>
#define item int
typedef struct st{
    int data;
    struct st * left;
    struct st * right;
}Tnode;
Tnode* get_node(item value)
{
    Tnode * newnode;
    newnode=(Tnode*)malloc(sizeof(Tnode));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}
void insert (Tnode**ptroot,item value)
{
    Tnode * tmp=get_node(value);
    if(*ptroot==NULL)
    {
        *ptroot=tmp;
        return;
    }
    else if( (*ptroot)->left==NULL )
        insert(&(*ptroot)->left,value);
    else
        insert(&(*ptroot)->right,value);
    

}
void preorder(Tnode *root)
{
	if(root==NULL) printf("NULL TREE");
	else
	{
		printf("%d ",root->data);
		if(root->left!=NULL) preorder(root->left);
		if(root->right!=NULL) preorder(root->right);
	}
}
void inorder(Tnode *root)
{
	if(root==NULL) printf("NULL TREE");
	else
	{
        if(root->left!=NULL) inorder(root->left);
		printf("%d ",root->data);
		if(root->right!=NULL) inorder(root->right);
	}
}
void postorder(Tnode *root)
{
	if(root==NULL) printf("NULL TREE");
	else
	{
		if(root->left!=NULL) postorder(root->left);
		if(root->right!=NULL) postorder(root->right);
        printf("%d ",root->data);
	}
}
void zigzag(Tnode * root)
{
    Tnode * tmp;
    if(root==NULL) printf("NULL TREE");
    else
    {
        tmp=root;
        printf("%d ",root->data);
        if(root->right!=NULL || root->left!=NULL)
        {
            printf("%d ",root->right->data);
            printf("%d ",root->left->data);
            root=root->left;
        }
        if(root->right!=NULL || root->left!=NULL)
        {
            printf("%d ",root->left->data);
            printf("%d ",root->right->data);
            root=root->right;
        }
        
    }

}
int main()
{
    Tnode * root=NULL;
    insert(&root,2);
    insert(&root,4);
    insert(&root,6);
    insert(&root,8);
    /*preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);*/
    zigzag(root);
    return 0;

}