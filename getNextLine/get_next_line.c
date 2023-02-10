/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranzgr <nfranzgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:45:13 by nfranzgr          #+#    #+#             */
/*   Updated: 2023/01/26 20:03:54 by nfranzgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char buf[30];
	static char * stbuf = null;
	ssize_t nr_bytes;
	int cnt;
	
	cnt = 0;
	if (fd == -1)
		printf("error al abrir el archivo \n");
	else
	{
		nr_bytes = read(fd, buf, 30);
		stbuf = buf;
		
		if (nr_bytes == 0)
			printf("Archivo vacio!");
		else
		{
			while (stbuf[cnt] == '\n')
				cnt++;
			stbuf[cnt] = '\n';
			printf("el numero de caracteres leidos es %d , contenido %s \n", (int)nr_bytes, buf);
		}
		cnt++;
		stbuf[cnt] = '\0';
	}
	printf("este es el verdadero %s", stbuf);
	return(stbuf);
}

int main (void)
{
	int fd;
	fd = open("archivo.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return(0);
}
https://www.youtube.com/watch?v=-Mt2FdJjVno&ab_channel=nikito