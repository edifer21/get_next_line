/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 12:49:57 by patferna          #+#    #+#             */
/*   Updated: 2024-11-20 12:49:57 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_KINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include "get_next_line.h"

int		ft_printf(char const *word, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_hex(unsigned long n);
int		ft_putnbr_hex_m(unsigned long n);

#endif