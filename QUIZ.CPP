//      PROJECT COMPUTER QUIZ
//INCLUDED HEADER FILES
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <fstream.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//	CLASS NAME : lines
//	DETAILS    : IT CONTROLS FUNCTIONS RELATED TO DRAW
//                   LINES, BOXES, ETC.
class lines
{
public :
		void line_hor (int, int, int, char) ;
		void line_ver (int, int, int, char) ;
		void box (int,int,int,int,char) ;
} ;
//	CLASS NAME : menu
//	DETAILS    : IT CONTROLS OVER ALL FUNCTIONING OF PROJECT
class menu
{
public :
		void main_menu(void) ;
		char *sub_menu(void) ;
		void start(void) ;
private :
		void edit_menu(void) ;
} ;
 //LASS NAME : quiz
//	DETAILS    : IT CONTROLS OVER ALL THE FUNCTIONS
//                   RELATED TO QUIZ
class quiz
{
public :
		void play(char filename[13]) ;
		void add(char filename[13]) ;
		void deletion(char filename[13]) ;
		void modify(char filename[13]) ;
private :
		void delete_record(char filename[13], int) ;
		void modify_record(char filename[13], int) ;
		void display_score(char name[20], int, int) ;
		int  recordno(char filename[13], int) ;
		int  record_count(char filename[13]) ;
		int  found_record(char filename[13], int) ;
		void display_record(char filename[13], int) ;
		int  ques_no ;
		char ques[60] ;
		char ans1[50] ;
		char ans2[50] ;
		char ans3[50] ;
		char sol ;
} ;
//	CLASS NAME    : lines
//	FUNCTION NAME : line_hor
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE HORIZONTAL LINE
void lines :: line_hor(int column1, int column2, int row, char c)
{
   for ( column1; column1<=column2; column1++ )
   {
      gotoxy(column1,row) ;
      cout <<c ;
   }
}
//	CLASS NAME    : lines
//	FUNCTION NAME : line_ver
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE VERTICAL LINE
void lines :: line_ver(int row1, int row2, int column, char c)
{
   for ( row1; row1<=row2; row1++ )
   {
      gotoxy(column,row1) ;
      cout <<c ;
   }
//	CLASS NAME    : lines
//	FUNCTION NAME : box
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE BOX
void lines :: box(int column1, int row1, int column2, int row2, char c)
{   char ch=218 ;
   char c1, c2, c3, c4 ;
   char l1=196, l2=179 ;
   if (c == ch)
   {
	c1 = 218 ;
	c2 = 191 ;
	c3 = 192 ;
	c4 = 217 ;
	l1 = 196 ;
	l2 = 179 ;
   }
   else
   {
	c1 = c ;
	c2 = c ;
	c3 = c ;
	c4 = c ;
	l1 = c ;
	l2 = c ;
   }
   gotoxy(column1,row1) ;
   cout <<c1 ;
   gotoxy(column2,row1) ;
   cout <<c2 ;
   gotoxy(column1,row2) ;
   cout <<c3 ;
   gotoxy(column2,row2) ;
   cout <<c4 ;
   column1++ ;
   column2-- ;
   line_hor(column1,column2,row1,l1) ;
   line_hor(column1,column2,row2,l1) ;
   column1-- ;
   column2++ ;
   row1++ ;
   row2-- ;
   line_ver(row1,row2,column1,l2) ;
   line_ver(row1,row2,column2,l2) ;
}
//	CLASS NAME    : menu
//	FUNCTION NAME : start
//	DETAILS       : IT CREATES THE OPENING SCREEN
void menu :: start(void)
{
   lines line ;
   textmode(C40) ;
   clrscr() ;
   textbackground(LIGHTCYAN);
   textcolor(BLACK) ;
   clrscr() ;
   gotoxy(8,12) ;
   cout <<"C O M P U T E R" ;
   gotoxy(25,12) ;
   cout <<"Q U I Z" ;
   line.box(4,10,36,14,219) ;
   gotoxy(5,21);
   cout<<"MADE BY :";
   gotoxy(5,22);
   cout<<"Author & Her Team";
   line.box(2,19,40,24,219);
   gotoxy(4,10);
   getch() ;
   textbackground(BLACK) ;
   textcolor(LIGHTGRAY) ;
   clrscr() ;
}
//	CLASS NAME    : menu
//	FUNCTION NAME : main_menu
//	DETAILS       : IT CREATES THE MAIN MENU TO CONTROL
//                   ALL THE FUNCTIONS
void menu :: main_menu(void)
{   lines line ;
   textmode(C40) ;
   clrscr ;
   int valid ;
   int n = 4 ;
   int x = 14 ;
   char ch1, ch2 ;
   char chr1=219, chr=175 ;
   do
   {
	line.box (1,1,39,25,219) ;
	line.line_hor(9,31,6,196) ;
	line.box (8,3,32,20,218) ;
	char c1=24, c2=25 ;
	gotoxy(3,24) ;
	cout <<c1 ;
	cout <<c2 ;
	cout <<"=Move <ENTER>=Select <ESC>=Exit" ;
	gotoxy(13,5) ;
	cout <<chr1 ;
	textbackground(WHITE) ;
	textcolor(BLACK) ;
	gotoxy(14,5) ;
	cprintf("Q U I Z ") ;
	textbackground(BLACK) ;
	textcolor(LIGHTGRAY) ;
	gotoxy(14,8) ;
	cout <<"OPTIONS" ;
	gotoxy(14,9) ;
	cout <<"-------" ;
	gotoxy(14,11) ;
	cout <<"PLAY" ;
	gotoxy(14,12) ;
	cout <<"ADD QUESTIONS" ;
	gotoxy(14,13) ;
	cout <<"EDIT" ;
	gotoxy(14,14) ;
	cout <<"QUIT" ;
	gotoxy(10,x) ;
	cout <<chr ;
	gotoxy(13,5) ;
	do
	{
	  do
	   {
	    do
	     {
		ch1 = getch() ;
		if ( ch1 == 27 )
			{
			 textmode(C80) ;
			 clrscr() ;
			 exit(0) ;
			 }
			} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
			if ( ch1 != 13 )
			{
			 do
			  {
			   ch2 = getch() ;
			   if ( ch2 == 27 )
					{
						textmode(C80) ;
						clrscr() ;
						exit(0) ;
					}
				} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
			}
		} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
		if (( ch1 == 0 ) && ( ch2 == 80 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if (n == 4)
			{
				n = 1 ;
				x = x - 3 ;
			}
			else
			{
				n = n + 1 ;
				x = x + 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(13,5) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
		if (( ch1 == 0 ) && ( ch2 == 72 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if ( n == 1 )
			{
				n = 4 ;
				x = x + 3 ;
			}
			else
			{
				n = n - 1 ;
				x = x - 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(13,5) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
	} while (( ch1 != 13 ) && ( ch2 != 13 )) ;
	if (n == 1)
	{
		char filename[13] ;
		strcpy(filename,sub_menu()) ;
		if (strcmp(filename,"null"))
		{
			quiz q ;
			q.play(filename) ;
			clrscr() ;
		}
	}
	if (n == 2)
	{
		char filename[13] ;
		strcpy(filename,sub_menu()) ;
		if (strcmp(filename,"null"))
		{
			textmode(C80) ;
			clrscr() ;
			quiz q ;
			q.add(filename) ;
			textmode(C40) ;
			clrscr() ;
		}
	}
	if (n == 3)
		edit_menu() ;
   } while ( n != 4 ) ;
   textmode(C80) ;
   clrscr() ;
}
//	CLASS NAME    : menu
//	FUNCTION NAME : edit_menu
//	DETAILS       : IT CREATES THE EDIT MAIN MENU
void menu :: edit_menu(void)
{
   lines line ;
   int valid ;
   static int n = 3 ;
   static int x = 19 ;
   char ch1, ch2 ;
   char chr1=219, chr=175 ;
   do
   {
	line.box(19,14,31,20,218) ;
	gotoxy(21,15) ;
	cout <<chr1 ;
	textbackground(WHITE) ;
	textcolor(BLACK) ;
	gotoxy(22,15) ;
	cprintf("E D I T ") ;
	textbackground(BLACK) ;
	textcolor(LIGHTGRAY) ;
	gotoxy(23,17) ;
	cout <<"DELETE" ;
	gotoxy(23,18) ;
	cout <<"MODIFY" ;
	gotoxy(23,19) ;
	cout <<"RETURN" ;
	gotoxy(20,x) ;
	cout <<chr ;
	gotoxy(21,15) ;
	do
	{
		do
		{
			do
			{
				ch1 = getch() ;
				if ( ch1 == 27 )
				{
					gotoxy(1,15) ; clreol() ;
					gotoxy(1,17) ; clreol() ;
					gotoxy(1,18) ; clreol() ;
					gotoxy(1,19) ; clreol() ;
					gotoxy(1,20) ; clreol() ;
					gotoxy(19,14) ; clreol() ;
					return ;
				}
			} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
			if ( ch1 != 13 )
			{
				do
				{
					ch2 = getch() ;
					if ( ch2 == 27 )
					{
						gotoxy(1,15) ; clreol() ;
						gotoxy(1,17) ; clreol() ;
						gotoxy(1,18) ; clreol() ;
						gotoxy(1,19) ; clreol() ;
						gotoxy(1,20) ; clreol() ;
						gotoxy(19,14) ; clreol() ;
						return ;
					}
				} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
			}
		} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
		if (( ch1 == 0 ) && ( ch2 == 80 ))
		{
			gotoxy(20,x) ;
			cout <<" " ;
			if (n == 3)
			{
				n = 1 ;
				x = x - 2 ;
			}
			else
			{
				n = n + 1 ;
				x = x + 1 ;
			}
			gotoxy(20,x) ;
			cout <<chr ;
			gotoxy(21,15) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
		if (( ch1 == 0 ) && ( ch2 == 72 ))
		{
			gotoxy(20,x) ;
			cout <<" " ;
			if ( n == 1 )
			{
				n = 3 ;
				x = x + 2 ;
			}
			else
			{
				n = n - 1 ;
				x = x - 1 ;
			}
			gotoxy(20,x) ;
			cout <<chr ;
			gotoxy(21,15) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
	} while (( ch1 != 13 ) && ( ch2 != 13 )) ;
	if (n == 1)
	{
		char filename[13] ;
		strcpy(filename,sub_menu()) ;
		if (strcmp(filename,"null"))
		{
			textmode(C80) ;
			clrscr() ;
			quiz q ;
			q.deletion(filename) ;
			textmode(C40) ;
			clrscr() ;
			return ;
		}
		clrscr() ;
		return ;
	}
	else
	if (n == 2)
	{
		char filename[13] ;
		strcpy(filename,sub_menu()) ;
		if (strcmp(filename,"null"))
		{
			textmode(C80) ;
			clrscr() ;
			quiz q ;
			q.modify(filename) ;
			textmode(C40) ;
			clrscr() ;
			return ;
		}
		clrscr() ;
		return ;
	}
   } while ( n != 3 ) ;
   gotoxy(1,15) ; clreol() ;
   gotoxy(1,17) ; clreol() ;
   gotoxy(1,18) ; clreol() ;
   gotoxy(1,19) ; clreol() ;
   gotoxy(1,20) ; clreol() ;
   gotoxy(19,14) ; clreol() ;
}
//	CLASS NAME    : menu
//	FUNCTION NAME : sub_menu
//	DETAILS       : IT CREATES THE SUB MAIN MENU AND
//                   RETURN FILE NAME
char *menu :: sub_menu(void)
{
   lines line ;
   clrscr() ;
   int valid ;
   static int n = 1 ;
   static int x = 10 ;
   char ch1, ch2 ;
   char chr1=219, chr=175 ;
   line.box(1,1,39,25,219) ;
   line.line_hor(2,38,23,196) ;
   char c1=24, c2=25 ;
   gotoxy(3,24) ;
   cout <<c1 ;
   cout <<c2 ;
   cout <<"=Move <ENTER>=Select <ESC>=Exit" ;
   gotoxy(13,6) ;
   cout <<chr1 ;
   textbackground(WHITE) ;
   textcolor(BLACK) ;
   gotoxy(14,6) ;
   cprintf("S U B - M E N U ") ;
   textbackground(BLACK) ;
   textcolor(LIGHTGRAY) ;
   line.box(11,5,31,7,218) ;
   gotoxy(14,10) ;
   cout <<"COMPUTERS" ;
   gotoxy(14,12) ;
   cout <<"MATHEMATICS" ;
   gotoxy(14,14) ;
   cout <<"SCIENCE" ;
   gotoxy(14,16) ;
   cout <<"GENERAL" ;
   gotoxy(14,18) ;
   cout <<"RETURN" ;
   gotoxy(12,x) ;
   cout <<chr ;
   gotoxy(13,6) ;
   do
   {
	do
	{
		do
		{
			ch1 = getch() ;
			if ( ch1 == 27 )
			{
				clrscr() ;
				return("null") ;
			}
		} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
		if ( ch1 != 13 )
		{
			do
			{
				ch2 = getch() ;
				if ( ch2 == 27 )
				{
					clrscr() ;
					return("null") ;
				}
			} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
		}
	} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
	if (( ch1 == 0 ) && ( ch2 == 80 ))
	{
		gotoxy(12,x) ;
		cout <<" " ;
		if (n == 5)
		{
			n = 1 ;
			x = x - 8 ;
		}
		else
		{
			n = n + 1 ;
			x = x + 2 ;
		}
		gotoxy(12,x) ;
		cout <<chr ;
		gotoxy(13,6) ;
		sound(200) ;
		delay(30) ;
		nosound() ;
	}
	if (( ch1 == 0 ) && ( ch2 == 72 ))
	{
		gotoxy(12,x) ;
		cout <<" " ;
		if ( n == 1 )
		{
			n = 5 ;
			x = x + 8 ;
		}
		else
		{
			n = n - 1 ;
			x = x - 2 ;
		}
		gotoxy(12,x) ;
		cout <<chr ;
		gotoxy(13,6) ;
		sound(200) ;
		delay(30) ;
		nosound() ;
	}
   } while (( ch1 != 13 ) && ( ch2 != 13 )) ;
   clrscr() ;
   if (n == 1)
	return("computer.dat") ;
   else
   if (n == 2)
	return("maths.dat") ;
   else
   if (n == 3)
	return("science.dat") ;
   else
   if (n == 4)
	return("general.dat") ;
   return("null") ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : record_count
//	DETAILS       : IT RETURNS THE NO. OF RECORD IN THE
//                   GIVEN FILE
int  quiz :: record_count(char filename[13])
{
   fstream file ;
   file.open(filename, ios::in) ;
   file.seekg(0,ios::beg) ;
   int t=0 ;
   while (file.read((char *) this, sizeof(quiz)))
	t++ ;
   file.close() ;
   return t ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : add
//	DETAILS       : IT ADDS THE RECORDS IN THE GIVEN FILE
void quiz :: add(char filename[13])
{
   lines line ;
   int valid ;
   int t_ques_no ;
   t_ques_no = record_count(filename) ;
   t_ques_no++ ;
   if (t_ques_no == 1)
   {
	ques_no = t_ques_no ;
	strcpy(ques,"abc") ;
	strcpy(ans1,"-") ;
	strcpy(ans2,"-") ;
	strcpy(ans3,"-") ;
	sol = '0' ;
	fstream file ;
	file.open(filename, ios::out | ios::app ) ;
	file.write((char *) this, sizeof(quiz)) ;
	file.close() ;
	delete_record(filename,t_ques_no) ;
   }
   char ch ;
   do
   {
	clrscr() ;
	line.box(1,1,79,23,218) ;
	gotoxy(3,5) ;
	cout <<"question # " <<t_ques_no ;
	gotoxy(3,8) ;
	cout <<"question : " ;
	gotoxy(3,10) ;
	cout <<"answer 1 : " ;
	gotoxy(3,12) ;
	cout <<"answer 2 : " ;
	gotoxy(3,14) ;
	cout <<"answer 3 : " ;
	gotoxy(3,16) ;
	cout <<"solution : " ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER QUESTION" ;
		gotoxy(14,8) ;
		gets(ques) ;
		strupr(ques) ;
		if (ques[0] == '0')
			return ;
		if (strlen(ques) > 159 || strlen(ques) == 0)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT BE BLANK OR GREATER THAN 159" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,8) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,10) ;
		gets(ans1) ;
		strupr(ans1) ;
		if (ans1[0] == '0')
			return ;
		if (strlen(ans1) > 49)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 49" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,10) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,12) ;
		gets(ans2) ;
		strupr(ans2) ;
		if (ans2[0] == '0')
			return ;
		if (strlen(ans2) > 49)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 49" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,14) ;
		gets(ans3) ;
		strupr(ans3) ;
		if (ans3[0] == '0')
			return ;
		if (strlen(ans3) > 49)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 49" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,14) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
		gotoxy(14,16) ;
		sol = getche() ;
		if (sol == '0')
			return ;
		if (sol != '1' && sol != '2' && sol != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(14,16) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,25) ;	clreol() ;
	gotoxy(1,24) ;  clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,19) ;
	cout <<"Do you want to save the record (y/n) : " ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(42,19) ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(42,19) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{
		ques_no = t_ques_no ;
		fstream file ;
		file.open(filename, ios::app ) ;
		file.write((char *) this, sizeof(quiz)) ;
		file.close() ;
		t_ques_no++ ;
	}
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,21) ;
	cout <<"Do you want to add more questions (y/n) : " ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(45,21) ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(45,21) ; clreol() ;
		}
	} while ( !valid ) ;
   } while (ch == 'Y')
//	CLASS NAME    : quiz
//	FUNCTION NAME : found_record
//	DETAILS       : IT SEARCH THE GIVEN RECORDS IN THE
//                   GIVEN FILE AND RETURN 0 IF NOT FOUND
int  quiz :: found_record(char filename[13], int t_ques_no)
{
   fstream file ;
   file.open(filename, ios::in) ;
   file.seekg(0,ios::beg) ;
   int found=0 ;
   while (file.read((char *) this, sizeof(quiz)))
   {
	if (t_ques_no == ques_no)
	{
		found++ ;
		break ;
	}
   }
   file.close() ;
   return found ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : display_record
//	DETAILS       : IT DISPLAY THE RECORD FOR THE GIVEN
//                   QUESTION NO. FROM THE GIVEN FILE
void quiz :: display_record(char filename[13], int t_ques_no)
{
   fstream file ;
   file.open(filename, ios::in) ;
   file.seekg(0,ios::beg) ;
   while (file.read((char *) this, sizeof(quiz)))
   {
	if (t_ques_no == ques_no)
	{
		gotoxy(3,3) ;
		cout <<"question # " <<t_ques_no ;
		gotoxy(3,7) ;
		cout <<"question : " <<ques ;
		gotoxy(3,8) ;
		cout <<"answer 1 : " <<ans1 ;
		gotoxy(3,9) ;
		cout <<"answer 2 : " <<ans2 ;
		gotoxy(3,10) ;
		cout <<"answer 3 : " <<ans3 ;
		break ;
	}
   }
   file.close() ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : delete_record
//	DETAILS       : IT DELETE THE RECORD FOR THE GIVEN
//                      QUESTION NO. FROM THE GIVEN FILE
void quiz :: delete_record(char filename[13], int t_ques_no)
{
   fstream file ;
   file.open(filename, ios::in) ;
   fstream temp ;
   temp.open("temp.dat", ios::out) ;
   file.seekg(0,ios::beg) ;
   while (!file.eof())
   {
	file.read((char *) this, sizeof(quiz)) ;
	if ( file.eof() )
		break ;
	if (ques_no != t_ques_no)
		temp.write((char *) this, sizeof(quiz)) ;
   }
   file.close() ;
   temp.close() ;
   file.open(filename, ios::out) ;
   temp.open("temp.dat", ios::in) ;
   temp.seekg(0,ios::beg) ;
   t_ques_no = 1 ;
   while (!temp.eof())
   {
	temp.read((char *) this, sizeof(quiz)) ;
	ques_no = t_ques_no ;
	if (temp.eof())
		break ;
	file.write((char *) this, sizeof(quiz)) ;
	t_ques_no++ ;
   }
   file.close() ;
   temp.close() ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : deletion
//	DETAILS       : IT GIVE THE QUESTION NO. TO DELETE
//                   RECORD FROM THE GIVEN FILE
void quiz :: deletion(char filename[13])
{   lines line ;
   clrscr() ;
   int valid ;
   int t_ques_no=0, t;
   char t1_ques_no[5] ;
   char ch ;
   line.box(1,1,79,23,218) ;
   gotoxy(72,25) ;
   cout <<"<0>=EXIT" ;
   gotoxy(3,3) ;
   cout <<"Enter question no. to be deleted : " ;
   do
   {
	gotoxy(38,3) ;
	gets(t1_ques_no) ;
   } while (strlen(t1_ques_no) == 0) ;
   t = atoi(t1_ques_no) ;
   t_ques_no = t ;
   if (t1_ques_no[0] == '0')
	return ;
   if (!found_record(filename,t_ques_no))
   {
	sound(500) ;
	delay(100) ;
	nosound() ;
	gotoxy(3,15) ;
	cout <<"question not found" ;
	line.line_hor(1,79,24,196) ;
	gotoxy(1,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
	return ;
   }
   clrscr() ;
   line.box(1,1,79,23,218) ;
   display_record(filename,t_ques_no) ;
   gotoxy(3,12) ;
   cout <<"Do you want to delete this Record (y/n) : " ;
   do
   {
	valid = 1 ;
	gotoxy(45,12) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(45,10) ; clreol() ;
	}
   } while (!valid ) ;
   if (ch == 'N')
	return ;
   gotoxy(1,25) ;
   cout <<"Wait..." ;
   delete_record(filename,t_ques_no) ;
   clrscr() ;
   sound(500) ;
   delay(100) ;
   nosound() ;
   gotoxy(3,14) ;
   cout <<"Record Deleted" ;
   line.line_hor(1,79,24,196) ;
   gotoxy(1,25) ;
   cout <<"Press any key to continue...." ;
   getch() ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : modify_record
//	DETAILS       : IT MODIFY THE RECORD FOR THE GIVEN
//                      QUESTION NO. FROM THE GIVEN FILE
void quiz :: modify_record(char filename[13], int t_ques_no)
{
   lines line ;
   int valid, modified=0 ;
   char ch ;
   line.line_hor(2,78,12,196) ;
   line.box(1,1,79,23,218) ;
   gotoxy(3,14) ;
   cout <<"QUESTION # " <<t_ques_no ;
   gotoxy(3,16) ;
   cout <<"QUESTION : " ;
   gotoxy(3,17) ;
   cout <<"ANSWER 1 : " ;
   gotoxy(3,18) ;
   cout <<"ANSWER 2 : " ;
   gotoxy(3,19) ;
   cout <<"ANSWER 3 : " ;
   gotoxy(3,20) ;
   cout <<"SOLUTION : " ;
   gotoxy(1,25) ;	clreol() ;
   line.line_hor(1,79,23,196) ;
   gotoxy(14,16) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,79,23,218) ;
	valid = 1 ;
	gotoxy(28,16) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,16) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,79,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,16) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER QUESTION" ;
	gotoxy(14,16) ;
	gets(ques) ;
	strupr(ques) ;
	if (ques[0] == '0')
		return ;
	if (strlen(ques) >159 || strlen(ques) == 0)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT BLANK OR GREATER THAN 159" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,16) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,17) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,79,23,218) ;
	valid = 1 ;
	gotoxy(28,17) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,17) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,79,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(13,17) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,17) ;
	gets(ans1) ;
	strupr(ans1) ;
	if (ans1[0] == '0')
		return ;
	if (strlen(ans1) > 49)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 49" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,17) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,18) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,79,23,218) ;
	valid = 1 ;
	gotoxy(28,18) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,18) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,79,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,18) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,18) ;
	gets(ans2) ;
	strupr(ans2) ;
	if (ans2[0] == '0')
		return ;
	if (strlen(ans2) > 49)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 49" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,18) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,19) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,79,23,218) ;
	valid = 1 ;
	gotoxy(28,19) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,19) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,79,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,19) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,19) ;
	gets(ans3) ;
	strupr(ans3) ;
	if (ans3[0] == '0')
		return ;
	if (strlen(ans3) > 49)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 49" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,19) ; clreol() ;
	}
   }
   if (!modified)
	return ;
   do
   {
	line.box(1,1,79,23,218) ;
	gotoxy(1,25) ;	clreol() ;
	valid = 1 ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
	gotoxy(14,20) ;
	sol = getche() ;
	if (sol == '0')
		return ;
	if (sol != '1' && sol != '2' && sol != '3')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,20) ; clreol() ;
	}
   } while (!valid) ;
   gotoxy(1,25) ; clreol() ;
   gotoxy(1,24) ; clreol() ;
   gotoxy(1,22) ;
   cout <<"Do you want to save the record (y/n)  : " ;
   do
   {
	line.box(1,1,79,23,218) ;
	valid = 1 ;
	gotoxy(41,22) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(41,22) ; clreol() ;
	}
   } while ( !valid ) ;
   if (ch == 'N')
	return ;
   fstream file ;
   file.open(filename, ios::out | ios::ate) ;
   int recno ;
   recno = t_ques_no ;
   int location ;
   location = (recno-1) * sizeof(quiz) ;
   file.seekp(location) ;
   file.write((char *) this, sizeof(quiz)) ;
   file.close() ;
   clrscr() ;
   sound(500) ;
   delay(100) ;
   nosound() ;
   gotoxy(1,14) ;
   cout <<"Record Modified" ;
   line.line_hor(1,79,24,196) ;
   gotoxy(1,25) ;
   cout <<"Press any key to continue..." ;
   getch() ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : modify
