#ifndef _AVLTREE_H_  
#define _AVLTREE_H_
#include "AVLTreeNode.h"
template <class T>
class AVLTree {
private:
	AVLTreeNode<T> *mRoot;    // 根结点

public:
	AVLTree();
	~AVLTree();

	// 获取树的高度//叶子节点为0 往上加 同一深度 高度可能不同 此高非彼高
	int height();
	// 
	int max(int a, int b);

	// 前序遍历"AVL树"
	void preOrder();
	// 中序遍历"AVL树"
	void inOrder();
	// 后序遍历"AVL树"
	void postOrder();

	// (递归实现)查找"AVL树"中键值为key的节点
	AVLTreeNode<T>* search(T key);
	// (非递归实现)查找"AVL树"中键值为key的节点
	AVLTreeNode<T>* iterativeSearch(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();

	// 将结点(key为节点键值)插入到AVL树中
	void insert(T key);

	// 删除结点(key为节点键值)
	void remove(T key);

	// 销毁AVL树
	void destroy();

	// 打印AVL树
	void print();
private:
	// 获取树的高度
	int height(AVLTreeNode<T>* tree);

	// 前序遍历"AVL树"
	void preOrder(AVLTreeNode<T>* tree) const;
	// 中序遍历"AVL树"
	void inOrder(AVLTreeNode<T>* tree) const;
	// 后序遍历"AVL树"
	void postOrder(AVLTreeNode<T>* tree) const;

	// (递归实现)查找"AVL树x"中键值为key的节点
	AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
	// (非递归实现)查找"AVL树x"中键值为key的节点
	AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的AVL树的最小结点。
	AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
	// 查找最大结点：返回tree为根结点的AVL树的最大结点。
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	// LL：左左对应的情况(左单旋转)。
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

	// RR：右右对应的情况(右单旋转)。
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

	// LR：左右对应的情况(左双旋转)。
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

	// RL：右左对应的情况(右双旋转)。
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

	// 将结点(z)插入到AVL树(tree)中
	AVLTreeNode<T>* insert(AVLTreeNode<T>* tree, T key);

	// 删除AVL树(tree)中的结点(z)，并返回被删除的结点
	AVLTreeNode<T>* remove(AVLTreeNode<T>* tree, AVLTreeNode<T>* z);
	// 销毁AVL树
	void destroy(AVLTreeNode<T>* &tree);

	// 打印AVL树
	void print(AVLTreeNode<T>* tree, T key, int direction);
};
#include <iostream>
using namespace std;
template<class T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const//前序遍历
{
	if (tree != NULL)
	{
		cout << tree->key << " " << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}

}
template<class T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const//中序遍历
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " " << endl;
		inOrder(tree->right);
	}
}
template<class T>
void  AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const//后序遍历
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " " << endl;
	}
}



template<class T>
int  AVLTree<T>::height()
{
	return height(this->mRoot);
}
template<class T>
int  AVLTree<T>::height(AVLTreeNode<T> *tree)
{
	return tree!=NULL ? tree->height : 0;
}
template<class T>
int  AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}
// 前序遍历"AVL树"11
template<class T>
void  AVLTree<T>::preOrder()
{
	this->preOrder(this->mRoot);
}
// 中序遍历"AVL树"11
template<class T>
void AVLTree<T>::inOrder()
{
	this->inOrder(this->mRoot);
}
// 后序遍历"AVL树"11
template<class T>
void AVLTree<T>::postOrder()
{
	this->postOrder(this->mRoot);
}
template<class T>
// (递归实现)查找"AVL树"中键值为key的节点
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
// (非递归实现)查找"AVL树"中键值为key的节点
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
// 查找最小结点：返回tree为根结点的AVL树的最小结点。
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
// 查找最大结点：返回tree为根结点的AVL树的最大结点。
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
// 将结点(z)插入到AVL树(tree)中
template <class T>
AVLTreeNode<T>*  AVLTree<T>::insert(AVLTreeNode<T>* tree, T key)//因为 有返回值 parent 可以不需要 
{
	if (tree == NULL)
	{
		AVLTreeNode<T> * z = new AVLTreeNode<T>(key, NULL, NULL);
		if (this->mRoot)
			tree = z;
		else
		{
			cout << "目标树为空!" << endl;
			tree = this->mRoot = z;
		}
	}
	else if(tree->key < key)
	{
		tree->right = insert(tree->right, key);
		if (height(tree->right) - height(tree->left) == 2)
		{
			if (key>tree->right->key)
				tree = rightRightRotation(tree);
			else
				tree = rightLeftRotation(tree);
		}
		
	}
	else
	{
		tree->left = insert(tree->left, key);
		if (height(tree->left) - height(tree->right) == 2)
		{
			if (key > tree->right->key)
				tree = leftRightRotation(tree);
			else
				tree = leftLeftRotation(tree);
		}
	}
	tree->height = max(height(tree->left), height(tree->right)) + 1; //叶子节点为0 往上加 同一深度 高度可能不同 此高非彼高
	return tree;
}
// 删除AVL树(tree)中的结点(z)，并返回被删除的结点
template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* tree, AVLTreeNode<T> *z)
{
	//AVLTreeNode<T> *temp = NULL;
	if (tree != NULL && z != NULL)
	{
		if (z->key < tree->key)
		{
			tree->left = remove(tree->left, z);
			if (height(tree->right) - height(tree->left) == 2)
			{
				AVLTreeNode<T>* r = tree->right;
				if (height(r->left)>height(r->right))
					tree = rightLeftRotation(tree);
				else
					tree = rightRightRotation(tree);
			}
		}
		else if (z->key > tree->key)
		{
			tree->right = remove(tree->right, z);
			if (height(tree->left) - height(tree->right) == 2)
			{
				AVLTreeNode<T>* r = tree->left;
				if (height(r->right) > height(r->left))
					tree = leftRightRotation(tree);
				else
					tree = leftLeftRotation(tree);
			}
		}
		else
		{
			AVLTreeNode<T>* temp = NULL;
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
// 销毁AVL树
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
// 打印AVL树  direction 0根节点  1左 2右
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
// 将结点(key为节点键值)插入到AVL树中
template <class T>
void AVLTree<T>::insert(T key)
{
	this->mRoot = insert(this->mRoot, key);
}

// 删除结点(key为节点键值)
template <class T>
void AVLTree<T>::remove(T key)
{
	AVLTreeNode<T> *node = search(key);
	remove(this->mRoot, node);
}

// 销毁AVL树
template <class T>
void AVLTree<T>::destroy()
{
	destroy(&(this->mRoot));
}
// LL：左左对应的情况(左单旋转)。
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T>* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
 	return k1;
}

// RR：右右对应的情况(右单旋转)。
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T>* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	return k1;
}

// LR：左右对应的情况(左双旋转)。
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k2)
{
	k2->left = rightRightRotation(k2->left);
	return leftLeftRotation(k2);
}

// RL：右左对应的情况(右双旋转)。
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k2)
{
	k2->right = leftLeftRotation(k2->right);
	return rightRightRotation(k2);
}
// 打印AVL树
template <class T>
void AVLTree<T>::print()
{
	if (this->mRoot)
		print(this->mRoot, this->mRoot->key, 0);
	else
		cout << "空树!" << endl;
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