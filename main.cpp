// ============================================================
//           CGPA CALCULATOR - CodeAlpha Project
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

// ------------------------------------------------------------
// Console colors
// ------------------------------------------------------------
const int CLR_DEFAULT = 7;
const int CLR_CYAN = 11;
const int CLR_GREEN = 10;
const int CLR_RED = 12;
const int CLR_YELLOW = 14;
const int CLR_WHITE = 15;

#include <windows.h>

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printLine(char symbol = '=', int width = 70)
{
	setColor(CLR_CYAN);

	for (int i = 0; i < width; i++)
	{
		cout << symbol;
	}

	cout << endl;
	setColor(CLR_DEFAULT);
}

void printTitle(string title)
{
	cout << endl;
	printLine('=');

	setColor(CLR_CYAN);
	cout << "                    " << title << endl;

	printLine('=');
}

// ------------------------------------------------------------
// Removes spaces from the beginning and end of input
// ------------------------------------------------------------
string trim(string text)
{
	int start = 0;
	int end = text.length() - 1;

	while (start < text.length() && text[start] == ' ')
	{
		start++;
	}

	while (end >= start && text[end] == ' ')
	{
		end--;
	}

	return text.substr(start, end - start + 1);
}

// ------------------------------------------------------------
// Converts grade to uppercase
// ------------------------------------------------------------
string makeUpperCase(string grade)
{
	for (int i = 0; i < grade.length(); i++)
	{
		if (grade[i] >= 'a' && grade[i] <= 'z')
		{
			grade[i] = grade[i] - 32;
		}
	}

	return grade;
}

// ------------------------------------------------------------
// Checks if grade is valid
// ------------------------------------------------------------
bool isValidGrade(string grade)
{
	if (grade == "A" || grade == "A-" ||
		grade == "B+" || grade == "B" || grade == "B-" ||
		grade == "C+" || grade == "C" || grade == "C-" ||
		grade == "D+" || grade == "D" || grade == "F" || grade == "W")
	{
		return true;
	}

	return false;
}

// ------------------------------------------------------------
// Converts grade into grade point
// ------------------------------------------------------------
double getGradePoint(string grade)
{
	if (grade == "A")
		return 4.0;
	else if (grade == "A-")
		return 3.7;
	else if (grade == "B+")
		return 3.3;
	else if (grade == "B")
		return 3.0;
	else if (grade == "B-")
		return 2.7;
	else if (grade == "C+")
		return 2.3;
	else if (grade == "C")
		return 2.0;
	else if (grade == "C-")
		return 1.7;
	else if (grade == "D+")
		return 1.3;
	else if (grade == "D")
		return 1.0;
	else
		return 0.0; // F And W
}

// ------------------------------------------------------------
// Reads a positive whole number with exception handling
// ------------------------------------------------------------
int readPositiveInteger(string message)
{
	string input;
	int number;

	while (true)
	{
		try
		{
			setColor(CLR_YELLOW);
			cout << message;
			setColor(CLR_WHITE);

			getline(cin, input);
			input = trim(input);

			number = stoi(input);

			if (number <= 0)
			{
				throw out_of_range("Number must be greater than zero.");
			}

			return number;
		}
		catch (exception& error)
		{
			setColor(CLR_RED);
			cout << "Error: Please enter a valid positive whole number.\n";
			setColor(CLR_DEFAULT);
		}
	}
}

// ------------------------------------------------------------
// Reads a decimal number within a specified range
// ------------------------------------------------------------
double readDouble(string message, double minimum, double maximum)
{
	string input;
	double number;

	while (true)
	{
		try
		{
			setColor(CLR_YELLOW);
			cout << message;
			setColor(CLR_WHITE);

			getline(cin, input);
			input = trim(input);

			number = stod(input);

			if (number < minimum || number > maximum)
			{
				throw out_of_range("Number is outside the allowed range.");
			}

			return number;
		}
		catch (exception& error)
		{
			setColor(CLR_RED);
			cout << "Error: Enter a value between "
				<< minimum << " and " << maximum << ".\n";
			setColor(CLR_DEFAULT);
		}
	}
}

