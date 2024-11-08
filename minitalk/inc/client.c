/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharfao <jcharfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:48:44 by jcharfao          #+#    #+#             */
/*   Updated: 2024/11/06 05:35:55 by jcharfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void send_bit(int pid, char c, int bit_count)
{
	if (c & (1 << (7 - bit_count)))
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
	else
	{
		if(kill(pid, SIGUSR1) == -1)
			exit(1);
	}
	usleep(100);
}

void send_message(int pid, char *message)
{
	int i = 0;
	int bit_count;
	
	while(message[i])
	{
		bit_count = 0;
		while(bit_count < 8)
		{
			send_bit(pid, message[i], bit_count);
			bit_count++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc !=3)
	{
		printf("Error. Uso: ./client <server pid> <message to send\n");
		return (1);
	}
	int server_pid = atoi(argv[1]);
	if(server_pid <= 0)
	{
		printf("PID Invalido\n");
		return (1);
	}
	char *message = argv[2];

	send_message(server_pid, message);
	printf("El mensaje se envio correctamente!!\n");
	return (0);
}