# include "header.h"

char buff[8];
int i = 0;

void charFromBinary()
{
    int ascii = 0;
    for (int j = 0; j < 8; j++)
    {
        ascii = ascii << 1;
        if (buff[j] == '1')
            ascii += 1;
    }
    printf("%c", (char)ascii);
    fflush(stdout);
    i = 0;
}

void sigusr1_handler(int sig)
{
    buff[i++] = '0';
    if (i == 8)
        charFromBinary();
}

void sigusr2_handler(int sig)
{
    buff[i++] = '1';
    if (i == 8)
        charFromBinary();
}

int main(void)
{
    printf("%sSERVER PID: %s%d\n",GREEN, WHITE, getpid());
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    while (1)
    {
        pause();
    }
    return 0;
}
