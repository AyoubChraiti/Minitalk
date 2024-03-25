# include "header.h"

void charToBinary(char c, int pid)
{
	int i = 0;
    for (i = 7; i >= 0; i--)
	{
        if (((c >> i) & 1) == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
	{
        printf("Usage: %s %s<PID of Server> <Message>\n", av[0], BLUE);
        return 1;
    }
    int pid = atoi(av[1]);
	if (kill(pid, 0) == -1)
	{
		printf("%sSERVER NOT FOUND\n", RED);
	}
    int i = 0;
    while (av[2][i])
	{
        charToBinary(av[2][i], pid);
		if (av[2][i + 1] == '\0')
			charToBinary('\n', pid);
        i++;
    }
    return (0);
}
