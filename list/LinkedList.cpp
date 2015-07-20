#include <iostream>
using namespace std;
#define DATA int

typedef struct NODE
{
	DATA data;
	struct NODE* next;
};

typedef struct LinkedList
{
	NODE* head;
	NODE* before;
	NODE* cur;
}LinkedList;

NODE* createNode(DATA data);
void LInit(LinkedList *plist);
void push(LinkedList *plist, DATA data);
bool LGetFirst(LinkedList *plist, DATA* FirstData);



NODE* createNode(DATA data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void LInit(LinkedList *plist)
{
	plist->head = createNode(0);	
}

void push(LinkedList *plist, DATA data)
{
	NODE* newNode = createNode(data);
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
}

bool LGetFirst(LinkedList *plist, DATA* FirstData)
{
	if (plist->head->next == NULL)
		return false;

	plist->before = plist->head;
	plist->cur = plist->head->next;
	
	*FirstData = plist->cur->data;
	return true;
}

bool LGetNext(LinkedList *plist, DATA* pData)
{
	if (plist->cur->next == NULL)
		return false;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pData = plist->cur->data;

	return true;
}

DATA Lpop(LinkedList *plist)
{	
	NODE* delNode = plist->cur;
	int delData = delNode->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delNode);
	
	return delData;
	
}

int main()
{
	LinkedList A;
	DATA data;

	LInit(&A);
	push(&A, 3);
	push(&A, 4);
	push(&A, 1);

	if (LGetFirst(&A, &data))
	{
		cout << data << " ";
		while (LGetNext(&A, &data))
			cout << data << " ";
		cout << endl; 
	}

	Lpop(&A);
	
	if (LGetFirst(&A, &data))
	{
		cout << data << " ";
		while (LGetNext(&A, &data))
			cout << data << " ";
		cout << endl;
	}

	return 0;
}
