# Usman Zaheer CIS 3490

## Compilation and Execution:
- Open terminal in the UsmanA4 folder directory (should be automatically created when extracting the tar)

- If a bin directory is not already present create a bin directory

- Type make
     - For individual question executables you can write "make pXX" for example "make p11" or "make p2" as you can see for individual executables it all all based on the file name

- Drag and drop the data files into the UsmanA4 directory. 
    - Make sure that for p11/p12 the file name is "data_A4_Q1.txt"

- Type ./pXX to run whichever question example "./p11" or "./p2". Hope you like it!

## After running ./p11 or ./p12:
- Will prompt for a key value from the user. You may type any key/string

## After running ./p2:
- Will prompt for a file name from the user. The file name must be the exact name of the
        file, including the .txt extension. For example "XXXXXXXXX.txt"

## Algorithms implemented:
- P11, Creating an Optimal Binary Search Tree using Dynamic Programming
- P12, Creating an Optimal Binary Search Tree using a Greedy Technique
- P2,  Gale-Shapley Stable Marriage Algorithm

## Data File Configurations:
- To run the program the data files should both be in the a4 directory

- I have hard coded the names of the data file for P11 - P12. The file name to be used in the program is "data_A4_Q1.txt"

- The data in the files being used in p2 must be in the same ordered set as the given file.
    - This means that the first character should be an integer representing the size of the NxN matrix
    - The data within the NxN matrix must be seperated by some sort white space and should follow the 
        NxN dimension property given by the first integer
     - All numbers should be interger numbers

## Limitations:
- P11 and P12 both assume that no word will be greater than 250 characters

- P2 simply assumes the data file follows the data guidlines set in the Data File Configurations Section
