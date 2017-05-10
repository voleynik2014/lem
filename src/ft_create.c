
#include <lem_in.h>

t_lem   *ft_create_room(t_data *data, char *line)
{
	char    **arr;
	t_lem   *room;
    int     i;

    i = -1;
	room = (t_lem *)malloc(sizeof(t_lem));
	ft_bzero(room, sizeof(t_lem));
	arr = ft_strsplit(line, ' ');
		ft_printf("%s",arr[0]);
	room->name = ft_strdup(arr[0]);
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->links = (t_lem **)malloc(sizeof(t_lem *) * 11);
	while (++i < 11)
		room->links[i] = NULL;
//	ft_bzero(room->links, sizeof(t_lem **));
//	room->links[10] = NULL;
    data->count_rooms++;
    return (room);
}
