#include <stdio.h>
#include "ͨѶ¼.h"
void menu()
{
	printf("*******************************\n");
	printf("*****1.add           2.del*****\n");
    printf("****3.search       4.modify****\n");
	printf("****5.show           6.sort****\n");
	printf("************0.exit*************\n");
	printf("*******************************\n");
}
void main()
{
	int input = 0;
	struct  Contact con;
	//��ʼ��ͨѶ¼
	IniContact(&con);
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Addcontact(&con);
			break;
		case 2:
			Delcontact(&con);
			break;
		case 3:
			Seacontact(&con);
			break;
		case 4:
			Modcontact(&con);
			break;
		case 5:
			Showcontact(&con);
			break;
		case 6:
			Sortcontact(&con);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
		}
	} 
	while (input);
}