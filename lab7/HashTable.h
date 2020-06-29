//---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------
#endif
#include "List.cpp"

template <class T>
class Hash
{
protected:
	int BUCKET;
	T data;
	List<T>* table;
public:
	Hash(int V);
	Hash(){}
	void SetBUCKET(int x);
	void Insert(int key, T data);

	void Del(int key);
	void DelAll();

	int HashFunc(int key)
	{
	   return key % BUCKET;
	}

	int HashFunc2(int key)
	{
	   return (key % 7 + HashFunc(key)) % BUCKET;
	}

	void Display(TMemo* Memo1);
	T Find(int key);
};