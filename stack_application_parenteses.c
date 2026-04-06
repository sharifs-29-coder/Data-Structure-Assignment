#include<stdio.h>
#include<string.h>

#define max 50   //macro definition

//global declaration 

int stack[max];    //this array stores the brackets 
 
int top = -1;    // 'top' keeps track of the top element of stack


// -------------------- PUSH FUNCTION --------------------
// This function inserts an element into the stack

void push(char ch)
{
    // Check for stack overflow

    if(top == max -1)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

// -------------------- POP FUNCTION --------------------
// This function removes and returns top element from stack

char pop()
{
    char pop_expression;

    pop_expression = stack[top];

    top--;

    return pop_expression;

}


// -------------------- MATCHING FUNCTION --------------------
// This function checks whether opening and closing brackets match

int ismatching(char left,char right)
{
    if(left == '(' && right == ')')
    {
        return 1;
    }
    else if(left == '[' && right == ']')
    {
        return 1;
    }
    else if(left == '{' && right == '}')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}


int main()
{
    char arr[50];  //this array stores the user input
    printf("enter the expression\n");                      //*  NOTE:
       scanf("%s",arr);                                                              // We do NOT use '&' here because 'exp' is an array.
                                                                // In C, the array name itself represents the address of its first element.
                                                                // So 'exp' is same as '&exp[0]'.
                                                                // But for normal variables or array elements (like arr[i]), we must use '&'
                                                             // because they store values, not addresses.*/ 


                    // Traverse each character of the expression
for(int i = 0; i< strlen(arr); i++)
    {
        if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
        {
              // If opening bracket, push into stack

            push(arr[i]);
        }

        else if(arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
               // If stack is empty → no matching opening bracket
            if(top == -1)
            {
                printf("invalid expressiong (stack is empty)\n");
                return 0;
            }
            else
            {
                char popped = pop();
                 // Check if popped bracket matches current bracket

                if(ismatching(popped,arr[i]) != 1)
                {
                    printf("Invalid expression (brackets does not match)\n");
                    return 0;
                }
            }
        }
    } 
    
    if(top == -1)
    {
        printf("valid expression\n");
    }
    else
    {

               // If stack still has elements → some brackets not closed
        printf("invalid expression (unclosed brackets)\n");
    }

    return 0;
}