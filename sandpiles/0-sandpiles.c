#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sandpiles.h"


/**
*	sandpile_tople- tople sandpile 1 givving grid 2 as result of that topling
*	@grid1: first grid
*	@grid2: empty grid
*	Return: grid 2 to later add to grid 1 to get the result
**/
int *sandpile_tople(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (grid1[i][j] > 3) {
					if (i - 1  >= 0) {
						if (grid1[i - 1][j] <= 3) {
							grid2[i][j] -= 1;
							grid2[i - 1][j] += 1;
						}
					}
					else grid2 [i][j] -= 1;
					if (j - 1  >= 0) {
						if (grid1[i][j - 1] <= 3) {
							grid2[i][j] -= 1;
							grid2[i][j - 1] += 1;
						}
					}
					else grid2 [i][j] -= 1;
					if (i + 1  < 3) {
						if (grid1[i + 1][j] <= 3) {
							grid2[i][j] -= 1;
							grid2[i + 1][j] += 1;
						}
					}
					else grid2 [i][j] -= 1;
					if (j + 1  < 3) {
						if (grid1[i][j + 1] <= 3) {
							grid2[i][j] -= 1;
							grid2[i][j + 1] += 1;
						}
					}
					else grid2 [i][j] -= 1;
				}
			}
		}
	return (grid2);
}


/**
*	sandpiles_sum - sums 2 sandpiles
*	@grid1: first grid
*	@grid2: grid to add
*	Return: none
**/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int stable = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid2[i][j] != 0) {
				stable = 0;
				grid1[i][j] += grid2[i][j];
				grid2[i][j] = 0;
			}
		}
	}

	if (!stable) {
		print_grid(grid1);

		sandpiles_sum(grid1, sandpile_tople(grid1, grid2));
	}
}
