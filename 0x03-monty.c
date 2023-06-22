#include "monty.h"
/**
 * mod_op - Computes the rest of the division of the second top element by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop_op(stack, line_number);
}
/**
 * pchar_op - Prints the char at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

/**
 * pstr_op - Prints the string starting at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
    {
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}

void rotl_op(stack_t **stack, unsigned int line_number)
{
    stack_t *last;
   (void)line_number; 

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->next = NULL;
    last->next->prev = last;
}

/**
 * rotr_op - Rotates the stack to the bottom.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *last;

    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        last = *stack;

        while (last->next != NULL)
            last = last->next;

        last->next = *stack;
        (*stack)->prev = last;
        *stack = (*stack)->prev;
        (*stack)->prev = NULL;
    }
}

