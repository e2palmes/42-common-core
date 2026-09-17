#include <stdlib.h>
#include <unistd.h>

int *queens;
int b_size;

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int is_safe(int row, int col)
{
    int i = 0;
    while (i < row)
    {
        if (queens[i] == col)
            return (0);
        if (ft_abs(row - i) == ft_abs(col - queens[i]))
            return (0);
        i++;
    }
    return (1);
}

void print_solution()
{
    int i = 0;
    char c;
    while (i < b_size)
    {
        c = queens[i] + '0';
        write(1, &c, 1);
        if (i != b_size -1)
            write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);
}

void solve (int row)
{
    int col;
    if (row == b_size)
    {
        print_solution();
        return;
    }
    col = 0;
    while (col < b_size)
    {
        if (is_safe(row, col))
        {
            queens[row] = col;
            solve(row + 1);
        }
        col++;
    }
}

int main (int argc, char **argv)
{
    int N;

    if (argc != 2)
        return (-1);
    N = atoi(argv[1]);
    if (N < 1)
        return (-1);
    b_size = N;
    queens = malloc(sizeof(int) * N);
    if (!queens)
        return (-1);
    solve(0);
    free(queens);
    return (0);
}
