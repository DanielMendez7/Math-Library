/****** Test_PM_Library.cc ******************************
*          Author: Daniel Mendez
*            Date: 11/01/2022
*         Purpose: Driver code to test Pauli Matrix functions. 
* Compile Command: g++  -g  -std=gnu++11  -Wall  -Werror  Test_PM_Library.cc  Pauli_Matrix_Library.cc -o  Test_PM_Library
*     Run Command: ./Test_PM_Library
*************************************/
#include "Pauli_Matrix_Library.h"


int main(void) {

    cout << "**************************** Goal 1: Is the Random matrix, Hermitian? ***************************" << endl;
    // TEST 1
    // const int goal1_num_of_tests = 5;
    // const int goal1_matrix_entry_bound = 15;
    // const bool goal1_print_matrix = true;
    // Goal1Test(goal1_num_of_tests, goal1_matrix_entry_bound, goal1_print_matrix);


    cout << "\n*************************** Goal 2: Decompose a 2 x 2 Hermitian Matrix into Pauli Matrices ***************************" << endl;
    // TEST 2
    // const int goal2_num_of_tests = 3;
    // const int goal2_matrix_entry_bound = 15;
    // Goal2Test(goal2_num_of_tests, goal2_matrix_entry_bound);


    cout << "\n*************************** Goal 3: The Pauli Group ***************************" << endl;
    // TEST 3
    // cout << "TESTING: Multiply pauli matrix by a phase:" << endl; 
    // const complex<float> phi1 = complex<float>(-1, 0);
    // const complex<float> phi2 = complex<float>(0, 1);
    // TestMultiplyPhase(phi1, phi2);

    
    // TEST 4
    // cout << "TESTING: P^2 = I, where P is a pauli matrix:" << endl; 
    // TestPauliIsHermitian();


    // TEST 5
    // cout << "TESTING: One Test of Pauli Matrix Multiplication: " << endl; 
    // const string p_matrix1_string = "X";
    // const string p_matrix2_string = "X"; 
    // const complex<float> phi3 = complex<float>(0, -1);
    // const complex<float> phi4 = complex<float>(-1, 0);
    // ShortTestMultiplyPauli(phi3, p_matrix1_string, phi4, p_matrix2_string);


    // TEST 6
    // const string p_matrix1_string = "Z";
    // const string p_matrix2_string = "Z"; 
    // cout << "TESTING: Sixteen Tests of Pauli Matrix Multiplication using " << "Pauli " << p_matrix1_string << " and " << "Pauli " << p_matrix2_string << endl; 
    // FullTestMultiplyPauli(p_matrix1_string, p_matrix2_string);


    cout << "\n*************************** Goal 4: Pauli Algebra for Multiple Qubits ***************************" << endl;
    // TEST 7
    // cout << "TESTING: Tensor Product from Pauli String and Pauli Scalar Multiplication: " << endl; 
    // const complex<float> scalar = complex<float>(5, 10);   
    // TestConstructPauliElement(scalar, "IZI");


    // TEST 8
    // cout << "TESTING: Pauli Algebra Element Addition." << endl;
    // const string p1_algebra_string = "XZ";
    // const string p2_algebra_string = "XZ";
    // const complex<float> z1 = complex<float>(2, 5);
    // const complex<float> z2 = complex<float>(-1, -3);
    // TestAddPauliAlgebra(z1, p1_algebra_string, z2, p2_algebra_string);


    // TEST 9
    // cout << "TESTING: Pauli Algebra Element Multiplication." << endl;
    // const string p3_algebra_string = "ZX";
    // const string p4_algebra_string = "ZY";
    // const complex<float> z3 = complex<float>(0, 1);
    // const complex<float> z4 = complex<float>(-1, 0);
    // TestMultiplyPauliAlgebra(z3, p3_algebra_string, z4, p4_algebra_string);

    return 0;
}