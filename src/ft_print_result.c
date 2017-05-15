#include <lem_in.h>

void	ft_print_rooms(t_way *res_way)
{
	int i;

	i = -1;
	while (res_way->room[++i])
		ft_printf("-%s", res_way->room[i]->name);
	while (++i < 10)
		ft_printf("  ");
	ft_printf(" --> ");
	ft_printf("%d - %d\n", res_way->id, res_way->performance);
}