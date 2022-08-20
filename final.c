#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct profile
{
	int num;
	char name;
};
struct student
{
	struct profile pf;
	int year;	//�г�
	double grade;	//����
	struct student* next;
};

typedef struct student Student;


int main(void)
{
	FILE* ifp;
	int res;
	Student std;

	Student* head;
	Student* last;
	Student* node;

	head = NULL;
	last = NULL;

	printf("2020158048 Ȳ����\n\n");
	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("�Է������� ������ ����");
		return 1;
	}

	

	while (1)
	{
		res = fscanf(ifp, "%d%s%d%lf", &(std.pf.num), &(std.pf.name), &(std.year), &(std.grade));//�Է�
		if (res == EOF)
		{
			break;
		}

		if (std.pf.num > 0)//student ����ü�� �� ����
		{
			node = (Student*)malloc(sizeof(Student));
			node->pf.name = std.pf.name;
			node->pf.num = std.pf.num;
			node->year = std.year;
			node->grade = std.grade;
			node->next = NULL;

		}
		else
		{
			continue;
		}
		if (head == NULL)
		{
			head = node;
		}
		else
		{
			last->next = node;
		}
		last = node;

		printf("%d%5s%5d%5.1lf\n", node->pf.num, &(std.pf.name), node->year, node->grade);//���
	}


	fclose(ifp);

	return 0;


}