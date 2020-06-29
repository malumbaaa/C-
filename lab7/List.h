//---------------------------------------------------------------------------

#ifndef ListH
#define ListH

#endif

//---------------------------------------------------------------------------
template <class T>
struct Node
{
	int key;
	T data;
	Node* next;
	Node* prev;
};

template <class T>
class List
{

	Node<T>* head;
	Node<T>* tail;
	int count;
	public:
	bool IsNULL();
	int GetCount();
	void AddHead(int key, T data);
	T GetHead();
	List();
    ~List();
	void Insert(int n, int key, T data);
	void Print(TMemo* Memo1, int i);
	void DelAll();
	void Del(int pos);
	bool DelByKey(T key);
	T Find(T key);
	int GetAverage();
    int MoreThanAverage(int av);
};


