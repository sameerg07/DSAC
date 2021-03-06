// You're now a baseball game point recorder.

// Given a list of strings, each string can be one of the 4 following types:

// Integer (one round's score): Directly represents the number of points you get in this round.
// "-100" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
// "-200" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
// "-300" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
// Each round's operation is permanent and could have an impact on the round before and the round after.

// You need to return the sum of the points you could get in all the rounds.

// Example 1:
// Input: [5,2,-300,-200,-100]
// Output: 30
// Explanation: 
// Round 1: You could get 5 points. The sum is: 5.
// Round 2: You could get 2 points. The sum is: 7.
// Operation 1: The round 2's data was invalid. The sum is: 5.  
// Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
// Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
// Example 2:
// Input: [5,-2,4,-300,-200,9,-100,-100]
// Output: 27
// Explanation: 
// Round 1: You could get 5 points. The sum is: 5.
// Round 2: You could get -2 points. The sum is: 3.
// Round 3: You could get 4 points. The sum is: 7.
// Operation 1: The round 3's data is invalid. The sum is: 3.  
// Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
// Round 5: You could get 9 points. The sum is: 8.
// Round 6: You could get -4 + 9 = 5 points. The sum is 13.
// Round 7: You could get 9 + 5 = 14 points. The sum is 27.



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stack{
    int top;
    int size;
    int *stk;
};

struct Stack *CreateStack(int size){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->stk = (int*)malloc(sizeof(int)*size);
    return stack;
}

int pop(struct Stack *stack){
    return stack->stk[(stack->top)--];
}

void push(int data,struct Stack *stack){
    stack->stk[++(stack->top)] = data;
}

void display(struct Stack *stk)
{
    printf("printing the stack ..... \n");
    if (stk->top == -1)
    {
        printf("stack is empty\n");
        printf("----------------------\n");
        return;
    }
    for(int j = stk->top;j>-1; j--)
    {
        printf("%d\n",stk->stk[j]);
    }
    printf("----------------------\n");
}

int calPoints(int *ops, int opsSize){
    // printf("%c",ops[0][0]);
    int sum = 0;
    struct Stack *stack = CreateStack(opsSize);
    for(int i=0 ; i<opsSize ; i++)
    {
        display(stack);
        if(ops[i] == -100){
            int ele = stack->stk[stack->top] + stack->stk[(stack->top)-1];
            push(ele,stack);
            sum = sum + ele;
        }
        else
            if(ops[i] == -200){
                int ele = 2*stack->stk[stack->top];
                push(ele,stack);
                sum = sum + ele;
            }
            else
                if(ops[i] == -300){
                    int ele = pop(stack);
                    sum = sum - ele;
                }
                else
                {
                    int ele = ops[i];
                    push(ele,stack);
                    sum = sum + ele;
                    
                }
        printf("sum is: %d\n",sum);
    }
    return sum;
}

int main()
{
    int arr[5] = {5,2,-300,-200,-100};
    printf("%d\n",calPoints(arr,5));
    return 0;
}