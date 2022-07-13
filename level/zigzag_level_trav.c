#include<stdio.h>
#include<stdlib.h>
#include "queue2.h"
#define item int
/*typedef struct st{
    int data;
    struct st * left;
    struct st * right;
}Tnode;*/
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
    Tnode * root;
    if(*ptroot==NULL)
    {
        *ptroot=tmp;
        return;
        
    }
    else if( (*ptroot)->left==NULL && (*ptroot)->right!=NULL )
        insert(&(*ptroot)->left,value);
    else if( (*ptroot)->right==NULL && (*ptroot)->left!=NULL )
        insert(&(*ptroot)->right,value);
    else
        insert(&(*ptroot)->left,value);
    

}
void Binsert(Tnode**ptroot,item key)
{
    Tnode * tmp=get_node(key);
    if(*ptroot==NULL)
    {
        *ptroot=tmp;

    }
    else if(key<(*ptroot)->data)
        insert(&(*ptroot)->left,key);
    else
        insert(&(*ptroot)->right,key);
    
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
void levelorder(Tnode * root)
{
    queue q;
    init(&q,5);
    if(root==NULL)
        return;
    else
    {
            enqueue(&q,root);
            while(!isempty(&q))
            {
                root=dequeue(&q);
                printf("%d ",root->data);
                if(root->left!=NULL)
                    enqueue(&q,root->left);
                if( root->right!=NULL)
                    enqueue(&q,root->right);
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
    insert(&root,10);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    zigzag(root);
    printf("\n");
    levelorder(root);
    return 0;

}