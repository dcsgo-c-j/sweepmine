#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define	ROW 10	    //输出的行数
#define COL 10	    //输出的列数
#define ROWS ROW+2  //实际的行数
#define COLS COL+2	
#define MINE 10     //雷

int map[ROWS][COLS];

void mnue_MineCle()
{
	printf("          扫雷        \n");
	printf("**********************\n");
	printf("***   0.退出游戏   ***\n");
	printf("***   1.开始游戏   ***\n");
	printf("***********************\n");
}

//初始化map
void InitMineMap(int map[ROWS][COLS])
{
	int count_mine = MINE;
	int x = 0, y = 0;
	
	for (x = 0;x < ROWS;x++)
	{
		for (y = 0;y < COLS;y++)
		{
			map[x][y] = 0;
		}
	}
	while (count_mine > 0)
	{
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (map[x][y] == 0)
		{
			map[x][y] = -1;
			count_mine--;
		}
	}
}

void InitPalyerMap(int PalyerMap[COLS][ROWS])
{

}

//打印雷
void PutMineMap(int map[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	for (i = 1;i <= row;i++)
	{
		for (j = 1;j <= col;j++)
		{
			printf("%-2d ",map[i][j]);
		}
		printf("\n");
	}
}

//打印map
void PutMap(int map[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	for (x = 1;x <= row;x++)
	{
		for (y = 1;y <= row;y++)
		{
			printf("%d ", map[x]);
		}
	}
	
}
void MineCle()
{
	InitMineMap(map);
	InitPalyerMap(PalyerMap);
	PutMineMap(map, ROW, COL);
	PutMap(map, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		mnue_MineCle();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:MineCle();
			break;
		case 0:
			break;
		default:printf("输入错误请重新输入\n");
			break;
		}
	} while (input);
	

	return 0;
}