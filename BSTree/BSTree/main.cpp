#include "BSTree.h"
int main()
{
	BSTree<int> * BTree = new BSTree<int>();
	int arry[10] = { 5, 3, 7, 6, 1, 2, 8, 9, 4, 10 };
	for (int i = 0; i < 10; i++)
	{
		BTree->insert(arry[i]);
	}
	BTree->print();
	BTree->remove(3);
	cout << "---------------------" << endl;
	BTree->print();
	system("pause");
	return 0;
}