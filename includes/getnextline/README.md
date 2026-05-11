This project has been created as part of the 42 curriculum by ediba-de

# Get_next_line

## Description
This project is about building a program that handles reading a file one line at a time from it's FIle Descriptor.

It furnishes a function get_next_line, which takes the file descriptor of the file you want to read and return the file content one line at a time, printing the next time at each call from the first to the last one

#### Step-by-Step Algorithm

* ###### Persistent Storage with `static stash`
The function uses a static char *stash variable to retain the text read from `read()` function to buffer.
This is essential because read() may retrieve more data than needed for a single line. Without this mechanism, characters after the newline would be lost.

* ###### Step 1: Reading Data (set_stash)

The set_stash function reads from the file descriptor and appends the read content to the stash until either a newline (\n) is encountered, or the end of the file is reached.

* ###### Step 2: Extracting the Line (_get_line)
Once enough data is stored in stash, the _get_line function extracts the next complete line from the stash

* ###### Step 3: Updating the Stash (update_stash)
After extracting the line, the leftover part of the stash must be preserved for the next function call.

* ###### Memory Management Strategy
Memory allocation and deallocation are handled carefully throughout the implementation:
Temporary buffers are freed immediately after use.
The stash is freed when no longer needed.
Each returned line is dynamically allocated and must be freed by the caller.
This prevents memory leaks and ensures safe memory usage.

* ###### Justification of the Approach
This design was chosen because it satisfies several critical requirements of the project:

1. Handles arbitrary line lengths independent of BUFFER_SIZE.
2. Minimizes system calls by stopping reads once a newline is found.
3. Preserves leftover data between function calls using a static buffer.
4. Modular structure improves readability and maintainability.

Separating the logic into set_stash, _get_line, and update_stash also improves code clarity and simplifies debugging, as each function has a well-defined responsibility.

## Instructions

##### *Compilation, installation and execution*

to compile the project you can run the following commands from it's root folder:

``` cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c```

with ```main.c``` being your program where you include get_next_line.h and call the get_next_line function.

## Resources

* Static variables:
https://en.wikipedia.org/wiki/Static_variable
https://www.geeksforgeeks.org/c/static-variables-in-c/

* Read function:
https://www.w3schools.com/c/c_files_read.php

Referenced also the LIBFT Project for some functions: gnl_strjoin, ft_strlen, ft_strdup, ft_strchr

And used ChatGPT as help to write this README file, review code and track some bugs like memory leaks for example