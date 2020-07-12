# MIMIC the LINUX 'grep' command with C language

### grep command in Unix/Linux ###
The grep command searches a file(s) for a particular pattern of characters, and displays all lines that contain that pattern(regular expression) in the given file(S) input.

### Syntax: ###
grep [options] pattern [files]

### Some options: ###
-c : This prints only a count of the lines that match a pattern
-i : Ignores, case for matching
-l : Displays list of a filenames only
-h : Display the matched lines, but do not display the filenames

This code handles -i, -c options.
Some example textfiles to run the code are provided in the repo. Refer to Output_Screenshot image for more help.

Compile and run the makefile. Execute the grep command as you would normally in the command prompt for windows.