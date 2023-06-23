#include "monty.h"
/**
 * mod - Calculates the remainder of the division of the second top 
 * element by the top element.
 * @stack: Pointer to the stack elements
 * @line_number: Line number.
 *
 * Description: This func calculates the remainder of the division of the second top element by
 * the top element and replaces them with their result.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    int remainder;
    stack_t *tmp = *stack;
    int length = dlistint_len(*stack);

    if (length < 2)
    {
        error_modu(line_number);
        exit(EXIT_FAILURE);
    }

    if (tmp->n == 0)
    {
        error_div2(line_number);
        exit(EXIT_FAILURE);
    }

    remainder = (tmp->next->n) % (tmp->n);
    tmp->next->n = remainder;
    tmp->next->prev = NULL;
    *stack = tmp->next;
    free(tmp);
}

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function prints the character at the top of the stack.
 * The top element of the stack should represent an ASCII value.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!(*stack))
    {
        error_pchar2(line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        errchar(line_number);
        exit(EXIT_FAILURE);
    }

    putchar((*stack)->n);
    putchar(10);
}

/**
 * pstr - Prints the string starting from the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function prints the string starting from the top of the stack.
 * The elements of the stack should represent ASCII values of characters, and the
 * string is printed until a non-printable character or the end of the stack is reached.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *traverse = *stack;
    (void)line_number;

    while (traverse && traverse->n > 0 && traverse->n < 127)
    {
        putchar(traverse->n);
        traverse = traverse->next;
    }

    putchar(10);
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function rotates the stack, moving the second element to the top.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;
    *stack = tmp->next;
    (*stack)->prev = NULL;
    add_dnodeint_end(stack, tmp->n);
    free(tmp);
}

/**
 * rotr - Rotates the stack to the last element.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Description: This function rotates the stack, moving the last element to the top.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = get_dnodeint_at_index(*stack, dlistint_len(*stack) - 1);
    add_dnodeint(stack, tmp->n);
    delete_dnodeint_at_index(stack, dlistint_len(*stack) - 1);
}
