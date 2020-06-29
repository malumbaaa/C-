//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)


struct Elem
{
   UnicodeString data;
   Elem *next, *prev;
};

class List
{
   Elem *Head, *Tail;
   int Count;

public:

   List();
   List(const List&);
   ~List();

   int GetCount();
   Elem* GetElem(int pos);
   UnicodeString GetData(int pos);

   void DelAll();
   void Del(int pos = 0);
   void Insert(int pos = 0);
   void AddTail(UnicodeString n);
   void AddHead(UnicodeString n);
   void Print();
   void Print(int pos);
};


