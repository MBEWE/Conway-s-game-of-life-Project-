# Conway-s-game-of-life-Project-
Project (Thabang M, Mbewe S, Martha M, Thabiso Phetla, Koketso S, William M)

Project Specification:

/*****************************************************************/

      Your task is to write a program to calculate the next 
      generation of Conway's game of life, given any starting
      position. You start with a two dimensional grid of cells,
      where each cell is either alive or dead. The grid is finite,
      and no life can exist off the edges. When calculating the
      next generation of the grid, follow these four rules:

      1. Any live cell with fewer than two live neighbours dies,
         as if caused by underpopulation.
      2. Any live cell with more than three live neighbours dies,
         as if by overcrowding.
      3. Any live cell with two or three live neighbours lives
         on to the next generation.
      4. Any dead cell with exactly three live neighbours becomes
         a live cell.

      Examples: * indicates live cell, . indicates dead cell

      Example input: (4 x 8 grid)
              4 8
            ........
            ....*...
            ...**...
            ........

      Example output:
              4 8
            ........
            ...**...
            ...**...
            ........

/************************************************************************/


TEST CASE:CONWAY’S GAME OF LIFE

Cells die when:

                1 - It has less than two neighbours-underflaw.

                2 - It has more than three members - overflaw.
                
Cells replicate when:

                        1 - It has 3 live neighbours 

                        2 - It  has two live neighbours.
                        




