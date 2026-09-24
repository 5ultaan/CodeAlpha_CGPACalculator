# 🎓 CGPA Calculator — CodeAlpha Internship

### C++ Programming Internship — Task 1

A **console-based CGPA Calculator** developed in **C++** as part of the **CodeAlpha C++ Programming Internship**. The application allows students to enter their courses, grades, and credit hours, calculates the semester GPA, and determines the overall CGPA using previous academic records.

---

## 📌 Project Overview

The **CGPA Calculator** is designed to provide a simple and reliable way for students to calculate their academic performance.

The program collects:

* Number of courses
* Course names
* Grades
* Credit hours
* Previous CGPA
* Previously completed credit hours

It then calculates:

* Total semester credits
* Grade points for each course
* Semester GPA
* Overall CGPA

The final result is presented in a structured academic report.

---

## 🎯 Internship Task

This project was completed as **Task 1: CGPA Calculator** for the **CodeAlpha C++ Programming Internship**.

### Task Requirements

The internship task required the application to:

* Take input for the number of courses taken by the student.
* Accept the grade and credit hours for each course.
* Calculate total credits and total grade points.
* Calculate the semester GPA.
* Calculate the overall CGPA.
* Display individual course grades and the final CGPA.

This implementation extends the basic requirements by also including course names, input validation, previous academic records, formatted output, and console color formatting.

---

## ✨ Features

### 📚 Course Management

* Enter the number of courses.
* Enter the name of each course.
* Enter the grade obtained in each course.
* Enter credit hours for each course.

### 📊 GPA & CGPA Calculation

* Calculates individual grade points.
* Calculates weighted grade points using credit hours.
* Calculates total semester credits.
* Calculates semester GPA.
* Calculates overall CGPA using previous CGPA and completed credits.

### ✅ Input Validation

The program validates user input to reduce incorrect entries.

Validation includes:

* Positive number of courses.
* Non-empty course names.
* Valid letter grades.
* Credit hours between **1 and 6**.
* Previous CGPA between **0.00 and 4.00**.
* Previous completed credits between **0 and 500**.
* Exception handling for invalid numeric input.

### 🎨 Console Interface

The application uses Windows console colors to make the interface easier to read.

Different colors are used for:

* Section headings
* User prompts
* Successful results
* Error messages
* Important information

### 📋 Final Academic Report

The final output displays a structured table containing:

| No. | Course Name    | Grade | Credits | Grade Point |
| --: | -------------- | ----- | ------: | ----------: |
|   1 | Course Example | A     |     3.0 |        4.00 |
|   2 | Course Example | B+    |     3.0 |        3.30 |

The report also displays:

* Total Semester Credits
* Semester GPA
* Overall CGPA

---

## 🧮 Grade Point System

The calculator uses the following grading scale:

| Grade | Grade Point |
| ----- | ----------: |
| A     |        4.00 |
| A-    |        3.70 |
| B+    |        3.30 |
| B     |        3.00 |
| B-    |        2.70 |
| C+    |        2.30 |
| C     |        2.00 |
| C-    |        1.70 |
| D+    |        1.30 |
| D     |        1.00 |
| F     |        0.00 |
| W     |        0.00 |

---

## 📐 Calculation Method

### Semester GPA

The semester GPA is calculated using weighted grade points:

```text
Semester GPA =
Total Grade Points / Total Credit Hours
```

Where:

```text
Grade Points = Grade Point × Credit Hours
```

For example:

```text
Course Grade Point = 3.30
Credit Hours = 3

Weighted Grade Points = 3.30 × 3
                       = 9.90
```

---

### Overall CGPA

When previous academic records are provided, the program calculates the overall CGPA using:

```text
Overall CGPA =
((Previous CGPA × Previous Credits) + Current Grade Points)
/
(Previous Credits + Current Credits)
```

This allows the current semester's performance to be combined with the student's previous academic record.

---

## 🛠️ Technologies Used

* **C++**
* **Object-Oriented / Procedural C++ Concepts**
* **Standard C++ Library**
* `iostream`
* `iomanip`
* `string`
* `stdexcept`
* `cctype`
* **Windows API**
* `windows.h`
* Dynamic memory allocation
* Exception handling

---

## 💻 C++ Concepts Demonstrated

This project demonstrates several fundamental C++ programming concepts:

### Variables & Data Types

Uses:

* `int`
* `double`
* `string`
* `bool`

### Functions

The program is divided into reusable functions such as:

```cpp
setColor()
printLine()
printTitle()
trim()
makeUpperCase()
isValidGrade()
getGradePoint()
readPositiveInteger()
readDouble()
```

### Arrays & Dynamic Memory

Dynamic arrays are used to store course information:

```cpp
string* courseNames;
string* grades;
double* creditHours;
double* gradePoints;
```

Memory is allocated dynamically based on the number of courses entered by the user.

### Exception Handling

The program uses:

```cpp
try
catch
throw
```

to handle invalid numeric input and prevent unexpected program termination.

### String Handling

The application processes user input using functions for:

* Removing unnecessary spaces
* Converting grades to uppercase
* Validating grade values

### Formatted Output

The final report uses:

```cpp
setw()
setprecision()
fixed
left
```

