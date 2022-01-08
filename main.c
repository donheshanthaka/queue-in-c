#include <stdio.h>
#include <stdlib.h>

// linked list

struct node{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if(front == NULL){
        front  = temp;
        rear = temp;
    }
    rear->link = temp;
    rear = temp;
}

void dequeue(){ // deleting the front(head) node
    if (front == NULL){
        printf("Error: The queue is empty!\n");
        return;
    }
    struct node *temp = front;
    front = front->link;
    free(temp);
    temp = NULL;
}

struct node *returnfront(){
    if(front == NULL){
        printf("Error: The queue is empty!\n");
        return;
    }
    return front;
}

void print(){
    if(front == NULL){
        printf("Error: The queue is empty!\n");
        return;
    }
    struct node *temp = front;
    printf("\nQueue: ");
    while(temp != NULL){
        printf(" <- %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


int main()
{
    dequeue();

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    print();

    printf("\nFront: %d\n", returnfront()->data);

    dequeue();

    enqueue(7);

    print();

    return 0;
}
