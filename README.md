# Smart_Home_Design_System
A C++-based object-oriented programming (OOP) project that simulates a smart home environment. The system enables users to control and manage devices like lights, fans, and security systems through a simple interface. It demonstrates OOP principles such as encapsulation, inheritance, and polymorphism.

This project was developed during my second semester as part of an Object-Oriented Programming (OOP) course.

# How to Use
Main Files

System.cpp is the main file that drives the program.
Accounts.cpp is a supplementary file for managing user account creation. It does not function independently.

# Audio Files

.wav files are included for sound effects and are compatible with Dev-C++. Compatibility with other IDEs, such as Visual Studio, is not guaranteed.
Setup Instructions

Download System.cpp, Accounts.cpp, and the .wav files to your system.
Ensure the .wav files are placed in a directory of your choice and update the file paths in the code. 
For example:
PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"), NULL, SND_FILENAME | SND_SYNC);
Replace the file path with the location of the .wav file on your system. Placing them in the Downloads folder will minimize changes.
Configuring Sound in Dev-C++

To enable sound functionality in Dev-C++, follow these steps:
Go to Tools > Compiler Options.
Add -lwinmm to the linker commands.

# Support
If you encounter any issues or need assistance, feel free to contact me. I’ll be happy to help resolve any problems.
