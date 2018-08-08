#ifndef _RBTREE_H_ 
#define _RBTREE_H_
#include "RBTreeNode.h"
template <class T>
class RBTree
{
public:
	RBTree();
	~RBTree();

	// ǰ�����"�����"
	void preOrder();
	// �������"�����"
	void inOrder();
	// �������"�����"
	void postOrder();

	// (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
	RBTreeNode<T>* search(T key);
	// (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
	RBTreeNode<T>* iterativeSearch(T key);

	// ������С��㣺������С���ļ�ֵ��
	T minimum();
	// ��������㣺���������ļ�ֵ��
	T maximum();

	// �ҽ��(x)�ĺ�̽�㡣��������"�����������ֵ���ڸý��"��"��С���"��
	RBTreeNode<T>* successor(RBTreeNode<T> *x);
	// �ҽ��(x)��ǰ����㡣��������"�����������ֵС�ڸý��"��"�����"��
	RBTreeNode<T>* predecessor(RBTreeNode<T> *x);

	// �����(keyΪ�ڵ��ֵ)���뵽�������
	void insert(T key);

	// ɾ�����(keyΪ�ڵ��ֵ)
	void remove(T key);

	// ���ٺ����
	void destroy();

	// ��ӡ�����
	void print();
private:
	// ǰ�����"�����"
	void preOrder(RBTreeNode<T>* tree) const;
	// �������"�����"
	void inOrder(RBTreeNode<T>* tree) const;
	// �������"�����"
	void postOrder(RBTreeNode<T>* tree) const;

	// (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBTreeNode<T>* search(RBTreeNode<T>* x, T key) const;
	// (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBTreeNode<T>* iterativeSearch(RBTreeNode<T>* x, T key) const;

	// ������С��㣺����treeΪ�����ĺ��������С��㡣
	RBTreeNode<T>* minimum(RBTreeNode<T>* tree);
	// ��������㣺����treeΪ�����ĺ����������㡣
	RBTreeNode<T>* maximum(RBTreeNode<T>* tree);

	// ����
	void LeftRotation(RBTreeNode<T>* &root, RBTreeNode<T>* x);
	// ����
	void RightRotation(RBTreeNode<T>* &root, RBTreeNode<T>* y);
	// ���뺯��
	void insert(RBTreeNode<T>* &root, RBTreeNode<T>* node);
	// ������������
	void insertFixUp(RBTreeNode<T>* &root, RBTreeNode<T>* node);
	// ɾ������
	void remove(RBTreeNode<T>* &root, RBTreeNode<T> *node);
	// ɾ����������
	void removeFixUp(RBTreeNode<T>* &root, RBTreeNode<T> *node, RBTreeNode<T> *parent);

	// ���ٺ����
	void destroy(RBTreeNode<T>* &tree);

