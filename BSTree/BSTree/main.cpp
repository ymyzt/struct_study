#include "BSTree.h"
int main()
{
	BSTree<int> * BTree = new BSTree<int>();
	int arry[6] = { 1 ,5 ,4, 3 ,2, 6 };
	for (int i = 0; i < 6; i++)
	{
		BTree->insert(arry[i]);
	}
	cout << "前序：" << endl;
	BTree->preOrder();
	cout << "---------------------" << endl;
	cout << "中序：" << endl;
	BTree->inOrder();
	cout << "---------------------" << endl;
	cout << "后序：" << endl;
	BTree->postOrder();
	cout << "---------------------" << endl;
	cout << "最小：" << BTree->minimum()<< endl;
	cout << "---------------------" << endl;
	cout << "最大：" << BTree->maximum() << endl;
	cout << "---------------------" << endl;
	BTree->print();
	cout << "删除3:" << endl;
	BTree->remove(3);
	cout << "---------------------" << endl;
	BTree->inOrder();
	system("pause");
	return 0;
}