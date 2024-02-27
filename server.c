
# include "libft/includes/libft.h"
# include <signal.h>


void sig_handler(int signum)
  {
	static int	oct;
	static char	bin;

	if (!bin)
		bin = 0;
	if (!oct)
		oct = 0;
	if (signum == SIGUSR1)
		bin += (128 >> oct);
	oct++;
	if (oct == 8)
	{
		ft_printf("response %c\n", bin);
		bin = 0;
		oct = 0;
	}
	ft_printf("bin is %d - oct is : %d\n", bin, oct);
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
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	
	while(1)
		pause();

	/* Program will terminate with a SIGUSR2 */
  }

