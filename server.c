
# include "libft/includes/libft.h"
# include <signal.h>

char	to_char(int signum)
{
	static int	oct;
	static int	bin;

	bin = 0;
	oct = 7;
	if(oct >= 0)
	{

		if (signum == SIGUSR1)
			bin =+ bin >> oct | 1;
		oct--;
	}
	else
	{
		oct = 7;
		ft_printf("response %c\n", bin);
	}
	ft_printf("bin is %d - oct is : %d\n", bin, oct);

}

void sig_handler(int signal_number)
  {
	char response;

	response = to_char(signal_number);
	ft_printf("response: %c\n", response);
	// (void)info;
	// (void)context;

  }


int main( void )
  {

	struct sigaction sa;
	// sigset_t set;

	// sigemptyset( &set );
	// sigaddset( &set, SIGUSR1);

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_handler = sig_handler;
	ft_printf("server initialized! pid: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();

	/* Program will terminate with a SIGUSR2 */
  }

