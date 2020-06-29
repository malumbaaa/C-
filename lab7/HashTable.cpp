//---------------------------------------------------------------------------

#pragma hdrstop

#include "HashTable.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)



template <class T>
void Hash<T>::SetBUCKET(int x)
{
   this->BUCKET = x;
   table = new List<T>[BUCKET];
}

template <class T>
Hash<T>::Hash(int x)
{
	this->BUCKET = x;
	table = new List<T>[BUCKET];
}

template <class T>
void Hash<T>::Insert(int key, T data)
{
	int index = HashFunc(key);
	if (table[index].IsNULL())
	table[index].AddHead(key, data);
	else
	{
		index = HashFunc2(key);
		int i;
		for (i = 0; i < BUCKET-1; i++)
		{
		if (table[(index+i)%BUCKET].IsNULL())
		{
		table[(index+i)%BUCKET].AddHead(key, data);
		return;
		}
		}
		table[index].AddHead(key, data);

	}
}

template <class T>
void Hash<T>::Del(int key)
{
  int index = HashFunc(key);
  if (table[index].DelByKey(key))
  return;

  index = HashFunc2(key);
  for (int i = 0; i < BUCKET-1; i++)
  {
	  if (table[(index+i)%BUCKET].DelByKey(key))
	  return;
  }
}

template <class T>
void Hash<T>::DelAll()
{
	 for (int i = 0; i < BUCKET; i++)
	 {
		table[i].DelAll();
	 }
	 delete(table);
}

template <class T>
T Hash<T>::Find(int key)
{
  int index = HashFunc(key);
  if (table[index].Find(key) != "")
  return table[index].Find(key);
  else
  {
		index = HashFunc2(key);
		for (int i = 0; i < BUCKET-1; i++)
		{
		  if (table[(index+i)%BUCKET].Find(key) != "")
			return table[(index+i)%BUCKET].Find(key);
		}
  }
}

template <class T>
void Hash<T>::Display(TMemo* Memo1) {
   for (int i = 0; i < BUCKET; i++)
  {
	table[i].Print(Memo1, i);
  }
}

