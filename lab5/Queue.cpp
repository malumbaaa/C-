//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



template <class T>
Queue<T>::Queue()
{
   head = tail = NULL;
   count = 0;
}

template <class T>
void Queue<T>::AddHead(T data)
{
   Node<T> * temp = new Node<T>;

   temp->prev = NULL;
   temp->data = data;
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
T Queue<T>::GetTail()
{
   if(count != 0)
   {
   T data = 0;
   if (count == 1) {
	data = head->data;
   delete(head);
   head=NULL;
   count--;
   }
   else
   {
   data = tail->data;
   tail =  tail->prev;
   delete(tail->next);
   tail->next=NULL;
   count--;
   }
   return data;
   }
  // MassageShow("Empty");
   return 0;
}

template <class T>
T Queue<T>::ShowTail()
{
if(count != 0)
   {
	if (tail) return tail->data;
   }
   else return 0;
}

