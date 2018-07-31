#ifndef _BSTREE_H_
#define _BSTREE_H_
#include "BSTNode.h"
template <class  T>
class BSTree{
	private:
		BSTNode<T> *mRoot;    // �����
	public:
		BSTree();
		~BSTree();
	
		// ǰ�����"������"11
		void preOrder();
		// �������"������"11
		void inOrder();
		// �������"������"11
		void postOrder();
	
		// (�ݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
		BSTNode<T>* search(T key);
		// (�ǵݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
		BSTNode<T>* iterativeSearch(T key);
	
		// ������С��㣺������С���ļ�ֵ��
		T minimum();
		// ��������㣺���������ļ�ֵ��
		T maximum();
	
		// �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
		BSTNode<T>* successor(BSTNode<T> *x);
		// �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
		BSTNode<T>* predecessor(BSTNode<T> *x);
	
		// �����(keyΪ�ڵ��ֵ)���뵽��������
		void insert(T key);
	
		// ɾ�����(keyΪ�ڵ��ֵ)
		void remove(T key);
	
		// ���ٶ�����
		void destroy();
	
		// ��ӡ������
		void print();
	private:
		// ǰ�����"������"
		void preOrder(BSTNode<T>* tree) const;
		// �������"������"
		void inOrder(BSTNode<T>* tree) const;
		// �������"������"
		void postOrder(BSTNode<T>* tree) const;
	
		// (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�11
		BSTNode<T>* search(BSTNode<T>* x, T key) const;
		// (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�11
		BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;
	
		// ������С��㣺����treeΪ�����Ķ���������С��㡣11
		BSTNode<T>* minimum(BSTNode<T>* tree);
		// ��������㣺����treeΪ�����Ķ�����������㡣11
		BSTNode<T>* maximum(BSTNode<T>* tree);
	
		// �����(z)���뵽������(tree)��
		void insert(BSTNode<T>* &tree, BSTNode<T>* z);
	
		// ɾ��������(tree)�еĽ��(z)�������ر�ɾ���Ľ��
		BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);
	
		// ���ٶ�����
		void destroy(BSTNode<T>* &tree);
	
		// ��ӡ������
		void print(BSTNode<T>* tree, T key, int direction);
};
#endif

