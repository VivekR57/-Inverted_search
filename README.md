# 🔍 Inverted Index Database System

The **Inverted Index Database System** is a **C-based** application designed to efficiently index and search words across multiple **text files**. It creates an **inverted index** where each word maps to the files containing it and the frequency of its occurrence, significantly improving search efficiency. The project employs **data structures** such as **hash tables** and **linked lists**, showcasing concepts in **file processing** and **memory management**.

---

## 🛠 Project Features

- **Hash Table Implementation:** 27-bucket hash table for fast lookups, including non-alphabetic characters.
- **File Validation:** Ensures input files are **.txt** format, **existing**, and **non-empty**.
- **Dynamic Memory Management:** Uses **dynamic allocation** for linked lists of **files** and **word occurrences**.
- **Word Indexing:** Maps each word to its **source files** and **occurrence counts**.
- **Efficient Search:** Achieves **O(1)** average-case performance with **hash-based lookups**.
- **Database Persistence:** Allows **saving** and **loading** the **inverted index** to/from a file.
- **Interactive Interface:** Menu-driven for operations like **create**, **display**, **search**, **save**, and **update**.

---

## 🧰 Technology Stack

- **Programming Language:** C
- **Data Structures:** Hash Table, Doubly Linked List
- **File I/O:** Persistent **inverted index** storage and retrieval
- **Memory Management:** Dynamic allocation and deallocation
- **Error Handling:** Comprehensive **file validation** and **input checking**

---

## 🔄 Project Workflow

1. **Initialization:** Validates **command-line arguments** and **input files**.
2. **Database Creation:** Reads files, processes words, and constructs the **inverted index**.
3. **User Operations:** Supports **search**, **display**, **save**, and **update** functions.
4. **Memory Management:** Ensures proper **allocation** and **deallocation** to prevent **memory leaks**.

---

## 📂 File Structure

- `main.c` - **Core application logic**, manages the **menu-driven interface**.
- `hash_table.c` - Implements the **hash table** and **indexing functions**.
- `file_reader.c` - Validates and reads **text files**.
- `index_builder.c` - Constructs the **inverted index** from **file data**.
- `search.c` - Provides **search functionality** using **hash-based lookups**.
- `persistence.c` - Manages **saving** and **loading** the **index database**.
- `memory_manager.c` - Handles **dynamic memory** operations to avoid **leaks**.
- `utils.c` - Contains **utility functions** for **error handling** and **input validation**.

---

## 🚀 Future Enhancements

- **Performance Improvements:** Dynamic **hash table resizing**, **multi-threading**, and **memory optimization**.
- **Advanced Search:** Implement **wildcard**, **fuzzy**, **Boolean**, and **phrase searches**.
- **Extended File Support:** Add support for **PDFs**, **HTML**, **Word documents**, and **structured data**.
- **GUI Development:** Create a **graphical interface** and add **command history** and **search result highlighting**.
- **System Integration:** Develop a **web API** for **remote access** and **database connectivity**.

---

## 📧 Contact

For any questions, feel free to reach out:

- **Vivek**
- Email: [gopivivek57@gmail.com](mailto:gopivivek57@gmail.com)
- LinkedIn: [Vivek](https://www.linkedin.com/in/vivek57/)

