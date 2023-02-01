#include "ͨѶ¼.h"
#include <string.h>
void IniContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void Addcontact(struct Contact* ps)
{
	if (ps->size == MAX)
		printf("ͨѶ¼����,�޷�����");
	else
	{
		printf("���������֣�>\n");
		scanf_s("%s", &ps->data[ps->size].name);
		printf("���������䣺>\n");
		scanf_s("%d", &ps->data[ps->size].age);
		printf("�������Ա�>\n");
		scanf_s("%s", ps->data[ps->size].sex);
		printf("��������룺>\n");
		scanf_s("%s", ps->data[ps->size].tele);
		printf("������סַ��>\n");
		scanf_s("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
void Delcontact(struct Contact* ps)
{
	if (ps->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	char name[MAX_NAME];
	printf("������Ҫɾ����ϵ�˵�����\n");
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
		printf("�޴���!!");
	else
	{
		int j = 0;
		for (j = 0; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
	}
	ps->size--;
	printf("ɾ���ɹ�\n");
}
void Showcontact(const struct Contact* ps)
{
	if (ps->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","סַ");
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
		printf("ͨѶ¼Ϊ�գ��޷��޸�\n");
    else
    {
		printf("��������Ҫ�޸���ϵ�˵�����\n");
		char name[MAX_NAME];
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (0 == strcmp(ps->data[i].name, name))
				break;
		}
    printf("������������>\n");
	scanf_s("%s", ps->data[i].name);
	printf("����������: >\n");
	scanf_s("%d", &ps->data[i].age);
	printf("�������Ա�: >\n");
	scanf_s("%s", ps->data[i].sex);
	printf("������绰����: >\n");
	scanf_s("%s", ps->data[i].tele);
	printf("�������ַ: >\n");
	scanf_s("%s", ps->data[i].addr);
    }
}
void Seacontact(struct Contact* ps)
{
	int i = 0;
		printf("��������Ҫ������ϵ�˵�����\n");
		char name[MAX_NAME];
		scanf_s("%s", name);
		for (i = 0; i < ps->size; i++)
		{
			if (0 == strcmp(ps->data[i].name, name))
				break;
		}
		if (i == ps->size)
			printf("���޴���\n");
		else
		{
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}
