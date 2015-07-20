#include <iostream>
using namespace std;
#define DATA int

typedef struct NODE
{
	DATA data;
	struct NODE* next;
}NODE;

typedef struct LinkedList
{
	NODE* head;
}List;

NODE* createNode(DATA data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->next = NULL;
	newNode->data = data;

	return newNode;
}

void Linit(List* plist)
{
	plist->head = createNode(0);
}


int NodeCmp(int n1, int n2)
{
	if (n1 < n2)
		return 1;
	return 0;	
}

void Lpush(List *plist, DATA data)
{
	NODE* newNode = createNode(data);
	NODE* cur = plist->head;

	while (cur->next != NULL && NodeCmp(cur->next->data, data))
		cur = cur->next;

	newNode->next = cur->next;
	cur->next = newNode;	
}

void Lprint(List *plist)
{
	NODE* cur = plist->head->next;

	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

bool Lpop(List *plist, int *delData)
{
	if (plist->head->next == NULL)
		return false;

	NODE* delNode = plist->head->next;
	*delData = delNode->data;

	plist->head->next = delNode->next;
	free(delNode);
	return true;
	
}

int main()
{
	List A;
	DATA data;

	Linit(&A);
	Lpush(&A, 4);
	Lpush(&A, 3);
	Lpush(&A, 1);
	Lpush(&A, 2);
	Lpush(&A, 9);

	Lprint(&A);	
	Lpop(&A, &data);
	Lprint(&A);
	Lpop(&A, &data);
	Lprint(&A);
	Lpop(&A, &data);
	Lprint(&A);
	Lpop(&A, &data);
	Lprint(&A);
	Lpop(&A, &data);
	Lprint(&A);
	Lpop(&A, &data);
	Lprint(&A);
	return 0;
}
