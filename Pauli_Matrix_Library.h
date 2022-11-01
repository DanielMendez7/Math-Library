/****** Pauli_Matrix_Library.h ******************************
*          Author: Daniel Mendez
*            Date: 11/01/2022
*         Purpose: Specification of Pauli Matrix Classes, Methods, and Functions. 
*************************************/
#include <iostream>
#include <vector>
#include <complex>
#include <random>
#include <algorithm>
#include <array>
#include <string>
using namespace std;


#ifndef PAULI_MATRIX_LIBRARY
#define PAULI_MATRIX_LIBRARY

// Square Matrices 
class CMatrix {
public:
    // Base Class Constructors
    //-------------------------------------
    CMatrix();
    CMatrix(string inPauliID);
    CMatrix(unsigned short int inRowSize, unsigned short int inColSize);
    CMatrix(const CMatrix &inMatrix2); // Copy Constructor
    
    // Base Class Methods
    //-------------------------------------
    vector<complex<float>> GetMatrix() const { return m_vecMatrix; };
    unsigned short int GetRowSize() const    { return m_iRowSize; };
    unsigned short int GetColSize() const    { return m_iColSize; }; 
    void PrintMatrix() const;
    complex<float> GetValueAt(const unsigned short int inRowIndex,  const unsigned short int inColIndex) const;
    void ModifyValueAt(const unsigned short int inRowIndex,  const unsigned short int inColIndex, const complex<float> inVal);
    void ConjugateTranspose();
    bool operator==(const CMatrix& inMatrix2);
    complex<float> Trace() const;
    void operator*(const CMatrix &inMatrix2);      // TODO: Consider changing this to return an object.
    void MatrixMultiply(const CMatrix &inMatrix2); // TODO: Consider changing this to return an object.
    vector<float> PauliDecomposition() const;

protected:
    // Base Class Data Members
    //-------------------------------------
    vector<complex<float> > m_vecMatrix; // n * n matrix represented by 1 dimensional vector.
    unsigned short int m_iRowSize;
    unsigned short int m_iColSize;
};
CMatrix ComposeHermitian(const vector<float> inRealConst);



class CPauliMatrix : public CMatrix {
public:
    // Derived Class Constructors
    //-------------------------------------
    CPauliMatrix();
    CPauliMatrix(string inPauliID);
    CPauliMatrix(unsigned short int inRowSize, unsigned short int inColSize);

    // Derived Class Methods
    //-------------------------------------
    string PauliToString() const;
    CPauliMatrix operator*(const CPauliMatrix &inPauli2) const;
    void operator*(const complex<float> inPhi);

protected:
    // Derived Class Data Members    // For Example: XY = iZ This gives m_cxPauliFactor = i and m_sPauliString = "Z", 
    //-------------------------------------
    // Also have matrix, row_size, and col_size as protected data members.    
    complex<float> m_cxPauliFactor;  // Only the following complex numbers: { 1, -1, i, -i }
    string m_sPauliString;           // Single Character String such as "Z"
};
CPauliMatrix MultiplyPauli(const CPauliMatrix &inPauli1, const CPauliMatrix &inPauli2);
void MultiplyPhase(const complex<float> inPhi, CPauliMatrix &inPauli);
void TestMultiplyPhase(const complex<float> &inPhi1, const complex<float> &inPhi2);
void TestPauliIsHermitian();
void ShortTestMultiplyPauli(const complex<float> &inPhi1, const string &inPauliID1, const complex<float> &inPhi2, const string &inPauliID2);
void FullTestMultiplyPauli(const string &inPauliID1,  const string &inPauliID2);



class CPauliAlgebraElement : public CPauliMatrix {
public:

    // Derived Derived Class Constructors
    //-------------------------------------
    CPauliAlgebraElement(string inPauliID);
    CPauliAlgebraElement(unsigned short int inRowSize, unsigned short int inColSize);
    
    // Derived Derived Class Methods
    //-------------------------------------
    string PauliAlgebraElementToString() const;
    CPauliAlgebraElement operator*(const CPauliAlgebraElement &inPAElement2) const; // For MakePauliAlgebraElement()
    void operator*(const complex<float> &inZ);                                      // For MultiplyPauliAlgebraByScalar()
    CPauliAlgebraElement operator+(const CPauliAlgebraElement &inPAElement2) const; // For AddPauliAlgebra()
    CPauliAlgebraElement operator%(const CPauliAlgebraElement &inPAElement2) const; // For MultiplyPauliAlgebra()

private:
    // Derived Derived Class Data Members  // For Example: -iX @ Y @ Z  This gives pauli_element_phase = -i and pauli_element_string = "X @ Y @ Z"
    //-------------------------------------
    complex<float> m_cxElementPhase;       // Any complex number.
    string m_sElementString;               // X tensor Y tensor Z would be "X @ Y @ Z"

};
void GetPauliString(const string &inPauliChar1, const string &inPauliChar2, complex<float> &outFactor, string &outPauliChar3);
CPauliAlgebraElement MakePauliAlgebraElement(string inPauliGroupString);
void MultiplyPauliAlgebraByScalar(const complex<float> &inZ, CPauliAlgebraElement &inPAElement);
CPauliAlgebraElement AddPauliAlgebra(const CPauliAlgebraElement &inPAElement1, const CPauliAlgebraElement &inPAElement2);
CPauliAlgebraElement MultiplyPauliAlgebra(const CPauliAlgebraElement &inPAElement1, const CPauliAlgebraElement &inPAElement2);
void TestConstructPauliElement( const complex<float> &inZ, const string inPauliGroupString );
void TestAddPauliAlgebra( const complex<float> &inZ1, const string &inPAString1, const complex<float> &inZ2, const string &inPAString2);
void TestMultiplyPauliAlgebra( const complex<float> &z1, const string &p1_algebra_string, const complex<float> &z2, const string &p2_algebra_string );

CMatrix GenerateHermitianMatrix(const unsigned short int inBoundParam=10, unsigned short int inSideLength=0);
void Goal1Test(unsigned short int inNumOfTests=10, unsigned short int inBoundParam=10, bool inWillPrintMatrix=false);
void Goal2Test(unsigned short int inNumOfTests=10, unsigned short int inBoundParam=10, unsigned short int inSideLength=2);

#endif