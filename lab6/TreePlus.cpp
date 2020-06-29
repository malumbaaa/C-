//---------------------------------------------------------------------------

#pragma hdrstop

#include "TreePlus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


template <class T>
Node<T>* TreePlus<T>::remove_max_left(Node<T>* p)
{
		if( p->right==0 )
		{
		if (p->left) delete (p->left);
		 return NULL;
		}
	p->right = remove_max_left(p->right);
	return Tree<T>::balance(p);
}

template <class T>
void TreePlus<T>::RemoveMaxLeft()
{
if (Tree<T>::root->left)
	Tree<T>::root->left = remove_max_left(Tree<T>::root->left);
	Tree<T>::root = Tree<T>::balance(Tree<T>::root);
}