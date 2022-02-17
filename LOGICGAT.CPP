#include<iostream.h>
#include<conio.h>
class logicgate
{
 protected:
 int input1,input2;
 public:
 virtual void get_output()=0;
};
class AND:public logicgate
{
 public:
 void get1()
 {
 cout<<"enter input1: ";
 cin>>input1;
 cout<<"enter input2: ";
 cin>>input2;
 }
 void get_output()
 {
  cout<<"AND gate output is= "<<(input1*input2);
 }
};
class OR:public logicgate
{
 public:
 void get2()
 {
 cout<<"\nenter input1: ";
 cin>>input1;
 cout<<"enter input2: ";
 cin>>input2;
 }
 void get_output()
 {
  if(input1!=1 && input2!=1)
  {
  cout<<"OR gate output is= "<<(input1+input2);
  }
  else
  {
  cout<<"OR gate output is= 1";
  }
 }
};
void main()
{
AND n;
OR o;
clrscr();
n.get1();
n.get_output();
o.get2();
o.get_output();
getch();
}


