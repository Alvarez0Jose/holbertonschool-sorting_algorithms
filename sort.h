#ifndef SORT_H
#define SORT_H

/* Libraries */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: integer store in the node
 * @prev: pointer to the previous element in the list
 * @next: pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** Prototypes **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

#endif
