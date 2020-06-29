//---------------------------------------------------------------------------

#ifndef TreePlusH
#define TreePlusH
#include "Tree.cpp"
//---------------------------------------------------------------------------
#endif

template <class T>
class TreePlus: public Tree<T>
{
Node<T>*  remove_max_left(Node<T>* p);
public:
void RemoveMaxLeft();
};

