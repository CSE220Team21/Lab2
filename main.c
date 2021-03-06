/* CSE 220 Lab 2 Team 21: Ashley Krueger, Mike Mayr, Charlie Crowe */

#include "common.h"

int main (int argc, const char *argv[])
{
     FILE *source_file;
     char source_name[MAX_FILE_NAME_LENGTH];
     char date[DATE_STRING_LENGTH];

     if(argc != 2)
     {
          printf("Incoreect number of options!!!!");
          return 1;
     }

     source_file=init_lister(argv[1],source_name,date); //Calls the init lister function and sets a value to the pointer source_file

     while(get_source_line(source_file,source_name,date)){
     }//Calls the Boolean function until it is false
     return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
     time_t timer;
     struct tm *clk;//creates a pointer called clk of type struct tm
     FILE *file;

     time(&timer);
     clk=localtime(&timer);//instantiates clk to local time

     strcpy(source_file_name,name);//copies over the pointer name to the char source file name

     int i;

     //for loop clears out the array since strcat is used later
     for(i=0; i<sizeof(dte); i++){
          dte[i]=NULL;//sets every location to null
     }

     //stores all of the components of the date header in strings
     char date[5];//date number
     char stryr[5];// year number since 1900
     char strmon[3];//month starting with 0
     char strhr[3];//hour in a string
     char strmin[3];//minutes in a string

     //prints every component of the date header
     sprintf(stryr, "%d", (clk->tm_year + 1900));
     sprintf(strmon, "%d", (clk->tm_mon + 1));
     sprintf(date, "%d", (clk->tm_mday));
     sprintf(strhr, "%d", (clk->tm_hour));
     sprintf(strmin, "%d", (clk->tm_min));

     //concatinates the strings into the character array dte
     strcat(dte, strmon);
     strcat(dte, "/");
     strcat(dte, date);
     strcat(dte, "/");
     strcat(dte, stryr);
     strcat(dte, " ");
     strcat(dte, strhr);
     strcat(dte, ":");
     strcat(dte, strmin);
     strcat(dte, "\0");

     file=fopen(source_file_name, "r");//opens the file

     return file;//returns the file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
     char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
     char source_buffer[MAX_SOURCE_LINE_LENGTH];
     static int line_number = 0;


     if(fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file))
     {
          source_buffer[79] = '\n';
          source_buffer[80] = '\0';
          strcpy(print_buffer,source_buffer);//copies the string in source buffer over to print buffer
          print_line(line_number, print_buffer,src_name,todays_date); //calls the print line function
          line_number++;//increments the line number
          return (TRUE);
     }
     else
     {
          return (FALSE);
     }
}
