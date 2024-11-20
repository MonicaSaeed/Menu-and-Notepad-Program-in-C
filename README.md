# Menu and Notepad Program in C  

## Overview  
This project consists of two programs implemented in C:  

1. **Menu Program**:  
   - A menu-driven program to manage employees, allowing operations such as:  
     - Adding a new employee.  
     - Searching for an employee by index.  
     - Displaying all employees.  
   - Includes a text-based UI using `gotoxy` and `textattr` functions for navigation and highlighting.

2. **Notepad Program**:  
   - A simple text editor with basic features:  
     - Navigate text using arrow keys (Right, Left, Up, Down).  
     - Edit text with `Backspace`, `Delete`, and insertion.  
     - Save lines in dynamically allocated memory.  
   - Features support for multi-line editing within specified dimensions.  

---

## Key Features  

### Menu Program:  
- **Menu Navigation**: Navigate between options using arrow keys, `Home`, `End`, and `Enter`.  
- **Employee Management**:  
  - **Add New**: Input and save employee data.  
  - **Search**: Retrieve and display an employee’s details by index.  
  - **Display All**: View all stored employee records.  

### Notepad Program:  
- **Text Editing**:  
  - Insert characters at the current cursor position.  
  - Delete characters using `Backspace` or `Delete`.  
- **Cursor Movement**: Move cursor within lines or between lines.  
- **Memory Management**: Dynamic allocation for storing text lines, ensuring efficient memory use.  

---
