//---------------------------------------------------------------------------

#pragma hdrstop

#include "Box.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Box::draw(int a, int b, int c,int d,TCanvas *Canvas)
{
x1=a;
y1=b;
x2=c;
y2=d;

Canvas->Rectangle(x1,y1,x2,y2);
}

int Box::Square(int a,int b,int c,int d, TCanvas *Canvas)
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
Square=SecondSide*FirstSide;
return Square;

}

int Box::Perimetr(int a,int b,int c,int d,TCanvas *Canvas)
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
 Per=2*(SecondSide+FirstSide);
 return Per;
}
