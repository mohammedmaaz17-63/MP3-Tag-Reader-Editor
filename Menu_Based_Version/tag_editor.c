#include "mp3_header.h"

void tag_editor(char *filename, char *Tag, char *new_data) {
    FILE *fp = fopen(filename, "rb");
    FILE *dub_fp = fopen("duplicate.mp3", "wb");

    //check if both files are created successfully created
    if (!fp || !dub_fp) {
        perror("File Error");
        return;
    }

    //header remains same, so don't change the header
    char header[10];
    fread(header, 1, 10, fp);
    fwrite(header, 1, 10, dub_fp);

    for (int i = 0; i < 6; i++) {
        char tag[5] = {0};
        fread(tag, 1, 4, fp);
        fwrite(tag, 1, 4, dub_fp);

        int size;
        fread(&size, 4, 1, fp);
        int og_size = convert(size); 
        
        char flags[2];
        fread(flags, 1, 2, fp);

        if (strcmp(Tag, tag) == 0) //if the tag we are currently reading and the tag given by the user is same
        {
            // Keep the original size in the header so we don't break the file
            fwrite(&size, 4, 1, dub_fp);
            fwrite(flags, 1, 2, dub_fp);

            // 1. Handle Encoding Byte
            char encoding;
            fread(&encoding, 1, 1, fp);
            fwrite(&encoding, 1, 1, dub_fp);

            // 2. Calculate usable space
            // If og_size is 10, 1 byte is encoding, so 9 bytes are for text.
            int usable_text_space = og_size - 1; 
            int new_data_len = strlen(new_data);

            // 3. Write new data
            if (new_data_len > usable_text_space) {
                fwrite(new_data, 1, usable_text_space, dub_fp);
            } else 
            {
                fwrite(new_data, 1, new_data_len, dub_fp);
                // 4. Pad exactly enough nulls to fill the original frame size
                for (int j = 0; j < (usable_text_space - new_data_len); j++) {
                    fputc('\0', dub_fp);
                }
            }

            // 5. Skip the old data in the source file correctly
            fseek(fp, og_size - 1, SEEK_CUR);
            
            printf("Success: Tag %s updated.\n", Tag);
        } 
        else 
        {
            fwrite(&size, 4, 1, dub_fp);
            fwrite(flags, 1, 2, dub_fp);

            char *buffer = malloc(og_size);
            if(buffer)
            {
                fread(buffer, 1, og_size, fp);
                fwrite(buffer, 1, og_size, dub_fp);
                free(buffer);
            }
        }
    }

    // Copy remaining audio data
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) //read till the last character of the file
    {
        fwrite(buffer, 1, bytes, dub_fp);//write it in the duplicate file
    }

    fclose(fp);
    fclose(dub_fp);
    remove(filename);
    rename("duplicate.mp3", filename);//Here we are renaming our duplicate file name as same as the original file name
}