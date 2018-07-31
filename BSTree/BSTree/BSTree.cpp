#include "BSTree.h"
#include <iostream>
using namespace std;
template<class T>
void BSTree::preOrder(BSTNode<T>* tree)//前序遍历
{	
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->left);
	}
	
}
template<class T>
void BSTree::inOrder(BSTNode<T>* tree)//中序遍历
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  BSTree::postOrder(BSTNode<T>* tree)//后序遍历
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		inOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}
// (递归实现)查找"二叉树"中键值为key的节点
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
// (非递归实现)查找"二叉树"中键值为key的节点
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
// 查找最小结点：返回tree为根结点的二叉树的最小结点。
template <class T>
BSTNode<T>* BSTree::minimum(BSTNode<T>* tree)
{
	BSTNode<T> *result = tree;

	while (result->left != NULL)
	{
		result = result->left;
	}
	return result;
}
// 查找最大结点：返回tree为根结点的二叉树的最大结点。
template <class T>
BSTNode<T>*  BSTree::maximum(BSTNode<T>* tree)
{
	BSTNode<T> *result = tree;

	while (result->right != NULL)
	{
		result = result->right;
	}
	return result;
}
// 将结点(z)插入到二叉树(tree)中
template <class T>
void  BSTree::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{

}