#ifndef _BSTREE_H_
#define _BSTREE_H_
#include "BSTNode.h"
template <class  T>
class BSTree{//二叉查找树
	private:
		BSTNode<T> *mRoot;    // 根结点
	public:
		BSTree();
		~BSTree();
	
		// 前序遍历"二叉树"11
		void preOrder();
		// 中序遍历"二叉树"11
		void inOrder();
		// 后序遍历"二叉树"11
		void postOrder();
	
		// (递归实现)查找"二叉树"中键值为key的节点11
		BSTNode<T>* search(T key);
		// (非递归实现)查找"二叉树"中键值为key的节点11
		BSTNode<T>* iterativeSearch(T key);
	
		// 查找最小结点：返回最小结点的键值。11
		T minimum();
		// 查找最大结点：返回最大结点的键值。11
		T maximum();
	
		// 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
		BSTNode<T>* successor(BSTNode<T> *x);
		// 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
		BSTNode<T>* predecessor(BSTNode<T> *x);
	
		// 将结点(key为节点键值)插入到二叉树中
		void insert(T key);
	
		// 删除结点(key为节点键值)
		void remove(T key);
	
		// 销毁二叉树
		void destroy();
	
		// 打印二叉树
		void print();
	private:
		// 前序遍历"二叉树"11
		void preOrder(BSTNode<T>* tree) const;
		// 中序遍历"二叉树"11
		void inOrder(BSTNode<T>* tree) const;
		// 后序遍历"二叉树"11
		void postOrder(BSTNode<T>* tree) const;
	
		// (递归实现)查找"二叉树x"中键值为key的节点11
		BSTNode<T>* search(BSTNode<T>* x, T key) const;
		// (非递归实现)查找"二叉树x"中键值为key的节点11
		BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;
	
		// 查找最小结点：返回tree为根结点的二叉树的最小结点。11
		BSTNode<T>* minimum(BSTNode<T>* tree);
		// 查找最大结点：返回tree为根结点的二叉树的最大结点。11
		BSTNode<T>* maximum(BSTNode<T>* tree);
	
		// 将结点(z)插入到二叉树(tree)中11
		void insert(BSTNode<T>* tree, BSTNode<T>* z);
	
		// 删除二叉树(tree)中的结点(z)，并返回被删除的结点11
		BSTNode<T>* remove(BSTNode<T>* tree, BSTNode<T> *z);
	
		// 销毁二叉树11
		void destroy(BSTNode<T>* &tree);
	
		// 打印二叉树11
		void print(BSTNode<T>* tree, T key, int direction);
};
#endif
#include <iostream>
using namespace std;
template<class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const//前序遍历
{
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}

}
template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const//中序遍历
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  BSTree<T>::postOrder(BSTNode<T>* tree) const//后序遍历
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		inOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}

// 前序遍历"二叉树"11
template<class T>
void  BSTree<T>::preOrder()
{
	this->preOrder(this->mRoot);
}
// 中序遍历"二叉树"11
template<class T>
void BSTree<T>::inOrder()
{
	this->inOrder(this->mRoot);
}
// 后序遍历"二叉树"11
template<class T>
void BSTree<T>::postOrder()
{
	this->postOrder(this->mRoot);
}
template<class T>
// (递归实现)查找"二叉树"中键值为key的节点
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
// (非递归实现)查找"二叉树"中键值为key的节点
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
// 查找最小结点：返回tree为根结点的二叉树的最小结点。
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
// 查找最大结点：返回tree为根结点的二叉树的最大结点。
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
// 将结点(z)插入到二叉树(tree)中
template <class T>
void  BSTree<T>::insert(BSTNode<T>* tree, BSTNode<T>* z)
{
	if (tree == NULL)
	{
		cout << "目标树为空!" << endl;
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
// 删除二叉树(tree)中的结点(z)，并返回被删除的结点
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
	else if (temp->left == NULL || temp->right == NULL)//单个子节点或者没有子节点
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
	else//双子节点
	{
		successornode = successor(temp);
		temp->key = successornode->key;
		temp = remove(successornode->parent, successornode);
	}
	return temp;
}
// 销毁二叉树
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
// 打印二叉树  direction 0根节点  1左 2右
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
// 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x)
{
	if (x == NULL)
		return NULL;
	if (x->right)//有右子节点
		return minimum(x->right);
	else
	{
		BSTNode<T> *temp = x->parent;
		while (temp)
		{
			if (temp->left&&temp->left == x)//往上找  该节点为左子节点
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
// 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
	if (x == NULL)
		return NULL;
	if (x->left)//有左子节点
		return maximum(x->left);
	else
	{
		BSTNode<T> *temp = x->parent;
		while (temp)
		{
			if (temp->right&&temp->right == x)//往上找  该节点为右子节点
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
// 将结点(key为节点键值)插入到二叉树中
template <class T>
void BSTree<T>::insert(T key)
{
	BSTNode<T> * node = new BSTNode<T>(key, NULL, NULL, NULL);
	insert(this->mRoot, node);
}

// 删除结点(key为节点键值)
template <class T>
void BSTree<T>::remove(T key)
{
	BSTNode<T> *node = search(key);
	remove(this->mRoot, node);
}

// 销毁二叉树
template <class T>
void BSTree<T>::destroy()
{
	destroy(&(this->mRoot));
}

// 打印二叉树
template <class T>
void BSTree<T>::print()
{
	if (this->mRoot)
		print(this->mRoot, this->mRoot->key, 0);
	else
		cout << "空树!" << endl;
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