#include<stdio.h>
#include<string.h>

void tag_viewer(char*filename);
void tag_editor(char*filename,char*Tag,char*new_data);
void help();

int main()
{
    char option[10];
    char filename[100];
    char tag[10];
    char new_data[100];

    printf("Enter the option to perform operation\n");
    printf("Enter -v to view the details of the mp3 file\n");
    printf("Enter -e to edit the details of the mp3 file\n");
    printf("Enter -h or help to get all the details of all\n");

    fgets(option, sizeof(option), stdin);
    option[strcspn(option, "\n")] = '\0';
    //this above line removes the newline character from the end of the input string, which is read by fgets when the user presses Enter. strcspn finds the newline character index in the string and replaces it with the null character to make the string clean.
    //option[-v\n] => after this line, option will be "-v" instead of "-v\n"
    if(strcasecmp("-v", option) == 0)
    {
        printf("Enter the file name\n");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0';
        //same as above, removes the newline character from the end of the input string.
        if(strstr(filename, ".mp3") == NULL)
        {
            printf("Invalid file name\n");
            return 0;
        }

        tag_viewer(filename);
    }
    else if(strcasecmp("-e", option) == 0)
    {
        printf("Enter the file name\n");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0';
        //same as above, removes the newline character from the end of the input string.
        if(strstr(filename, ".mp3") == NULL)
        {
            printf("Invalid file name\n");
            return 0;
        }

        printf("Enter the tag of the mp3 file you want to edit\n");
        fgets(tag, sizeof(tag), stdin);
        tag[strcspn(tag, "\n")] = '\0';
        //same as above, removes the newline character from the end of the input string.
        if(strcmp(tag,"TIT2")==0 || strcmp(tag,"TYER")==0 ||
           strcmp(tag,"TALB")==0 || strcmp(tag,"TPE1")==0 ||
           strcmp(tag,"TCON")==0 || strcmp(tag,"COMM")==0 )
        {
            printf("Enter the new data you want to store in the place of old one\n");
            fgets(new_data, sizeof(new_data), stdin);
            new_data[strcspn(new_data, "\n")] = '\0';
            //same as above, removes the newline character from the end of the input string.
            tag_editor(filename, tag, new_data);
        }
        else
        {
            printf("Invalid tag\n");
        }
    }
    else if(strcasecmp("-h", option) == 0 || strcasecmp("help", option) == 0)
    {
        help();
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}