#ifndef _AVLTREENODE_H_
#define _AVLTREENODE_H_
template<class T>
class AVLTreeNode{
	public:
		T key;
		AVLTreeNode<T>* left;
		AVLTreeNode<T>* right;
		int height;
		AVLTreeNode(T key, AVLTreeNode<T> *left, AVLTreeNode<T> *right) :
		key(key), left(left), right(right)
		{}
};
#endif