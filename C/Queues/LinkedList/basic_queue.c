#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;    
};

struct Queue
{
    struct Node *front,*rear;
    // int max_size;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    if (( queue->front == NULL) && ( queue->rear == NULL))
    {
        printf("queue is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int peek(struct Queue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
        return INT_MIN;
    }
    return queue->front->data;

}

void enqueue(int data,struct Queue *queue)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    int empty = isEmpty(queue);
    if (empty == 1)
    {
       queue->front = temp;
       queue->rear = temp;
       printf("enqueued %d\n",data);
       return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
    printf("enqueued %d\n",data);
}

int size(struct Queue *queue)
{
    int sum = 0;
    int empty = isEmpty(queue);
    if (empty == 1)
    {
       return 0;
    }
    struct Node *temp = queue->front;
    while(temp!=queue->rear)
    {
        sum++;
        temp = temp->next;
    }
    sum++;
    return sum;
}

void dequeue(struct Queue *queue)
{
    
    int empty = isEmpty(queue);
    if (empty == 1)
    {
       return;
    }
    if (size(queue) == 1)
    {
        queue->rear = NULL;
    }

    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    printf("dequeued %d\n",temp->data);
    free(temp);
}


void display(struct Queue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
       return;
    }
    struct Node *temp = queue->front;
    while(temp!=queue->rear)
    {
        printf("%d<-",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    // free(temp); //it will delete the rear memory

}

int main()
{
    struct Queue *queue;
    queue = createQueue();

    enqueue(1,queue);
    display(queue);

    enqueue(2,queue);
    display(queue);

    enqueue(3,queue);
    display(queue);

    enqueue(4,queue);
    display(queue);

    enqueue(5,queue);
    display(queue);

    enqueue(6,queue);
    display(queue);

    dequeue(queue);
    display(queue);


    dequeue(queue);
    display(queue);


    dequeue(queue);
    display(queue);


    dequeue(queue);
    display(queue);


    dequeue(queue);
    display(queue);

    dequeue(queue);
    display(queue);


}


