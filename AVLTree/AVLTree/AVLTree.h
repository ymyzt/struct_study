#ifndef _AVLTREE_H_  
#define _AVLTREE_H_
#include "AVLTreeNode.h"
template <class T>
class AVLTree {
private:
	AVLTreeNode<T> *mRoot;    // �����

public:
	AVLTree();
	~AVLTree();

	// ��ȡ���ĸ߶�
	int height();
	// ��ȡ���ĸ߶�
	int max(int a, int b);

	// ǰ�����"AVL��"
	void preOrder();
	// �������"AVL��"
	void inOrder();
	// �������"AVL��"
	void postOrder();

	// (�ݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* search(T key);
	// (�ǵݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* iterativeSearch(T key);

	// ������С��㣺������С���ļ�ֵ��
	T minimum();
	// ��������㣺���������ļ�ֵ��
	T maximum();

	// �����(keyΪ�ڵ��ֵ)���뵽AVL����
	void insert(T key);

	// ɾ�����(keyΪ�ڵ��ֵ)
	void remove(T key);

	// ����AVL��
	void destroy();

	// ��ӡAVL��
	void print();
private:
	// ��ȡ���ĸ߶�
	int height(AVLTreeNode<T>* tree);

	// ǰ�����"AVL��"
	void preOrder(AVLTreeNode<T>* tree) const;
	// �������"AVL��"
	void inOrder(AVLTreeNode<T>* tree) const;
	// �������"AVL��"
	void postOrder(AVLTreeNode<T>* tree) const;

	// (�ݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
	// (�ǵݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

	// ������С��㣺����treeΪ������AVL������С��㡣
	AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
	// ��������㣺����treeΪ������AVL��������㡣
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	// LL�������Ӧ�����(����ת)��
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

	// RR�����Ҷ�Ӧ�����(�ҵ���ת)��
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

	// LR�����Ҷ�Ӧ�����(��˫��ת)��
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

	// RL�������Ӧ�����(��˫��ת)��
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

	// �����(z)���뵽AVL��(tree)��
	AVLTreeNode<T>* insert(AVLTreeNode<T>* tree, T key);

	// ɾ��AVL��(tree)�еĽ��(z)�������ر�ɾ���Ľ��
	AVLTreeNode<T>* remove(AVLTreeNode<T>* tree, AVLTreeNode<T>* z);

	// ����AVL��
	void destroy(AVLTreeNode<T>* &tree);

	// ��ӡAVL��
	void print(AVLTreeNode<T>* tree, T key, int direction);
};
#include <iostream>
using namespace std;
template<class T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const//ǰ�����
{
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}

}
template<class T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		inOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}

