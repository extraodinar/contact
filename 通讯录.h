#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include <stdio.h>
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};

void IniContact(struct Contact* ps);
void Addcontact(struct Contact* ps);
void Delcontact(struct Contact* ps);
void Seacontact(struct Contact* ps);
void Modcontact(struct Contact* ps);
void Showcontact(const struct Contact* ps);
void Sortcontact(struct Contact* ps);