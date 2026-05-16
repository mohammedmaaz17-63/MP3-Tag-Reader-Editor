#include "mp3_header.h"

void help(void)
{
    printf("--------------------------------------------------\n");
    printf("              MP3 TAG READER & EDITOR             \n");
    printf("--------------------------------------------------\n\n");

    printf("This application is used to:\n");
    printf("1. View MP3 tag information\n");
    printf("2. Edit MP3 tag information\n\n");

    printf("AVAILABLE OPTIONS:\n");
    printf("-v     -> View MP3 file details\n");
    printf("-e     -> Edit MP3 file details\n");
    printf("-h     -> Display help menu\n");

    printf("TAGS THAT CAN BE VIEWED/EDITED:\n");
    printf("Title\n");
    printf("Artist\n");
    printf("Album\n");
    printf("Year\n");
    printf("Genre\n");
    printf("Comment\n\n");

    printf("STEPS TO VIEW DETAILS:\n");
    printf("1. Enter -v\n");
    printf("2. Enter the MP3 file name\n");
    printf("3. The tag details will be displayed\n\n");

    printf("STEPS TO EDIT DETAILS:\n");
    printf("1. Enter -e\n");
    printf("2. Enter the tag to edit\n");
    printf("3. Enter the new data\n");
    printf("4. Enter the MP3 file name\n");
    printf("5. Updated details will be saved\n\n");

    printf("TAGS THAT CAN BE EDITED USING THE BELOW SPECIFIED TAGS:\n");
    printf("TIT2  -> Title\n");
    printf("TPE1  -> Artist\n");
    printf("TALB  -> Album\n");
    printf("TYER  -> Year\n");
    printf("TCON  -> Genre\n");
    printf("COMM  -> Comment\n\n");

    printf("EXAMPLE:\n");
    printf("Enter the option : -v\n");
    printf("Enter file name  : sample.mp3\n\n");

    printf("Enter the option : -e\n");
    printf("Enter file name  : sample.mp3\n\n");
    printf("Enter tag        : TIT2\n");
    printf("Enter new data   : New Song\n");

    printf("--------------------------------------------------\n");
}