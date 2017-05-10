
#include "lem_in.h"


t_lem	*ft_search_room(t_data *data, char *source)
{
	int	i;

	i = -1;
	while (data->rooms[++i]->name)
		if (ft_strequ(data->rooms[i]->name, source))
			return (data->rooms[i]);
	ft_printf("Don`t find a room(");
	return (0);
}

void	ft_read_links(t_data *data)
{
	char	**tmp;
	char 	*line;
	t_lem	*room1;
	t_lem	*room2;
	int		i;

	while (get_next_line(data->fd, &line))
	{
        if ((line[0] == '#' && line[1] != '#') || !line)
            ft_strdel(&line);
        else if (!*line)
            break ;
        else
        {
            tmp = ft_strsplit(line, '-');
            room1 = ft_search_room(data, tmp[0]);
			room2 = ft_search_room(data, tmp[1]);
            i = -1;
            while (room1->links[++i]);
            room1->links[i] = room2;  // in a future check if length og link will more then 10 and check names for repeats
			i = -1;
			while (room2->links[++i]);
			room2->links[i] = room1;
        }
    }
}

int		ft_read_line(t_data *data, char *line)
{
	int i;

	i = 0;
	while (get_next_line(data->fd, &line))
	{
		if ((line[0] == '#' && line[1] != '#') || !line)
			ft_strdel(&line);
		else if (ft_strequ(line, "##end"))
		{
			get_next_line(data->fd, &line);
			data->rooms[i] = ft_create_room(data, line);
			ft_read_links(data);
			break ;
		}
		else
			data->rooms[i++] = ft_create_room(data, line);
	}
	return (1);
}