// ǰ�����"AVL��"11
template<class T>
void  AVLTree<T>::preOrder()
{
	this->preOrder(this->mRoot);
}
// �������"AVL��"11
template<class T>
void AVLTree<T>::inOrder()
{
	this->inOrder(this->mRoot);
}
// �������"AVL��"11
template<class T>
void AVLTree<T>::postOrder()
{
	this->postOrder(this->mRoot);
}
template<class T>
// (�ݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
AVLTreeNode<T> *AVLTree<T>::search(AVLTreeNode<T>* tree, T key) const
{
	if (tree == NULL)
		return NULL;
	AVLTreeNode<T> *result = NULL;
	if (tree->key == key)
		result = tree;
	else if (tree->key < key)
		result = search(tree->right, key);
	else
		result = search(tree->left, key);
	return result;
	//if (tree == NULL || tree->key == key)
	//	return x;
	//
	//if (key < tree->key)
	//	return search(tree->left, key);
	//else
	//	return search(tree->right, key);
}
template<class T>
AVLTreeNode<T> *AVLTree<T>::search(T key)
{
	return search(this->mRoot, key);
}
// (�ǵݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
template<class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(AVLTreeNode<T> *tree, T key) const
{
	AVLTreeNode<T> *result = NULL;
	AVLTreeNode<T> *temp = NULL;
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
	//while ((x != NULL) && (x->key != key))
	//{
	//	if (key < x->key)
	//		x = x->left;
	//	else
	//		x = x->right;
	//}
	//
	//return x;
}
template<class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(this->mRoot, key);
}
// ������С��㣺����treeΪ������AVL������С��㡣
template <class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	AVLTreeNode<T> *result = tree;

	while (result->left != NULL)
	{
		result = result->left;
	}
	return result;
}
template <class T>
T AVLTree<T>::minimum()
{
	if (minimum(this->mRoot))
		return minimum(this->mRoot)->key;
	return 0;
}
// ��������㣺����treeΪ������AVL��������㡣
template <class T>
AVLTreeNode<T>*  AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	AVLTreeNode<T> *result = tree;

	while (result->right != NULL)
	{
		result = result->right;
	}
	return result;
}
template <class T>
T  AVLTree<T>::maximum()
{
	if (maximum(this->mRoot))
		return maximum(this->mRoot)->key;
	return 0;
}
// �����(z)���뵽AVL��(tree)��
template <class T>
AVLTreeNode<T>*  AVLTree<T>::insert(AVLTreeNode<T>* tree, T key)
{
	AVLTreeNode<T> * z = new AVLTreeNode<T>(key, NULL, NULL);
	if (tree == NULL)
	{
		cout << "Ŀ����Ϊ��!" << endl;
		if (this->mRoot)
			tree = this->mRoot;
		else
			tree = this->mRoot = z;
		return;
	}
	AVLTreeNode<T> *temp = tree;
	while (tree != NULL)
	{
		temp = tree;
		if (tree->key < z->key)
			tree = tree->right;
		else
			tree = tree->left;

	}
	if (temp->key < z->key)
		temp->right = z;
	else
		temp->left = z;
	z->parent = temp;
}
// ɾ��AVL��(tree)�еĽ��(z)�������ر�ɾ���Ľ��
template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* tree, AVLTreeNode<T> *z)
{
	//AVLTreeNode<T> *temp = NULL;
	AVLTreeNode<T> *successornode = NULL;
	AVLTreeNode<T> *temp = search(tree, z->key);
	if (temp == NULL)
	{
		return NULL;
	}
	else if (temp->left == NULL || temp->right == NULL)//�����ӽڵ����û���ӽڵ�
	{
		successornode = temp->left ? temp->left : temp->right;
		if (temp->parent == NULL)
		{
			tree = successornode;
			return temp;
		}
		temp->parent->left == temp ? temp->parent->left = successornode : temp->parent->right = successornode;
		if (successornode)
			successornode->parent = temp->parent;
	}
	else//˫�ӽڵ�
	{
		successornode = successor(temp);
		temp->key = successornode->key;
		temp = remove(successornode->parent, successornode);
	}
	return temp;
}
// ����AVL��
template <class T>
void AVLTree<T>::destroy(AVLTreeNode<T>* &tree)
{
	if (tree->left != NULL)
		destroy(tree->left)
	if(tree->right != NULL)
		destroy(tree->right)
	delete tree;
	tree = NULL;
}
// ��ӡAVL��  direction 0���ڵ�  1�� 2��
template <class T>
void AVLTree<T>::print(AVLTreeNode<T>* tree, T key, int direction)
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
// �����(keyΪ�ڵ��ֵ)���뵽AVL����
template <class T>
void AVLTree<T>::insert(T key)
{
	insert(this->mRoot, key);
}

// ɾ�����(keyΪ�ڵ��ֵ)
template <class T>
void AVLTree<T>::remove(T key)
{
	AVLTreeNode<T> *node = search(key);
	remove(this->mRoot, node);
}

// ����AVL��
template <class T>
void AVLTree<T>::destroy()
{
	destroy(&(this->mRoot));
}

// ��ӡAVL��
template <class T>
void AVLTree<T>::print()
{
	if (this->mRoot)
		print(this->mRoot, this->mRoot->key, 0);
	else
		cout << "����!" << endl;
}
template <class T>
AVLTree<T>::AVLTree()
{
	this->mRoot = NULL;
}
template <class T>
AVLTree<T>::~AVLTree()
{
	this->destroy();
}


#endif