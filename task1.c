#include <stdio.h>
#include <stdlib.h>


typedef struct student{
	char name[10];
	char major[10];
	char hak[10];
	char* sex;
} student;


typedef struct Node {
	student stud;
	struct Node* next;
}Node;

/*
int main()
{
	
	student std[7] = { {"���μ�", "��������", "4�г�", "��"},
		{"����ȣ", "��������", "3�г�", "��"},
		{"������", "��������", "3�г�", "��"},
		{"������", "�������", "4�г�", "��"},
		{"�Ǽҿ�", "��������", "4�г�", "��"},
		{"��ٳ�", "��������", "2�г�", "��"}
	};


	student* st;
	st = std;


	for (int i = 0; i < 6; i++)
	{
		printf("%10s %10s %10s %2s    \n", st->name, st->major, st->hak, st->sex);
		st++;
	}
	
	Node* head = malloc(sizeof(Node));

	Node* node1 = malloc(sizeof(Node));
	Node* node2 = malloc(sizeof(Node));
	Node* node3 = malloc(sizeof(Node));
	Node* node4 = malloc(sizeof(Node));
	Node* node5 = malloc(sizeof(Node));
	Node* node6 = malloc(sizeof(Node));


	node1->stud = std[0];
	head->next = node1;

	node2->stud = std[1];
	node1->next = node2;

	node3->stud = std[2];
	node2->next = node3;

	node4->stud = std[3];
	node3->next = node4;

	node5->stud = std[4];
	node4->next = node5;

	node6->stud = std[5];
	node5->next = node6;

	node6->next = NULL;

	Node* cur = head->next;

	while (cur != NULL)
	{
		printf("%5s %5s %5s %2s \n", cur->stud.name, cur->stud.major, cur->stud.hak, cur->stud.sex);
		cur = cur->next;
	}

	free(node6);
	free(node5);
	free(node4);
	free(node3);
	free(node2);
	free(node1);
	free(head);






}*/