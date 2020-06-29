//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Queue.cpp"
#include "Stack.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Queue queue;
Stack stack;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
UnicodeString str = Form2->Edit1->Text ;
int n = 1, m = 1;
for (int i = 0; i < str.Length(); i++)
{
char ch = str[n];

	if (isalpha(ch))
	{
	
		switch (m) {
		  case 1: 
		  ch = 'a';
		  break;  
		  case 2: 
		  ch = 'b'; 
			  break; 
		  case 3: 
		  ch = 'c'; 
			  break; 
		  case 4: 
		  ch = 'd'; 
			  break; 
		  case 5: 
		  ch = 'e'; 
		  	  break; 
        default:
		   break;
		}
		m++;
			queue.Add(ch);
	}
	if (isdigit(ch))
	{
			queue.Add(ch);
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	 {
			  if (stack.Look() == ' ' || stack.Look() == '(' || ((stack.Look() == '+' || stack.Look() == '-') && (ch == '*' || ch == '/'))) {
					stack.Add(ch);
			  }
			  else// if ( stack.Look() == '*' || stack.Look() == '/') {
				 {	   //	if (ch == '+' || ch == '-')
						while (stack.Look() != ' ' && (stack.Look() != '(' && ( stack.Look() != '-' || stack.Look() != '+')))
						{
						queue.Add(stack.Get());
						}
						stack.Add(ch);
					   /*	else   {while (stack.Look() != ' ' && stack.Look() != '(')
						{
						queue.Add(stack.Get());

						}
						stack.Add(ch);
						}  */
				   }
				   //else     stack.Add(ch);
	 }
	 else if (ch == '(')
	 {
		   stack.Add(ch);
	 }
	 else if (ch == ')')
	 {
		   while (stack.Look() != '(')
						{
						queue.Add(stack.Get());
						//stack.Add(ch);
						}
						stack.Get();
	 }
	// else queue.Add(ch);
	n++;
}
	while (stack.Look() != ' ')
	{
		queue.Add(stack.Get());
	}

	String result;
	while (queue.Look() != ' ')
	result = result + queue.Get();

	 Form2->Edit2->Text = result;

	 n = 1;
	 int edit = 0;
	 for (int i = 0; i < result.Length(); i++)
{
	char ch = result[n];
	 float x1, x2;
	if (isdigit(ch))
	{
		stack.Add(ch);
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
	float x; 
	UnicodeString b = stack.Get(), a = stack.Get();
	if (isdigit(b[b.Length()])) {
		x2 = StrToFloat(b);
	}
	else if (b == "a") {
		   x2 =  StrToFloat(Form2->Edit4->Text); 
		 }
	else if (b == "b") {
		   x2 =  StrToFloat(Form2->Edit5->Text);
		 }
			else if (b == "c") {
		   x2 =  StrToFloat(Form2->Edit6->Text);	 
		 }
			else if (b == "d") {
		   x2 =  StrToFloat(Form2->Edit7->Text);	 
		 }
			else if (b == "e") {
		   x2 =  StrToFloat(Form2->Edit8->Text);	 
		 }

		 if (isdigit(a[a.Length()])) {
		x1 = StrToFloat(a);
	}
	else if (a == "a") {
		   x1 =  StrToFloat(Form2->Edit4->Text); 
		 }
	else if (a == "b") {
		   x1 =  StrToFloat(Form2->Edit5->Text);
		 }
			else if (a == "c") {
		   x1 =  StrToFloat(Form2->Edit6->Text);	 
		 }
			else if (a == "d") {
		   x1 =  StrToFloat(Form2->Edit7->Text);	 
		 }
			else if (a == "e") {
		   x1 =  StrToFloat(Form2->Edit8->Text);	 
		 }

		 
		if (ch == '+') {
			x = x1 + x2;
		}
		else 	if (ch == '-') {
			x = x1 - x2;
		}
			else 	if (ch == '*') {
			x = x1 * x2;
		}
			else 	if (ch == '/') {
			x = x1 / x2;
		}
	
		stack.Add(FloatToStr(x));
	}       
	
	else stack.Add(ch);

	n++;
}
   Form2->Edit3->Text = stack.Get();



   
	while (stack.Look() != ' ')
	stack.Get();
	while (queue.Look() != ' ')
	queue.Get();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
