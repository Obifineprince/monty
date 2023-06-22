#include "monty.h"

/**
 * free_dlistint - releases a doubly linked list
 * @head: pointer to the head of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: double pointer to the head of the list
 * @n: data for the new node
 * Return: address of the new element, or NULL if it fails
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp = malloc(sizeof(stack_t));

	if (tmp == NULL)
	{
		error_malloc();
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
		return (NULL);

	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = NULL;

	if (*head != NULL)
	{
		tmp->next = *head;
		(*head)->prev = tmp;
	}

	*head = tmp;

	return (*head);
}

/**
 * dlistint_len - returns the number of nodes in a linked list
 * @h: pointer to the doubly linked list
 * Return: number of nodes
 */
size_t dlistint_len(const stack_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: double pointer to the head of the doubly linked list
 * @n: data for the new node
 * Return: address of the new node, or NULL if it fails
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = malloc(sizeof(stack_t));
	stack_t *end = *head;

	if (tmp == NULL)
	{
		error_malloc();
		exit(EXIT_FAILURE);
	}

	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = NULL;

	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}

	while (end->next != NULL)
		end = end->next;
	end->next = tmp;
	tmp->prev = end;

	return (tmp);
}

/**
 * get_dnodeint_at_index - returns
 * the nth node of a doubly linked list
 * @head: pointer to the head of the list
 * @index: index of the node
 * Return: nth node or NULL if the node does not exist
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (count < index)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
		count++;
	}
	return (head);
}
