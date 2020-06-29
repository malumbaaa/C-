//---------------------------------------------------------------------------

#ifndef BoxH
#define BoxH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>

class Box
{
 int x1,y1,x2,y2;
 public:
 void draw(int a,int b,int c,int d,TCanvas *Canvas);
 int Square(int a,int b,int c,int d,TCanvas *Canvas);
 int Perimetr (int a,int b,int c,int d,TCanvas *Canvas);
} ;
