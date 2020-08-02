#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * removeDuplicates(char * S){
    char *stack = (char*)malloc(10*sizeof(char));
    int top = -1;
    for(int i=0;i<strlen(S);i++)
    {
        if(S[i]==stack[top])
            stack[top--] = '\0';
        else
            stack[++top] = S[i];
            
        printf("Now top is %d\n",top);
        printf("top of stack is : %c\n",stack[top]);
        printf("---------------------------\n");
    }
    return stack;
}

int main(){
    printf("%s\n",removeDuplicates("abbaca"));
    return 0;
}