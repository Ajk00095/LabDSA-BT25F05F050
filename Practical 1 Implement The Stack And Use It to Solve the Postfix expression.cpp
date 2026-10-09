#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    stack[++top] = val;
}

int pop()
{
    if (top == -1)
    {
        printf("Invalid postfix expression\n");
        exit(1);
    }

    return stack[top--];
}

int isEmpty()
{
    return top == -1;
}

int evaluatePostfix(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
    {
        char ch = exp[i];

        if (isspace((unsigned char)ch))
        {
            i++;
            continue;
        }

        if (isdigit((unsigned char)ch))
        {
            int num = 0;

            while (isdigit((unsigned char)exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            continue;
        }
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '^')
        {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch)
            {
                case '+':
                    result = val1 + val2;
                    break;

                case '-':
                    result = val1 - val2;
                    break;

                case '*':
                    result = val1 * val2;
                    break;

                case '/':
                    if (val2 == 0)
                    {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }

                    result = val1 / val2;
                    break;

                case '^':
                    if (val2 < 0)
                    {
                        printf("Error: Negative exponent not supported\n");
                        exit(1);
                    }

                    result = 1;

                    for (int j = 0; j < val2; j++)
                    {
                        result *= val1;
                    }

                    break;

                default:
                    result = 0;
            }

            push(result);
        }
        else
        {
            printf("Invalid character: %c\n", ch);
            exit(1);
        }

        i++;
    }

    if (top != 0)
    {
        printf("Error: Invalid postfix expression\n");
        exit(1);
    }

    return pop();
}

int main()
{
    char exp[MAX];

    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);

    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
