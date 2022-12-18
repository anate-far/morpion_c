#ifndef LIB_h
#define LIB_h
	
void    ft_grid_display(char *grid, int size);
char     *ft_grid_create(void);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int	ft_check_line(char *grid, int size_line, int y);
int	ft_check_column(char *grid, int size_column, int x);
int	ft_check_diagonal(char *grid, int size_diagonal);
int	ft_check_win(char *grid, int size_line);
int	ft_cell_is_empty(char *grid, int cell);
int	ft_check_equality(char *grid, int size);


#endif
