#ifndef _RBTREE_H_ 
#define _RBTREE_H_
#include "RBTreeNode.h"
template <class T>
class RBTree
{
public:
	RBTree();
	~RBTree();

	// 前序遍历"红黑树"
	void preOrder();
	// 中序遍历"红黑树"
	void inOrder();
	// 后序遍历"红黑树"
	void postOrder();

	// (递归实现)查找"红黑树"中键值为key的节点
	RBTreeNode<T>* search(T key);
	// (非递归实现)查找"红黑树"中键值为key的节点
	RBTreeNode<T>* iterativeSearch(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();

	// 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
	RBTreeNode<T>* successor(RBTreeNode<T> *x);
	// 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
	RBTreeNode<T>* predecessor(RBTreeNode<T> *x);

	// 将结点(key为节点键值)插入到红黑树中
	void insert(T key);

	// 删除结点(key为节点键值)
	void remove(T key);

	// 销毁红黑树
	void destroy();

	// 打印红黑树
	void print();
private:
	RBTreeNode<T>* mRoot;
	// 前序遍历"红黑树"
	void preOrder(RBTreeNode<T>* tree) const;
	// 中序遍历"红黑树"
	void inOrder(RBTreeNode<T>* tree) const;
	// 后序遍历"红黑树"
	void postOrder(RBTreeNode<T>* tree) const;

	// (递归实现)查找"红黑树x"中键值为key的节点
	RBTreeNode<T>* search(RBTreeNode<T>* x, T key) const;
	// (非递归实现)查找"红黑树x"中键值为key的节点
	RBTreeNode<T>* iterativeSearch(RBTreeNode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的红黑树的最小结点。
	RBTreeNode<T>* minimum(RBTreeNode<T>* tree);
	// 查找最大结点：返回tree为根结点的红黑树的最大结点。
	RBTreeNode<T>* maximum(RBTreeNode<T>* tree);

	// 左旋
	RBTreeNode<T>* LeftRotation( RBTreeNode<T>*& x);
	// 右旋
	RBTreeNode<T>* RightRotation( RBTreeNode<T>*& y);
	// 插入函数
	void insert(RBTreeNode<T>* &root, RBTreeNode<T>* node);
	// 插入修正函数
	void insertFixUp(RBTreeNode<T>* &root, RBTreeNode<T>* node);
	// 删除函数
	RBTreeNode<T>* remove(RBTreeNode<T>* &root, RBTreeNode<T> *node);
	// 删除修正函数
	void removeFixUp(RBTreeNode<T>* &root, RBTreeNode<T> *node, RBTreeNode<T> *parent);

	// 销毁红黑树
	void destroy(RBTreeNode<T>* &tree);

	// 打印红黑树
	void print(RBTreeNode<T>* tree, T key, int direction);
};
#include <iostream>
using namespace std;
template<class T>
void RBTree<T>::preOrder(RBTreeNode<T>* tree) const//前序遍历
{
	if (tree != NULL)
	{
		cout << tree->key << " color is "<<tree->color << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}

}
template<class T>
void RBTree<T>::inOrder(RBTreeNode<T>* tree) const//中序遍历
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  RBTree<T>::postOrder(RBTreeNode<T>* tree) const//后序遍历
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}
// 前序遍历"RB树"11
template<class T>
void  RBTree<T>::preOrder()
{
	this->preOrder(this->mRoot);
}
// 中序遍历"RB树"11
template<class T>
void RBTree<T>::inOrder()
{
	this->inOrder(this->mRoot);
}
// 后序遍历"RB树"11
template<class T>
void RBTree<T>::postOrder()
{
	this->postOrder(this->mRoot);
}
template<class T>
// (递归实现)查找"RB树"中键值为key的节点
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
// (非递归实现)查找"RB树"中键值为key的节点
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
// 查找最小结点：返回tree为根结点的RB树的最小结点。
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
// 查找最大结点：返回tree为根结点的RB树的最大结点。
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
// 将结点(z)插入到RB树(tree)中
template <class T>
void  RBTree<T>::insert(RBTreeNode<T>* &tree, RBTreeNode<T>* z)
{
	RBTreeNode<T>* temp = tree;
	RBTreeNode<T>* temp2 = tree;
	if (tree == NULL)
	{
		if (this->mRoot)
			tree = z;
		else
		{
			cout << "目标树为空!" << endl;
			tree = this->mRoot = z;
		}
		temp = tree;
	}
	else
	{
		
		while (temp)
		{
			temp2 = temp;
			if (temp->key > z->key)
				temp = temp->left;
			else if (temp->key < z->key)
				temp = temp->right;
			else
				cout << "已存在节点"<<z->key << endl;
		}
		if (temp2->key < z->key)
			temp2->right = z;
		else if (temp2->key>z->key)
			temp2->left = z;
		z->parent = temp2;
	}	
	insertFixUp(this->mRoot, z);
	//return temp;
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
		while (z->parent)
		{
			RBTreeNode<T> *z_p = z->parent;
			RBTreeNode<T> *z_g = z_p->parent;
			if (z_p->color != Black)
			{
				RBTreeNode<T>* z_u = z_p == z_g->left ? z_g->right : z_g->left;
				if (z_u&&z_u->color == Red)
				{
					z_p->color = Black;
					z_u->color = Black;
					z_g->color = Red;
					z = z_g;
				}
				else
					{
						if (z_p == z_g->left)
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
							}
						}
						else
						{
							if (z == z_p->right)
							{
								z_p->color = Black;
								z_g->color = Red;
								LeftRotation(z_g);
								z = z_p;
							}
							else
							{
								RightRotation(z_p);
								z = z_p;
							}

						}
					}
				
			}
			else
			{
				z = tree;
				break;
			}

		}
		z->color = Black;
		tree = z;
	}
}
template <class T>
RBTreeNode<T>* RBTree<T>::remove(RBTreeNode<T>* &tree, RBTreeNode<T> *z)
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
// 销毁RB树
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
// 打印RB树  direction 0根节点  1左 2右
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
// 将结点(key为节点键值)插入到RB树中
template <class T>
void RBTree<T>::insert(T key)
{
	RBTreeNode<T>* z = new RBTreeNode<T>(key, Red, NULL, NULL, NULL);
	//this->mRoot = 
	insert(this->mRoot, z);
}

