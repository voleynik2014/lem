
#ifndef LEM_IN
# define LEM_IN
# define TRUE 1
# define FALSE 0

# include "../libft/libft.h"

typedef struct		s_flow
{
    int             id;
    int             performance;
    int             count_ways;
	struct s_way	**ways;
}					t_flow;

typedef struct		s_way
{
    int             id;
    int             performance;
    struct s_lem	**room;
}					t_way;


typedef struct		s_lem
{
	char			*name;
	int				count_ants;
	int				x;
	int				y;
	struct s_lem	**links;
}					t_lem;

typedef struct		s_data
{
	int 			fd;
	int				count_rooms;
	struct s_lem	**rooms_reserved;
    struct s_way	**all_possible_ways;
//	struct s_lem	***roads_reserved;
	struct s_lem	**rooms;
    struct s_flow  **all_possible_flows;
    struct s_flow  *final_ways;
	int 			point;
	int 			count_rooms_in_theway;
}					t_data;

void	get_num_ants(t_data *data);

t_lem	*ft_search_room(t_data *data, char *source);
int     ft_read_line(t_data *data, char *line);
void    ft_read_links(t_data *data);//, char *line);

t_lem   *ft_create_room(t_data *data, char *line);

void    build_new_way(t_data *data, t_lem *current_point);

void    calc_optimal_way(t_data *data);

#endif
