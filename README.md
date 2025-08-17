# Number_Conversion
Number System Conversion Mini Project

This is a C mini project that allows users to convert numbers between different number systems.
It also stores inputs and outputs in text files (Input.txt and Output.txt).

📌 Features

Convert Decimal → Binary

Convert Binary → Decimal

Convert Decimal → Octal

Convert Octal → Decimal

Convert Decimal → Hexadecimal

Convert Hexadecimal → Decimal

Input and Output stored in files for reference

🖥️ Technologies Used

Language: C

Header Files:

stdio.h

stdlib.h

string.h

math.h

conio.h

📂 File Handling

Input.txt → Stores the user inputs (decimal, binary, octal, hexadecimal numbers).

Output.txt → Stores the conversion results.

⚙️ How to Run

Clone or download this repository.

Compile the code:

gcc converter.c -o converter


Run the program:

./converter


Follow the on-screen menu to choose conversion options.

📑 Menu Options
1) Decimal to Binary  
2) Binary to Decimal  
3) Decimal to Octal  
4) Octal to Decimal  
5) Decimal to Hexadecimal  
6) Hexadecimal to Decimal  
7) Exit  

📸 Example Output
Enter Decimal number: 25  

RESULT  
----------------------  
Binary value is: 11001  
----------------------  


Input stored in Input.txt:

Decimal number : 25


Output stored in Output.txt:

Binary number : 11001

🚀 Future Enhancements

Add direct conversion between non-decimal systems (e.g., Binary ↔ Hexadecimal).

Create a graphical user interface (GUI) version.

Improve error handling for invalid inputs.
