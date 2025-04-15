//Find length of user input linked list.

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
    struct node *head = NULL, *temp;
    for(int i = 1; i <= size; i++){
        struct node *nnode = (struct node *) malloc (sizeof(struct node));
        if(nnode == NULL){
            printf("Memory allocation failed!");
            return 1;
        }
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
    int length = 0;
    temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    printf("\nEntered linked list :\n");
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n Length of linked list is %d.", length);
}
