# MP3 Tag Reader & Editor - Menu Based Version

This is the menu-driven implementation of the MP3 Tag Reader & Editor project developed in C.

The application allows users to:

* View MP3 metadata
* Edit MP3 metadata
* Access help menu interactively

---

# Compilation

```bash
gcc *.c
```

---

# Execution

```bash
./a.out
```

---

# Program Flow

```text
Enter the option to perform operation

Enter -v to view the details of the mp3 file
Enter -e to edit the details of the mp3 file
Enter -h or help to get all the details
```

---

# Viewing MP3 Details

## Steps

1. Enter `-v`
2. Enter MP3 file name
3. Program displays tag information

## Example

```text
-v

Enter the file name
sample.mp3

Title   : Old song
Artist  : Yo Yo Honey Singh - [SongsPk.CC]
Album   : Yaariyan
Year    : 2014
Genre   : Bollywood Music - [SongsPk.CC]
Comment : eng
```

---

# Editing MP3 Details

## Steps

1. Enter `-e`
2. Enter file name
3. Enter tag to edit
4. Enter new data

## Example

```text
-e

Enter the file name
sample.mp3

Enter the tag of the mp3 file you want to edit
TIT2

Enter the new data you want to store in the place of old one
New Song

Success: Tag TIT2 updated.
```

---

# Help Menu

## Example

```text
-h
```

Displays:

* Available options
* Editable tags
* Usage instructions
* Examples

---

# Concepts Used

* File Handling
* Binary File Processing
* Dynamic Memory Allocation
* Menu-Driven Programming
* ID3v2 Tag Processing
* User Interaction Handling
