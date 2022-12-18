#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_cell_is_empty(char *grid, int cell)
{
	if(grid[cell - 1] == 'X' || grid[cell -1 ] == 'O')
	{
		write (1, "Case invalide\n", 14); 
		return (0);
	}
	return (1);
}

int	ft_check_win(char *grid, int size_line)
{
	int	i = 0;
	
	//Loop for check grid
	while ( i < size_line)
	{
		if (ft_check_line(grid, size_line, i) == 1 ||
		ft_check_column(grid, size_line, i) == 1||
		ft_check_diagonal(grid, size_line) == 1)
			return (1);
		if (ft_check_line(grid, size_line, i) == 2 ||
		ft_check_column(grid, size_line, i) == 2||
		ft_check_diagonal(grid, size_line) == 2)
			return (2);
		i++;
		
	}
	return (0);
}

int	ft_check_line(char *grid, int size_line, int y)
{
	int	i = 0;
	int	check_p_1 = 0;
	int	check_p_2 = 0;


	if((y > size_line) || (y < 0))
		return (-1);
	//Loop for read line
	while (i < size_line)
	{
		if(grid[size_line * y + i] == 'X')
			check_p_1++;
		if(grid[size_line * y + i] == 'O')
			check_p_2++;
		i++;
	}
	if(check_p_1 == 3)
		return (1);
	else if(check_p_2 == 3)
		return (2);
	return (0);
	
}

int	ft_check_column(char *grid, int size_column, int x)

{
	int	i = 0;
	int	check_p_1 = 0;
	int	check_p_2 = 0;

	if((x > size_column) || (x < 0))
		return (-1);
	//Loop for read column
	while(i < size_column)
	{
		if (grid[size_column * i + x] == 'X')
			check_p_1++; 
		if (grid[size_column * i + x] == 'O')
			check_p_2++; 
		i++;
	}
	if(check_p_1 == 3)
		return (1);
	else if(check_p_2 == 3)
		return (2);
	return (0);
}

int	ft_check_diagonal(char *grid, int size_diagonal)
{
	int	i = 0;
	int	y = 0;
	int	check_p_1 = 0;
	int	check_p_2 = 0;

	//Loop for diagonal left
	while(i < size_diagonal)
	{
		if (grid[size_diagonal * i + i] == 'X')
			check_p_1++;		
		if (grid[size_diagonal * i + i] == 'O')
			check_p_2++;
		i++;

	}	
	if(check_p_1 == 3)
		return (1);
	else if(check_p_2 == 3)
		return (2);
	check_p_1 = 0;
	check_p_2 = 0;
	i-=1;
	//Loop for diagonal right
	while(y < size_diagonal)
	{
		if (grid[size_diagonal * y + i] == 'X')
			check_p_1++;		
		if (grid[size_diagonal * y + i] == 'O')
			check_p_2++;
		i--;
		y++;
		
	}
	if(check_p_1 == 3)
		return (1);
	else if(check_p_2 == 3)
		return (2);
	return (0);
}

int	ft_check_equality(char *grid, int size)
{
	int	i = 0;
	
	while(i < size)
	{
		if (grid[i] != 'X' && grid[i] != 'O')
			return (1);
		i++;			
	}
	return (0);
}

char	*ft_grid_create(void)
{
	char	*grid = malloc(sizeof(char) * 9);
	int	i = 0;

	if(!grid)
		return (0);
	while (grid[i] < 9)
	{
		grid[i] = i + 49;
		i++;
	}
	grid[i] = '\0';
	return (grid);	
}

void	ft_grid_display(char *grid, int size)
{
	int	i = 0;
	
	
while (i < size)
	{
		if ((i % 3) == 0 && i > 0)
			write(1, "\n", 1);	
		ft_putchar(grid[i]);
		i++;
	}
	write(1, "\n\n", 2);
}

