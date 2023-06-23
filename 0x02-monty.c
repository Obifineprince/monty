#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function adds the top two elements of the stack and
 * replaces them with their sum.
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack, *next = NULL;
    int sum, length = dlistint_len(*stack);

    if (length < 2)
    {
        error_add(line_number);
        exit(EXIT_FAILURE);
    }

    next = head->next;
    sum = (*stack)->n + ((*stack)->next)->n;
    next->n = sum;
    *stack = next;
    free(head);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function does nothing and is used as a placeholder.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    (void)stack;
}

/**
 * sub - Subtracts the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function subtracts the top element of the stack from the
 * second top element and replaces them with their difference.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    int diff, length;
    stack_t *temp = *stack;

    length = dlistint_len(*stack);
    if (length < 2)
    {
        error_sub(line_number);
        exit(EXIT_FAILURE);
    }

    diff = (temp->next->n) - (temp->n);
    temp->next->n = diff;
    temp->next->prev = NULL;
    *stack = temp->next;
    free(temp);
}

/**
 * divt - Divides the second top element by the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function divides the second top element of the stack by
 * the top element and replaces them with their quotient.
 */
void divt(stack_t **stack, unsigned int line_number)
{
    int quotient;
    stack_t *temp = *stack;
    int length = dlistint_len(*stack);

    if (length < 2)
    {
        error_div1(line_number);
        exit(EXIT_FAILURE);
    }

    if (temp->n == 0)
    {
        error_div2(line_number);
        exit(EXIT_FAILURE);
    }

    quotient = (temp->next->n) / (temp->n);
    temp->next->n = quotient;
    temp->next->prev = NULL;
    *stack = temp->next;
    free(temp);
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function multiplies the top two elements of the stack and
 * replaces them with their product.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    int product;
    stack_t *tmp = *stack;
    int length = dlistint_len(*stack);

    if (length < 2)
    {
        error_mul(line_number);
        exit(EXIT_FAILURE);
    }

    product = (tmp->n) * (tmp->next->n);
    tmp->next->n = product;
    tmp->next->prev = NULL;
    *stack = tmp->next;
    free(tmp);
}
