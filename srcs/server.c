/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:46:33 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/16 21:46:37 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/server.h"

void sig_handler(int signum)
{
	static int	oct;
	static char	bin;

	if (!bin)
		bin = 0;
	if (!oct)
		oct = 0;
	//Entender melhor essa sentença abaixo
	if (signum == SIGUSR1)
		bin += (128 >> oct);
	oct++;
	if (oct == 8)
	{
		ft_printf("%c", bin);
		bin = 0;
		oct = 0;
	}
}


int main( void )
  {

	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sig_handler;


	ft_printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	ft_printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
	ft_printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	ft_printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
	ft_printf("--------------------server is listening!--------------------\n");
	ft_printf("\e[1;92mPID: %d\n", getpid());





	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);

	while(1)
		pause();
  }

