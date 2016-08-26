/*Team Members
    William Matjokane
    Koketso Seopela
    Sibongile Mbewe
    Martha Phora
    Thabiso Phetla
    Thabang Melatoe
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
/*defining the colours to be used*/
#define YELLOW	"\x1b[33;40m"
#define MAGENTA	"\x1b[35;40m"

using namespace std;

class GameOfLife {
	int width, height;
	bool grid [1000][1000];
public:
	GameOfLife(int, int);
	void next();
	void showGameOfLife();
};
GameOfLife::GameOfLife(int a, int b) {
	height = a;
	width = b;
/*default living cells*/
	grid[11][12] = true;
	grid[12][13] = true;
	grid[13][11] = true;
	grid[13][12] = true;
	grid[13][13] = true;

	grid[15][22] = true;
	grid[15][23] = true;
	grid[15][24] = true;
	grid[16][24] = true;
	grid[16][26] = true;

	grid[5][6] = true;
	grid[5][6] = true;
	grid[6][5] = true;
	grid[16][24] = true;
	grid[16][26] = true;

    grid[15+2][22+2] = true;
	grid[15+2][23+2] = true;
	grid[15+2][24+2] = true;
	grid[16+2][24+2] = true;
	grid[16+2][26+2] = true;
}
void GameOfLife::next()
{
	int cell_around = 0;
	bool temp [height][width];
/*playing the game and setting the next life*/
	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			if ( (i+1) < height && grid[i + 1][j] == true )
			{
				cell_around++;
			}
			if ( (i-1) >= 0 && grid[i - 1][j] == true )
			{
				cell_around++;
			}
			if ( (j+1) < width && grid[i][j+1] == true )
			{
				cell_around++;
			}
			if ( (j-1) >= 0 && grid[i][j-1] == true )
			{
				cell_around++;
			}
			if ( (i+1) < height && (j+1) < width && grid[i+1][j+1] == true )
			{
				cell_around++;
			}
			if ( (i+1) < height && (j-1) >= 0 && grid[i+1][j-1] == true )
			{
				cell_around++;
			}
			if ( (i-1) >= 0 && (j+1) < width && grid[i-1][j+1] == true )
			{
				cell_around++;
			}
			if ( (i-1) >= 0 && (j-1) >= 0 && grid[i-1][j-1] == true )
			{
				cell_around++;
			}

			if (cell_around < 2 || cell_around > 3)
			{
				temp[i][j] = false;
			}
			else if (cell_around == 2)
			{
				temp[i][j] = grid[i][j];
			}
			else if (cell_around == 3)
			{
				temp[i][j] = true;
			}

			cell_around = 0;

		}
	}

	for (int i = 0 ; i < height ; i++ )
	{
		for (int j = 0 ; j < width ; j++ )
		{
			grid[i][j] = temp[i][j];
		}
	}
}
void GameOfLife::showGameOfLife() {
    /*displaying the grid allowing with colours*/
	for (int i = 0; i < height ; i++ )
	{
		for (int j = 0 ; j < width ; j++ )
		{
			if ( grid[i][j] == true )
			{
				cout <<YELLOW<< "*";
			}
			else
			{
				cout <<MAGENTA "-";
			}

			if ( (j + 1) >= width )
			{
				cout << endl;
			}
		}
	}
}
int main () {

    int count =0;
    char exitplan = 'c';
    GameOfLife life(30, 50);

	cout << endl;

	do
    {
        count++;
		system("cls");
		life.next();
		life.showGameOfLife();
		cout << endl;
		system("sleep 0.5");
        if (count %5 ==0)
        {
            cout<<"press c to continue displaying life cycle or s to stop"<<endl;
            cin>>exitplan;
            if (exitplan != 'c' )
            {
                cout<<"GoodBYE!!"<<endl;
                exit(1);
            }
        }
	} while (1);
	return 0;
}