// 删除结点(key为节点键值)
template <class T>
void RBTree<T>::remove(T key)
{
	RBTreeNode<T> *node = search(key);
	remove(this->mRoot, node);
}

// 销毁RB树
template <class T>
void RBTree<T>::destroy()
{
	destroy(&(this->mRoot));
}
// LL：左左对应的情况(左单旋转)。
template <class T>
RBTreeNode<T>* RBTree<T>::LeftRotation(RBTreeNode<T>*& k2)
{
	RBTreeNode<T>* k1 = k2->right;
	RBTreeNode<T>* p = k2->parent;
	k2->right = k1->left;
	k1->parent = p;
	k2->parent = k1;
	k1->left = k2;
	if (p)
		p->left == k2 ? p->left = k1 : p->right = k1;
	return k1;
}

// RR：右右对应的情况(右单旋转)。
template <class T>
RBTreeNode<T>* RBTree<T>::RightRotation(RBTreeNode<T>*& k2)
{
	RBTreeNode<T>* k1 = k2->left;
	RBTreeNode<T>* p = k2->parent;
	k2->left = k1->right;
	k1->parent = p;
	k2->parent = k1;
	k1->right = k2;
	if (p)
		p->left == k2 ? p->left = k1 : p->right = k1;
	return k1;
}

// LR：左右对应的情况(左双旋转)。
//template <class T>
//RBTreeNode<T>* RBTree<T>::leftRightRotation(RBTreeNode<T>* k2)
//{
//	k2->left = RightRotation(k2->left);
//	return LeftRotation(k2);
//}
//
//// RL：右左对应的情况(右双旋转)。
//template <class T>
//RBTreeNode<T>* RBTree<T>::rightLeftRotation(RBTreeNode<T>* k2)
//{
//	k2->right = LeftRotation(k2->right);
//	return RightRotation(k2);
//}
// 打印RB树
template <class T>
void RBTree<T>::print()
{
	if (this->mRoot)
		print(this->mRoot, this->mRoot->key, 0);
	else
		cout << "空树!" << endl;
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
