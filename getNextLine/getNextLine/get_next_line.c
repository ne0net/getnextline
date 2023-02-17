 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranzgr <nfranzgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:45:13 by nfranzgr          #+#    #+#             */
/*   Updated: 2023/02/15 14:36:58 by nfranzgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char buf[30];
	static char * stbuf = NULL;
	ssize_t nr_bytes;
	char *line = (char *) malloc (10000);
	int cnt;
	int cnt_a;
	char p = 'l';
	cnt = 0;
	if (fd == -1)
		printf("error al abrir el archivo \n");
	else
	{
		cnt_a = 0;
		if (stbuf != NULL)
		{
			while(stbuf[cnt_a] != '\n')
			cnt_a++;
		}
			
		 while (stbuf == NULL || stbuf[cnt_a] != '\n')
		 {
			nr_bytes = read(fd, buf, 9);
			stbuf = buf;
			if (stbuf != NULL)
			{
				cnt_a = 0;
				while(stbuf[cnt_a] != '\n' && stbuf[cnt_a])
				cnt_a++;
			}
		}
		
		if (nr_bytes == 0)
			printf("Archivo vacio!");
		else
		{

			cnt_a = 0;
			while(p != '\n')
			{
				line[cnt_a] = stbuf[cnt_a];
				p = stbuf[cnt_a];
				cnt_a++;
				cnt++;
			}
			printf("el numero de caracteres leidos es %d , contenido %s \n", (int)nr_bytes, buf);
			cnt_a --;
			line[cnt_a] = '\0';
				cnt = 0;
			while (stbuf[cnt])
			{
				stbuf[cnt] = stbuf[cnt_a + 1];
				cnt++;
				cnt_a++;
			}
			printf("linea %s", line);
		}
	}

	printf("nuevo stbuf %s", stbuf);
	return(line);
}

int main (void)
{
	int fd;
	fd = open("archivo.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return(0);
}
