//Function to swap two adjacent node.

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
    int pos;
    printf("Enter the number of node to which it's and it's next adjacent node's data to be swap : ");
    scanf("%d", &pos);
    temp = head;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
    }
    int swapper = temp->data;
    temp->data = temp->next->data;
    temp->next->data = swapper;
    printf("\nlinked list :\n");
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
