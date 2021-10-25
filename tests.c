#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char *str = malloc(sizeof(char) * 42);
    int fd = open("./gnlTester/files/nl", O_RDWR);
	int read_result = read(fd, str, 42);

    printf("returns %d\n%s", read_result, str);
    read_result = read(fd, str, 42);
    printf("returns %d\n%s", read_result, str);
}