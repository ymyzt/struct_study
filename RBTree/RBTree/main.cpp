#include "RBTree.h"
int main()
{
	RBTree<int> * rb_tree = new RBTree<int>();
	int arry[6] = { 1, 5, 4, 3, 2, 6 };
	for (int i = 0; i < 6; i++)
	{
		rb_tree->insert(arry[i]);
		rb_tree->print();
		rb_tree->preOrder();
		cout << "-------------------" << endl;
	}
	cout << "Ç°Ðò£º" << endl;
	rb_tree->preOrder();
	rb_tree->print();
	system("pause");
	return 0;
}