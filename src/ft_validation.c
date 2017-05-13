#include "lem_in.h"

int		check_valid_count_ants(char *line)
{
	int i;

	i = -1;
	if (!line || !*line)
	{
		free(line);
		exit(ft_printf("Invalid input\n") - 14);
	}
	while (line[++i])
		if (!ft_isdigit(line[i])) {
			exit(ft_printf("Invalid number\n") - 15);
		}
	return (TRUE);
}