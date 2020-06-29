//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
#include "Queue.cpp"

#endif

//---------------------------------------------------------------------------

template <class T>
class List: public Queue<T>
{
	public:
	List();
	void Insert(int n, T data);
	void Print(TListBox* ListBox1);
	void DelNegative();
};



