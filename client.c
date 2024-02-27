#include "libft/includes/libft.h"
#include <signal.h>


void	to_bin(char *pid, char *message)
{
	int	pid_n;
	int	i;
	char c;

	c = message[0];
	i = 7;
	pid_n = ft_atoi(pid);

	while(i >= 0 )
	{
		if ((c >> i) & 1 )
			kill(pid_n, SIGUSR1);
		else
			kill(pid_n, SIGUSR2);
		ft_printf("processing %d\n", (c >> i & 1));
		i--;
		usleep(500);
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
