#include <windows.h>
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void bgfill(int x1, int y1, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));
	SelectObject(device_context, brush);
	FloodFill(device_context, x1, y1, (RGB(R, G, B)));
	DeleteObject(brush);
}
void myLine(int x1, int y1, int x2, int y2,int R ,int B,int G)//use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); //2 is the width of the pen
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0));
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
}
void myTriangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid = (x1 + x2) / 2;
	MoveToEx(device_context, mid, y1, NULL);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x2, y2);
	LineTo(device_context, mid, y1);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));
	SelectObject(device_context, brush);
	FloodFill(device_context, mid, (y1 + y2) / 2, (RGB(R, G, B)));
	DeleteObject(pen);
	DeleteObject(brush);
}
void myKite(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2;
	MoveToEx(device_context, mid, y1, NULL);
	LineTo(device_context, x1, mid1);
	LineTo(device_context, mid, y2);
	LineTo(device_context, x2, mid1);
	LineTo(device_context, mid, y1);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));
	SelectObject(device_context, brush);
	FloodFill(device_context, mid, (y1 + y2) / 2, (RGB(R, G, B)));
	DeleteObject(pen);
	DeleteObject(brush);
}
void myDiamond(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2, tenpart = (x2 - x1) / 5, tenpart1 = (y2 - y1) / 5;
	MoveToEx(device_context, x1, y1+tenpart1, NULL);
	LineTo(device_context, mid, y2);
	LineTo(device_context, x2, y1+tenpart1);
	LineTo(device_context, x2-tenpart, y1);
	LineTo(device_context, x1 + tenpart, y1);
	LineTo(device_context, x1, y1 + tenpart1);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));
	SelectObject(device_context, brush);
	FloodFill(device_context, mid, (y1 + y2) / 2, (RGB(R, G, B)));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1 + tenpart1, NULL);
	LineTo(device_context, x2, y1 + tenpart);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myHexagone(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2;
	MoveToEx(device_context, mid, y1, NULL);
	LineTo(device_context, x1, y1 + 5);
	LineTo(device_context, x1, y2 - 5);
	LineTo(device_context, mid, y2);
	LineTo(device_context, x2, y2 - 5);
	LineTo(device_context, x2, y1 + 5);
	LineTo(device_context, mid, y1);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));
	SelectObject(device_context, brush);
	FloodFill(device_context, mid, (y1 + y2) / 2, (RGB(R, G, B)));
	DeleteObject(pen);
	DeleteObject(brush);
}
void myCube(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid = (x1 + x2) / 2, x0 = (sqrt(x2 - x1)) * 3, y0 = (sqrt(y2 - y1)) * 3;//1212
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x1, y1);
	LineTo(device_context, x1 + x0, y1 - y0);
	LineTo(device_context, x2 + x0, y1 - y0);
	LineTo(device_context, x2, y1);
	MoveToEx(device_context, x2 + x0, y1 - y0, NULL);
	LineTo(device_context, x2 + x0, y2 - y0);
	LineTo(device_context, x2, y2);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(device_context, brush);
	FloodFill(device_context, mid, (y1 + y2) / 2, (RGB(R, G, B)));
	FloodFill(device_context, x1 + 15, y1 - 5, (RGB(R, G, B)));
	FloodFill(device_context, x2 + 5, y2 - 15, (RGB(R, G, B)));
	DeleteObject(pen);
	DeleteObject(brush);
}
void myRect(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR,FG,FB)); //Fill color is passed as parameter to the function!!!
	SelectObject(device_context,brush);
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2,int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR,FG,FB));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}