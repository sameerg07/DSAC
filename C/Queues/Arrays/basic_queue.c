#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    int front;
    int rear;
    int max_size;
    int *array;
};

struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->max_size = size;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->max_size * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    if ((queue->rear + 1) == queue->max_size)
    {
        printf("queue is full\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isEmpty(struct Queue *queue)
{
    if ((queue->rear) < (queue->front))
    {
        printf("queue is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int size(struct Queue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
        return 0;
    }
    else
    {
        return ((queue->rear)-(queue->front)+1);
    }
    
    
}

void enqueue(int data,struct Queue *queue)
{
    int full = isFull(queue);
    if (full == 1)
    {
        return;
    }

    queue->rear++; //increment rear
    queue->array[queue->rear] = data;
    printf("added %d to the queue\n",data);
}

void dequeue(struct Queue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
        return;
    }
    printf("dequeued %d\n",queue->array[queue->front]);
    (queue->front)++; 
}

int peek(struct Queue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
        return INT_MIN;
    }
    return queue->array[queue->front];

}

void display(struct Queue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
        return;
    }
    for(int i = queue->front ; i<=queue->rear; i++)
    {
        printf("%d ",queue->array[i]);
    }
    printf("\n------------------------------------\n");
}

int main()
{
    struct Queue *queue;
    queue = createQueue(5);

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


}

