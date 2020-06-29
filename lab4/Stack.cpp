//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"

#pragma package(smart_init)




List::List()
{
   Head = Tail = 0;
   Count = 0;
}

List::List(const List & L)
{
   Head = Tail = 0;
   Count = 0;
   Elem * temp = L.Head;

   while(temp != 0)
   {
	  AddTail(temp->data);
	  temp = temp->next;
   }
}

List::~List()
{
   DelAll();
}

void List::AddHead(UnicodeString n)
{
   Elem * temp = new Elem;

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

void List::AddTail(UnicodeString n)
{
   Elem * temp = new Elem;
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


void List::Del(int pos)
{
   if(pos < 1 || pos > Count)
   {
	  return;
   }

   int i = 1;
   Elem * Del = Head;

   while(i < pos)
   {
	  Del = Del->next;
	  i++;
   }

   Elem * PrevDel = Del->prev;
   Elem * AfterDel = Del->next;

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

void List::Print(int pos)
{
   if(pos < 1 || pos > Count)
   {
	  return;
   }

   Elem * temp;

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

void List::Print()
{
   if(Count != 0)
   {
	  Elem * temp = Head;
	  while(temp->next != 0)
	  {
		  temp = temp->next;
	  }
   }
}

void List::DelAll()
{
   while(Count != 0)
	  Del(1);
}

int List::GetCount()
{
	return Count;
}

Elem * List::GetElem(int pos)
{
pos++;
   Elem *temp = Head;

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
}

UnicodeString List::GetData(int pos)
{
pos++;
   Elem *temp = Head;
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

  List list;
  //golova na4alo

 class Stack
 {
 public:
	  void Add(UnicodeString n)
	  {
		  list.AddHead(n);
	  }
	  UnicodeString Get()
	  {
		   UnicodeString data = list.GetData(0);
		   list.Del(1);
		   return data;
	  }
	  UnicodeString Look(int n)
	  {
		 return list.GetData(n);
	  }
	  UnicodeString Look()
	  {
		 return list.GetData(0);
	  }
 };

