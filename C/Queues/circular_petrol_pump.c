#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct PetrolPump
{
    int capacity;
    int distance;
    int id;
    struct PetrolPump *next;
};

struct PumpQueue
{
    struct PetrolPump *front,*rear;
};

int isEmpty(struct PumpQueue *queue)
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

int size(struct PumpQueue *queue)
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

void enqueue(int cap , int dis , int id ,struct PumpQueue *queue)
{
    struct PetrolPump *petrolpump = (struct PetrolPump*)malloc(sizeof(struct PetrolPump));
    petrolpump -> capacity = cap;
    petrolpump -> distance = dis;
    petrolpump -> id       = id;

    int empty = isEmpty(queue);
    if (empty == 1)
    {
       queue->front = petrolpump;
       queue->rear = petrolpump;
       printf("enqueued %d\n",petrolpump->id);
       return;
    }
    queue->rear->next = petrolpump;
    queue->rear = petrolpump;
    printf("enqueued %d\n",petrolpump->id);
}

void dequeue(struct PumpQueue *queue)
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

    struct PetrolPump *temp = queue->front;
    queue->front = queue->front->next;
    printf("dequeued %d\n",temp->id);
    free(temp);
}

struct PumpQueue *createPumpQueue()
{
    struct PumpQueue *pumpqueue = (struct PumpQueue*)malloc(sizeof(struct PumpQueue));
    pumpqueue->front = NULL;
    pumpqueue->rear = NULL;

    return pumpqueue;
}




int peek(struct PumpQueue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
        return INT_MIN;
    }
    return queue->front->id;

}
void display(struct PumpQueue *queue)
{
    int empty = isEmpty(queue);
    if (empty == 1)
    {
       return;
    }
    struct PetrolPump *temp = queue->front;
    while(temp!=queue->rear)
    {
        printf("{%d %d %d}<-",temp->capacity,temp->distance,temp->id);
        temp = temp->next;
    }
    printf("{%d %d %d}\n",temp->capacity,temp->distance,temp->id);
    // free(temp); //it will delete the rear memory

}

int possible(struct PetrolPump *pumpArray,int no_pumps)
{
    struct PumpQueue *pumpqueue;
    pumpqueue = createPumpQueue();

    for(int i = 0 ; i< no_pumps ; i++)
    {
        enqueue(pumpArray[i].capacity,pumpArray[i].distance,pumpArray[i].id,pumpqueue);
    }

    struct PetrolPump *temp = pumpqueue->front;

    int curr_petrol = 0;
    
    while(temp!=pumpqueue->rear)
    {
        display(pumpqueue);
        printf("curr_petrol = %d at ptr %d before filling from origin %d\n" , curr_petrol,temp->id,pumpqueue->front->id );
        curr_petrol += temp->capacity - temp->distance;

        if (curr_petrol>=0)
        {
            temp = temp->next;
            printf("curr_petrol = %d at ptr %d after filling from origin %d\n" , curr_petrol,temp->id,pumpqueue->front->id );
            printf("--------------------------------------------\n");
        }
        else
        {
            printf("curr_petrol = %d at ptr %d after filling from origin %d\n" , curr_petrol,temp->id,pumpqueue->front->id );
            
            // printf("one {%d %d %d}\n",temp->capacity,temp->distance,temp->id);
            struct PetrolPump *temp1 = pumpqueue->front;
            dequeue(pumpqueue);
            enqueue(temp1->capacity,temp1->distance,temp1->id,pumpqueue);
            display(pumpqueue);
            curr_petrol = 0;

            if(pumpqueue->front->id == 1)
            {
                printf("not possible \n");
                return 0;
            }
            printf("--------------------------------------------\n");
        }
        

    }
    if (curr_petrol >= 0)
        return 1;
    else
    {
        printf("not possible \n");
        return 0;
    }
}

int main()
{
    struct PetrolPump pumps[] = {{6, 4, 1}, {3, 6, 2}, {7, 3, 3}, {4, 5, 4}};
    int poss = possible(pumps,4);
    printf("possibility:%d\n",poss);
    return 0;
}