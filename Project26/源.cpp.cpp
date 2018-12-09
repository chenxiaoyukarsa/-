#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>



int map[7][10] = {

{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 },

{ 0, 1, 1, 1, 0, 0, 0, 0, 1, 0 },

{ 1, 1, 3, 0, 4, 1, 1, 0, 1, 1 },

{ 1, 3, 3, 4, 0, 4, 0, 0, 0, 1 },

{ 1, 3, 3, 0, 4, 0, 4, 0, 1, 1 },

{ 1, 1, 1, 1, 1, 1, 0, 5, 1, 0 },

{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 0 } };//墙为1 空地为0 箱子为4 人为5 目的地为3

void DrawMap()

{

	//用for循环遍历数组

	for (int i = 0; i < 7; i++)

	{

		for (int j = 0; j < 10; j++)

		{

			switch (map[i][j])

			{

			case 0:

				printf("  ");

				break;

			case 1:

				printf("■");

				break;

			case 3:

				printf("☆");

				break;

			case 4:

				printf("□");

				break;

			case 5:

				printf("▲");

				break;

			case 7: //4+3 箱子+目的地

				printf("★");

				break;

			case 8: //5+3 人+目的地

				printf("▲");

				break;

			}

		}

		printf("\n");

	}

}

void PlayGame()

{

	//获取到当前人的下标 时刻都能够确定人的下标

	int row, col; //人的行 和 列

	for (int i = 0; i < 7; i++) //控制变量 0-6

	{

		for (int j = 0; j < 10; j++) //控制变量 0-9

		{

			if (map[i][j] == 5 || map[i][j] == 8)

			{

				row = i; //i 0-6

				col = j; //j 0-9

			}

		}

	}

	printf("(%d,%d)\n", row, col);

	//键盘来控制图形对应的数据.

	//wasd 字符  char

	char input; //定义一个字符变量

	input = getch(); //变量接受键盘的输入

	//getchar()显示回文 按下enter键接收完成 getch()不现实回文,按下马上接收

	switch (input)

	{

		/*************************************

		人能走的情况:

		1.人的前面是空地.

		2.人的前面是目的地.

		3.人的前面是箱子,箱子的前面是空地.

		4.人的前面是箱子,箱子的前面是目的地.

		***************************************/

	case 'w': //上

		if (map[row - 1][col] == 0 || map[row - 1][col] == 3) //如果人的前面是空地或者目的地

		{

			map[row][col] -= 5; //人的ID有可能是5 也有可能是8

			map[row - 1][col] += 5;

		}

		else if (map[row - 1][col] == 4 || map[row - 1][col] == 7)//人的前面是箱子

		{

			if (map[row - 2][col] == 0 || map[row - 2][col] == 3)//箱子的前面是空地

			{

				map[row - 2][col] += 4;

				map[row - 1][col] += 1;

				map[row][col] -= 5;

			}

		}

		break;

	case 's': //下

		if (map[row + 1][col] == 0 || map[row + 1][col] == 3) //如果人的前面是空地或者目的地

		{

			map[row][col] -= 5; //人的ID有可能是5 也有可能是8

			map[row + 1][col] += 5;

		}

		else if (map[row + 1][col] == 4 || map[row + 1][col] == 7)//人的前面是箱子

		{

			if (map[row + 2][col] == 0 || map[row + 2][col] == 3)//箱子的前面是空地

			{

				map[row + 2][col] += 4;

				map[row + 1][col] += 1;

				map[row][col] -= 5;

			}

		}

		break;

	case 'a': //左

		if (map[row][col - 1] == 0 || map[row][col - 1] == 3) //如果人的前面是空地或者目的地

		{

			map[row][col] -= 5; //人的ID有可能是5 也有可能是8

			map[row][col - 1] += 5;

		}

		else if (map[row][col - 1] == 4 || map[row][col - 1] == 7)//人的前面是箱子

		{

			if (map[row][col - 2] == 0 || map[row][col - 2] == 3)//箱子的前面是空地

			{

				map[row][col - 2] += 4;

				map[row][col - 1] += 1;

				map[row][col] -= 5;

			}

		}

		break;

	case 'd': //右

		if (map[row][col + 1] == 0 || map[row][col + 1] == 3) //如果人的前面是空地或者目的地

		{

			map[row][col] -= 5; //人的ID有可能是5 也有可能是8

			map[row][col + 1] += 5;

		}

		else if (map[row][col + 1] == 4 || map[row][col + 1] == 7)//人的前面是箱子

		{

			if (map[row][col + 2] == 0 || map[row][col + 2] == 3)//箱子的前面是空地

			{

				map[row][col + 2] += 4;

				map[row][col + 1] += 1;

				map[row][col] -= 5;

			}

		}

		break;

		break;

	}

}

int main()

{

	while (1)

	{

		system("cls");

		DrawMap();

		PlayGame();

	}

	return 0;

}

/*

1.完成控制台推箱子.

2.尝试去使用图形库来写推箱子.

定义保存图片的变量: IMAGE box;

加载图片: loadimage(&box,L"E:\images/box.jpg",width,height);

输出图片到界面: putimage(x,y,&box);*/
