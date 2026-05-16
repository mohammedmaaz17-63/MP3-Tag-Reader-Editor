# 🎵 MP3 Tag Reader & Editor

A C-based MP3 Tag Reader & Editor developed to efficiently read, display, and modify MP3 metadata using ID3 tags through both Command Line Argument (CLA) and Menu-Driven interfaces.

---

# 📖 Project Overview

MP3 files contain metadata such as:

* Title
* Artist
* Album
* Year
* Genre
* Comment

Managing and editing these tags manually can be difficult and time-consuming.

This project was developed to create a simple and efficient solution for reading and editing MP3 metadata using the C programming language and binary file handling techniques.

The application supports:

* Viewing MP3 metadata
* Editing MP3 metadata
* Menu-driven interaction
* Command-line based operations

---

# 🎯 Problem Statement

Managing MP3 metadata manually has several limitations:

-> Difficulty in editing metadata efficiently
-> Improper organization of music files
-> Time-consuming manual modifications
-> Lack of lightweight metadata editing tools
-> Risk of corrupting binary files without proper handling

This project solves these problems by providing:

-> Efficient MP3 metadata reading
-> Easy metadata editing
-> Binary-safe file operations
-> Simple user interaction
-> Lightweight command-line utility

---

# 🚀 Objectives of the Project

-> To understand binary file handling in C
-> To implement real-world file processing concepts
-> To understand ID3 tag structures in MP3 files
-> To practice modular programming
-> To improve debugging and problem-solving skills
-> To develop both CLA-based and menu-driven applications

---

# ✨ Features

## 📄 View MP3 Metadata

Displays:

* Title
* Artist
* Album
* Year
* Genre
* Comment

## ✏️ Edit MP3 Metadata

Supports editing:

* Title
* Artist
* Album
* Year
* Genre
* Comment

## 🖥️ Multiple Interfaces

* Command Line Argument (CLA) version
* Menu-Driven version

## 💾 Binary File Processing

* Reads ID3 tags safely
* Preserves MP3 file structure
* Handles frame-based metadata editing

---

# 🛠️ Tools & Technologies Used

| Tool / Technology         | Purpose                       |
| ------------------------- | ----------------------------- |
| C Programming             | Core application development  |
| GCC Compiler              | Compiling source code         |
| Linux / WSL               | Development environment       |
| Binary File Handling      | Reading & editing MP3 files   |
| Dynamic Memory Allocation | Handling variable frame sizes |
| ID3v2 Tags                | MP3 metadata processing       |

---

# 🧠 Concepts Used

-> File Handling
-> Binary File Processing
-> Dynamic Memory Allocation
-> String Handling
-> Structures
-> Functions
-> Pointers
-> Command Line Argument Parsing
-> Menu-Driven Programming
-> Modular Programming

---

# 📂 Project Structure

```text
MP3-Tag-Reader-Editor/
│
├── CLI_Version/
│
├── Menu_Based_Version/
│
└── README.md
```

---

# ⚙️ How to Compile and Run

## 🔹 Compile

```bash
gcc *.c
```

---

# ▶️ CLI Version

## View MP3 Details

```bash
./a.out -v sample.mp3
```

## Edit MP3 Details

```bash
./a.out -e -t "New Song" sample.mp3
```
## Help

```bash
./a.out -help
```
---

# ▶️ Menu-Based Version

## Run

```bash
./a.out
```

## Example Flow

```text
Enter the option to perform operation

Enter -v to view the details of the mp3 file
Enter -e to edit the details of the mp3 file
Enter -h or help to get all the details
```

---

# 🏷️ Supported Tags

| Frame ID | Description |
| -------- | ----------- |
| TIT2     | Title       |
| TPE1     | Artist      |
| TALB     | Album       |
| TYER     | Year        |
| TCON     | Genre       |
| COMM     | Comment     |

---

# 💾 File Handling

The project uses binary file handling to:

* Read ID3 metadata frames
* Modify MP3 tag information
* Preserve MP3 file structure
* Update frame contents dynamically

---

# 📸 Sample Output

```text
Title   : Old song
Artist  : Yo Yo Honey Singh
Album   : Yaariyan
Year    : 2014
Genre   : Bollywood Music
Comment : eng
```

---

# 🎓 Learning Outcomes

Through this project, the following skills were improved:

-> Binary file handling in C
-> MP3 ID3 tag processing
-> Dynamic memory management
-> Modular programming
-> Command-line application development
-> Menu-driven application design
-> Debugging techniques
-> File structure analysis

---

# 🔮 Future Enhancements

-> GUI-based MP3 editor
-> Playlist management
-> Batch MP3 tag editing
-> Support for additional ID3 versions
-> Album art editing support

---

# 📝 Note

MP3 sample files are excluded from this repository to avoid copyright issues.

If required, feel free to contact me for a sample test file to run the project.

---

# 👨‍💻 Author

Mohammed Maaz

LinkedIn: [www.linkedin.com/in/mdm-mohammedmaaz](http://www.linkedin.com/in/mdm-mohammedmaaz)

---

# 📜 License

This project is developed for educational and learning purposes.
