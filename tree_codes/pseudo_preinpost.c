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
    stack s;
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
void postorder(node * root)
{
    stack s;
    init(&s);
    while(root!=NULL)
    {
        if(root->right!=NULL)
            push(&s,root->right);
        push(&s,root);
        root=root->left;
    }
    if(!isempty(&s))
    {
        root=pop(&s);
        if(root->right==peek(&s))
        {
            temp=pop(&s);
            push(&s,root);
            root=temp;
        }
        else{
            printf("%d",root->data);
            root=NULL;
        }
    }

}

void levelorder(node * root)
{
    queue q;
    if(root==NULL)
        return;
    else
    {
            while(root!=NULL)
            {
                printf(root->data);
                if(root->left!=NULL)
                    enqueue(&q,root->left);
                if( root->right!=NULL)
                    enqueue(&q,root->right);
                if(!isempty(&s))
                    root=dequeue(&q);
            }

    }
}