#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"

int	main(void)
{
	char	*grid = ft_grid_create();
	int	player_play = 1;
	int	cell = 0;

	if(grid == 0)
	{
		write(1, "Impossible de creer la grille\n", 31);
		return (EXIT_FAILURE);
	}
	write(1, "type '10' for quit game\n#########################\n",50 );
	ft_grid_display(grid, 9);	
	//Loop for play game
	while(!ft_check_win(grid, 3))
	{
		//Check equality
		if (ft_check_equality(grid, 9) == 0)
		{
			write(1, "EQUALITY YOURS LOSE\n", 20);
			return (0);
		}	
		//Check cell is good
		while (cell < 1 || cell > 9 || !ft_cell_is_empty(grid, cell)) 
		{
			if (player_play == 1)
				write(1, "Player 1 choose your cell : ", 28);
			else
				write(1, "Player 2 choose your cell : ", 28);
			scanf("%d", &cell);
			//quit game
			if(cell == 10)
				return (0);
		}
		if (player_play == 1)
			grid[cell - 1] = 'X';
		if (player_play == 2)
			grid[cell - 1] = 'O';
		//Display grid
		ft_grid_display(grid, 9);	
		//change player and reboot cell
		if (player_play == 1)
			player_play = 2;
		else
			player_play = 1;
		cell = 0;
		//check winer
		if (ft_check_win(grid, 3) == 1)
			write(1, "PLAYER 1 WIN!!!\n", 16);
		if (ft_check_win(grid, 3) == 2)
			write(1, "PLAYER 1 WIN!!!\n", 16);
	}
	free(grid);
	return(EXIT_SUCCESS);
}
