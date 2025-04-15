//Take two linked list from user, merge them in sorted way.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int size1;
    printf("Enter the number of node in 1st linked list : ");
    scanf("%d", &size1);
    struct node *head1 = NULL, *temp1;
    for(int i = 1; i <= size1; i++){
        struct node *nnode = (struct node *) malloc (sizeof(struct node));+
        if(nnode == NULL){
            printf("Memory allocation failed!");
            return 1;
        }
        printf("Enter data : ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head1 == NULL){
            head1 = nnode;
            temp1 = nnode;
        } else {
            temp1->next = nnode;
            temp1 = nnode;
        }
    }
    int size2;
    printf("Enter the number of node in 2nd linked list : ");
    scanf("%d", &size2);
    struct node *head2 = NULL, *temp2;
    for(int i = 1; i <= size2; i++){
        struct node *nnode = (struct node *) malloc (sizeof(struct node));
        if(nnode == NULL){
            printf("Memory allocation failed!");
            return 1;
        }
        printf("Enter data : ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head2 == NULL){
            head2 = nnode;
            temp2 = nnode;
        } else {
            temp2->next = nnode;
            temp2 = nnode;
        }
    }
    temp1 = head1;
    temp2 = head2;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp2;
    struct node *head = head1;
    int size = size1 + size2;
    for(int i = 0; i < (size - 1); i++){
        temp1 = head, temp2 = head->next;
        for(int j = 0; j < (size - i - 1); j++){
            if(temp1->data > temp2->data){
                int dataTemp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = dataTemp;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    temp1 = head;

    while(temp1 != NULL){
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
}
