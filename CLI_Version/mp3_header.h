#ifndef MP3_HEADER_H
#define MP3_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRAME_SIZE 1024

// Utility
int convert(int size);

// Core Functionalities - Names matched to main.c
void tag_viewer(char *filename);
void tag_editor(char *filename, char *Tag, char *new_data);

#endif