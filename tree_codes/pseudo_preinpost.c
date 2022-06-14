typedef struct st{

    ITEM data;
    struct st * left;
    struct st * right;

}node;


void preorder(node * root)
{
    stack s;
    do{
        while(root!=NULL)
        {
            printf(root->data);
            if(root->right!=NULL)
                push(&s,root->right);
            if(root->left!=NULL)
                root=root->left;
            else
                root=pop(&s);
        }
    }while(!isempty(&s));
}

void inorder(node * root)
{
    do{
        while(root!=NULL)
        {
            push(&S,root);
            root=root->left;
        }
        root=pop(&s);
        printf(root->data);
        if(root->right!=NULL)
            root=root->right;
    }while(!isempty(&s));

}