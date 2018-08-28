/*
** EPITECH PROJECT, 2018
** Main
** File description:
** Main
*/

#include "project.h"

block_t *head = NULL;
const size_t BLOCK_SIZE = sizeof(block_t);
const char METADATA_SIZE = 1;
pthread_mutex_t locker = PTHREAD_MUTEX_INITIALIZER;

static block_t *extend_heap(block_t *last, size_t size)
{
	block_t *tmp;

	tmp = sbrk(0);
	if (sbrk(PAGE_CALC(size, BLOCK_SIZE)) == ((void *) - 1))
		return (NULL);
	tmp->next = NULL;
	tmp->size = size;
	tmp->prev = last;
	tmp->ptr = tmp + METADATA_SIZE;
	tmp->isFree = FALSE;
	if (last)
		last->next = tmp;
	return (tmp);
}

static block_t *find_block(block_t **last, size_t size)
{
	block_t *tmp = head;

	while (tmp)
	{
		if (tmp->isFree && tmp->size >= size)
			return tmp;
		*last = tmp;
		tmp = tmp->next;
	}
	return tmp;
}

void split_block(block_t *tmp, size_t size)
{
	block_t *new;

	new = (block_t *) (((char *) tmp) + size + BLOCK_SIZE);
	new->size = tmp->size - size - BLOCK_SIZE;
	new->next = tmp->next;
	new->prev = tmp;
	new->ptr = new + METADATA_SIZE;
	new->isFree = TRUE;
	tmp->size = size;
	tmp->next = new;
	if (new->next)
		new->next->prev = new;
}

static void *add_block(int size)
{
	block_t *tmp;
	block_t *tail;

	tail = head;
	tmp = find_block(&tail, size);
	if (!tmp)
		tmp = extend_heap(tail, size);
	else
	{
		if (tmp->size >= size + BLOCK_SIZE)
			split_block(tmp, size);
		tmp->isFree = FALSE;
	}
	pthread_mutex_unlock(&locker);
	return (!tmp ? NULL : tmp + METADATA_SIZE);
}

void *malloc(size_t s)
{
	size_t size = ALIGN(s);

	if ((int)size <= 0)
		return NULL;
	pthread_mutex_lock(&locker);
	if (head)
		return add_block(size);
	else
	{
		head = extend_heap(NULL, size);
		pthread_mutex_unlock(&locker);
		return (!head ? NULL : head + METADATA_SIZE);
	}
}
