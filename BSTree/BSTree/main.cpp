#include "BSTree.h"
int main()
{
	BSTree<int> * BTree = new BSTree<int>();
	int arry[6] = { 1 ,5 ,4, 3 ,2, 6 };
	for (int i = 0; i < 6; i++)
	{
		BTree->insert(arry[i]);
	}
	cout << "ǰ��" << endl;
	BTree->preOrder();
	cout << "---------------------" << endl;
	cout << "����" << endl;
	BTree->inOrder();
	cout << "---------------------" << endl;
	cout << "����" << endl;
	BTree->postOrder();
	cout << "---------------------" << endl;
	cout << "��С��" << BTree->minimum()<< endl;
	cout << "---------------------" << endl;
	cout << "���" << BTree->maximum() << endl;
	cout << "---------------------" << endl;
	BTree->print();
	cout << "ɾ��3:" << endl;
	BTree->remove(3);
	cout << "---------------------" << endl;
	BTree->inOrder();
	system("pause");
	return 0;
}