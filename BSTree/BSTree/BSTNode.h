#ifndef _BSTNODE_H_
#define _BSTNODE_H_
template <class  T>
class BSTNode{
public:
	T key;
	BSTNode<T> * parent;
	BSTNode<T> * left;
	BSTNode<T> * right;
	BSTNode(T key, BSTNode<T> * parent, BSTNode<T> * left, BSTNode<T> * right) :key(key), parent(), left(left), right(right){}
};
#endif