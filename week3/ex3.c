#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct Node {
    int data;
    struct Node* next;
};

void print_list(struct Node* n)
{   printf("List:");
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void create_node( struct Node** new_node,int value,struct Node* child_node){
    *new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node)->data=value;
    (*new_node)->next=child_node;
}

void insert_node(int value,struct Node* prev_ref)
{
    struct Node* new_node
            = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->next=NULL;
    if(prev_ref->next==NULL){
        prev_ref->next = new_node;
    }else{
        struct Node* temp =  prev_ref->next;
        prev_ref->next=new_node;
        new_node->next=temp;
    }
}

//Another implementation for explicitly defined outside of method node
void insert_given_node(struct Node* new_node,struct Node* prev_ref)
{
    if(prev_ref->next==NULL){
        prev_ref->next = new_node;
    }else{
        struct Node* temp =  prev_ref->next;
        prev_ref->next=new_node;
        new_node->next=temp;
    }
}
void delete_node(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
int main()
{
    struct Node *head, *first, *second, *third;
    create_node(&head,3,NULL);
    create_node(&first,1,NULL);
    create_node(&second,2,NULL);
    create_node(&third,4,NULL);

    insert_node(5,head);
    insert_given_node(first,head);
    insert_given_node(second,first);
    insert_given_node(third,second);
    print_list(head);

    delete_node(&head,3);
    delete_node(&head,6);
    print_list(head);

}


