#include <stdio.h>
#include <stdlib.h>
#define def 1
struct tree{
    struct tree *lchild;
    struct tree *rchild;
    int value;
};
typedef struct tree* TREE;
void preorder(TREE t){
        if(t==NULL)
            return;
        printf("%d\t",t->value);
        preorder(t->lchild);
        preorder(t->rchild);
        return;
}
void postorder(TREE t){
    if(t==NULL)
            return;
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d\t",t->value);
    return;
}
void inorder(TREE t){
    if(t==NULL)
            return;
    inorder(t->lchild);
    printf("%d\t",t->value);
    inorder(t->rchild);
    return;
}
int main()
{
    TREE t=(TREE)malloc(sizeof(TREE));
    t->value=200;
    TREE nc1=(TREE)malloc(sizeof(TREE));
    TREE nc2=(TREE)malloc(sizeof(TREE));
    nc1->value=100;
    nc2->value=300;
    nc1->lchild=NULL;
    nc1->rchild=NULL;
    nc2->rchild=NULL;
    nc2->lchild=NULL;
    t->lchild=nc1;
    t->rchild=nc2;
    preorder(t);
    printf("\n");
    postorder(t);
    printf("\n");
    inorder(t);
    printf("\n");
    char junk;
    junk=getchar();
	return 0;
}
