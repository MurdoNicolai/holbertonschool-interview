#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"

/**
 * is_valid_input - Check if the input string is composed of digits
 *
 * @num_str: Input string
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_input(char *num_str)
{
	int i = 0;

	while (num_str[i] != '\0')
	{
	if (num_str[i] < '0' || num_str[i] > '9')
	{
	return (0);
	}
	i++;
	}
	return (1);
}

/**
 * multiply - Multiply two numbers represented as strings
 *
 * @num1: First number
 * @num2: Second number
 *
 * Return: Result of multiplication as a dynamically allocated string
 */
char *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int result_len = len1 + len2;


	char *result = (char *)calloc(result_len + 1, sizeof(char));

	if (result == NULL)
	{
	printf("Memory allocation failed\n");
	exit(EXIT_FAILURE);
	}

	for (int i = len1 - 1; i >= 0; i--)
	{
	for (int j = len2 - 1; j >= 0; j--)
	{
	int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];

	result[i + j + 1] = product % 10;
	result[i + j] += product / 10;
	}
	}
	int i;

	for (i = 0; i < result_len; i++)

	result[i] += '0';

	i = 0;

	while (result[i] == '0' && result[i + 1] != '\0')
	i++;

	for (int j = 0; i + j <= result_len; j++)
	result[j] = result[i + j];

	return (result);
}

/**
 * print_number - Print a number represented as a string
 *
 * @num_str: Input string representing a number
 */
void print_number(char *num_str)
{
	int i = 0;

	while (num_str[i] == '0' && num_str[i + 1] != '\0')
	i++;

	while (num_str[i] != '\0')
	{
	_putchar(num_str[i]);
		i++;
	}

	if (i == 0)
	_putchar('0');
}

/**
 * main - Entry point
 *
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 or 98 if error
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
	{
	printf("Error\n");
	return (98);
	}

	char *num1 = argv[1];
	char *num2 = argv[2];

	if (!(is_valid_input(num1) && is_valid_input(num2)))
	{
	printf("Error\n");
	return (98);
	}

	result = multiply(num1, num2);

	print_number(result);
	_putchar('\n');

	free(result);

	return (0);
}


