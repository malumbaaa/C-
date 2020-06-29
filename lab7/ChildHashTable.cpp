//---------------------------------------------------------------------------

#pragma hdrstop

#include "ChildHashTable.h"
#include "HashTable.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)


template <class T>
class ChildHash : public Hash<T>
 {
 public:
	ChildHash(){}
	ChildHash(int x) : Hash<T>(x){}
	void MoreThanAverage(TMemo* Memo);
 };

template <class T>
void ChildHash<T>::MoreThanAverage(TMemo* Memo2)
 {
 int av = 0;
 int count_ = 0;
   for (int i = 0; i < Hash<T>::BUCKET; i++)
  {
	   if (Hash<T>::table[i].GetAverage() != 0) count_ ++;
	   av += Hash<T>::table[i].GetAverage();
  }
  if (count_) {
	 av /=  count_;
  }


  count_ = 0;
  for (int i = 0; i < Hash<T>::BUCKET; i++)
  {
		count_ += Hash<T>::table[i].MoreThanAverage(av);
  }
  Memo2->Lines->Add(IntToStr(count_));
}