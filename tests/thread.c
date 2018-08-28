/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "project.h"
#include <pthread.h>

void *thread_malloc(void *arg)
{
	char **test = malloc(100);

	for (size_t i = 0; i < 100; i++) {
		test[i] = malloc(11);
		for (size_t j = 0; j < 10; j++) {
			test[i][j] = j + 48;
		}
		test[i][10] = 0;
		cr_assert(strlen(test[i]) == 10);
	}
	free(test);
	(void)arg;
	return NULL;
}

Test(misc, thread_malloc)
{
	pthread_t thread1;
	pthread_t thread2;

	cr_assert(!pthread_create(&thread1, NULL,
			thread_malloc, NULL));
	cr_assert(!pthread_create(&thread2, NULL,
			thread_malloc, NULL));
	cr_assert(!pthread_join(thread1, NULL));
	cr_assert(!pthread_join(thread2, NULL));
}
