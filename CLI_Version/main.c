#include<stdio.h>
#include<string.h>

void tag_viewer(char*filename);
void tag_editor(char*filename,char*Tag,char*new_data);
void help(void);
void no_arg(void);
int is_mp3(char*filename);

int main(int argc, char *argv[])
{
    // No arguments
    if (argc == 1)
    {
        printf("Insufficient arguments\n");
        return 0;
    }

    // Help option
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-help") == 0)
        {
            help();
            return 0;
        }
        printf("\n====================================\n");
        printf("       ERROR: INVALID INPUT..!\n");
        printf("\n====================================\n");
        return 0;
    }

    // View option: ./a.out -v file.mp3
    else if (argc == 3)
    {
        char filename[50];
        strcpy(filename,argv[2]);
        FILE *fptr = fopen(filename, "rb");
        if (fptr == NULL) 
        {
           printf("\n=========================================================\n");
            printf("              ERROR: INVALID MP3 FILE  \n");
            printf("---------------------------------------------------------\n");
            return 0;
        }

        if (strcasecmp(argv[1], "-v") == 0)
        {
            printf("\n---------------------------------------------------------------\n");
            printf("                 MP3 TAG INFORMATION \n");
            printf("-------------------------------------------------------------\n");
            tag_viewer(filename);
            printf("-------------------------------------------------------------\n");
            return 0;
        }
        printf("Invalid view option!\n");
        return 0;
    }

    // Edit option: ./a.out -e -t "New Title" file.mp3
    else if (argc == 5)
    {

        int v = is_mp3(argv[4]);
        if (v == 0)
        {
            printf("\n=========================================================\n");
            printf("     ERROR: INVALID MP3 FILE  \n");
            printf("---------------------------------------------------------\n");
            printf("   The file '%s' is not a valid MP3/ID3 tagged file.\n", argv[4]);
            printf("=========================================================\n\n");

            return 0;
        }

        if (strcmp(argv[1], "-e") != 0)
        {
            printf("Invalid command! Use -e for edit.\n");
            return 0;
        }

        char *opt = argv[2]; // -t / -a / -A / -y / -c
        char *new_data = argv[3];
        char *filename = argv[4];

        // Map options to ID3 frame names
        if (strcmp(opt, "-t") == 0)
        {
            tag_editor(filename, "TIT2", new_data); // Title
        }
        else if (strcmp(opt, "-a") == 0)
        {
            tag_editor(filename, "TPE1", new_data); // Artist
        }
        else if (strcmp(opt, "-A") == 0)
        {
            tag_editor(filename, "TALB", new_data); // Album
        }
        else if (strcmp(opt, "-y") == 0)
        {
            tag_editor(filename, "TYER", new_data); // Year
        }
        else if (strcmp(opt, "-g") == 0)
        {
            tag_editor(filename, "TCON", new_data);// Genre
        }
        else if (strcmp(opt, "-c") == 0)
        {
            tag_editor(filename, "COMM", new_data); // Comment
        }
        else
        {
            printf("Invalid edit option: %s\n", opt);
            no_arg();
            return 0;
        }

        printf("---------------------------------------------------------\n");
        printf("         CONTENT UPDATED SUCCESSFULLY!   \n");
        printf("---------------------------------------------------------\n\n");

        return 0;
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}