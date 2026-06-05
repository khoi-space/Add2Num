# Add2Num
A C++ implementation for adding two large numbers represented as strings. This project simulates the column-addition algorithm taught in primary school, handles arbitrarily large intergers.
## Project Structure
```text
.
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

4. **Run Coverage Test**
```bash
make coverage
```

_Notes_: A folder named "coverage_report" will be generated. Open the file index.html inside to see the detailed coverage report.

5. **Clean Workspace**: Delete the ```build/``` directory and remove all temporary files.
```bash
make clean
```

## Configuration
See file: [include/Config.h](include/Config.h)  
To disable the feature: Comment out or remove the macro definition.

### Manage the logging behavior
```C++
#define LOGGING
```

### Enable stress test when testing units
```C++
#define STRESS_TEST
```
