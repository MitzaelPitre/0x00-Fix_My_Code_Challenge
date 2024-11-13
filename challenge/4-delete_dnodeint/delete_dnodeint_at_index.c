#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int p = 0;

    if (*head == NULL) // Verifica si la lista está vacía
        return (-1);

    // Navega hasta el nodo en la posición `index`
    while (p < index && current != NULL)
    {
        current = current->next;
        p++;
    }

    // Si no existe un nodo en `index`
    if (current == NULL)
        return (-1);

    // Si estamos eliminando la cabeza de la lista
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL) // Si hay un nodo después de la cabeza
            (*head)->prev = NULL;
    }
    else
    {
        // Conectar el nodo previo al siguiente
        if (current->prev != NULL)
            current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}

