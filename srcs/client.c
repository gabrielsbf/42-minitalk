#include "../includes/client.h"

void	to_bin(char *pid, char *message)
{
	int	pid_n;
	int	i;
	int c;

	c = 0;
	i = 7;
	pid_n = ft_atoi(pid);

	while(message[c] != '\0')
	{
		while(i >= 0 )
		{
			if ((message[c] >> i) & 1 )
				kill(pid_n, SIGUSR1);
			else
				kill(pid_n, SIGUSR2);
			i--;
			usleep(250);
		}
		i = 7;
		c++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		to_bin(argv[1], argv[2]);
	}
	else
		return (0);

}
