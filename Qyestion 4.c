//Find the third node from last (nodes >= 10).

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int size;
    printf("Enter the number of node : ");
    scanf("%d", &size);
    struct node *head = NULL;
    struct node *temp = NULL;
    for(int i = 1; i <= size; i++) {
        struct node* nnode = (struct node*)malloc(sizeof(struct node));
        if(nnode == NULL){
            printf("Memory allocation failed!");
            return 1;
        printf("Enter data : ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head == NULL){
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
    }
    temp = head;
    for(int i = 1; i <= size - 3; i++){
        temp = temp->next;
    }
    printf("Data of third node from last node is %d.", temp->data);
}
