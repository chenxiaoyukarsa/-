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

{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 0 } };//ǽΪ1 �յ�Ϊ0 ����Ϊ4 ��Ϊ5 Ŀ�ĵ�Ϊ3

void DrawMap()

{

	//��forѭ����������

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

				printf("��");

				break;

			case 3:

				printf("��");

				break;

			case 4:

				printf("��");

				break;

			case 5:

				printf("��");

				break;

			case 7: //4+3 ����+Ŀ�ĵ�

				printf("��");

				break;

			case 8: //5+3 ��+Ŀ�ĵ�

				printf("��");

				break;

			}

		}

		printf("\n");

	}

}

void PlayGame()

{

	//��ȡ����ǰ�˵��±� ʱ�̶��ܹ�ȷ���˵��±�

	int row, col; //�˵��� �� ��

	for (int i = 0; i < 7; i++) //���Ʊ��� 0-6

	{

		for (int j = 0; j < 10; j++) //���Ʊ��� 0-9

		{

			if (map[i][j] == 5 || map[i][j] == 8)

			{

				row = i; //i 0-6

				col = j; //j 0-9

			}

		}

	}

	printf("(%d,%d)\n", row, col);

	//����������ͼ�ζ�Ӧ������.

	//wasd �ַ�  char

	char input; //����һ���ַ�����

	input = getch(); //�������ܼ��̵�����

	//getchar()��ʾ���� ����enter��������� getch()����ʵ����,�������Ͻ���

	switch (input)

	{

		/*************************************

		�����ߵ����:

		1.�˵�ǰ���ǿյ�.

		2.�˵�ǰ����Ŀ�ĵ�.

		3.�˵�ǰ��������,���ӵ�ǰ���ǿյ�.

		4.�˵�ǰ��������,���ӵ�ǰ����Ŀ�ĵ�.

		***************************************/

	case 'w': //��

		if (map[row - 1][col] == 0 || map[row - 1][col] == 3) //����˵�ǰ���ǿյػ���Ŀ�ĵ�

		{

			map[row][col] -= 5; //�˵�ID�п�����5 Ҳ�п�����8

			map[row - 1][col] += 5;

		}

		else if (map[row - 1][col] == 4 || map[row - 1][col] == 7)//�˵�ǰ��������

		{

			if (map[row - 2][col] == 0 || map[row - 2][col] == 3)//���ӵ�ǰ���ǿյ�

			{

				map[row - 2][col] += 4;

				map[row - 1][col] += 1;

				map[row][col] -= 5;

			}

		}

		break;

	case 's': //��

		if (map[row + 1][col] == 0 || map[row + 1][col] == 3) //����˵�ǰ���ǿյػ���Ŀ�ĵ�

		{

			map[row][col] -= 5; //�˵�ID�п�����5 Ҳ�п�����8

			map[row + 1][col] += 5;

		}

		else if (map[row + 1][col] == 4 || map[row + 1][col] == 7)//�˵�ǰ��������

		{

			if (map[row + 2][col] == 0 || map[row + 2][col] == 3)//���ӵ�ǰ���ǿյ�

			{

				map[row + 2][col] += 4;

				map[row + 1][col] += 1;

				map[row][col] -= 5;

			}

		}

		break;

	case 'a': //��

		if (map[row][col - 1] == 0 || map[row][col - 1] == 3) //����˵�ǰ���ǿյػ���Ŀ�ĵ�

		{

			map[row][col] -= 5; //�˵�ID�п�����5 Ҳ�п�����8

			map[row][col - 1] += 5;

		}

		else if (map[row][col - 1] == 4 || map[row][col - 1] == 7)//�˵�ǰ��������

		{

			if (map[row][col - 2] == 0 || map[row][col - 2] == 3)//���ӵ�ǰ���ǿյ�

			{

				map[row][col - 2] += 4;

				map[row][col - 1] += 1;

				map[row][col] -= 5;

			}

		}

		break;

	case 'd': //��

		if (map[row][col + 1] == 0 || map[row][col + 1] == 3) //����˵�ǰ���ǿյػ���Ŀ�ĵ�

		{

			map[row][col] -= 5; //�˵�ID�п�����5 Ҳ�п�����8

			map[row][col + 1] += 5;

		}

		else if (map[row][col + 1] == 4 || map[row][col + 1] == 7)//�˵�ǰ��������

		{

			if (map[row][col + 2] == 0 || map[row][col + 2] == 3)//���ӵ�ǰ���ǿյ�

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

1.��ɿ���̨������.

2.����ȥʹ��ͼ�ο���д������.

���屣��ͼƬ�ı���: IMAGE box;

����ͼƬ: loadimage(&box,L"E:\images/box.jpg",width,height);

���ͼƬ������: putimage(x,y,&box);*/
