#ifndef _BSTREE_H_
#define _BSTREE_H_
#include "BSTNode.h"
template <class  T>
class BSTree{
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
	
		// (递归实现)查找"二叉树"中键值为key的节点
		BSTNode<T>* search(T key);
		// (非递归实现)查找"二叉树"中键值为key的节点
		BSTNode<T>* iterativeSearch(T key);
	
		// 查找最小结点：返回最小结点的键值。
		T minimum();
		// 查找最大结点：返回最大结点的键值。
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
		// 前序遍历"二叉树"
		void preOrder(BSTNode<T>* tree) const;
		// 中序遍历"二叉树"
		void inOrder(BSTNode<T>* tree) const;
		// 后序遍历"二叉树"
		void postOrder(BSTNode<T>* tree) const;
	
		// (递归实现)查找"二叉树x"中键值为key的节点11
		BSTNode<T>* search(BSTNode<T>* x, T key) const;
		// (非递归实现)查找"二叉树x"中键值为key的节点11
		BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;
	
		// 查找最小结点：返回tree为根结点的二叉树的最小结点。11
		BSTNode<T>* minimum(BSTNode<T>* tree);
		// 查找最大结点：返回tree为根结点的二叉树的最大结点。11
		BSTNode<T>* maximum(BSTNode<T>* tree);
	
		// 将结点(z)插入到二叉树(tree)中
		void insert(BSTNode<T>* &tree, BSTNode<T>* z);
	
		// 删除二叉树(tree)中的结点(z)，并返回被删除的结点
		BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);
	
		// 销毁二叉树
		void destroy(BSTNode<T>* &tree);
	
		// 打印二叉树
		void print(BSTNode<T>* tree, T key, int direction);
};
#endif

