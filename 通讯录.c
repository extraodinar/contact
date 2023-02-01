#include <stdio.h>
#include "通讯录.h"
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
	//初始化通讯录
	IniContact(&con);
	do
	{
		menu();
		printf("请选择\n");
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
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
		}
	} 
	while (input);
}