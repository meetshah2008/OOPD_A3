# Railway Program

*Name*: Shah Meetkumar Yagneshkumar
*Roll-No*: MT24136

This project simulates a railway system using C++. It contains a shared library (libstation.so) and an executable program (railway). The program uses a two-step process for building: First, compile the shared library, and then link the main program with this library to generate the executable.

## Files in the Project

- *StationLibrary.h*: Header file that defines the Station, Line, and Platform classes, along with their functions.
- *StationLibrary.cpp*: Source file implementing the logic of the classes and their functions from StationLibrary.h.
- *main.cpp*: The main program file that simulates the railway system and interacts with the shared library.
- *Makefile1*: Contains the commands to build the shared library (libstation.so).
- *Makefile2*: Contains the commands to compile main.cpp, link it with the shared library, and create the executable (railway).
- *railway*: The executable generated after compilation.
- *libstation.so*: The shared library containing the code for the railway system.

## Building the Project

Follow these steps to build and run the project:

### Step 1: Build the Shared Library

First, you need to compile the shared library libstation.so. To do this, run the following command in the terminal:

```bash
make -f makefile1 lib 
```

### Step 2: Build the executable
Secondly, compile and link the main.cpp file with shared library to generate the executable program, run following command in the terminal:

```bash
make -f makefile2 test
```

### citation
chatgpt
