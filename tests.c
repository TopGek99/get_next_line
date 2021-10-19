#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void	clean_output(char *output)
{
	char	*new_line = ft_strchr(output, '\n');
	if (new_line)
	{
		*new_line = '\\';
		*(new_line+1) = 'n';
	}
}

int main(void)
{
	int fd = open("gnlTester/files/empty", O_RDWR);
	char *output = get_next_line(1000);
	printf("\033[0;32m\nINVALID FD TESTS:\033[0m \n\ngnl output: %s\nexpected output: (null)\n\n", output);
	output = get_next_line(-1);
	printf("gnl output: %s\nexpected output: (null)\n\n", output);
	output = get_next_line(fd);
	printf("gnl output: %s\nexpected output: (null)\n\n", output);

	fd = open("gnlTester/files/empty", O_RDWR);
	output = get_next_line(fd);
	printf("\033[0;32mEMPTY FILE TESTS:\033[0m \n\ngnl output: %s\nexpected output: (null)\n\n", output);
	output = get_next_line(fd);
	printf("gnl output: %s\nexpected output: (null)\n\n", output);

	fd = open("gnlTester/files/nl", O_RDWR);
	output = get_next_line(fd);
	if (!strcmp(output,"\n"))
		printf("works");
	// printf("\033[0;32mNEW LINE TESTS:\033[0m \n\ngnl output: %s\nexpected output: \\n\n\n", output);
	// output = get_next_line(fd);
	// printf("gnl output: %s\nexpected output: (null)\n\n", output);
}