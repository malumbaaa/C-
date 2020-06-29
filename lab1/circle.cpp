//---------------------------------------------------------------------------

#pragma hdrstop

#include "Curcle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Curcle::draw(int a,int b,int c,int d,TCanvas *Canvas)
{
x1=a;
y1=b;
x2=c;
y2=d;
Canvas->Ellipse(x1,y1,x2,y2);
}

int Curcle::Square(int a,int b,int c,int d,TCanvas *Canvas)
{
x1=a;
y1=b;
x2=c;
y2=d;
int FirstSide;
FirstSide=abs(x1-x2);
int SecondSide;
SecondSide=abs(y1-y2);
int Square;
Square=3.14*(FirstSide/2)*(SecondSide/2);
return Square;
}

int Curcle::Perimetr (int a,int b,int c,int d,TCanvas *Canvas)
{
x1=a;
y1=b;
x2=c;
y2=d;
int FirstSide;
FirstSide=abs(x1-x2);
int SecondSide;
SecondSide=abs(y1-y2);
int Per;
Per=3.14*((FirstSide/2)+(SecondSide/2));
return Per;
}
