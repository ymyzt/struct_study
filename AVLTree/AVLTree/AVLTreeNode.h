#ifndef _AVLTREENODE_H_
#define _AVLTREENODE_H_
template<class T>
class AVLTreeNode{
	public:
		T key;
		AVLTreeNode* left;
		AVLTreeNode* right;
		int height;
		AVLTreeNode(T key, AVLTreeNode *left, AVLTreeNode *right) :
		key(key), left(left), right(right)
		{}
};
#endif