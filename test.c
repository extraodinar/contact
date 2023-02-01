#include "通讯录.h"
#include <string.h>
void IniContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void Addcontact(struct Contact* ps)
{
	if (ps->size == MAX)
		printf("通讯录已满,无法增加");
	else
	{
		printf("请输入名字：>\n");
		scanf_s("%s", &ps->data[ps->size].name);
		printf("请输入年龄：>\n");
		scanf_s("%d", &ps->data[ps->size].age);
		printf("请输入性别：>\n");
		scanf_s("%s", ps->data[ps->size].sex);
		printf("请输入号码：>\n");
		scanf_s("%s", ps->data[ps->size].tele);
		printf("请输入住址：>\n");
		scanf_s("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}
void Delcontact(struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空\n");
	char name[MAX_NAME];
	printf("请输入要删除联系人的姓名\n");
	scanf_s("%s", name);
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (0==strcmp(ps->data[i].name, name))
		{
			break;
		}
	}
	if (i == ps->size)
		printf("无此人!!");
	else
	{
		int j = 0;
		for (j = 0; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
	}
	ps->size--;
	printf("删除成功\n");
}
void Showcontact(const struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空\n");
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","住址");
		for (i=0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[i].name, 
				ps->data[i].age, 
				ps->data[i].sex, 
				ps->data[i].tele, 
				ps->data[i].addr);
		}
	}
}
void Modcontact(struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空，无法修改\n");
    else
    {
		printf("请输入需要修改联系人的姓名\n");
		char name[MAX_NAME];
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (0 == strcmp(ps->data[i].name, name))
				break;
		}
    printf("请输入姓名：>\n");
	scanf_s("%s", ps->data[i].name);
	printf("请输入年龄: >\n");
	scanf_s("%d", &ps->data[i].age);
	printf("请输入性别: >\n");
	scanf_s("%s", ps->data[i].sex);
	printf("请输入电话号码: >\n");
	scanf_s("%s", ps->data[i].tele);
	printf("请输入地址: >\n");
	scanf_s("%s", ps->data[i].addr);
    }
}
void Seacontact(struct Contact* ps)
{
	int i = 0;
		printf("请输入需要查找联系人的姓名\n");
		char name[MAX_NAME];
		scanf_s("%s", name);
		for (i = 0; i < ps->size; i++)
		{
			if (0 == strcmp(ps->data[i].name, name))
				break;
		}
		if (i == ps->size)
			printf("查无此人\n");
		else
		{
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", 
				    ps->data[i].name,
					ps->data[ps->size].age,
					ps->data[ps->size].sex,
					ps->data[ps->size].tele,
					ps->data[ps->size].addr);
		}
}
int* cmp(const void* e1, const void* e2)
{
	return ((struct Contact*)e1)->data - ((struct Contact*)e1)->data;
}

void Sortcontact(struct Contact* ps)
{
	qsort(ps->data, sizeof(ps->data) / sizeof(ps->data[0]), sizeof(ps->data[0]), cmp);
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}
