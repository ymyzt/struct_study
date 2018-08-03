#ifndef _BSTREE_H_
#define _BSTREE_H_
#include "BSTNode.h"
template <class  T>
class BSTree{//���������
	private:
		BSTNode<T> *mRoot;    // �����
	public:
		BSTree();
		~BSTree();
	
		// ǰ�����"������"11
		void preOrder();
		// �������"������"11
		void inOrder();
		// �������"������"11
		void postOrder();
	
		// (�ݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�11
		BSTNode<T>* search(T key);
		// (�ǵݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�11
		BSTNode<T>* iterativeSearch(T key);
	
		// ������С��㣺������С���ļ�ֵ��11
		T minimum();
		// ��������㣺���������ļ�ֵ��11
		T maximum();
	
		// �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
		BSTNode<T>* successor(BSTNode<T> *x);
		// �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
		BSTNode<T>* predecessor(BSTNode<T> *x);
	
		// �����(keyΪ�ڵ��ֵ)���뵽��������
		void insert(T key);
	
		// ɾ�����(keyΪ�ڵ��ֵ)
		void remove(T key);
	
		// ���ٶ�����
		void destroy();
	
		// ��ӡ������
		void print();
	private:
		// ǰ�����"������"11
		void preOrder(BSTNode<T>* tree) const;
		// �������"������"11
		void inOrder(BSTNode<T>* tree) const;
		// �������"������"11
		void postOrder(BSTNode<T>* tree) const;
	
		// (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�11
		BSTNode<T>* search(BSTNode<T>* x, T key) const;
		// (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�11
		BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;
	
		// ������С��㣺����treeΪ�����Ķ���������С��㡣11
		BSTNode<T>* minimum(BSTNode<T>* tree);
		// ��������㣺����treeΪ�����Ķ�����������㡣11
		BSTNode<T>* maximum(BSTNode<T>* tree);
	
		// �����(z)���뵽������(tree)��11
		void insert(BSTNode<T>* tree, BSTNode<T>* z);
	
		// ɾ��������(tree)�еĽ��(z)�������ر�ɾ���Ľ��11
		BSTNode<T>* remove(BSTNode<T>* tree, BSTNode<T> *z);
	
		// ���ٶ�����11
		void destroy(BSTNode<T>* &tree);
	
		// ��ӡ������11
		void print(BSTNode<T>* tree, T key, int direction);
};
#endif
#include <iostream>
using namespace std;
template<class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const//ǰ�����
{
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}

}
template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  BSTree<T>::postOrder(BSTNode<T>* tree) const//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		inOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}

// ǰ�����"������"11
template<class T>
void  BSTree<T>::preOrder()
{
	this->preOrder(this->mRoot);
}
// �������"������"11
template<class T>
void BSTree<T>::inOrder()
{
	this->inOrder(this->mRoot);
}
// �������"������"11
template<class T>
void BSTree<T>::postOrder()
{
	this->postOrder(this->mRoot);
}
template<class T>
// (�ݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
BSTNode<T> *BSTree<T>::search(BSTNode<T>* tree, T key) const
{
	if (tree == NULL)
		return NULL;
	BSTNode<T> *result = NULL;
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
BSTNode<T> *BSTree<T>::search(T key)
{
	return search(this->mRoot, key);
}
// (�ǵݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T> *tree,T key) const
{
	BSTNode<T> *result = NULL;
	BSTNode<T> *temp = NULL;
	temp = tree;
	while (temp != NULL)
	{
		if (temp->key == key)
		{
			result = temp;
			break;
		}
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
BSTNode<T>* BSTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(this->mRoot, key);
}
// ������С��㣺����treeΪ�����Ķ���������С��㡣
template <class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	BSTNode<T> *result = tree;

	while (result->left != NULL)
	{
		result = result->left;
	}
	return result;
}
template <class T>
T BSTree<T>::minimum()
{
	if (minimum(this->mRoot))
		return minimum(this->mRoot)->key;
	return 0;
}
// ��������㣺����treeΪ�����Ķ�����������㡣
template <class T>
BSTNode<T>*  BSTree<T>::maximum(BSTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	BSTNode<T> *result = tree;

	while (result->right != NULL)
	{
		result = result->right;
	}
	return result;
}
template <class T>
T  BSTree<T>::maximum()
{
	if (maximum(this->mRoot))
		return maximum(this->mRoot)->key;
	return 0;
}
// �����(z)���뵽������(tree)��
template <class T>
void  BSTree<T>::insert(BSTNode<T>* tree, BSTNode<T>* z)
{
	if (tree == NULL)
	{
		cout << "Ŀ����Ϊ��!" << endl;
		if (this->mRoot)
			tree = this->mRoot;
		else
			tree = this->mRoot = z;
		return;
	}
	BSTNode<T> *temp = tree;
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
// ɾ��������(tree)�еĽ��(z)�������ر�ɾ���Ľ��
template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* tree, BSTNode<T> *z)
{
	//BSTNode<T> *temp = NULL;
	BSTNode<T> *successornode = NULL;
	BSTNode<T> *temp = search(tree, z->key);
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
// ���ٶ�����
template <class T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
	if (tree->left != NULL)
		destroy(tree->left)
	if(tree->right != NULL)
		destroy(tree->right)
	delete tree;
	tree = NULL;
}
// ��ӡ������  direction 0���ڵ�  1�� 2��
template <class T>
void BSTree<T>::print(BSTNode<T>* tree, T key, int direction)
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
// �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x)
{
	if (x == NULL)
		return NULL;
	if (x->right)//�����ӽڵ�
		return minimum(x->right);
	else
	{
		BSTNode<T> *temp = x->parent;
		while (temp)
		{
			if (temp->left&&temp->left == x)//������  �ýڵ�Ϊ���ӽڵ�
				break;
			else
			{
				x = x->parent;
				temp = x->parent;
			}
				
		}
		return temp;
	}
}
// �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
	if (x == NULL)
		return NULL;
	if (x->left)//�����ӽڵ�
		return maximum(x->left);
	else
	{
		BSTNode<T> *temp = x->parent;
		while (temp)
		{
			if (temp->right&&temp->right == x)//������  �ýڵ�Ϊ���ӽڵ�
				break;
			else
			{
				x = x->parent;
				temp = x->parent;
			}

		}
		return temp;
	}
}
// �����(keyΪ�ڵ��ֵ)���뵽��������
template <class T>
void BSTree<T>::insert(T key)
{
	BSTNode<T> * node = new BSTNode<T>(key, NULL, NULL, NULL);
	insert(this->mRoot, node);
}

// ɾ�����(keyΪ�ڵ��ֵ)
template <class T>
void BSTree<T>::remove(T key)
{
	BSTNode<T> *node = search(key);
	remove(this->mRoot, node);
}

// ���ٶ�����
template <class T>
void BSTree<T>::destroy()
{
	destroy(&(this->mRoot));
}

// ��ӡ������
template <class T>
void BSTree<T>::print()
{
	if (this->mRoot)
		print(this->mRoot, this->mRoot->key, 0);
	else
		cout << "����!" << endl;
}
template <class T>
BSTree<T>::BSTree()
{
	this->mRoot = NULL;
}
template <class T>
BSTree<T>::~BSTree()
{
	this->destroy();
}