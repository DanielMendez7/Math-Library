# Math Library

# Introduction
My name is Daniel Mendez, and I wrote all the code in this repository by myself. I wrote approximately 1400 lines of C++ source code. The repository currently only contains a package to manipulate Pauli matrices, but will be updated to contain more math libraries.

These three files contain the source code to manipulate pauli matrices:
1. Pauli_Matrix_Library.cc  
    - Contains all function and constructor definitions
2. Pauli_Matrix_Library.h 
    - Contains all function, constructor, and class specifications.
3. Test_PM_Library.cc
    - Contains Nine automated test cases to test functionality of my functions. Each test case has input parameters so that you may scale the test to your liking.



# Automated Tests
Here I will show 1 example for each of my nine test cases. However, please do not limit yourself to these specific test cases. You can modify the input parameters for each test case as you like in `Test_PM_Library.cc` 

Compilation command is: `g++  -g  -std=gnu++11  -Wall  -Werror  Test_PM_Library.cc  Pauli_Matrix_Library.cc -o  Test_PM_Library`

Run Command: `./Test_PM_Library`

**TEST 1: Create a Hermitian Matrix, then test if it is Hermitian.**

**Driver Code**

![alt text](Images/Test1_Code.png) 


**Terminal Output**

![alt text](Images/Test1_Terminal_Part1.png) 
![alt text](Images/Test1_Terminal_Part2.png)



**TEST 2: Decompose a 2 x 2 Hermitian Matrix into Pauli Matrices**

**Driver Code**

![alt text](Images/Test2_Code.png) 


**Terminal Output**

![alt text](Images/Test2_Terminal.png) 



**TEST 3: Multiply pauli matrix by a phase:**

**Driver Code**

![alt text](Images/Test3_Code.png) 

**Terminal Output**

![alt text](Images/Test3_Terminal_Part1.png) 

![alt text](Images/Test3_Terminal_Part2.png)


**TEST 4: P^2 = I, where P is a pauli matrix:**

**Driver Code**

![alt text](Images/Test4_Code.png) 


**Terminal Output**

![alt text](Images/Test4_Terminal.png) 


**TEST 5: One Test of Pauli Matrix Multiplication:**

**Driver Code**

![alt text](Images/Test5_Code.png) 


**Terminal Output**

![alt text](Images/Test5_Terminal.png) 


**TEST 6: Sixteen Tests of Pauli Matrix Multiplication**

**Driver Code**

![alt text](Images/Test6_Code.png) 


**Terminal Output**

![alt text](Images/Test6_Terminal_Part1.png)
![alt text](Images/Test6_Terminal_Part2.png)
![alt text](Images/Test6_Terminal_Part3.png)
![alt text](Images/Test6_Terminal_Part4.png)
![alt text](Images/Test6_Terminal_Part5.png)
![alt text](Images/Test6_Terminal_Part6.png) 


## Pauli Algebra Tests

**TEST 7: Tensor Product from Pauli String and Pauli Scalar Multiplication:**

**Driver Code**

![alt text](Images/Test7_Code.png) 


**Terminal Output**

![alt text](Images/Test7_Terminal.png) 

**TEST 8: Pauli Algebra Element Addition.**

**Driver Code**

![alt text](Images/Test8_Code.png) 


**Terminal Output**

![alt text](Images/Test8_Terminal.png) 

**TEST 9: Pauli Algebra Element Multiplication.**

**Driver Code**

![alt text](Images/Test9_Code.png) 


**Terminal Output**

![alt text](Images/Test9_Terminal.png) 



### Future Work: Improvements To Make
1. Add more math library functionality beyond just Pauli matrices.

2. I am using the complex class from C++ Standard Library to represent complex numbers. The biggest drawback to this is that it only allows for float, double, long double types. These data types take up too much space for a small project like this which does not require a high amount of decimal precision. It may have been better to go a different route to use up less memory.

3. Use an established Matrix class for C++ (i.e. Eigen), however, I made my own matrix class to have more freedom in creating my own functions. Nevertheless, this did come with tradeoffs.

4. Split this project up into multiple files and have a more "software development" like file structure. 


# License:
This project is licensed under the MIT License - see the *LICENSE.md* file for details
