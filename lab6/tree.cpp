//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



template <class T>
void Tree<T>::destroy_tree(Node<T>* p)
{
  if(p!=NULL)
  {
	destroy_tree(p->left);
	destroy_tree(p->right);
	delete p;
  }
  root = NULL;
}

template <class T>
void Tree<T>::DestroyTree()
{
	destroy_tree(root);
}

template <class T>
Tree<T>::~Tree()
{
	destroy_tree(root);
}

template <class T>
void Tree<T>::Insert(int k, T data)
{
	root = insert(root, k, data);
}

template <class T>
void Tree<T>::Remove(int k)
{
	root = remove(root, k);
}


template <class T>
Tree<T>::Tree()
{
	root = NULL;
}

template <class T>
int Tree<T>::height_difference(Node<T>* p)
{
	int hl, hr;
	if (!p->left) hl=0;
	else hl = p->left->height;
	
	if (!p->right) hr=0;
	else hr = p->right->height;
	return hr - hl;
}

template <class T>
void Tree<T>::height_normalize(Node<T>* p)
{
	int hl, hr;
	if (!p->left) hl=0;
	else hl = p->left->height;
	
	if (!p->right) hr=0;
	else hr = p->right->height;
	
	if (hl>hr) p->height=hl+1;
	else p->height=hr+1;
}

template <class T>
Node<T>* Tree<T>::rotate_right(Node<T>* p)
{
	Node<T>* q = p->left;
	p->left = q->right;
	q->right = p;
	height_normalize(p);
	height_normalize(q);
	return q;
}

template <class T>
Node<T>* Tree<T>::rotate_left(Node<T>* q)
{
	Node<T>* p = q->right;
	q->right = p->left;
	p->left = q;
	height_normalize(q);
	height_normalize(p);
	return p;
}

template <class T>
Node<T>* Tree<T>::balance(Node<T>* p)
{
	height_normalize(p);
	if( height_difference(p)>=2 )
	{
		if( height_difference(p->right) < 0 )
			p->right = rotate_right(p->right);
		return rotate_left(p);
	}
	if( height_difference(p)<=-2 )
	{
		if( height_difference(p->left) > 0  )
			p->left = rotate_left(p->left);
		return rotate_right(p);
	}
	return p;
}

template <class T>
Node<T>* Tree<T>::insert(Node<T>* p, int k, T data)
{
	if(!p) return new Node<T>(k, data);
	if(k < p->key)
		p->left = insert(p->left,k, data);
	else if(k > p->key)
		p->right = insert(p->right,k, data);
	return balance(p);
}

template <class T>
Node<T>* Tree<T>::find_min(Node<T>* p)
{
	return p->left?find_min(p->left):p;
}

template <class T>
Node<T>* Tree<T>::remove_min(Node<T>* p)
{
	if( p->left==0 )
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}

template <class T>
Node<T>* Tree<T>::remove(Node<T>* p, int k)
{
	if( !p ) return 0;
	if( k < p->key )
		p->left = remove(p->left,k);
	else if( k > p->key )
		p->right = remove(p->right,k);
	else
	{
		Node<T>* q = p->left;
		Node<T>* r = p->right;
		delete p;
		if( !r ) return q;
		Node<T>* min = find_min(r);
		min->right = remove_min(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

template <class T>
void Tree<T>::tree_view(Node<T>* p, TTreeView* TreeView1 , TTreeNode* TreeNode1, int n)
{
	if (p == NULL)  
	{
	   return;
	}
	
	if (n == 1) 
	TreeNode1=TreeView1->Items->
	AddChild(TreeNode1, "right " + IntToStr(p->key) + " " + p->data);
	else if (n == 2)
	TreeNode1=TreeView1->Items->
	AddChild(TreeNode1, "left " + IntToStr(p->key) + " " + p->data);
	
	tree_view(p->right, TreeView1, TreeNode1, 1);
	tree_view(p->left, TreeView1, TreeNode1, 2);   


}

template <class T>
Node<T>* Tree<T>::find(Node<T>* p, int k)
{
	if(!p) return NULL;
	if(k == p->key)
	   return p;	

	if(k < p->key)
		return find(p->left,k);
	else if(k > p->key)                                                	
		return find(p->right,k);
}

template <class T>
T Tree<T>::Find(int k)
 {
 Node<T>* p = find(root, k);
 if (p)
  return p->data;	 
 }

template <class T>
void Tree<T>::TreeView(TTreeView* TreeView1)
{
  if (root == NULL) {
	TreeView1->Items->Clear();  
  }	
  else
  tree_view(root, TreeView1, TreeView1->Items->
  AddChild(NULL, "root " + IntToStr(root->key) + " " + (UnicodeString)root->data), 0);
}

template <class T>
void Tree<T>::inorder_print(Node<T>* p, TMemo* Memo1)
{
	if (p)
	{
	  inorder_print(p->left, Memo1);
	  Memo1->Lines->Add(IntToStr(p->key)+ " " + p->data);
	  inorder_print(p->right, Memo1);
	}
}

template <class T>
void Tree<T>::preorder_print(Node<T>* p, TMemo* Memo1)
{
	if (p)
	{
	  Memo1->Lines->Add(IntToStr(p->key)+ " " + p->data);
	  inorder_print(p->left, Memo1);
	  inorder_print(p->right, Memo1);
	}
}

template <class T>
void Tree<T>::postorder_print(Node<T>* p, TMemo* Memo1)
{
	if (p) 
	{
	  inorder_print(p->left, Memo1);
	  inorder_print(p->right, Memo1);
	  Memo1->Lines->Add(IntToStr(p->key)+ " " + p->data);
	}
}


template <class T>
void Tree<T>::InorderPrint(TMemo* Memo1)
{
  inorder_print(root , Memo1);
}

template <class T>
void Tree<T>::PreorderPrint(TMemo* Memo1)
{
  preorder_print(root , Memo1);
}

template <class T>
void Tree<T>::PostorderPrint(TMemo* Memo1)
{
  postorder_print(root , Memo1);
}


