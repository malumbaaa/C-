//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TPanel *Panel1;
	TLabel *Label2;
	TPanel *Panel2;
	void __fastcall FormMouseDown(TObject *Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	 void __fastcall FormMouseUp(TObject *Sender,TMouseButton Button,TShiftState Shift,int X,int Y);
	void __fastcall FormMouseMove(TObject *Sender,TShiftState Shift,int X,int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
