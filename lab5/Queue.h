//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
//---------------------------------------------------------------------------
#endif



template <class T>
struct Node
{
	T data;
	Node* next;
	Node* prev;
};

template <class T>
class Queue
{
	protected:
	Node<T>* head;
	Node<T>* tail;
	int count;
	public:
	Queue();
	void AddHead(T data);
	T GetTail();
    T ShowTail();
};