to create a clean and readable table.

---

## 🔄 Program Workflow

```text
             ┌──────────────────────┐
             │      Start Program   │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Enter Number of      │
             │ Courses              │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Enter Course Details │
             │                      │
             │ • Course Name        │
             │ • Grade              │
             │ • Credit Hours       │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Calculate Grade      │
             │ Points & Credits     │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Calculate Semester   │
             │ GPA                  │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Enter Previous CGPA  │
             │ & Completed Credits  │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Calculate Overall    │
             │ CGPA                 │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │ Display Final Report │
             └──────────┬───────────┘
                        │
                        ▼
             ┌──────────────────────┐
             │        End           │
             └──────────────────────┘
```

---

## 🖥️ Sample Output

```text
======================================================================
                         CGPA CALCULATOR
======================================================================

Enter number of courses: 5

----------------------------------------------------------------------
Course 1 Details

Enter course name: Programming Fundamentals
Enter grade (A, A-, B+, B, B-, C+, C, C-, D+, D, F, W): A
Enter credit hours (1 to 6): 3

----------------------------------------------------------------------
Course 2 Details

Enter course name: Discrete Structures
Enter grade: A-
Enter credit hours (1 to 6): 3
```

After entering all courses:

```text
======================================================================
                       FINAL CGPA REPORT
======================================================================

No.  Course Name                   Grade     Credits     Grade Point
----------------------------------------------------------------------
1    Programming Fundamentals     A         3.0         4.00
2    Discrete Structures          A-        3.0         3.70
3    Database Systems             B+        3.0         3.30
4    English                      A         3.0         4.00
5    Mathematics                  B+        3.0         3.30
----------------------------------------------------------------------

Total Semester Credits: 15.0
Semester GPA: 3.66
Overall CGPA: 3.58
======================================================================
```

> **Note:** The sample values above are for demonstration purposes.

---

## 🛡️ Input Validation & Error Handling

The application includes validation to handle common input errors.

### Invalid Number of Courses

```text
Enter number of courses: -2

Error: Please enter a valid positive whole number.
```

### Invalid Grade

```text
Enter grade: X

Error: Invalid grade. Please enter again.
```

### Invalid Credit Hours

```text
Enter credit hours (1 to 6): 8

Error: Enter a value between 1 and 6.
```

### Empty Course Name

```text
Enter course name:

Error: Course name cannot be empty.
```

These checks help make the program more reliable and user-friendly.

---

## 🗂️ Project Structure

```text
CodeAlpha_CGPACalculator/
│── 1. Screenshot.jpg
│── 2. Screenshot.jpg
├── 3. Screenshot.jpg
│── README.md
└── main.cpp
```

The main implementation is contained in `main.cpp`.

---

## ⚙️ Requirements

To compile and run this project, you need:

* Windows operating system
* C++ compiler
* Visual Studio or another compatible C++ IDE/compiler
* Support for Windows API through `windows.h`

The program uses Windows console functionality for colored output, so it is designed primarily for a **Windows environment**.

---

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/CodeAlpha_CGPACalculator.git
```

### 2. Open the Project

Open `main.cpp` in:

* Visual Studio
* Code::Blocks
* Another compatible C++ development environment

### 3. Compile the Program

Compile `main.cpp` using a C++ compiler.

### 4. Run

Execute the generated program and follow the instructions displayed in the console.

---

## 📌 Project Highlights

This project focuses on practical implementation of fundamental C++ programming concepts through a real-world academic use case.

### Key Learning Areas

* C++ syntax and programming fundamentals
* Functions and modular programming
* Dynamic memory allocation
* Arrays
* String manipulation
* Input validation
* Exception handling
* Mathematical calculations
* Formatted console output
* Windows console API
* User-friendly command-line interfaces

---

## 🔮 Future Improvements

Possible improvements for future versions include:

* Saving student records to files.
* Supporting multiple students.
* Adding a student profile system.
* Adding semester-by-semester academic records.
* Generating a printable CGPA report.
* Adding a graphical user interface.
* Supporting customizable grading scales.
* Replacing manual dynamic arrays with modern C++ containers such as `vector`.

---

## 🎓 Internship Information

**Internship:** C++ Programming Internship
**Organization:** CodeAlpha
**Task:** Task 1 — CGPA Calculator

This project was developed as part of the practical programming tasks assigned during the CodeAlpha C++ Programming Internship.

The internship focuses on developing practical programming skills through hands-on C++ projects, with emphasis on programming fundamentals, algorithms, software development, memory management, object-oriented programming, and debugging.

---

## 👨‍💻 Author

**Sultan Shahzad Awan**

BS Artificial Intelligence Student
University of Central Punjab

### Profiles

* **LinkedIn:** [(http://www.linkedin.com/in/sultanshahzadawan)]
* **GitHub:** [(https://github.com/5ultaan)]

---

## ⭐ Acknowledgment

Thanks to **CodeAlpha** for providing the internship opportunity and practical project-based learning experience in C++ programming.

---

### 📌 Repository

**Repository Name:** `CodeAlpha_CGPACalculator`

**Project:** CGPA Calculator
**Language:** C++
**Internship:** CodeAlpha C++ Programming Internship
**Task:** 1
