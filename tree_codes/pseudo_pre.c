typedef struct st{

    ITEM data;
    struct st * left;
    struct st * right;

}node;


void preorder(node * root)
{
    stack s;
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
}