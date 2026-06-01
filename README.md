# Add2Num
A C++ implementation for adding two large numbers represented as strings. This project simulates the column-addition algorithm taught in primary school, handles arbitrarily large intergers.
## Project Structure
```text
.
├── build/                # Excecute and binary files
│   └── main
├── include/
│   ├── Config.h          # Global configuration macros
│   └── MyBigNumber.h     # Class and method declarations
├── src/
│   ├── main.cpp          # Demo entry point for manual inspection
│   └── MyBigNumber.cpp   # Core column-addition logic & logging
├── tests/
│   └── test_main.cpp     # Modularized manual Unit Test cases
├── Makefile              # Automated build system pipeline
└── README.md             # Documentation
```

## Prerequisites
Please ensure you have a C++ toolchain installed on your environment (Linux or macOS preferred):
- ```g++``` compiler supporting C++11 standard or higher.
- ```make``` utility for build automation.

## User Guide
1. **View Help Menu**: To display all available automation targets, run:

```bash
make
```

or 
```bash
make help
```

2. **Compile and Run the Main file**
```bash
make run
```

3. **Run Unit Tests**
```bash
make test
```

4. **Clean Workspace**: Delete the ```build/``` directory and remove all temporary binary files.
```bash
make clean
```

## Configuration (LOGGING Toggle)
You can manage the logging behavior by modifying the file [include/Config.h](include/Config.h):
- To enable Logging feature: Keep the macro defined.

```C++
#define LOGGING
```

- To disable Logging feature: Comment out or remove the macro definition.
```C++
// define LOGGING
```
