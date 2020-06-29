//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Box.cpp"
#include "Curcle.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TPoint a;
Box B;
Curcle C;
bool is_left_mouse_down=0;
bool is_right_mouse_down=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void _fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X,int Y)
{
if(Button ==mbLeft)
 {
 is_left_mouse_down=1;
 a.x=X;
 a.y=Y;

 }
 if (Button == mbRight)
 {
 is_right_mouse_down=1;
 a.x=X;
 a.y=Y;
 }


}
//---------------------------------------------------------------------------


void _fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X,int Y)


{

  if(is_left_mouse_down)
  {
   Form1->Refresh();
   Canvas->Pen->Color=clRed;
   C.draw(a.x,a.y,X,Y,Canvas);
   Panel1->Caption = IntToStr(C.Perimetr(a.x,a.y,X,Y,Canvas))+"pixels";
	 Panel2->Caption = IntToStr(C.Square(a.x,a.y,X,Y,Canvas))+"pixels";
  }

	if(is_right_mouse_down)
  {
   Form1->Refresh();
   Canvas->Pen->Color=clGreen;
   B.draw(a.x,a.y,X,Y,Canvas);
   Panel1->Caption = IntToStr(C.Perimetr(a.x,a.y,X,Y,Canvas))+"pixels";
	 Panel2->Caption = IntToStr(C.Square(a.x,a.y,X,Y,Canvas))+"pixels";
  }
}
