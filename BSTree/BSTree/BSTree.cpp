#include "BSTree.h"
#include <iostream>
using namespace std;
template<class T>
void BSTree::preOrder(BSTNode<T>* tree)//ǰ�����
{	
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->left);
	}
	
}
template<class T>
void BSTree::inOrder(BSTNode<T>* tree)//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  BSTree::postOrder(BSTNode<T>* tree)//�������
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		inOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}
// (�ݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
template<class T>
BSTNode<T> *BSTree::search(BSTNode<T>* tree,T key) const
{
	if (tree == NULL)
		return NULL;
	BSTNode<T> *result = NULL;
	if (tree->key == key)
		result =  tree;
	else if (tree->key<key)
		result =  search(tree->left, key);
	else
		result =  search(tree->right, key);
	return result;
}
template<class T>
BSTNode<T> *BSTree::search(T key)
{
	return search(this->mRoot, key);
}
// (�ǵݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
template<class T>
BSTNode<T>* BSTree::iterativeSearch(T key)
{
	BSTNode<T> *result = NULL;
	BSTNode<T> *temp = NULL;
	temp = this->mRoot;
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
}
// ������С��㣺����treeΪ�����Ķ���������С��㡣
template <class T>
BSTNode<T>* BSTree::minimum(BSTNode<T>* tree)
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
// ��������㣺����treeΪ�����Ķ�����������㡣
template <class T>
BSTNode<T>*  BSTree::maximum(BSTNode<T>* tree)
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
// �����(z)���뵽������(tree)��
template <class T>
void  BSTree::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
	if (tree == NULL)
	{
		cout << "����ʧ��" << endl;
		return;
	}
	BSTNode<T> *temp = tree;
	while (temp!=NULL)
	{
		if (temp->key < z->key)
			temp = temp->right;
		else
			temp = temp->left;

	}
	if (temp->key < z->key)
		temp->right = z;
	else
		temp->left = z;
}
// ɾ��������(tree)�еĽ��(z)�������ر�ɾ���Ľ��
template <class T>
BSTNode<T>* BSTree::remove(BSTNode<T>* &tree, BSTNode<T> *z)
{
	//BSTNode<T> *temp = NULL;
	BSTNode<T> *successornode = NULL;
	//temp = search(tree, z->key);
	if (z == NULL)
	{
		return NULL;
	}
	else if (z->left == NULL || z->right == NULL)//�����ӽڵ����û���ӽڵ�
	{
		successornode = z->left || z->right;
		if (successornode != NULL)
		{
			if (z->parent == NULL)
			{
				tree = successornode;
				return z;
			}
			z->parent->left == z ? z->parent->left = successornode : z->parent->right = successornode;
		}
	}
	else//˫�ӽڵ�
	{
		successornode = successor(temp);
		z->key = successornode->key;
		if (successornode->right)
			z->right = successornode->right;
		z = successornode;
	}
	return z;
}