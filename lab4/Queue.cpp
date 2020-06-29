//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"

#pragma package(smart_init)


List2::List2()
{
   Head = Tail = 0;
   Count = 0;
}

List2::List2(const List2 & L)
{
   Head = Tail = 0;
   Count = 0;
   Elem2 * temp = L.Head;

   while(temp != 0)
   {
	  AddTail(temp->data);
	  temp = temp->next;
   }
}

List2::~List2()
{
   DelAll();
}

void List2::AddHead(UnicodeString n)
{
   Elem2 * temp = new Elem2;

   temp->prev = 0;
   temp->data = n;
   temp->next = Head;

   if(Head != 0)
	  Head->prev = temp;

   if(Count == 0)
	  Head = Tail = temp;
   else
	  Head = temp;

   Count++;
}

void List2::AddTail(UnicodeString n)
{
   Elem2 * temp = new Elem2;
   temp->next = 0;
   temp->data = n;
   temp->prev = Tail;

   if(Tail != 0)
	  Tail->next = temp;

   if(Count == 0)
	  Head = Tail = temp;
   else
   Tail = temp;

   Count++;
}


void List2::Del(int pos)
{
   if(pos < 1 || pos > Count)
   {
	  return;
   }

   int i = 1;
   Elem2 * Del = Head;

   while(i < pos)
   {
	  Del = Del->next;
	  i++;
   }

   Elem2 * PrevDel = Del->prev;
   Elem2 * AfterDel = Del->next;

   if(PrevDel != 0 && Count != 1)
	  PrevDel->next = AfterDel;

	if(AfterDel != 0 && Count != 1)
	  AfterDel->prev = PrevDel;

   if(pos == 1)
	   Head = AfterDel;
   if(pos == Count)
	   Tail = PrevDel;

   delete Del;

   Count--;
}

void List2::Print(int pos)
{
   if(pos < 1 || pos > Count)
   {
	  return;
   }

   Elem2 * temp;

   if(pos <= Count / 2)
   {
	  temp = Head;
	  int i = 1;

	  while(i < pos)
	  {
		 temp = temp->next;
		 i++;
	  }
   }
   else
   {
	  temp = Tail;
	  int i = 1;

	  while(i <= Count - pos)
	  {
		 temp = temp->prev;
		 i++;
	  }
   }

}

void List2::Print()
{
   if(Count != 0)
   {
	  Elem2 * temp = Head;
	  while(temp->next != 0)
	  {
		  temp = temp->next;
	  }
   }
}

void List2::DelAll()
{
   while(Count != 0)
	  Del(1);
}

int List2::GetCount()
{
	return Count;
}

/*Elem2 * List2::GetElem(int pos)
{
pos++;
   Elem2 *temp = Head;

   if(pos < 1 || pos > Count)
   {
	  return 0;
   }

   int i = 1;

   while(i < pos && temp != 0)
   {
	  temp = temp->next;
	  i++;
   }

   if(temp == 0)
	  return 0;
   else
	  return temp;
}         */

UnicodeString List2::GetData(int pos)
{
pos++;
   Elem2 *temp = Head;
   if (Count == 0) {
	 return ' ';
   }
   if(pos < 1 || pos > Count)
   {
	  return ' ';
   }

   int i = 1;

   while(i < pos && temp != 0)
   {
	  temp = temp->next;
	  i++;
   }

   if(temp == 0)
	  return ' ';
   else
	  return temp->data;
}



  List2 list2;
  //golova na4alo

 class Queue
 {
    public:
	  void Add(UnicodeString n)
	  {
		  list2.AddTail(n);
	  }
	  UnicodeString Get()
	  {
		   UnicodeString data = list2.GetData(0);
		   list2.Del(1);
		   return data;
	  }
      UnicodeString Look(int n)
	  {
		 return list2.GetData(n);
	  }
      UnicodeString Look()
	  {
		 return list2.GetData(0);
	  }
 };

