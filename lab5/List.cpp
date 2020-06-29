//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)



template <class T>
List<T>::List()
{
   Queue<T>::head = Queue<T>::tail = NULL;
   Queue<T>::count = 0;
}


template <class T>
void List<T>::Insert(int n, T data)
{
	Node<T>* node = new Node<T>;
	node->data = data;
	if (!Queue<T>::head)
	{
	   Queue<T>::head = node;
	   Queue<T>::tail = node;
	   node->next = NULL;
	   node->prev = NULL;
	}
	else if (n == 1)
	{
		Queue<T>::head->prev = node;
		node->next = Queue<T>::head;
		node->prev = NULL;
		Queue<T>::head = node;
	}
	else if (n>Queue<T>::count)
	{
		Queue<T>::tail->next = node;
		node->prev = Queue<T>::tail;
		node->next = NULL;
		Queue<T>::tail = node;
	}
	else
	{
	Node<T> * next_node = Queue<T>::head;
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
	Queue<T>::count++;
}

template <class T>
void List<T>::Print(TListBox* ListBox1)
{
   if(Queue<T>::count != 0)
   {
	  Node<T> * temp = Queue<T>::head;
	  while(temp->next != 0)
      {
		  ListBox1->Items->Add(IntToStr(temp->data));
		  temp = temp->next;
      }

	  ListBox1->Items->Add(IntToStr(temp->data));
   }
}

template <class T>
void List<T>::DelNegative()
{
	Node<T>* temp = Queue<T>::head;
		while (temp)
		{
			if (temp->data < 0)
			{
			if (temp->next)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				Node<T>* buf = temp->next;
				delete(temp);
				temp = buf;
				Queue<T>::count--;
				continue;
			}
			else
			{
                Queue<T>::tail = temp->prev;
				Node<T>* buf = temp;
				delete(temp);
				buf->prev->next=NULL;
                break;
            }
			}
			temp = temp->next;
		}
}
