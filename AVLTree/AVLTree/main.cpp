#include "AVLTree.h"
int main()
{
	AVLTree<int> * avl_tree = new AVLTree<int>();
	int arry[6] = { 1, 5, 4, 3, 2, 6 };
	for (int i = 0; i < 6; i++)
	{
		avl_tree->insert(arry[i]);
	}
	cout << "ǰ��" << endl;
	avl_tree->preOrder();
	cout << "---------------------" << endl;
	cout << "����" << endl;
	avl_tree->inOrder();
	cout << "---------------------" << endl;
	cout << "����" << endl;
	avl_tree->postOrder();
	cout << "---------------------" << endl;
	cout << "��С��" << avl_tree->minimum() << endl;
	cout << "---------------------" << endl;
	cout << "���" << avl_tree->maximum() << endl;
	cout << "---------------------" << endl;
	avl_tree->print();
	cout << "ɾ��3:" << endl;
	avl_tree->remove(3);
	cout << "---------------------" << endl;
	avl_tree->inOrder();
	system("pause");
	return 0;
}