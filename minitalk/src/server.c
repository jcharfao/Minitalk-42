/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharfao <jcharfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:45:54 by jcharfao          #+#    #+#             */
/*   Updated: 2024/11/06 05:33:56 by jcharfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

static char current_bit = 0;
static int bit_count = 0;

void handler(int sig)
{
	if (sig == SIGUSR1)
		current_bit &= ~(1 << (7 -bit_count));
	else if(sig == SIGUSR2)
		current_bit |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_bit,1);
		bit_count = 0;
		current_bit = 0;
	}
}

int main()
{
	int pid = getpid();
	printf("The Server PID is: %d\n", pid);
	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	
	while(1)
		pause();
	return 0;
}