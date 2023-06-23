#include "monty.h"
/**
 * push - Pushes a value onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function pushes a value onto the stack. It checks if the
 * value is valid and converts it to an integer. The mode determines whether
 * the value is added to the end or the beginning of the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
    int element, index = 0;

    if (value == NULL)
    {
        error_int(line_number);
        exit(EXIT_FAILURE);
    }

    if (value[0] == '-')
        index++;

    for (; value[index]; index++)
    {
        if (value[index] >= '0' && value[index] <= '9')
            continue;

        error_int(line_number);
        exit(EXIT_FAILURE);
    }

    element = atoi(value);

    if (mode == 1)
        add_dnodeint_end(stack, element);
    else
        add_dnodeint(stack, element);
}

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function prints all the elements in the stack from top
 * to bottom.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *traverse;
    (void)line_number;

    if (*stack == NULL || stack == NULL)
        return;

    traverse = *stack;

    while (traverse)
    {
        printf("%d\n", traverse->n);
        traverse = traverse->next;
    }
}

/**
 * pint - Prints the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function prints the value of the top element in the stack.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        error_pint(line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function removes the top element from the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if (*stack == NULL || stack == NULL)
    {
        error_pop(line_number);
        exit(EXIT_FAILURE);
    }

    *stack = temp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

/**
 * swap - Swaps the top two elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function swaps the positions of the top two elements in
 * the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack, *next = NULL;
    int length = dlistint_len(*stack);

    if (length < 2)
    {
        error_swap(line_number);
        exit(EXIT_FAILURE);
    }

    next = (*stack)->next;
    head->prev = next;
    head->next = next->next;
    next->next = head;
    next->prev = NULL;
    *stack = next;
}

