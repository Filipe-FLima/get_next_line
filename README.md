# **Get Next Line**
## Description
The Get Next Line project aims to create a function that reads a line from a file descriptor in an efficient and dynamic way. 
This project includes a mandatory part and a bonus part. The main function, get_next_line, allows reading from files or standard input, returning one line at a time.

## Mandatory Part
In the mandatory part of the project, the get_next_line function must be able to read a line from a file or any other file descriptor.
It should handle multiple calls, returning one line with each call until there’s nothing left to read. The function should behave consistently whether reading from files or from standard input.

## Requirements:
**Function get_next_line:**

Prototype: char *get_next_line(int fd);

The function should read a line from the file descriptor given by fd.
It should return the line read, including the newline character \n if present, except when reaching the end of the file without a newline.
If there is nothing left to read or if an error occurs, the function should return NULL.
The function should be called repeatedly to read subsequent lines from a file or standard input.
It must be implemented efficiently, reading the file in small chunks and returning the line as soon as possible.

**Mandatory Files:**
get_next_line.c
get_next_line_utils.c
get_next_line.h

**External Functions:**
read()
malloc()
free()

**Behavior:**
The function should be efficient, minimizing the number of reads performed.
It must work correctly for both files and standard input (stdin).
The code should be compiled with the -D BUFFER_SIZE=n flag to set the buffer size used by read().
The function should handle various buffer sizes, such as 1, 42, 9999, or even very large values.
Use of global variables, libft, or the lseek() function is not allowed.

## Bonus Part
In the bonus part, you’ll be challenged to further optimize the get_next_line function and add extra features.

**Bonus Requirements:**

Single Static Variable:
Implement the get_next_line function using only one static variable to control the state between consecutive calls.

Multiple File Descriptors:
The get_next_line function must be able to manage multiple file descriptors simultaneously. For example, you should be able to call get_next_line for different descriptors (e.g., 3, 4, and 5) without losing the reading state of each descriptor.

Bonus Files:
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c

## Compilation
To compile the project, use the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
---

For the bonus part, use files with the _bonus suffix:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
---

## Testing the Project
This project includes a test main function that allows you to test get_next_line in various scenarios:

**File Reading**
**Standard Input (Terminal)**
**Bonus - Multiple File Descriptors**

Simply compile the code along with get_next_line.c, get_next_line_utils.c, and, if testing the bonus, the bonus files. This setup enables you to validate both the mandatory and bonus functionality of get_next_line.
