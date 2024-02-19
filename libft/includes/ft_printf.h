/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:26 by gabrfern          #+#    #+#             */
/*   Updated: 2023/12/06 15:22:27 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H



int		ft_printf(const char *text, ...);
void	ft_putnbu_r(unsigned int n, int fd, int *result);
void	ft_putnbr_r(int n, int fd, int *result);
void	ft_putstr_r(char *s, int fd, int *result);
void	ft_puthex_r(unsigned long long n, int fd, int prefix, int *result);
void	ft_puthex_upper_r(unsigned long long n, int fd, int *result);
void	ft_putchar_r(char c, int fd, int *result);


#endif
