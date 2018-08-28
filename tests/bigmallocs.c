/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "project.h"

Test(misc, big_malloc)
{
	char *test = malloc(22);

	for (size_t i = 0; i < 21; i++)
		test[i] = 'a' + i;
	test[21] = 0;
	free(test);
	cr_assert(strlen(test) == 21);
	cr_assert(!strcmp(test, "abcdefghijklmnopqrstu"));
}

Test(misc, big_realloc_malloc)
{
	char *test = malloc(22);
	char *anothertest;
	char *newtest;

	for (size_t i = 0; i < 21; i++)
		test[i] = 'a' + i;
	test[21] = 0;
	cr_assert(strlen(test) == 21);
	cr_assert(!strcmp(test, "abcdefghijklmnopqrstu"));

	newtest = realloc(test, 150);
	cr_assert(test != newtest);
	anothertest = realloc(newtest, 22);
	cr_assert(!strcmp(anothertest, "abcdefghijklmnopqrstu"));
	cr_assert(anothertest == newtest);
	free(anothertest);
}

Test(misc, int_tab)
{
	int *tab = malloc(4 * sizeof(int));

	for (size_t i = 0; i < 4; i++) {
		tab[i] = i + 37537;
		cr_assert(tab[i] == (int)(i + 37537));
	}
	free(tab);
}