	// ��ӡ�����
	void print(RBTreeNode<T>* tree, T key, int direction);
};
#include <iostream>
using namespace std;
template<class T>
void RBTree<T>::preOrder(RBTreeNode<T>* tree) const//ǰ�����
{
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}

}
template<class T>
void RBTree<T>::inOrder(RBTreeNode<T>* tree) const//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  RBTree<T>::postOrder(RBTreeNode<T>* tree) const//�������
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}
// ǰ�����"RB��"11
template<class T>
void  RBTree<T>::preOrder()
{
	this->preOrder(this->mRoot);
}
// �������"RB��"11
template<class T>
void RBTree<T>::inOrder()
{
	this->inOrder(this->mRoot);
}
// �������"RB��"11
template<class T>
void RBTree<T>::postOrder()
{
	this->postOrder(this->mRoot);
}
template<class T>
// (�ݹ�ʵ��)����"RB��"�м�ֵΪkey�Ľڵ�
RBTreeNode<T> *RBTree<T>::search(RBTreeNode<T>* tree, T key) const
{
	if (tree == NULL)
		return NULL;
	RBTreeNode<T> *result = NULL;
	if (tree->key == key)
		result = tree;
	else if (tree->key < key)
		result = search(tree->right, key);
	else
		result = search(tree->left, key);
	return result;
}
template<class T>
RBTreeNode<T> *RBTree<T>::search(T key)
{
	return search(this->mRoot, key);
}
// (�ǵݹ�ʵ��)����"RB��"�м�ֵΪkey�Ľڵ�
template<class T>
RBTreeNode<T>* RBTree<T>::iterativeSearch(RBTreeNode<T> *tree, T key) const
{
	RBTreeNode<T> *result = NULL;
	RBTreeNode<T> *temp = NULL;
	temp = tree;
	while (temp != NULL &&temp->key != key)
	{
		result = temp;
		if (temp->key < key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return result;
}
template<class T>
RBTreeNode<T>* RBTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(this->mRoot, key);
}
// ������С��㣺����treeΪ������RB������С��㡣
template <class T>
RBTreeNode<T>* RBTree<T>::minimum(RBTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	RBTreeNode<T> *result = tree;

	while (result->left != NULL)
	{
		result = result->left;
	}
	return result;
}
template <class T>
T RBTree<T>::minimum()
{
	if (minimum(this->mRoot))
		return minimum(this->mRoot)->key;
	return 0;
}
// ��������㣺����treeΪ������RB��������㡣
template <class T>
RBTreeNode<T>*  RBTree<T>::maximum(RBTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	RBTreeNode<T> *result = tree;

	while (result->right != NULL)
	{
		result = result->right;
	}
	return result;
}
template <class T>
T  RBTree<T>::maximum()
{
	if (maximum(this->mRoot))
		return maximum(this->mRoot)->key;
	return 0;
}
// �����(z)���뵽RB��(tree)��
template <class T>
RBTreeNode<T>*  RBTree<T>::insert(RBTreeNode<T>* tree, RBTreeNode<T>* z)
{
	if (tree == NULL)
	{
		if (this->mRoot)
			tree = z;
		else
		{
			cout << "Ŀ����Ϊ��!" << endl;
			tree = this->mRoot = z;
		}
	}
	else
	{
		RBTreeNode<T>* temp = tree;
		while (tree)
		{
			temp = tree;
			if (tree->left->key > z->key)
				tree = tree->left;
			else if (tree->right->key < z->key)
				tree = tree->right;
			else
				cout << "�Ѵ��ڽڵ�"<<z->key << endl;
		}
		if (temp->key < z->key)
			temp->right = z;
		else if (temp->key>z->key)
			temp->left = z;
		z->parent = temp;
	}	
	insertFixUp(tree, z);
	return tree;
}
template <class T>
void RBTree<T>::insertFixUp(RBTreeNode<T>* &tree, RBTreeNode<T> *z)
{
	if (tree == z)
	{
		z->color = Black;
	}
	else
	{
		while (1)
		{
			RBTreeNode<T> *z_p = z->parent;
			RBTreeNode<T> *z_g = z_p->parent;
			if (z_p->color != Black)
			{
				RBTreeNode<T>* z_u = z_p == z_g->left ? z_g->right : z_g->left;
				if (z_u->color == Red)
				{
					z_p->color = Red;
					z_u->color = Red;
					z_g->color = Black;
					z = z_g;
					if (z == tree)
						break;
				}
				else
				{
					if (z == z_p->right)
					{
						LeftRotation(z_p);
						z = z_p;
					}
					else
					{
						z_p->color = Black;
						z_g->color = Red;
						RightRotation(z_g);
						z = z_p;
						if (z_g == tree)
						{
							tree = z;
							break;
						}
							
					}
				}
			}
		}
	}
}
template <class T>
RBTreeNode<T>* RBTree<T>::remove(RBTreeNode<T>* tree, RBTreeNode<T> *z)
{
	//RBTreeNode<T> *temp = NULL;
	if (tree != NULL && z != NULL)
	{
		if (z->key < tree->key)
		{
			tree->left = remove(tree->left, z);
			if (height(tree->right) - height(tree->left) == 2)
			{
				RBTreeNode<T>* r = tree->right;
				if (height(r->left)>height(r->right))
					tree = rightLeftRotation(tree);
				else
					tree = RightRotation(tree);
			}
		}
		else if (z->key > tree->key)
		{
			tree->right = remove(tree->right, z);
			if (height(tree->left) - height(tree->right) == 2)
			{
				RBTreeNode<T>* r = tree->left;
				if (height(r->right) > height(r->left))
					tree = leftRightRotation(tree);
				else
					tree = LeftRotation(tree);
			}
		}
		else
		{
			RBTreeNode<T>* temp = NULL;
			if (tree->left && tree->right)
			{
				if (height(tree->left) > height(tree->right))
				{
					temp = maximum(tree->left);
					tree->key = temp->key;
					tree->left = remove(tree->left, temp);
				}
				else
				{
					temp = minimum(tree->right);
					tree->key = temp->key;
					tree->right = remove(tree->right, temp);
				}

			}
			else
			{
				temp = tree;
				if (tree->left)
					tree = tree->left;
				else if (tree->right)
					tree = tree->right;
				else
					tree = NULL;
				delete temp, temp = NULL;


			}
		}
		return tree;
	}
	else
		return NULL;

}
// ����RB��
template <class T>
void RBTree<T>::destroy(RBTreeNode<T>* &tree)
{
	if (tree->left != NULL)
		destroy(tree->left)
	if (tree->right != NULL)
		destroy(tree->right)
		delete tree;
	tree = NULL;
}
// ��ӡRB��  direction 0���ڵ�  1�� 2��
template <class T>
void RBTree<T>::print(RBTreeNode<T>* tree, T key, int direction)
{
	if (direction == 0)
	{
		cout << tree->key << " is root!" << endl;
	}
	else if (direction == 1)
	{
		cout << key << " 's left node is " << tree->key << "  !" << endl;
	}
	else
	{
		cout << key << " 's right node is " << tree->key << "  !" << endl;
	}
	if (tree->left != NULL)
		print(tree->left, tree->key, 1);
	if (tree->right != NULL)
		print(tree->right, tree->key, 2);
}
// �����(keyΪ�ڵ��ֵ)���뵽RB����
template <class T>
void RBTree<T>::insert(T key)
{
	this->mRoot = insert(this->mRoot, key);
}

// ɾ�����(keyΪ�ڵ��ֵ)
template <class T>
void RBTree<T>::remove(T key)
{
	RBTreeNode<T> *node = search(key);
	remove(this->mRoot, node);
}

// ����RB��
template <class T>
void RBTree<T>::destroy()
{
	destroy(&(this->mRoot));
}
// LL�������Ӧ�����(����ת)��
template <class T>
RBTreeNode<T>* RBTree<T>::LeftRotation(RBTreeNode<T>* k2)
{
	RBTreeNode<T>* k1 = k2->right;
	k2->right = k1->left;
	k1->parent = k2->parent;
	k2->parent = k1;
	k1->left = k2;
	return k1;
}

// RR�����Ҷ�Ӧ�����(�ҵ���ת)��
template <class T>
RBTreeNode<T>* RBTree<T>::RightRotation(RBTreeNode<T>* k2)
{
	RBTreeNode<T>* k1 = k2->left;
	k2->left = k1->right;
	k1->parent = k2->parent;
	k2->parent = k1;
	k1->right = k2;
	return k1;
}

// LR�����Ҷ�Ӧ�����(��˫��ת)��
//template <class T>
//RBTreeNode<T>* RBTree<T>::leftRightRotation(RBTreeNode<T>* k2)
//{
//	k2->left = RightRotation(k2->left);
//	return LeftRotation(k2);
//}
//
//// RL�������Ӧ�����(��˫��ת)��
//template <class T>
//RBTreeNode<T>* RBTree<T>::rightLeftRotation(RBTreeNode<T>* k2)
//{
//	k2->right = LeftRotation(k2->right);
//	return RightRotation(k2);
//}
// ��ӡRB��
template <class T>
void RBTree<T>::print()
{
	if (this->mRoot)
		print(this->mRoot, this->mRoot->key, 0);
	else
		cout << "����!" << endl;
}
template <class T>
RBTree<T>::RBTree()
{
	this->mRoot = NULL;
}
template <class T>
RBTree<T>::~RBTree()
{
	this->destroy();
}

#endif
