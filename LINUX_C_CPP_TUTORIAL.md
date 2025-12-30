# Linux C/C++ Programming Guide (Ubuntu)

This is a long-form, practical guide for writing, compiling, and running C and C++ programs on Ubuntu. It assumes you are working in a terminal and using the system tools that come with a typical Ubuntu install.

## 0) The core idea

Your workflow is always the same:

1. Write code in a text file.
2. Compile it into an executable.
3. Run the executable.
4. Fix errors and repeat.

Everything below is just variations on those steps.

---

## 1) Terminal basics you will use every day

### Navigate the filesystem

```bash
pwd            # show current directory
ls             # list files
ls -l          # list files with details
cd foldername  # change directory
cd ..          # go up one directory
```

### Create and manage files

```bash
touch hello.cpp          # create an empty file
mkdir projects           # create a folder
mv hello.cpp src/        # move a file
cp hello.cpp backup.cpp  # copy a file
rm backup.cpp            # delete a file
```

### View file contents

```bash
cat hello.cpp      # print the file
less hello.cpp     # scroll through the file
head -n 20 file    # first 20 lines
tail -n 20 file    # last 20 lines
```

### Running programs

```bash
./a.out            # run the program in the current folder
./program_name     # run an executable named program_name
```

Note: `./` matters because the shell does not search the current folder by default.

---

## 2) Editors: nano, emacs, vim

Use any editor you like, but these are always available on Ubuntu and are useful in a terminal.

### Nano (simple and friendly)

Open a file:

```bash
nano hello.cpp
```

Useful keys (shown at the bottom in nano):
- `Ctrl+O` : save (write) the file
- `Ctrl+X` : exit
- `Ctrl+K` : cut a line
- `Ctrl+U` : paste a line
- `Ctrl+W` : search

### Emacs (powerful, classic)

Open a file:

```bash
emacs hello.cpp
```

If you are new to emacs, the built-in tutorial is worth it:

```bash
emacs
then press Ctrl+H and then T
```

Useful keys:
- `Ctrl+X Ctrl+S` : save
- `Ctrl+X Ctrl+C` : exit
- `Ctrl+K` : cut line
- `Ctrl+Y` : paste
- `Ctrl+S` : search forward

### Vim (fast once you learn modes)

Open a file:

```bash
vim hello.cpp
```

Vim has *modes*:
- **Normal mode**: navigation and commands
- **Insert mode**: typing text

Common steps:
- Press `i` to enter Insert mode
- Type your code
- Press `Esc` to return to Normal mode
- Type `:w` to save
- Type `:q` to quit
- Type `:wq` to save and quit

Useful commands:
- `dd` : delete a line
- `yy` : copy a line
- `p`  : paste
- `/text` : search for "text"

---

## 3) Install the compiler toolchain

If you are missing compilers, install them once:

```bash
sudo apt update
sudo apt install build-essential
```

This installs `gcc`, `g++`, `make`, and common development tools.

---

## 4) Your first C program

Create `hello.c`:

```c
#include <stdio.h>

int main(void){
    printf("Hello, C!\n");
    return 0;
}
```

Compile and run:

```bash
gcc -Wall -Wextra -std=c11 hello.c -o hello
./hello
```

Flags explained:
- `-Wall -Wextra` : show more warnings (good!)
- `-std=c11` : use the C11 standard
- `-o hello` : name the output executable

---

## 5) Your first C++ program

Create `hello.cpp`:

```cpp
#include <iostream>
using namespace std;

int main(){
    cout << "Hello, C++!" << endl;
    return 0;
}
```

Compile and run:

```bash
g++ -Wall -Wextra -std=c++17 hello.cpp -o hello
./hello
```

Flags explained:
- `-std=c++17` is a common modern default for C++.

---

## 6) Multiple files

When your project has more than one file, compile them together.

Example:

`main.cpp`
```cpp
#include <iostream>
using namespace std;

int add(int a, int b);

int main(){
    cout << add(2, 3) << endl;
    return 0;
}
```

`math.cpp`
```cpp
int add(int a, int b){
    return a + b;
}
```

Compile both:

```bash
g++ -Wall -Wextra -std=c++17 main.cpp math.cpp -o app
./app
```

---

## 7) Basic Makefile (optional but useful)

Create a file named `Makefile`:

```make
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

app: main.cpp math.cpp
	$(CXX) $(CXXFLAGS) main.cpp math.cpp -o app

clean:
	rm -f app
```

Then:

```bash
make
./app
make clean
```

Note: The lines under targets must start with a tab.

---

## 8) Common errors and what they mean

- **"No such file or directory"**: you are in the wrong folder or typed the name wrong.
- **"undefined reference"**: you forgot to compile/link another file.
- **"permission denied" when running**: use `./` and make sure it is compiled.
- **Warnings**: read them. Many bugs show up as warnings before they become errors.

---

## 9) Useful compiler flags

For C++:

```bash
g++ -Wall -Wextra -Wpedantic -std=c++17 file.cpp -o app
```

For C:

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 file.c -o app
```

If you want debugging info (for `gdb`):

```bash
g++ -g -Wall -Wextra -std=c++17 file.cpp -o app
```

---

## 10) Basic `gdb` debugging (optional)

Compile with `-g`:

```bash
g++ -g -Wall -Wextra -std=c++17 main.cpp -o app
```

Then:

```bash
gdb ./app
```

Useful commands inside gdb:
- `run` : start the program
- `bt` : backtrace (stack)
- `break main` : set a breakpoint
- `next` : step to next line
- `print x` : print a variable
- `quit` : exit gdb

---

## 11) File organization (recommended)

A simple layout:

```
project/
  src/
    main.cpp
    math.cpp
  include/
    math.h
  Makefile
```

This keeps your code tidy as projects grow.

---

## 12) If you get stuck

- Re-read the error message. It usually tells you the line number.
- Check your file names and folder.
- Compile one file at a time to isolate errors.
- Ask for help with the exact error and the line of code.

---

## Quick command reference

```bash
# compile C
 gcc -Wall -Wextra -std=c11 file.c -o app

# compile C++
 g++ -Wall -Wextra -std=c++17 file.cpp -o app

# run
 ./app

# edit (pick one)
 nano file.cpp
 emacs file.cpp
 vim file.cpp
```
