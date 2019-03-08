#include<iostream>
using namespace std;
struct BiNode
{
	char data;
	BiNode *lchild, *rchild;
};
class BiTree
{
public:
	int empty();
	BiTree() { root = Creat(root); }
	~BiTree() { Release(root); }
	void Print_leafnode() { Print_leafnode(root); }
	
private:
	int front, rear;
	BiNode *root;
	void Print_leafnode(BiNode *bt);
	BiNode *Creat(BiNode *bt);
	void Release(BiNode *bt);
};
int main()
{
	while (1)
	{
		BiTree Bit;
		if (Bit.empty() == 1)
		{
			Bit.Print_leafnode();
			cout << endl;
		}
		else
		{
			cout << "NULL" << endl;
			break;
		}
	}
	return 0;
}
BiNode *BiTree::Creat(BiNode *bt)
{
	char ch;
	cin >> ch;
	if (ch == '#')bt = NULL;
	else
	{
		bt = new BiNode;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}
void BiTree::Release(BiNode* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}
void BiTree::Print_leafnode(BiNode *bt)
{
	if (bt == NULL) return;
	if (!bt->lchild && !bt->rchild)
		cout << bt->data<<" ";
	Print_leafnode(bt->lchild);
	Print_leafnode(bt->rchild);
}
int BiTree::empty()
{
	if (root == NULL)
		return 0;
	else
		return 1;
}