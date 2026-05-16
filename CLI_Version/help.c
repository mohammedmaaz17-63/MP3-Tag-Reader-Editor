#include "mp3_header.h"
int is_mp3(char *filename)
{
    if(strstr(filename,".mp3") == NULL)
    {
        return 0;
    }
}
void no_arg()
{
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("                                      INVALID ARGUMENTS PROVIDED                                        \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Usage:\n");
    printf("To \"HELP\" pass in this format: ./a.out -help\n");
    printf("To \"VIEW\" pass in this format: ./a.out -v <file>\n");
    printf("To \"EDIT\" pass in this format: ./a.out -e [-t/-a/-A/-y/-g/-c] \"<changing_txt/ new text>\" <file>\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
}

void help(void)
{
    printf("-----------------------------------------------------------------------------------\n");
    printf("                       MP3 TAG READER & EDITOR HELP                                \n");
    printf("-----------------------------------------------------------------------------------\n");

    printf("Options:\n");
    printf("  -v <file>               to view MP3 tag information\n");
    printf("  -e <tag> <text> <file>  to edit MP3 tag\n\n");

    printf("Tag Options for editing:\n");
    printf("  -t    Edit Title\n");
    printf("  -a    Edit Artist\n");
    printf("  -A    Edit Album\n");
    printf("  -y    Edit Year\n");
    printf("  -g    Edit Genre\n");
    printf("  -c    Edit Comment\n\n");

    printf("Examples:\n");
    printf("  To view tags:\n");
    printf("      ./a.out -v sample.mp3\n\n");

    printf("  To edit title:\n");
    printf("      ./a.out -e -t \"New Song Name\" sample.mp3\n\n");

    printf("  To edit artist:\n");
    printf("      ./a.out -e -a \"New Artist\"  sample.mp3\n\n");


    printf("-----------------------------------------------------------------------------------\n");
}