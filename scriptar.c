/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:35:57 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/20 08:50:42 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void	map00(void)
{
	int		fd;
	int		i;
	int 	score;
	char    buf[4097];

	i = 0;
	score = 0;
	printf("|--------------------------|\n");
	printf("|          MAP 00          |\n");
	printf("|--------------------------|\n");
	printf("%-12s VS    %-12s :", "cbarbier", "abanlin");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 ./cbarbier.filler -p2 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "carli");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 ./cbarbier.filler -p2 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "champely");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 ./cbarbier.filler -p2 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "grati");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 ./cbarbier.filler -p2 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "hcao");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 ./cbarbier.filler -p2 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "superjeannot");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 ./cbarbier.filler -p2 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "abanlin", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 ./cbarbier.filler -p1 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "carli", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 ./cbarbier.filler -p1 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "champely", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 ./cbarbier.filler -p1 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "grati", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 ./cbarbier.filler -p1 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "hcao", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 ./cbarbier.filler -p1 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "superjeannot", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 ./cbarbier.filler -p1 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
}


void	map01(void)
{
	int		fd;
	int		i;
	int 	score;
	char    buf[4097];

	i = 0;
	score = 0;
	printf("|--------------------------|\n");
	printf("|          MAP 01          |\n");
	printf("|--------------------------|\n");
	printf("%-12s VS    %-12s :", "cbarbier", "abanlin");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 ./cbarbier.filler -p2 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "carli");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 ./cbarbier.filler -p2 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "champely");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 ./cbarbier.filler -p2 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "grati");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 ./cbarbier.filler -p2 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "hcao");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 ./cbarbier.filler -p2 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "superjeannot");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 ./cbarbier.filler -p2 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "abanlin", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 ./cbarbier.filler -p1 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "carli", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 ./cbarbier.filler -p1 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "champely", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 ./cbarbier.filler -p1 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "grati", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 ./cbarbier.filler -p1 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "hcao", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 ./cbarbier.filler -p1 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "superjeannot", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 ./cbarbier.filler -p1 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
}

void	map02(void)
{
	int		fd;
	int		i;
	int 	score;
	char    buf[4097];

	i = 0;
	score = 0;
	printf("|--------------------------|\n");
	printf("|          MAP 02          |\n");
	printf("|--------------------------|\n");
	printf("%-12s VS    %-12s :", "cbarbier", "abanlin");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 ./cbarbier.filler -p2 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "carli");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 ./cbarbier.filler -p2 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "champely");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 ./cbarbier.filler -p2 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "grati");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 ./cbarbier.filler -p2 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "hcao");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 ./cbarbier.filler -p2 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "cbarbier", "superjeannot");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 ./cbarbier.filler -p2 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "abanlin", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 ./cbarbier.filler -p1 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "carli", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 ./cbarbier.filler -p1 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "champely", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 ./cbarbier.filler -p1 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "grati", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 ./cbarbier.filler -p1 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "hcao", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 ./cbarbier.filler -p1 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "superjeannot", "cbarbier");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 ./cbarbier.filler -p1 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "cbarbier"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
}

int	main(void)
{
	printf("------------------------\n");
	printf("FILLER ANALYSIS SCRIPT :\n");
	printf("------------------------\n");
	printf("Each map will be played,\nPlayer will play in both position,\nIf more than 3/5 victories,\n WIN otherwise LOOSE\n   GOOD LUCK\n");
	map00();
	map01();
	map02();
	return (0);
}
