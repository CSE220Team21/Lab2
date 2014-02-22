/* CSE 220 Lab 2 Team 21: Ashley Krueger, Mike Mayr, Charlie Crowe */

#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        print_page_header(source_name_to_print, date_to_print);//calls the print page header function
        line_count=1;//initializes the line count to 1
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
        save_chp=(line+MAX_PRINT_LINE_LENGTH);//sets save chp to the line plus the length
        save_ch=*save_chp;//sets save ch to the pointer
        *save_chp='\0';//dereferences the pointer and sets it equal to the null character
    }
    if (save_chp)  
    {
        printf("%s: ", line);//prints the line number
        *save_chp=save_ch;//sets the pointer back
    }
   
    if (save_chp)
    {
       line_count++;  //increments line_count
    }
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
    
    page_number++;//increments page number
    printf("%s\nPage: %d %s\n", source_name, page_number, date);//calls printf and prints out the header with the file name, page number, and the date
}
