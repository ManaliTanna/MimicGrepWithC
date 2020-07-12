# MIMIC the LINUX grep command with C language

### grep command in Unix/Linux ###
The grep command searches a file(s) for a particular pattern of characters, and displays all lines that contain that pattern(regular expression) in the given file(S) input.

Syntax:
grep [options] pattern [files]

Some options:
-c : This prints only a count of the lines that match a pattern
-h : Display the matched lines, but do not display the filenames
-i : Ignores, case for matching
-l : Displays list of a filenames only

This code handles -i, -c options.
Compile and run the makefile. Execute the grep command as you would normally in the command prompt for windows.