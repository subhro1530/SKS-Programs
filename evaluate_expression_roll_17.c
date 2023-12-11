/*
Program 4:
Take a sufficiently long arithmetic expression with +,-,*,/,^ operators including parenthesis. Evaluate the expression.
Problem Statement:
Develop a program to evaluate a complex arithmetic expression, accommodating basic operators such as addition, subtraction, multiplication, and division, as well as exponentiation and parentheses. The program should correctly parse and execute the expression, adhering to standard mathematical precedence rules and handling lengthy input expressions.
Algorithm:
1.	Store the expression from the user in a string variable
2.	Loop through the expression characters and check for the operators and return the result of the respective operation in integer format.
3.	Process the expression characters from right to left so that the precedence rule is followed.
4.	If opening bracket is found store the strings after it in a variable until close bracket is encountered.
5.	Perform step 4 for every sub bracket inside parent bracket.4
6.	For each string, according to the operators present, first perform power operation (if present) , then multiplication/division and in the end add/sub.
7.	Store the results of individual operations in a variable and perform step 6 .
8.	Print the final result
9.	Exit from the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct
{
    char operator;
    int precedence;
} Operator;

int apply_operator(char operator, int left, int right)
{
    switch (operator)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    case '^':
        return pow(left, right);
    default:
        return 0; // Invalid operator
    }
}

int evaluate_expression(const char *expression)
{
    Operator operators[] = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

    char operators_stack[MAX_EXPRESSION_LENGTH];
    int values_stack[MAX_EXPRESSION_LENGTH];
    int operators_top = -1;
    int values_top = -1;
    int i = 0;

    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]))
        {
            char *end;
            int value = strtol(&expression[i], &end, 10);
            values_stack[++values_top] = value;
            i = end - expression;
        }
        else if (expression[i] == '(')
        {
            operators_stack[++operators_top] = expression[i];
            i++;
        }
        else if (expression[i] == ')')
        {
            while (operators_top >= 0 && operators_stack[operators_top] != '(')
            {
                char operator= operators_stack[operators_top--];
                int right = values_stack[values_top--];
                int left = values_stack[values_top--];
                values_stack[++values_top] = apply_operator(operator, left, right);
            }
            operators_top--; // Pop '('
            i++;
        }
        else if (strchr("+-*/^", expression[i]) != NULL)
        {
            while (operators_top >= 0 &&
                   strchr("+-*/^", operators_stack[operators_top]) != NULL &&
                   operators[operators_stack[operators_top] - '+'].precedence >= operators[expression[i] - '+'].precedence)
            {
                char operator= operators_stack[operators_top--];
                int right = values_stack[values_top--];
                int left = values_stack[values_top--];
                values_stack[++values_top] = apply_operator(operator, left, right);
            }
            operators_stack[++operators_top] = expression[i];
            i++;
        }
        else
        {
            i++; // Skip other characters
        }
    }

    while (operators_top >= 0)
    {
        char operator= operators_stack[operators_top--];
        int right = values_stack[values_top--];
        int left = values_stack[values_top--];
        values_stack[++values_top] = apply_operator(operator, left, right);
    }

    return values_stack[values_top];
}

int main()
{
    char expression[MAX_EXPRESSION_LENGTH];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character from the end of the expression
    if (expression[strlen(expression) - 1] == '\n')
    {
        expression[strlen(expression) - 1] = '\0';
    }

    int result = evaluate_expression(expression);

    printf("Result: %d\n", result);

    return 0;
}
