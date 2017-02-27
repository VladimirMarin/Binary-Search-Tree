#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left , *right;
};
void afisareRSD(struct node *leaf)
{
    if(leaf != NULL)
    {
        printf(" %d " , leaf->key);
        afisareRSD(leaf->left);
        afisareRSD(leaf->right);
    }
}
void afisareSRD(struct node *leaf)
{
    if(leaf != NULL)
    {
        afisareSRD(leaf->left);
        printf(" %d " , leaf->key);
        afisareSRD(leaf->right);
    }
}
void adaugare(struct node **leaf , int key)
{
    if(*leaf == NULL)
    {
        *leaf = malloc(sizeof(struct node));
        (*leaf)->key = key;
        (*leaf)->left = NULL;
        (*leaf)->right = NULL;
        return;
    }
    else
        if((*leaf)->left == NULL)
            adaugare(&(*leaf)->left , key);
    else
        adaugare(&(*leaf)->right , key);
}
int main()
{
    struct node* head = NULL;
    int i , a;
    for( i = 0 ; i < 10 ; i++)
    {
        scanf("%d" , &a);
        adaugare(&head , a);
    }
    //afisareRSD(head);
    afisareSRD(head);
    return 0;
}
