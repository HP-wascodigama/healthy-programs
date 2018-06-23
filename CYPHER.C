#include<stdio.h>
#include<conio.h>
#include<string.h>
//shift cypher.
void main()
{
 char *str;
 int i,cy,l;
 clrscr();
 printf("enter simple text: ");
 gets(str);
 printf("enter cypher value for shift cypher=");
 scanf("%d",&cy);
 l=strlen(str);
 printf("%d",l);
 for(i=0;i<l;i++)
 {
  if((str[i]<='Z' && str[i]>='A' && str[i+cy]<='Z') || (str[i]>='a' && str[i]<='z' && str[i+cy]<='z'))
  {
   str[i] = str[i]+cy;
   printf("\n");
   puts(str);
   printf(" we in 1st if");
  }
  else if(str[i]<='Z' && str[i]>='A' && str[i+cy]>='Z')
  {
   str[i] = 97+(i+cy-122);
   printf("\n");
   puts(str);
   printf("we in 2nd if");
  }
  else if(str[i]<='z' && str[i]>='a' && str[i+cy]>='z')
  {
   str[i] = 65+(i+cy-89);
   printf("\n");
   puts(str);
   printf("we in 3rd if");
  }
  else
  {
   printf("enter text con't convertable: ");
  }
 }
 printf("cypertext is: ");
 puts(str);
 getch();
}
