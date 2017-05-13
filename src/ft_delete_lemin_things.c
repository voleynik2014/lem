#include "lem_in.h"

void	ft_delete_room(t_lem *current_room)
{
	free(current_room);
}

void	ft_delete_way(t_way **current_way)
{
	free(current_way);
}

void	ft_delete_flow(t_flow **current_flow)
{
	free(current_flow);
}