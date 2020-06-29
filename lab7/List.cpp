//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)



template <class T>
List<T>::List()
{
   head = tail = NULL;
   count = 0;
}

template <class T>
 bool List<T>::IsNULL()
 {
	 return head == NULL;
 }

template <class T>
void List<T>::Insert(int n, int key, T data)
{
	Node<T>* node = new Node<T>;
	node->data = data;
	node->key = key;
	if (!head)
	{
	   head = node;
	   tail = node;
	   node->next = NULL;
	   node->prev = NULL;
	}
	else if (n == 1)
	{
		head->prev = node;
		node->next = head;
		node->prev = NULL;
		head = node;
	}
	else if (n>count)
	{
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;
	}
	else
	{
	Node<T> * next_node = head;
	int i = 1;
	while (i<n)
	{
		i++;
		next_node = next_node->next;
	}
	Node<T> * prev_node = next_node->prev;

	prev_node->next = node;
	next_node->prev = node;
	node->next = next_node;
	node->prev = prev_node;
	}
    count++;
}

template <class T>
void List<T>::Print(TMemo* Memo1, int i)
{
	Memo1->Lines->Add("");
   if(count != 0)
   {
	  Node<T> * temp = head;
	  while(temp != 0)
	  {
		  Memo1->Lines->Strings[i] += (IntToStr(temp->key)) + "-" + temp->data + " ";
		  temp = temp->next;
	  }

   }
}

template <class T>
int List<T>::GetAverage()
{
int av = 0;
   if(count != 0)
   {
	  Node<T> * temp = head;
	  while(temp != 0)
	  {
		av += temp->key;
		  temp = temp->next;
	  }

   }
   else return 0;
   return av/count;
}

template <class T>
int List<T>::MoreThanAverage(int av)
{
int a = 0;
   if(count != 0)
   {
	  Node<T> * temp = head;
	  while(temp != 0)
	  {
		if (temp->key > av) a++;
		  temp = temp->next;
	  }

   }
   return a;
}

template <class T>
bool List<T>::DelByKey(T key)
{
   int i = 1;
   if (head == NULL) return false;
   Node<T> * Del = head;

   while(Del->key!=key)
   {
	  Del = Del->next;
	  i++;
	  if (!Del) return false;
   }

   Node<T> * PrevDel = Del->prev;
   Node<T> * AfterDel = Del->next;

   if(PrevDel != 0 && count != 1)
	  PrevDel->next = AfterDel;

	if(AfterDel != 0 && count != 1)
	  AfterDel->prev = PrevDel;

   if(i == 1)
	   head = AfterDel;
   if(i == count)
	   tail = PrevDel;

   delete Del;

   count--;
   return true;
}

template <class T>
void List<T>::Del(int pos)
{
   if(pos < 1 || pos > count)
   {
	  throw Exception("Incorrect index");
	  return;
   }

   int i = 1;
   Node<T> * Del = head;

   while(i < pos)
   {
	  Del = Del->next;
	  i++;
   }

   Node<T> * PrevDel = Del->prev;
   Node<T> * AfterDel = Del->next;

   if(PrevDel != 0 && count != 1)
	  PrevDel->next = AfterDel;

	if(AfterDel != 0 && count != 1)
	  AfterDel->prev = PrevDel;

   if(pos == 1)
	   head = AfterDel;
   if(pos == count)
	   tail = PrevDel;

   delete Del;

   count--;
}

template <class T>
void List<T>::DelAll()
{
   while(count != 0)
	  Del(1);
}

 template <class T>
List<T>::~List()
{
   DelAll();
}

template <class T>
T List<T>::Find(T key)
{
   Node<T>* find = head;
   if (!find) return "";

   while(find->key!=key)
   {
	  find = find->next;
	  if (!find) return "";
   }

   return find->data;
}

template <class T>
void List<T>::AddHead(int key, T data)
{
   Node<T> * temp = new Node<T>;

   temp->prev = NULL;
   temp->data = data;
   temp->key = key;
   temp->next = head;

   if(head != 0)
	  head->prev = temp;

   if(count == 0)
	  head = tail = temp;
   else
	  head = temp;

   count++;
}

template <class T>
T List<T>::GetHead()
{
   T data = head->data;
   head =  head->next;
   delete(head->prev);
   head->prev=Null;
   count--;
   return data;
}

template <class T>
int List<T>::GetCount()
{
	return count;
}
