//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)


struct Elem2
{
   UnicodeString data;
   Elem2 *next, *prev;
};

class List2
{
   Elem2 *Head, *Tail;
   int Count;

public:

   List2();
   List2(const List2&);
   ~List2();

   int GetCount();
   Elem2* GetElem2(int pos);
   UnicodeString GetData(int pos);

   void DelAll();
   void Del(int pos = 0);
   void Insert(int pos = 0);
   void AddTail(UnicodeString n);
   void AddHead(UnicodeString n);
   void Print();
   void Print(int pos);
};


