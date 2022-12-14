/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivelling <izaakvellinga@gmail.com>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 17:24:14 by ivelling      #+#    #+#                 */
/*   Updated: 2022/10/25 22:42:46 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "parsing.h"
#include "cub.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_map_struct	ms;

	if (argc != 2)
		error_and_msg("Input misconfiguration", 2);
	if (extention_check(argv[1], ".cub"))
		error_and_msg("Wrong file extension", 2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_and_msg("Empty or No File", 2);
	ft_memset(&ms, 0, sizeof(t_map_struct));
	file_parser(&ms, fd);
	close(fd);
	init_textures(&ms);
	to_tomato_factory(ms);
}
