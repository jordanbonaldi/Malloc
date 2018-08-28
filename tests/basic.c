/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "project.h"

Test(misc, little_malloc)
{
	char *test = malloc(4);
	test[0] = 'a';
	test[1] = 'b';
	test[2] = 'c';
	test[3] = 0;
	cr_assert(strlen(test) == 3);
	free(test);
}

Test(misc, negative_malloc)
{
	void *test = malloc(-1);
	cr_assert(test == NULL);
	free(test);
}

Test(misc, impossible_malloc)
{
	void *test = malloc(345678909876545);
	cr_assert(test == NULL);
	free(test);
}

Test(misc, loop_malloc)
{
	char **test = malloc(100);

	for (size_t i = 0; i < 100; i++) {
		test[i] = malloc(11);
		for (size_t j = 0; j < 10; j++) {
			test[i][j] = j + 48;
		}
		test[i][10] = 0;
		cr_assert(strlen(test[i]) == 10);
		free(test[i]);
	}
	free(test);
}

Test(misc, pointer_pos)
{
	void *pos = sbrk(0);
	char *pows = malloc(100);

	free(pows);
	cr_assert(pos != sbrk(0));
}
