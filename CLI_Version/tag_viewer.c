#include "mp3_header.h"

int convert(int size) 
{
    char *ptr = (char *)&size;
    // Swap bytes for Big Endian to Little Endian
    return (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | (ptr[3]);
}

void tag_viewer(char *filename) 
{
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) 
    {
        printf("Error: File does not exist.\n");
        return;
    }
    fseek(fptr, 10, SEEK_SET); // Skip Header
    int count = 0;

    while (count < 6) //because we are only going to read 6 frames (TIT2, TYER, TALB, TPE1, TCON, COMM)
    {
        char tag[5] = {0};// 4 bytes for tag + 1 byte for null
        if (fread(tag, 1, 4, fptr) != 4) 
            break;

        int size = 0;
        fread(&size, 4, 1, fptr);// Read the size as a 4-byte integer from the file which is the information of the tag, which is in Big Endian format.
        size = convert(size);// We will convert it into the Little Endian using the convert function

        fseek(fptr, 2, SEEK_CUR); // Skip flags

        // ID3 frames usually have an encoding byte (1 byte)
        char encoding;
        fread(&encoding, 1, 1, fptr);

        char info[MAX_FRAME_SIZE] = {0};
        int read_len = (size - 1 < MAX_FRAME_SIZE) ? size - 1 : MAX_FRAME_SIZE - 1;
        
        fread(info, 1, read_len, fptr);
        info[read_len] = '\0';

        // Skip any remaining bytes in this frame if it exceeded MAX_FRAME_SIZE
        if (size - 1 > read_len) 
        {
            fseek(fptr, size - 1 - read_len, SEEK_CUR);
        }

        if (strcmp(tag, "TIT2") == 0) printf("Title   : %s\n", info);
        else if (strcmp(tag, "TYER") == 0) printf("Year    : %s\n", info);
        else if (strcmp(tag, "TALB") == 0) printf("Album   : %s\n", info);
        else if (strcmp(tag, "TPE1") == 0) printf("Artist  : %s\n", info);
        else if (strcmp(tag, "TCON") == 0) printf("Genre   : %s\n", info);
        else if (strcmp(tag, "COMM") == 0) printf("Comment : %s\n", info);

        count++;//after reading one tag, we will increment the count and move to the next tag until we have read 6 tags.
    }
    fclose(fptr);//close the file pointer after we are done reading the tags from our mp3 file.
}