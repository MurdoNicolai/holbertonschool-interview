#ifndef sandpiles
#define sandpiles

#include <stddef.h>

int (*sandpile_tople(int grid1[3][3], int grid2[3][3]))[3];
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* sandpiles */
