#include "monty.h"

/**
*main - main function of the monty programme
*@argc: number of command-line arguments
*@argv: array of command-line argument strings
*Return: EXIT_SUCCES or EXIT_FAILURE
*/

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "Usage: monty file\n");
return (EXIT_FAILURE);
}
FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

stack_t *stack = NULL;
char *line = NULL;
size_t line_size = 0;
unsigned int line_number = 1;

while (getline(&line, &line_size, file) != -1)
{
char *opcode = strtok(line, " \t\n");
if (opcode != NULL && strcmp(opcode, "push") == 0)
{
push_element(&stack, line_number);
}
else if (opcode != NULL && strcmp(opcode, "pall") == 0)
{
pall_elements(&stack, line_number);
}
else if (opcode != NULL && strcmp(opcode, "pint") == 0)
{
pint(&stack, line_number);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
free(line);
fclose(file);
return (EXIT_FAILURE);
}
line_number++;
}
free_stack(&stack);
free(line);
fclose(file);
return (EXIT_SUCCESS);
}
