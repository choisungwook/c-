#include <iostream>
using namespace std;

template <typename T>
class NODE
{
private:
	NODE* Lnext;
	NODE* Rnext;
	T _data;
public:
	NODE(T element)
	{
		_data = element;
		Lnext = NULL;
		Rnext = NULL;
	}
	NODE() 
	{
		_data = 0;
		Lnext = NULL;
		Rnext = NULL;
	}
	NODE* GetLNext() { return this->Lnext; }
	NODE* GetRNext() { return this->Rnext; }
	void SetLNext(NODE* NextNode) {	this->Lnext = NextNode;	}
	void SetRNext(NODE* NextNode) {	this->Rnext = NextNode;	}
	T Getdata()	{ return _data;	}
};

template <typename T>
class BinaryTree : public NODE < T >
{
private:
	NODE* root;
public:
	BinaryTree()
	{
		root = NULL;
	}
	void Insert(T data);
	NODE* GetRoot()	{ return root; }
	void MakeLeftsubTree(NODE* parent, NODE* child) { parent->SetLNext(child); }
	void MakeRightsubTree(NODE* parent, NODE* child) { parent->SetRNext(child); }
};


template <typename T>
void BinaryTree<T>::Insert(T data)
{
	NODE* curNode = this->GetRoot();
	NODE* parentNode = NULL;
	NODE* newNode = NULL;
	
	if (curNode != NULL)
	{
		if (curNode->Getdata() == data)
			return;

		parentNode = curNode;
		if (curNode->Getdata() > data)
			curNode = curNode->GetLNext();
		else
			curNode = curNode->GetRNext();
	}

	newNode = new NODE(data);
	
	if (parentNode != NULL)
	{
		if (parentNode->Getdata() > data)
			MakeLeftsubTree(parentNode, newNode);
		else
			MakeRightsubTree(parentNode, newNode);
	}
	else
	{
		this->root = newNode;
	}


}


int main()
{
	BinaryTree<int> T1;
	T1.Insert(32);
	T1.Insert(14);
	T1.Insert(44);
	return 0;
}
