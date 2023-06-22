#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 * @value: Value to push to the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *value = value;

	char *endptr;

	int element;

    if (value == NULL)
    {
        error_int(line_number);
        exit(EXIT_FAILURE);
    }


    element = strtol(value, &endptr, 10);
    if (*endptr != '\0')
    {
        error_int(line_number);
        exit(EXIT_FAILURE);
    }

    if (mode == 1)
    {
        add_dnodeint_end(stack, element);
    }
    else
    {
        add_dnodeint(stack, element);
    }
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop_op - Removes the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;


    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack) ->n;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
