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

	// ��ȡ���ĸ߶�//Ҷ�ӽڵ�Ϊ0 ���ϼ� ͬһ��� �߶ȿ��ܲ�ͬ �˸߷Ǳ˸�
	int height();
	// 
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
AVLTreeNode<T>*  AVLTree<T>::insert(AVLTreeNode<T>* tree, T key)//��Ϊ �з���ֵ parent ���Բ���Ҫ 
{
	if (tree == NULL)
	{
		AVLTreeNode<T> * z = new AVLTreeNode<T>(key, NULL, NULL);
		if (this->mRoot)
			tree = z;
		else
		{
			cout << "Ŀ����Ϊ��!" << endl;
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
	tree->height = max(height(tree->left), height(tree->right)) + 1; //Ҷ�ӽڵ�Ϊ0 ���ϼ� ͬһ��� �߶ȿ��ܲ�ͬ �˸߷Ǳ˸�
	return tree;
}
// ɾ��AVL��(tree)�еĽ��(z)�������ر�ɾ���Ľ��
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
	this->mRoot = insert(this->mRoot, key);
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
// LL�������Ӧ�����(����ת)��
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

// RR�����Ҷ�Ӧ�����(�ҵ���ת)��
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

// LR�����Ҷ�Ӧ�����(��˫��ת)��
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k2)
{
	k2->left = rightRightRotation(k2->left);
	return leftLeftRotation(k2);
}

// RL�������Ӧ�����(��˫��ת)��
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k2)
{
	k2->right = leftLeftRotation(k2->right);
	return rightRightRotation(k2);
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