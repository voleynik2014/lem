
#ifndef LEM_IN
# define LEM_IN
# define TRUE 1
# define FALSE 0

# include "../libft/libft.h"

#include <time.h>

typedef struct		s_flow
{
    int             id;
	int             performance;
    int             quantity_ways;
    int             max_perf_rooms;
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
	int				link_size;
	struct s_lem	**links;
}					t_lem;

typedef struct		s_data
{
    int             total_ants;
	int 			fd;
	int				count_rooms;
	struct s_lem	**rooms_reserved;
    struct s_way	**all_possible_ways;
	struct s_lem	**rooms;
    struct s_flow   **all_possible_flows;
    struct s_flow   *final_ways;
	struct s_lem	*start_room;
	struct s_lem	*end_room;
	struct s_flow	*stack;
    int             tmp;
	int 			point;
	int 			count_rooms_in_theway;
}					t_data;

void	get_num_ants(t_data *data);

t_lem	*ft_search_room(t_data *data, char *source);
int     ft_read_line(t_data *data);
void    ft_read_links(t_data *data, char *line);

t_lem   *ft_create_room(t_data *data, char *line);

void    build_new_way(t_data *data, t_lem *current_point);
void	ft_build_start_to_end_room(t_data *data);

void ft_print_rooms(t_way *res_way);

void    calc_optimal_way(t_data *data);

void **permutation(t_data *data);
void	ft_print_flows(t_flow *stack);

void		ft_how_many(t_data *data);
int ft_ceil(int total_perform, int total_ants, int i);

//validation
int		check_valid_count_ants(char *line);
int     ft_valid_ways(t_data *data);

//realloc
t_lem	*ft_realloc_current_room(t_lem *current_room);
t_way	**ft_realloc_ways(t_data *data, int new_size);
t_flow	**ft_realloc_flows(t_data *data);
t_way	**ft_realloc_ways_stack(int new_size, int old_size, t_way **stack);
t_lem	**ft_realloc_array_rooms(t_data *data, int old_num, int new_num);

//delete
void	ft_delete_room(t_lem *current_room);
void	ft_delete_way(t_way **current_way);
void	ft_delete_all_ways(t_data *data);
void	ft_delete_all_rooms(t_data *data);
void	ft_delete_all_flows(t_data *data);

#endif
