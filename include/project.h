/*
** EPITECH PROJECT, 2018
** Main Project.h
** File description:
** Main Project.h
*/

#ifndef H_CHECK
	#define H_CHECK

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

# define ALIGN(x) (((x) + 7) & ~7)
# define PAGE_CALC(x, z) ((z + x - 1) / getpagesize() * \
		getpagesize() + getpagesize())

typedef enum mybool
{
	FALSE = 0,
	TRUE = 1
} mybool;

typedef struct block_s
{
	size_t size;
	mybool isFree;
	struct block_s *next;
	struct block_s *prev;
	void *ptr;
} block_t;

extern const size_t BLOCK_SIZE;
extern const char METADATA_SIZE;
extern block_t *head;
extern pthread_mutex_t locker;

block_t *fusion_blocks(block_t *block);
block_t *get_adress(void *ptr);
mybool can_be_free(void *ptr);
void split_block(block_t *tmp, size_t size);

extern void *realloc(void *ptr, size_t size);
extern void *malloc(size_t size);
extern void *calloc(size_t, size_t);
extern void free(void * ptr);
extern void show_alloc_mem(void);
extern void *reallocf(void *ptr, size_t size);

#endif
