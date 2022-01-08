#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int a[MAX_SIZE];
int front = -1;
int rear = -1;

void push(int x){
    if(((rear+1) % MAX_SIZE) == front){
        printf("Error: Queue is full!");
        return;
    }else if (front == -1 && rear == -1){ // To check whether Queue is empty or not
        front = 0;
        rear = 0;

    }else{
        rear = (rear + 1) % MAX_SIZE; // this line of code helps the function to loop through the array, after the last index, it will return back to 0
    }
    a[rear] = x;

}

void pop(){
    if (front == -1 && rear == -1){
        printf("Error: The stack is empty!\n");
        return;
    }else if( front == rear){ // when removing the last remaining element from the list
        a[front] = NULL;
        front = -1;
        rear = -1;
    }else{
        front = (front+1) % MAX_SIZE;
    }
}

int returnfront(){
    if(front == -1){
        printf("Error: The stack is empty!\n");
        return -1;
    }
    return a[front];
}

void print(){
    printf("\nQueue: ");
    // Finding number of elements in queue
    int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
    for (int i = 0; i < count; i++){
        int index = (front + i) % MAX_SIZE;
        printf("%d -> ", a[index]);
    }
    printf("\n");
}


int main()
{
    pop();

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    print();

    printf("\nfront: %d\n", returnfront());

    pop();

    push(7);

    print();

    return 0;
}
