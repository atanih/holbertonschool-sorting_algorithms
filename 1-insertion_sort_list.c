#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order using insertion sort
* @list: Double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
while (current->prev != NULL && current->n < current->prev->n)
{
temp = current->prev;

if (temp->prev != NULL)
temp->prev->next = current;
else
*list = current;

if (current->next != NULL)
current->next->prev = temp;

temp->next = current->next;
current->prev = temp->prev;
current->next = temp;
temp->prev = current;

print_list(*list);
}
current = current->next;
}
}
