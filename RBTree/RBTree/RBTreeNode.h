#ifndef _RBTREENODE_H_ 
#define _RBTREENODE_H_
enum Color { Red =1, Black };
template <class T>
class RBTreeNode{
	public:
		T key;
		Color color;
		RBTreeNode<T> *parent;
		RBTreeNode<T> *left;
		RBTreeNode<T> *right;
		RBTreeNode(T k, Color c, RBTreeNode<T> *p, RBTreeNode<T> *l, RBTreeNode<T> *r):
			key(k), color(c), parent(0), left(l), right(r){}
		
};
#endif