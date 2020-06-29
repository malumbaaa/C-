//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "SmartPointer.cpp"
#include "TreePlus.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//TreePlus<UnicodeString> tree1;
SmartPointer<TreePlus<UnicodeString>> tree1 (new TreePlus<UnicodeString>);

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
StringGrid1->Options = StringGrid1->Options << goEditing;

for(int i = 0; i < StringGrid1->RowCount; i++)
StringGrid1->Rows[i]->Clear();
int i, j;
 StringGrid1->Cells[1][0] = "#";
 StringGrid1->Cells[2][0] = "Фамилия";
for(i = 1; i < StringGrid1->RowCount; i++)
 {
 StringGrid1->Cells[0][i] = "строка " + IntToStr(i);
 }

 StringGrid1->Cells[1][1]="24684";
 StringGrid1->Cells[2][1]="Gardner";
 StringGrid1->Cells[1][2]="83656";
 StringGrid1->Cells[2][2]="Johnson";
 StringGrid1->Cells[1][3]="183758";
 StringGrid1->Cells[2][3]="Kennedy";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
TreeView1->Items->Clear();
for(int i = 1; i < StringGrid1->RowCount; i++)
{
 if (StringGrid1->Cells[1][i] == "") break;
 tree1->Insert(StrToInt(StringGrid1->Cells[1][i]), StringGrid1->Cells[2][i]);
 }
  tree1->TreeView(TreeView1);
  for (int i=0;i<TreeView1->Items->Count;i++)
       TreeView1->Items->Item[i]->Expand(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	for(int i = 1; i < StringGrid1->RowCount; i++)
{
 StringGrid1->Cells[1][i] = "";
 StringGrid1->Cells[2][i] = "";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	tree1->DestroyTree();
	TreeView1->Items->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
  tree1->RemoveMaxLeft();

  TreeView1->Items->Clear();
  tree1->TreeView(TreeView1);
for (int i=0;i<TreeView1->Items->Count;i++)
	   TreeView1->Items->Item[i]->Expand(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	Memo1->Lines->Add("Left-Root-Right");
	Memo1->Lines->Add("Симметричный");
	tree1->InorderPrint(Memo1);
	Memo1->Lines->Add("");
	Memo1->Lines->Add("Root-Left-Right");
	Memo1->Lines->Add("Прямой");
	tree1->PreorderPrint(Memo1);
	Memo1->Lines->Add("");
	Memo1->Lines->Add("Left-Right-Root");
	Memo1->Lines->Add("Обрятный");
	tree1->PostorderPrint(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
TreeView1->Items->Clear();
tree1->Remove(StrToInt(Edit3->Text));
tree1->TreeView(TreeView1);
for (int i=0;i<TreeView1->Items->Count;i++)
	   TreeView1->Items->Item[i]->Expand(0);
}

//---------------------------------------------------------------------------


