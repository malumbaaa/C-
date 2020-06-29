//---------------------------------------------------------------------------
#include <iostream>
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "ChildHashTable.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
 ChildHash<UnicodeString> table;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	table.DelAll();
	table.SetBUCKET(StrToInt(Edit3->Text));

	unsigned a[256];
	for (int i = 1; i <= 256; i++) a[i]=i;
	for (int i = 0; i < 256; i++)
	{
	  int j = random(i);
	  unsigned temp = a[j];
	  a[j] = a[i];
	  a[i] = temp;
	}


   for (int i = 0; i < StrToInt(Edit4->Text); i++)
   {
		table.Insert(a[i], (char)(random(25)+97));
   }
	table.Display(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Edit2->Text = table.Find(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
  //Memo2->Lines->Clear();
  table.MoreThanAverage(Memo2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	table.Del(StrToInt(Edit5->Text));
	Memo1->Lines->Clear();
	table.Display(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
	table.Insert(StrToInt(Edit6->Text), Edit7->Text);
    Memo1->Lines->Clear();
	table.Display(Memo1);
}
//---------------------------------------------------------------------------