//	DETAILS       : IT GIVE THE QUESTION NO. TO MODIFY
//                      RECORD FROM THE GIVEN FILE
void quiz :: modify(char filename[13])
{
   lines line ;
   clrscr() ;
   int valid ;
   int t_ques_no=0, t;
   char t1_ques_no[5] ;
   char ch ;
   line.box(1,1,79,23,218) ;
   gotoxy(72,25) ;
   cout <<"<0>=EXIT" ;
   gotoxy(3,3) ;
   cout <<"Enter question no. to be modify  : " ;
   do
   {
	gotoxy(38,3) ;
	gets(t1_ques_no) ;
   } while (strlen(t1_ques_no) == 0) ;
   t = atoi(t1_ques_no) ;
   t_ques_no = t ;
   if (t1_ques_no[0] == '0')
	return ;
   if (!found_record(filename,t_ques_no))
   {
	sound(500) ;
	delay(100) ;
	nosound() ;
	gotoxy(3,15) ;
	cout <<"question not found" ;
	line.line_hor(2,78,24,196) ;
	gotoxy(1,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
	return ;
   }
   clrscr() ;
   display_record(filename,t_ques_no) ;
   gotoxy(3,12) ;
   cout <<"Do you want to modify this Record (y/n) : " ;
   do
   {
	valid = 1 ;
	gotoxy(45,12) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(45,10) ; clreol() ;
	}
   } while (!valid ) ;
   if (ch == 'N')
	return ;
   modify_record(filename,t_ques_no) ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : display_score
//	DETAILS       : IT DISPLAY THE SCORE FOR THE GIVEN
//                      PLAYER'S NAME
void quiz :: display_score(char name[20], int played, int correct)
{
   clrscr() ;
   lines line ;
   line.box(1,1,39,25,218) ;
   line.box(2,2,38,24,219) ;
   textbackground(WHITE) ;
   textcolor(BLACK+BLINK) ;
   gotoxy(5,4) ;
   cprintf("                               ") ;
   gotoxy(9,4) ;
   cprintf("S C O R E   B O A R D") ;
   textbackground(BLACK) ;
   textcolor(LIGHTGRAY) ;
   gotoxy(5,7) ;
   cout <<"Player's Name : " <<name ;
   gotoxy(5,9) ;
   cout <<"questions Attempted : " <<played ;
   gotoxy(5,11) ;
   cout <<"Correct answer      : " <<correct ;
   gotoxy(5,13) ;
   cout <<"Wrong answer        : " <<played-correct ;
   int score ;
   score = correct * 10 ;
   gotoxy(5,16) ;
   cout <<"Score  : " <<score ;
   int tplayed ;
   tplayed = played * 10 ;
   float percentage ;
   percentage = ((score*100)/tplayed) ;
   gotoxy(5,18) ;
   cout <<"Percentage : " <<percentage ;
   getch() ;
}
//	CLASS NAME    : quiz
//	FUNCTION NAME : play
//	DETAILS       : IT CREATES SCREEN FOR PLAYING QUIZ
//                      TO THE PLAYER FOR THE GIVEN FILE NAME
//                      AND KEEP SCORE.
void quiz :: play(char filename[13])
{
   clrscr() ;
   int valid ;
   lines line ;
   char name[20] ;
   gotoxy(3,3) ;
   cout <<"Enter your name : " ;
   do
   {
	line.box(1,1,39,25,219) ;
	valid = 1 ;
	gotoxy(30,24) ;
	cout <<"<0>=EXIT" ;
	gotoxy(21,3) ;
	gets(name) ;
	strupr(name) ;
	if (name[0] == '0')
		return ;
	if (strlen(name) > 18)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(30,24) ;
		cout <<"        " ;
		gotoxy(3,23) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 18" ;
		gotoxy(3,24) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(3,23) ;
		cout <<"                                  " ;
		gotoxy(3,24) ;
		cout <<"                             " ;
		gotoxy(21,3) ;
		cout <<"                  " ;
	}
   } while ( !valid ) ;
   char t_sol, ch ;
   int  correct=0, played=0 ;
   fstream file ;
   file.open(filename,ios::in) ;
   file.seekg(0,ios::beg) ;
   while (file.read((char *) this, sizeof(quiz)))
   {
	clrscr() ;
	line.box(1,1,39,25,219) ;
	gotoxy(25,3) ;
	cout <<"SCORE:" <<correct*10 ;
	valid = 1 ;
	gotoxy(28,24) ;
	cout <<"<ESC>=Exit" ;
	gotoxy(3,4) ;
	cout <<"question # " <<ques_no ;
	gotoxy(3,6) ;
	cout <<"question : " <<ques ;
	gotoxy(3,10) ;
	cout <<"answer 1 : " <<ans1 ;
	gotoxy(3,11) ;
	cout <<"answer 2 : " <<ans2 ;
	gotoxy(3,12) ;
	cout <<"answer 3 : " <<ans3 ;
	gotoxy(3,14) ;
	cout <<"Enter correct solution : " ;
	int i=0, j=0, time=10 ;
	do
	{
		valid = 1 ;
		gotoxy(3,21) ;
		cout <<"Time : " <<time ;
		gotoxy(28,12) ;
		do
		{
			delay(1) ;
			i++ ;
			j++ ;
			if (j == 600)
			{
				j = 0 ;
				time-- ;
				gotoxy(11,21) ;
				cout <<" " ;
				gotoxy(10,21) ;
				cout <<time ;
				gotoxy(28,14) ;
			}
		} while (!kbhit() && i<6000) ;
		if (i >= 6000)
		{
			played++ ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(13,16) ;
			cout <<"Sorry Time up!" ;
			gotoxy(1,1) ;
			getch() ;
			if (played)
				display_score(name,played,correct) ;
			return ;
		}
		gotoxy(3,21) ;
		cout <<"             " ;
		gotoxy(28,12) ;
		t_sol = getche() ;
		if (t_sol == 27)
		{
			if (played)
				display_score(name,played,correct) ;
			return ;
		}
		if (t_sol != '1' && t_sol != '2' && t_sol != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(28,12) ;
			cout <<"  " ;
		}
	} while (!valid) ;
	played++ ;
	if (t_sol != sol)
	{
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,16) ;
		cout <<"wrong answer" ;
		gotoxy(13,17) ;
		cout <<"Correct answer : " <<sol ;
		gotoxy(1,1) ;
		ch = getch() ;
		gotoxy(14,15) ;
		cout <<"            " ;
		gotoxy(13,16) ;
		cout <<"                    " ;
		gotoxy(3,24) ;
		cout <<"                                    " ;
	}
	else
	{
		correct++ ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(16,16) ;
		cout <<"GOOD ! CORRECT ANSWER" ;
		gotoxy(25,3) ;
		cout <<"SCORE:" <<correct*10 ;
		gotoxy(1,1) ;
		ch = getch() ;
	}
	if (ch == 27)
	{
		display_score(name,played,correct) ;
		return ;
	}
   }
   gotoxy(3,22) ;
   cout <<"No more questions available" ;
   getch() ;
   if (!played)
	return ;
   display_score(name,played,correct) ;
}
//	FUNCTION NAME : main
//	DETAILS       : IT CALLS THE START FUNCTION AND
//                   MENU FUNCTION.
void main(void)
{
   menu m ;
   m.start() ;
   m.main_menu() ;
   getch();
}//               END OF PROJECT

