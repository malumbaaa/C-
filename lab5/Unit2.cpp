//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "List.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------

List<int> list;

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::randomeClick(TObject *Sender)
{
  randomize();
for (int i = 0; i < StrToInt(Edit1->Text); i++)
{
  list.Insert(1, random(20) - 10);
}
ListBox1->Items->Clear();
list.Print(ListBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	list.Insert(StrToInt(Edit2->Text), StrToInt(Edit3->Text));
	ListBox1->Items->Clear();
	list.Print(ListBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	list.DelNegative();
    ListBox1->Items->Clear();
	list.Print(ListBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	Edit4->Text=list.GetTail();
    ListBox1->Items->Clear();
	list.Print(ListBox1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	Edit5->Text = list.ShowTail();
}
//---------------------------------------------------------------------------
