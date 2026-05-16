# MP3 Tag Reader & Editor - CLI Version

This is the implementation of the MP3 Tag Reader & Editor using Command Line Argument (CLA).

The application allows users to:

* View MP3 metadata
* Edit MP3 metadata directly from terminal commands

---

# Compilation

```bash
gcc *.c
```

---

# Execution

## View MP3 Information

```bash
./a.out -v sample.mp3
```

---

## Edit MP3 Tags

### Edit Title

```bash
./a.out -e -t "New Song" sample.mp3
```

### Edit Artist

```bash
./a.out -e -a "New Artist" sample.mp3
```

### Edit Album

```bash
./a.out -e -A "New Album" sample.mp3
```

### Edit Year

```bash
./a.out -e -y "2025" sample.mp3
```

### Edit Genre

```bash
./a.out -e -g "Melody" sample.mp3
```

### Edit Comment

```bash
./a.out -e -c "Nice Song" sample.mp3
```


# Help Menu

```bash
./a.out -help
```

Displays:

* Available options
* Editable tags
* Usage instructions
* Examples


---

# Supported Options

| Option | Description              |
| ------ | ------------------------ |
| -v     | View MP3 tag information |
| -e     | Edit MP3 tag             |
| -t     | Edit Title               |
| -a     | Edit Artist              |
| -A     | Edit Album               |
| -y     | Edit Year                |
| -g     | Edit Genre               |
| -c     | Edit Comment             |
| -help  | Help                     |

---

# Example Output

```text
--------------------------------------------------
                MP3 TAG INFORMATION
--------------------------------------------------

Title   : New Song
Artist  : Yo Yo Honey Singh
Album   : Yaariyan
Year    : 2014
Genre   : Bollywood Music
Comment : eng
```

---

# Concepts Used

* File Handling
* Binary File Processing
* Dynamic Memory Allocation
* String Manipulation
* Command Line Argument Parsing
* ID3v2 Tag Processing
