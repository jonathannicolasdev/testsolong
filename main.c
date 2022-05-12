#include "mlx_sample.h"
//#include "./gnl/get_next_line.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	printf("hello %d\n", data->win_width);
	printf("hello %d\n", data->win_height);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, TITRE);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		create_map(argv[1], &data);
		init_map(&data);
		init_window(&data);
	}
	render(&data);
	mlx_loop(data.mlx);
}
