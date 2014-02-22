#include "common.h"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    
    source_file=init_lister(*argv,source_name,date); //Calls the init lister function and sets a value to the pointer source_file
    
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
    clk=localtime(&timer);
    
    strcpy(source_file_name,name);
    
    //stores all of the components of the date header in strings
    char date[5];
    char stryr[5];
    char strmon[3];
    char strhr[3];
    char strmin[3];
    
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
    strcat(dte, '\0');
    
    file=fopen(source_file_name, "r");
    
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
    
    fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file);
    
    if (source_buffer[0]) //This is the condition for the if statement
    {
	strcpy(print_buffer,source_buffer);//copies the string in source buffer over to print buffer
	print_line(print_buffer,src_name,todays_date); //calls the print line function
	line_number++;//increments the line number
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
