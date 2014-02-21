#include "common.h"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    
    source_file=init_lister(*argv,source_name,date) //Calls the init lister function and sets a value to the pointer source_file
    
   while(get_source_line(source_file,source_name,date)){
   }//Calls the Boolean function until it is false
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    
    /* Missing Code Here */
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
    
    if (source_buffer[0]) //This is the condition for the if statement
    {
	strcpy(print_buffer,source_buffer);//copies the string in source buffer over to print buffer
	line_number++;//increments the line number
	print_line(print_buffer,src_name,todays_date); //calls the print line function
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
