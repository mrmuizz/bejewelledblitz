#include<iostream>
#include<conio.h>

#include<time.h>
#include<fstream>
#include"help.h"
using namespace std;
int menu()//This function will print the initial menu which shows help, play and quit options. 
{
	int x = 0, y = 0, highscore = 0;
	while (1)//The loop will not terminate untill you quit or enter the game.
	{
		Sleep(300);
		myRect(300, 80, 550, 200, 0, 0, 255, 0, 0, 0); myRect(330, 50, 510, 170, 0, 0, 255, 0, 0, 0); myRect(360, 10, 480, 150, 0, 0, 255, 0, 0, 0);
		cout << "\n                                             BEJEWELED BLITZ\n\n                                               1.PLAY                                              \n                                               2.HELP                                              \n                                               3.Highscore                                               \n                                               4.Quit";
		x = _getch();
		if (x == '1')//'1' will break the loop and show difficulty then display the game. 
		{
			system("cls");
			cout << "Select difficulty level\n1.Easy\n2.Medium\n3.Hard\n";
			return 1;
		}
		else if (x == '2')//'2' will open up the help slide which will guide how to play.
		{
			system("cls");
			cout << "~Use arrow keys to move the marker in map.\n~Press enter key to select the jewel you want to swap.\n~.Use arrow keys to swap the jewel quickly after pressing enter.\n~.Crush cube jewel by swapping it with any other jewel.\n~.Score as much as you can in one minute.\n~.Press 'S' from keyboard during game to save your current game.\n~.Press 'L' from keyboard during game to load and go back to the game that you saved.\n~.Press 'H' from keyboard during the game to get a hint.\n~.Press 'Esc' from keyboard to quit the game anytime.\n\n\n\n\n\n          HAVE FUN !\n          PRESS ANY KEY TO GO BACK TO MENU \n          ";
			y = _getch();
			system("cls");
		}
		else if (x == '3')//Three will show current high score.
		{
			system("cls"); ifstream fin("highscore.txt");
			fin >> highscore; cout << " Current highest score is : " << highscore << "\n\n      Press any key to go back to menu";
			y = _getch(); system("cls");
		}
		else if (x == '4')//'4' will terminate the game.
			return 0;
	}
}
void map()//This function will print boundary of board & square boxes in it's background
{
	int xx = 550, yy = 30, y = 0;//Variable used in boxes.
	myRect(540, 20, 960, 440, 0, 250, 154, 0, 250, 154);//Boundary of map.
	for (int i = 0; i < 8; i++,yy=yy+50)//Loop will print background boxes in map.
	{
		for (int j = 0, xx = 550; j < 8; j++,xx=xx+50)
		{
			if (y == 0)
				myRect(xx, yy, xx + 50, yy + 50, 0, 0, 0, 200, 200, 200);//Colour 1 Boxes
			if (y == 1)
				myRect(xx, yy, xx + 50, yy + 50, 0, 0, 0, 105, 105, 105);//Colour 2 Boxes
			if (y == 0)//Switching of two boxes.
				y = 1;
			else
				y = 0;
		}
		if (y == 0)//Switching of two boxes.
			y = 1;
		else
			y = 0;
	}
}
int difficulty(int x)
{
	if (x == '1')
		return 4;
	if (x == '2')
		return 5;
	if (x == '3')
		return 6;
}
void correctrandomplacer(int array[][8])//This function will prevent from getting three or more similar jewels in initial map.
{
	srand(time(0));int x;
	x = _getch(); difficulty(x);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			array[i][j] = rand() % difficulty(x);
			if (array[i][j] == array[i][j - 1] && array[i][j] == array[i][j - 2]) //Prevention in X axis.
				while (array[i][j] == array[i][j - 1])//It will keep generating new number unless it is different from previous 2.
					array[i][j] = rand() % difficulty(x);
			if (array[i][j] == array[i - 1][j] && array[i][j] == array[i - 2][j])//Prevention in Y axis.
				while (array[i][j] == array[i - 1][j])
					array[i][j] = rand() % difficulty(x);
		}
	}
}
void jewels(int array[][8])//This function will print six different jewels ,fire and cube jewel and empty blocks(to show crushed jewels)
{
	int x1 = 560, y1 = 40, switcher = 0;//Variables in jewels.
	for (int i = 0; i < 8; i++)//Loop for placement of jewel in the map.
	{
		for (int j = 0; j < 8; j++,x1=x1+50)
		{
			if (array[i][j] == 0)//Jewel 1.
				myEllipse(x1, y1, x1 + 30, y1 + 30, 25, 25, 112, 173, 216, 230);
			if (array[i][j] == 1)//Jewel 2.
				myTriangle(x1, y1, x1 + 30, y1 + 30, 255, 0, 255, 128, 0, 128);
			if (array[i][j] == 2)//Jewel 3.
				myKite(x1, y1, x1 + 30, y1 + 30, 255, 0, 0, 255, 255, 0);
			if (array[i][j] == 3)//Jewel 4.
				myDiamond(x1, y1, x1 + 30, y1 + 30, 0, 255, 255, 0, 0, 255);
			if (array[i][j] == 4)//Jewel 5.
				myHexagone(x1, y1, x1 + 30, y1 + 30, 255, 0, 0, 255, 140, 0);
			if (array[i][j] == 5)//Jewel 6.
				myRect(x1, y1, x1 + 30, y1 + 30, 0, 128, 128, 0, 255, 255);
			if (array[i][j] == 6)//Ellipse fire jewel.
			{
				myEllipse(x1, y1, x1 + 30, y1 + 30, 255, 255, 0, 255, 255, 0);
				myEllipse(x1 + 5, y1 + 5, x1 + 25, y1 + 25, 25, 25, 112, 173, 216, 230);
			}
			if (array[i][j] == 7)//Triangle fire jewel.
			{
				myTriangle(x1, y1, x1 + 30, y1 + 30, 255, 255, 0, 255, 255, 0);
				myTriangle(x1 + 5, y1 + 5, x1 + 25, y1 + 25, 255, 0, 255, 128, 0, 128);
			}
			if (array[i][j] == 8)//Kite fire jewel.
			{
				myKite(x1, y1, x1 + 30, y1 + 30, 255, 255, 0, 255, 255, 0);
				myKite(x1 + 5, y1 + 5, x1 + 25, y1 + 25, 255, 0, 0, 255, 215, 0);
			}
			if (array[i][j] == 9)//Diamond fire jewel.
			{
				myDiamond(x1, y1, x1 + 30, y1 + 30, 255, 255, 0, 255, 255, 0);
				myDiamond(x1 + 5, y1 + 5, x1 + 25, y1 + 25, 0, 255, 255, 0, 0, 255);
			}
			if (array[i][j] == 10)//Hexagone fire jewel.
			{
				myHexagone(x1, y1, x1 + 30, y1 + 30, 255, 255, 0, 255, 255, 0);
				myHexagone(x1 + 5, y1 + 5, x1 + 25, y1 + 25, 255, 0, 0, 255, 140, 0);
			}
			if (array[i][j] == 11)//Rectangle fire jewel.
			{
				myRect(x1, y1, x1 + 30, y1 + 30, 255, 255, 0, 255, 255, 0);
				myRect(x1 + 5, y1 + 5, x1 + 25, y1 + 25, 0, 128, 128, 0, 255, 255);
			}
			if (array[i][j] == 12)//Special Cube jewel.
				myCube(x1 - 5, y1 + 10, x1 + 20, y1 + 30, 0, 100, 0, 85, 107, 47);
			if (array[i][j] == 13);//Empty Block (to show crushed jewels after swapping).
		}
		y1 = y1 + 50; x1 = 560;
	}
}
void marker(int x,int x1,int y,int y1, int R, int B, int G)//This function will print the red marker which will show the position of player in the ap.
{
	myLine(x, y, x1, y, R, B, G); myLine(x, y1, x1, y1, R, B, G);
	myLine(x, y, x, y1, R, B, G); myLine(x1, y, x1, y1, R, B, G);
}
void printer(int array[][8],int& score)
{
//This function will clear and reprint the map, jewels, marker and score to show any changes (as we need that many times below).
	Sleep(100); system("cls");
	map(); jewels(array);
	cout << "score : " << score;
}
int scorecount(int array[][8])//This function will count the score of player.
{
	int score = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (array[i][j] == 13)
				score = score + 50;
		}
	}
	return score;
}
bool cubejewelmaker(int x[][8])//This function will create the special cube jewel.
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (x[i][j] != 13 && x[i][j] == x[i][j + 1] && x[i][j] == x[i][j + 2] && x[i][j] == x[i][j + 3] && x[i][j] == x[i][j + 4])
			{//If we get consecutive five similar jewels in X axis.
				x[i][j] = 12; x[i][j + 1] = 13; x[i][j + 2] = 13; x[i][j + 3] = 13; x[i][j + 4] = 13; return true;
			}
			if (x[i][j] != 13 && x[i][j] == x[i + 1][j] && x[i][j] == x[i + 2][j] && x[i][j] == x[i + 3][j] && x[i][j] == x[i + 4][j])
			{//If we get consecutive five similar jewels in Y axis.
				x[i][j] = 12; x[i + 1][j] = 13; x[i + 2][j] = 13; x[i + 3][j] = 13; x[i + 4][j] = 13; return true;
			}
			if (x[i][j] != 13 && x[i][j] == x[i][j + 1] && x[i][j] == x[i][j + 2] && x[i][j] == x[i + 1][j + 2] && x[i][j] == x[i + 2][j + 2])
			{//If we get five similar jewels in inverted mirror "L" shape.
				x[i][j] = 12; x[i][j + 1] = 13; x[i][j + 2] = 13; x[i + 1][j + 2] = 13; x[i + 2][j + 2] = 13; return true;
			}
			if (x[i][j] != 13 && x[i][j] == x[i][j + 1] && x[i][j] == x[i][j + 2] && x[i][j] == x[i - 1][j + 2] && x[i][j] == x[i - 2][j + 2])
			{//If we get five similar jewels in mirror "L" shape.
				x[i][j] = 12; x[i][j + 1] = 13; x[i][j + 2] = 13; x[i - 1][j + 2] = 13; x[i - 2][j + 2] = 13; return true;
			}
			if (x[i][j] != 13 && x[i][j] == x[i + 1][j] && x[i][j] == x[i + 2][j] && x[i][j] == x[i + 2][j + 1] && x[i][j] == x[i + 2][j + 2])
			{//If we get five similar jewels in "L" shape.
				x[i][j] = 12; x[i + 1][j] = 13; x[i + 2][j] = 13; x[i + 2][j + 1] = 13; x[i + 2][j + 2] = 13; return true;
			}
			if (x[i][j] != 13 && x[i][j] == x[i][j + 1] && x[i][j] == x[i + 1][j] && x[i][j] == x[i][j + 2] && x[i][j] == x[i + 2][j])
			{//If we get five similar jewels in inverted "L" shape.
				x[i][j] = 12; x[i][j + 1] = 13; x[i + 1][j] = 13; x[i][j + 2] = 13; x[i + 2][j] = 13; return true;
			}
		}
	}
}
void cubejewelcrusher(int array[][8],int& cube)//This function will crush the special cube jewel.(implemented in the loopcontrol function in swapping).
{
	int score = 0;
	for (int i = 0; i < 8; i++)//This jewel will swap with any other jewel and remove all the jewels of that kind in the board.
		for (int j = 0; j < 8; j++)
		{
			if (array[i][j] == cube)
				array[i][j] = 13;
			if (cube == 12)
			{
				for (int k = 0; k < 8; k++)
					for (int l = 0; l < 8; l++)
						array[k][l] = 13;
			}
		} 
}
bool firejewelmaker(int array[][8])//This function will create fire jewel of respected jewel(if we get four similar jewels in X or Y axis).
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{    
			if (array[i][j] != 13 && array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2] && array[i][j] == array[i][j + 3])
			{//Making fire jewel in X axis
				array[i][j + 1] = 13; array[i][j + 2] = 13; array[i][j + 3] = 13; array[i][j] = array[i][j] + 6; return true;
			}
			if (array[i][j] != 13 && array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j] && array[i][j] == array[i + 3][j])
			{//Making fire jewel in Y axis
				array[i + 1][j] = 13; array[i + 2][j] = 13; array[i + 3][j] = 13; array[i][j] = array[i][j] + 6; return true;
			}
		}
}
bool firejewelcrusher(int a, int b, int c)
{//This function will crush one fire jewel with its two simple jewels.(case 1)
	if (a - 6 == b && b == c || a == b - 6 && b - 6 == c || a == b && b == c - 6)
		return true;
	return false;
}
bool firejewelcrusher2(int a, int b, int c, int d)
{//This function will crush one fire jewel with its three simple jewels.(case 2)
	if (a - 6 == b&&b == c&&c == d || a == b - 6 && b - 6 == c&&c == d || a == b&&b == c - 6 && c - 6 == d || a == b&&b == c&&c == d - 6)
		return true;
	return false;
}
bool firejewelcrusher3(int a, int b, int c)
{//This function will crush two fire jewels with their one simple jewel.(case 3)
	if (a - 6 == b - 6 && b - 6 == c || a == b - 6 && b - 6 == c - 6 || a - 6 == b && b == c - 6)
		return true;
	return false;
}
bool similarcrusher(int x[][8])//This function will crush three similar jewels create fire and cube jewels and crush fire jewels.
{
	bool flag = false;
	for (int i = 0; i < 8 ; i++)
		for (int j = 0; j < 8; j++)
		{
			if (cubejewelmaker(x) == true)//Creating cube jewel.
				return true;
			if (firejewelmaker(x) == true)//creating fire jewel.
				return true;
			if (firejewelcrusher3(x[i][j], x[i][j + 1], x[i][j + 2]) == true && x[i][j] != 13)
			{//X axis.
				for (int k = i - 1; k < i + 2; k++)
					for (int l = j - 1; l < j + 4; l++)
						x[k][l] = 13;
				flag = true;
			}
			if (firejewelcrusher3(x[i][j], x[i + 1][j], x[i + 2][j]) == true && x[i][j] != 13)
			{//Y axis.
				for (int k = i-1; k < i + 4; k++)
					for (int l = j - 1; l < j + 2; l++)
						x[k][l] = 13;
				flag = true;
			}
			if (firejewelcrusher2(x[i][j], x[i][j + 1], x[i][j + 2], x[i][j + 3]) == true && x[i][j] != 13)
			{//X axis.
				for (int k = i - 1; k < i + 2; k++)
					for (int l = j; l < j + 4; l++)
						x[k][l] = 13;
				flag = true;
			}
			if (firejewelcrusher2(x[i][j], x[i + 1][j], x[i + 2][j], x[i + 3][j]) == true && x[i][j] != 13)
			{//Y axis.
				for (int k = i; k < i + 4; k++)
					for (int l = j - 1; l < j + 2; l++)
						x[k][l] = 13;
				flag = true;
			}
			if (firejewelcrusher(x[i][j], x[i][j + 1], x[i][j + 2]) == true && x[i][j] != 13)
			{//X axis.
				for (int k = i - 1; k < i + 2; k++)
					for (int l = j; l < j + 3; l++)
						x[k][l] = 13;
				flag = true;
			}
			if (firejewelcrusher(x[i][j], x[i + 1][j], x[i + 2][j]) == true && x[i][j] != 13)
			{//Y axis.
				for (int k = i; k < i + 3; k++)
					for (int l = j - 1; l < j + 2; l++)
						x[k][l] = 13;
				flag = true;
			}
			if (x[i][j] == x[i + 1][j] && x[i][j] == x[i + 2][j])//Crushing three jewels in Y axis.
			{
				x[i][j] = 13; x[i + 1][j] = 13; x[i + 2][j] = 13; flag = true;
			}
			if (x[i][j] == x[i][j + 1] && x[i][j + 1] == x[i][j + 2])//Crushing three jewels in X axis.
			{
				x[i][j] = 13; x[i][j + 1] = 13; x[i][j + 2] = 13; flag = true;
			}
		}
	return flag;
}
void downmover(int array[][8])//This function will move down the jewels after crushing to fill empty space in the bottom.
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (array[i][j] == 10)
				for (int k = i; k > 0; k--)
					swap(array[k][j], array[k - 1][j]);
}
void empetyspacefiller(int x[][8])//This function will fill the empty spaces in map with random jewels after crushing and moving down.
{
	srand(time(0));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (x[i][j] == 13)
			{
				x[i][j] = rand() % 6;//While loop will prevent from getting three or more similar jewels after crushing
				while (x[i][j] == x[i][j - 1] || x[i][j] == x[i][j + 1] || x[i][j] == x[i - 1][j] || x[i][j] == x[i + 1][j])
					x[i][j] = rand() % 6;
			}
}
void gamesaver(int array[][8],int score,int t)//This function will save your current game.
{
	ofstream fout("saved.txt");
	fout << score << " " << t << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			fout << array[i][j] << " ";
		fout << endl;
	}
}
void gameloader(int array[][8],int& score,float& t)//This function will load your saved game.
{
	system("cls"); 
	ifstream fin("saved.txt");
	cout << "score :"; fin >> score; cout << score;
	fin >> t;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			fin >> array[i][j];
	map(); 
	jewels(array);
}
void timeupcrusher(int a[][8], int& x, int& x1, int&y, int&y1, int& score)
{//This function will crush all fire and cube jewels on board when time runs out.
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 12)//Crushing cube jewels.
			{
				a[i][j] = 13; printer(a, score); Sleep(400);
				for (int k = 0; k < 8; k++)
				{
					a[k][j] = 13; a[i][k] = 13;
				}
				score = score + 3200;
				printer(a, score); Sleep(200); downmover(a);
				printer(a, score); Sleep(200); empetyspacefiller(a);
				marker(x, x1, y, y1, 255, 0, 0);

			}
			else if (a[i][j] > 5 && a[i][j] < 12)//Crushing fire jewels.
			{
				a[i][j] = 13; printer(a, score); Sleep(400);
				a[i - 1][j] = 13; a[i][j] = 13; a[i + 1][j] = 13;
				a[i - 1][j + 1] = 13; a[i][j + 1] = 13; a[i + 1][j + 1] = 13;
				a[i - 1][j + 2] = 13; a[i][j + 2] = 13; a[i + 1][j + 2] = 13;
				score = score + 1800;
				printer(a, score); Sleep(200); downmover(a);
				printer(a, score); Sleep(200); empetyspacefiller(a);
				marker(x, x1, y, y1, 255, 0, 0);
			}
		}
}
bool hintcheck(int x[][8])
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (x[i][j] == x[i][j + 1] && x[i][j] == x[i][j + 2] || x[i][j] == x[i + 1][j] && x[i][j] == x[i + 2][j])
				return true;
	return false;
}
void hint(int a[][8])
{
	int x = 550, x1 = 600, y = 30, y1 = 80, flag = 0;
	for (int i = 0; i < 8; i++, y = y + 50, y1 = y1 + 50)
	{
		for (int j = 0, x = 550, x1 = 600; j < 6; j++, x = x + 50, x1 = x1 + 50)
		{
			swap(a[i][j], a[i][j + 1]);
			if (hintcheck(a) == true)
			{
				marker(x, x1, y, y1, 255, 0, 215); Sleep(250); marker(x, x1, y, y1, 0, 0, 0); Sleep(250);
				marker(x, x1, y, y1, 255, 0, 215); Sleep(250); marker(x, x1, y, y1, 0, 0, 0);
				flag = 1;
			}
			swap(a[i][j], a[i][j + 1]);
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
}
void gameplay(int array[][8])//This function will control all the tasks taking place in the loop.
{
	int i = 0, j = 0, x = 550, x1 = 600, y = 30, y1 = 80, a = 0, b = 0, checkhint = 0, score = 0, cube = 0, flag = 0, quit = 0, restart = 0, highscore = 0;
	ifstream fin("highscore.txt"); 
	fin >> highscore;
	char c;
	cout << "Score : " << score; 
	marker(x, x1, y, y1, 255, 0, 0);
	//Timer.
	float t = 950;
	myRect(548, 445, 952, 460, 255, 0, 0, 255, 0, 0); myRect(550, 447, t, 457, 255, 0, 0, 0, 0, 0); myRect(550, 447, t, 457, 255, 0, 0, 255, 215, 0);
	while (1)
	{  //Timer.
		myRect(548, 445, 952, 460, 255, 0, 0, 255, 0, 0); myRect(550, 447, 952, 457, 255, 0, 0, 0, 0, 0); myRect(550, 447, t, 457, 0, 0, 0, 0, 0, 0);
		t = t - 0.6667;	myRect(548, 447, t, 457, 255, 0, 0, 255, 215, 0); Sleep(100);//Time will end in one minute.
		marker(x, x1, y, y1, 0, 0, 0);//Marking lines movement.
		c = GetAsyncKeyState(38);
		if (c == 1 && y > 30)
		{
			y = y - 50; y1 = y1 - 50; i--;
		}
		c = GetAsyncKeyState(37);
		if (c == 1 && x > 550)
		{
			x = x - 50; x1 = x1 - 50; j--;
		}
		c = GetAsyncKeyState(39);
		if (c == 1 && x < 900)
		{
			x = x + 50; x1 = x1 + 50; j++;
		}
		c = GetAsyncKeyState(40);
		if (c == 1 && y < 380)
		{
			y = y + 50; y1 = y1 + 50; i++;
		}
		marker(x, x1, y, y1, 255, 0, 0);
		c = GetAsyncKeyState(13);//Swapping of jewels.
		if (c == 1)
		{
			a = i, b = j;
			Sleep(500);
			c = GetAsyncKeyState(38);
			if (c == 1 && i > 0)
				a = i - 1;
			c = GetAsyncKeyState(37);
			if (c == 1 && j > 0)
				b = j - 1;
			c = GetAsyncKeyState(39);
			if (c == 1 && j < 7)
				b = j + 1;
			c = GetAsyncKeyState(40);
			if (c == 1 && i < 7)
				a = i + 1;
			swap(array[i][j], array[a][b]); printer(array, score); Sleep(50);
			if (similarcrusher(array) == true || array[a][b] == 12)
			{
				if (array[a][b] == 12)//Cube jewel crusher.
				{
					cube = array[i][j]; array[a][b] = 13;
					cubejewelcrusher(array, cube);
					flag = 1; score = score + scorecount(array);
				}
			}
			else
				swap(array[i][j], array[a][b]); printer(array, score);//Reswapping jewels if they are not worth swapping.
		}
		while (similarcrusher(array) || flag == 1)//Processing.
		{
			flag = 0; score = score + scorecount(array);
			printer(array, score); Sleep(150); downmover(array);
			printer(array, score); Sleep(200); empetyspacefiller(array); jewels(array);
		}
		marker(x, x1, y, y1, 255, 0, 0);
		if (t < 550)//Time up menu.
		{
		    ofstream fout("highscore.txt");
			cout << "\n\n\n\n\n\n                  Time up !"; Sleep(3000);
			timeupcrusher(array, x, x1, y, y1, score);
			Sleep(1000); system("cls");
			if (highscore < score)
			{
				fout << score;
				cout << "Congratulations you broke the high score !\nNew high score is : " << score;
			}
			cout << "                                             \n\n\n\n\n\nTime Up !\nYour score is : " << score << "\n\nDo you want to restart?\n1.Yes\n2.No\n"; cin >> restart;
			if (restart == 1)
			{
				cout << "Please wait a moment"; Sleep(500); system("cls");
				map(); correctrandomplacer(array); jewels(array); gameplay(array);
			}
			if (restart == 2)
				break;
		}
		c = GetAsyncKeyState(27);//Quit menu.
		if (c == 1)
		{
			system("cls");  cout << "Do you want to quit the game ?\n1.Yes\n2.No\n"; cin >> quit;
			if (quit == 1)
			{
				system("cls"); int saver;
				cout << "Do you want to save your current game?\n1.Yes\n2.No\n"; cin >> saver;
				if (saver == 1)
				{
					gamesaver(array, score, t);
					cout << "Your game is saved !"; Sleep(1000);
				}
				if (saver == 2)
					break;
				break;
			}
			if (quit ==  2)
			{
				cout << "Please wait for a moment "; Sleep(1000);
				printer(array, score);
				marker(x, x1, y, y1, 255, 0, 0);
			}
		}
		c = GetAsyncKeyState(72);//Hint
		if (c == 1)
			hint(array);
		c = GetAsyncKeyState(83);//Saving Game.
		if (c == 1)
			gamesaver(array, score, t);
		c = GetAsyncKeyState(76);//Loading saved game.
		if (c == 1)
			gameloader(array, score, t);
	}
}
int main()
{
	int board[8][8];
	if (menu() == 1)
	{
		correctrandomplacer(board);
		map(); 
		jewels(board);
		gameplay(board);
	}
	return 0;
}