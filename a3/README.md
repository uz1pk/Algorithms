# Usman Zaheer CIS 3490

## Compilation
- Open terminal in the a3 folder directory

- If a bin directory is not already present, create a bin directory

- Type make

- Type ./a3 to run the program. Hope you like it !

## After running ./a3
- P11/P12: Will prompt for file name from the user. You must type the name of the
    file and the file should be in the same directory as the program. Any errors in finding/opening
    the file will exact the program. If a valid file is collected two algorithms will run.

- P21/P22/P23: These three programs will prompt the user for a patten string. From there 
    all three programs will execute and print the given information about the # of shifts.
    The time it took to execute and of course the number of contained strings within the data file
    which was given with the assginment. (data_A3_Q2.txt).
    - Because of the way I implemented handling of the new line. When you enter the 
        given pattern you must press enter to get the program to run properly.
        This means you cannot use an autograder which does not put new line at the end
        pattern as this will result in error. The algorithms themselves work fine. 
        I just accounted for new lines at the end of the lines by completely disregarding
        the last character.

## Algorithms implemented:
- P11, Brute Force
- P12, Pre-Sorting using merge sort, then Brute Force.
- P21, Brute Force
- P22, Horspool algorithm (shift table)
- P23, Boyer Moore algorithm (bad shift table and good shift table)

## Data Files Configurations
- To run the program the data files should both be in the same directory as the executable/C files.
    - For P11 and P12 the program will ask for a file name input that will be used by both.
        The file name should be inputted as the following, "filename.txt".

- I have hard coded the names of the data file for P21 - P23. The file name to be used in the program is "data_A3_Q2.txt".

- The data in both files must be in the same ordered set as the pre defined data files
    - data_A3_Q2.txt each line must not be over 1000 characters. The file itself can contain as many
        lines as you would like.
    - If you would like to use a different file/filename, simply change the text
        in the fopen call on line 56 of main.c to any file name you would like. As long as it follows
        the format.

## Limitations
- P11 and P12 both assumes all intervals are positive integers
    as well assumes the first index pair in each interval is smaller

- P21 to P23 all assume that each line of the inputted test file is maximum 1000 characters long. 
    Since we are using the file given to us it does not matter, however it is a good thing to keep in mind.
    The file itself can be as long as the user wants it.

## Analysis of Brute Force Search and Horspool Algorithm:

The ratio used for Performance analysis of the string searches
going to be calcualted as follows.
    Performance Ratio = (total shifts) / (Execution Time (ms))
    This will give us the shifts per ms ratio. This will be 
    rounded to the nearst whole number.

Search Patterns & Results:
1. __information__
    - Horspool:
      - Shifts: 391 103 
      - Execution Time: 8 ms
      - Performance Ratio: 48 888
    - Brute Force:
        - Shifts: 3 296 425 
        - Execution Time: 22 ms
        - Performance Ratio: 149 848

2. __above__
    - Horspool: 
        - Shifts: 699 228
        - Execution Time: 13 ms
        - Performance Ratio: 53 787
    - Brute Force:
        - Shifts: 3 296 512 
        - Execution Time: 21 ms
        - Performance Ratio: 156 977

3. __test__
    - Horspool: 
        - Shifts: 920 545 
        - Execution Time: 14 ms
        - Performance Ratio: 65 753
    - Brute Force:
        - Shifts: 3 296 350 
        - Execution Time: 21 ms
        - Performance Ratio: 156 969

4. __The__
        - Horspool: 
            Shifts: 1 118 574
            Execution Time: 17 ms
            Performance Ratio: 65 798
        - Brute Force:
            Shifts: 3 296 383 
            Execution Time: 17 ms
            Performance Ratio: 193 905
5. __rules__
    - Horspool: 
        - Shifts: 737 952
        - Execution Time: 13 ms
        - Performance Ratio: 56 766
    - Brute Force:
        - Shifts: 3 296 590 
        - Execution Time: 20 ms
        - Performance Ratio: 164 830
    
6. __of__
    - Horspool: 
        - Shifts: 1 691 160
        - Execution Time: 13 ms
        - Performance Ratio: 130 089
    - Brute Force:
        - Shifts: 3 272 832 
        - Execution Time: 21 ms
        - Performance Ratio: 155 849

7. __in any degree program with an unexpected financialemergency. Amount: Several__
    - Horspool: 
        - Shifts: 141 191
        - Execution Time: 3 ms
        - Performance Ratio: 47 063
    - Brute Force:
        - Shifts: 3 296 529 
        - Execution Time: 23 ms
        - Performance Ratio: 143 327

8. __Gray, O.A.C. '51, a Guelph football lineman and agreat player of the game.__
    - Horspool: 
        - Shifts: 128 073 
        - Execution Time: 2 ms
        - Performance Ratio: 64 037
    - Brute Force:
        - Shifts: 3 296 532 
        - Execution Time: 17 ms
        - Performance Ratio: 193 914

9. __LandscapeArchitecture__
    - Horspool: 
        - Shifts: 235 070
        - Execution Time: 4 ms
        - Performance Ratio: 58 768
    - Brute Force:
        - Shifts: 3 296 583
        - Execution Time: 16 ms
        - Performance Ratio: 206 036

10.  __in__
     - Horspool: 
        - Shifts: 1 693 078
        - Execution Time: 23 ms
        - Performance Ratio: 73 612
    - Brute Force:
        - Shifts: 3 255 910
        - Execution Time: 22 ms
        - Performance Ratio: 147 996

    Final Performance Results:
    - Horspool Average Performance Ratio:
            66456 shifts per ms
        
    - Brute Force Average Performance Ratio:
            166965 shifts per ms
