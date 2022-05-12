#include "mlx_sample.h"

// Récupérer le nombre de lignes dans le fichier .ber
int	retrieve_line_number(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	put_input_in_map(int row, size_t column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = malloc((ft_strlen(line) + 1) * sizeof(char));
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		i = 0;
		column = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;	
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i] != NULL)
		printf("%s", data->map.map[i++]);
}

void	create_map(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->map.line_count = retrieve_line_number(path);
	data->map.path = path;
	data->map.map = malloc((data->map.line_count + 1) * sizeof(char *));
	if (!(data->map.map))
			return ;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		printf("did not open map");
	else
	{
		put_input_in_map(row, column, i, data);
		close(data->map.fd);
	}
	print_map(data);
}
