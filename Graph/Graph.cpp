#include <iostream>
#include <cstdlib>
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

typedef struct Graph
{
	int numV;
	int numE;
	List *adjList;
}Graph;

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

void GraphInit(Graph *pg, int numOfv)
{
	pg->adjList = (List*)malloc(sizeof(List)*numOfv);
	
	pg->numE = 0;
	pg->numV = numOfv;

	for (int i = 0; i < numOfv; i++)	
		Linit(&(pg->adjList[i]));
}

void AddEdge(Graph *pg, int fromV, int toV)
{		
	Lpush(&(pg->adjList[fromV]),toV);	
	Lpush(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

void Showgraph(Graph *pg)
{
	for (int i = 1; i < pg->numV; i++)
	{
		cout << i << endl;
		Lprint(&(pg->adjList[i]));
	}
}

bool visit[10 + 1];

void DFS(Graph *pg,int index)
{
	visit[index] = true;
	cout << index << " ";
	
	NODE* cur = (pg->adjList[index]).head->next;
	
	while (cur != NULL)
	{
		if (visit[cur->data] == false)
			DFS(pg, cur->data);
		cur = cur->next;
	}

}


int main()
{
	Graph G;
	int total, start;
	int src, dst;

	cin >> total >> start;

	GraphInit(&G, total + 1);

	while ((cin >> src >> dst))	
		AddEdge(&G, src, dst);
	
	
	DFS(&G, start);
	cout << endl;
	

	return 0;
}