int main()
{
	try
	{
		printTitle("CGPA CALCULATOR");

		int numberOfCourses = readPositiveInteger("Enter number of courses: ");

		string* courseNames = new string[numberOfCourses];
		string* grades = new string[numberOfCourses];
		double* creditHours = new double[numberOfCourses];
		double* gradePoints = new double[numberOfCourses];

		double totalCredits = 0;
		double totalGradePoints = 0;

		for (int i = 0; i < numberOfCourses; i++)
		{
			printLine('-');

			setColor(CLR_CYAN);
			cout << "Course " << i + 1 << " Details\n";

			while (true)
			{
				setColor(CLR_YELLOW);
				cout << "Enter course name: ";
				setColor(CLR_WHITE);

				getline(cin, courseNames[i]);
				courseNames[i] = trim(courseNames[i]);

				if (courseNames[i] != "")
				{
					break;
				}

				setColor(CLR_RED);
				cout << "Error: Course name cannot be empty.\n";
				setColor(CLR_DEFAULT);
			}

			while (true)
			{
				setColor(CLR_YELLOW);
				cout << "Enter grade (A, A-, B+, B, B-, C+, C, C-, D+, D, F, W ) : ";
				setColor(CLR_WHITE);

				getline(cin, grades[i]);

				grades[i] = makeUpperCase(trim(grades[i]));

				if (isValidGrade(grades[i]))
				{
					break;
				}

				setColor(CLR_RED);
				cout << "Error: Invalid grade. Please enter again.\n";
				setColor(CLR_DEFAULT);
			}

			creditHours[i] = readDouble(
				"Enter credit hours (1 to 6): ", 1, 6
			);

			gradePoints[i] = getGradePoint(grades[i]);

			totalCredits += creditHours[i];
			totalGradePoints += gradePoints[i] * creditHours[i];
		}

		double semesterGPA = totalGradePoints / totalCredits;

		printTitle("PREVIOUS ACADEMIC RECORD");

		double previousCGPA = readDouble(
			"Enter previous CGPA (0.00 to 4.00): ", 0, 4
		);

		double previousCredits = readDouble(
			"Enter previous completed credits: ", 0, 500
		);

		double overallCGPA;

		overallCGPA = ((previousCGPA * previousCredits) + totalGradePoints)
			/ (previousCredits + totalCredits);

		printTitle("FINAL CGPA REPORT");

		setColor(CLR_CYAN);
		cout << left
			<< setw(5) << "No."
			<< setw(30) << "Course Name"
			<< setw(10) << "Grade"
			<< setw(12) << "Credits"
			<< setw(15) << "Grade Point"
			<< endl;

		printLine('-');

		setColor(CLR_WHITE);

		for (int i = 0; i < numberOfCourses; i++)
		{
			cout << left
				<< setw(5) << i + 1
				<< setw(30) << courseNames[i]
				<< setw(10) << grades[i]
				<< setw(12) << fixed << setprecision(1) << creditHours[i]
				<< setw(15) << fixed << setprecision(2) << gradePoints[i]
				<< endl;
		}

		printLine('-');

		setColor(CLR_YELLOW);
		cout << "\nTotal Semester Credits: ";
		setColor(CLR_WHITE);
		cout << fixed << setprecision(1) << totalCredits << endl;

		setColor(CLR_YELLOW);
		cout << "Semester GPA: ";
		setColor(CLR_GREEN);
		cout << fixed << setprecision(2) << semesterGPA << endl;

		setColor(CLR_YELLOW);
		cout << "Overall CGPA: ";
		setColor(CLR_GREEN);
		cout << fixed << setprecision(2) << overallCGPA << endl;

		setColor(CLR_DEFAULT);
		printLine('=');

		delete[] courseNames;
		delete[] grades;
		delete[] creditHours;
		delete[] gradePoints;
	}
	catch (exception& error)
	{
		setColor(CLR_RED);
		cout << "\nUnexpected error occurred: " << error.what() << endl;
		setColor(CLR_DEFAULT);
	}

	return 0;
}