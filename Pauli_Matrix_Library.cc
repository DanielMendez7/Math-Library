/****** Pauli_Matrix_Library.cc ******************************
*          Author: Daniel Mendez
*            Date: 11/01/2022
*         Purpose: Definition of Pauli Matrix functions. 
*************************************/
#include "Pauli_Matrix_Library.h"

CMatrix::CMatrix()
/********************************************
 *       Purpose: Default Square Matrix Constructor 
 *                intializes a 2 x 2 matrix with all 0 entries.                  
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    m_iRowSize = 2;
    m_iColSize = 2;

    unsigned short int num_of_entries = m_iRowSize * m_iColSize;
    m_vecMatrix = vector<complex<float> >(num_of_entries, complex<float>(0, 0));
}


CMatrix::CMatrix(string inPauliID) : CMatrix()
/********************************************
 *       Purpose: Initialize a 2 x 2 Pauli Matrix.        
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    if (!inPauliID.compare("X") || !inPauliID.compare("x")) {         
        // Row 1
        m_vecMatrix.at(0) = complex<float>(0, 0);
        m_vecMatrix.at(1) = complex<float>(1, 0);

        // Row 2
        m_vecMatrix.at(2) = complex<float>(1, 0);
        m_vecMatrix.at(3) = complex<float>(0, 0);
        // cout << matrix.size() << endl;

    }
    else if (!inPauliID.compare("Y") || !inPauliID.compare("y")) {     
        // Row 1
        m_vecMatrix.at(0) = complex<float>(0, 0);
        m_vecMatrix.at(1) = complex<float>(0, -1);

        // Row 2
        m_vecMatrix.at(2) = complex<float>(0, 1);
        m_vecMatrix.at(3) = complex<float>(0, 0);
    }
    else if (!inPauliID.compare("Z") || !inPauliID.compare("z")) {
        // Row 1
        m_vecMatrix.at(0) = complex<float>(1, 0);
        m_vecMatrix.at(1) = complex<float>(0, 0);

        // Row 2
        m_vecMatrix.at(2) = complex<float>(0, 0);
        m_vecMatrix.at(3) = complex<float>(-1, 0);
    }
    // Identity Matrix
    else {
        // Row 1
        m_vecMatrix.at(0) = complex<float>(1, 0);
        m_vecMatrix.at(1) = complex<float>(0, 0);

        // Row 2
        m_vecMatrix.at(2) = complex<float>(0, 0);
        m_vecMatrix.at(3) = complex<float>(1, 0);
    }

}


CMatrix::CMatrix(unsigned short int inRowSize, unsigned short int inColSize)
/********************************************
 *       Purpose: Square Matrix constructor initializes a 
 *                size_of_row  x  size_of_col  matrix with all 0 entries.                
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
 *          TODO: Add support for non square matrices.
********************************************/ 
{

    // This guarantees a square matrix.
    if ( inRowSize != inColSize ) {
        cout << "ERROR: Please provide n * n dimensions for the square matrix." << "Non Square matrix support will be added later." << '\n' 
             << "Error caught in Matrix(size_of_row, size_of_col) contructor. " << '\n'
             << "EXITING PROGRAM. . ." << endl;
        exit(1);
    }
    else {
        m_iRowSize = inRowSize;
        m_iColSize = inColSize;

        // Intialize matrix to all 0's
        unsigned short int m_iNumOfEntries = m_iRowSize * m_iColSize;
        m_vecMatrix = vector<complex<float> >(m_iNumOfEntries, complex<float>(0, 0));
    }

}

CMatrix::CMatrix(const CMatrix &inMatrix2)
/********************************************
 *       Purpose: Copy Constructor.                
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
 *          TODO: N/A
********************************************/ 
{
    m_iRowSize = inMatrix2.GetRowSize();
    m_iColSize = inMatrix2.GetColSize();
    m_vecMatrix = inMatrix2.GetMatrix();
}


void CMatrix::PrintMatrix() const 
/********************************************
 *       Purpose: Print all entries of the matrix data member.
 *  Precondition: N/A
 * Postcondition: Must NOT modify any data members of Matrix Object.
 *          Note: N/A
 *          TODO: 
********************************************/ 
{
    for ( unsigned short int r = 0; r < m_iRowSize; r++ ) {
        for ( unsigned short int c = 0; c < m_iColSize; c++ ) {
            cout << GetValueAt(r, c) << " ";
        }
        cout << "\n" << endl;
    }
}


complex<float> CMatrix::GetValueAt(const unsigned short int inRowIndex,  const unsigned short int inColIndex) const
/********************************************
 *       Purpose: Get 2D matrix index for a 1D vector
 *                The 1D vector acts as a 2D matrix.
 *  Precondition: N/A
 * Postcondition: Must NOT modify any data members of Matrix Object.
 *          Note: N/A
 *          TODO: N/A
********************************************/ 
{
    unsigned short int m_iOneDIndex = inRowIndex * m_iColSize + inColIndex;
    try {
        return m_vecMatrix.at(m_iOneDIndex);
    }
    catch(const std::out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << '\n' 
             << "Error caught in GetValueAt() method. Likely because you are trying to access " << m_iRowSize * m_iColSize << " entries in a for loop, when there are only " << m_vecMatrix.size() << " entries." << '\n' 
             << "EXITING PROGRAM . . ." << '\n';
        exit(1);
    }
}


void CMatrix::ModifyValueAt(const unsigned short int inRowIndex,  const unsigned short int inColIndex, const complex<float> inVal)
/********************************************
 *       Purpose: Modify Value at index of 1D vector.
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
 *          TODO: N/A
********************************************/ 
{
    unsigned short int m_iOneDIndex = inRowIndex * m_iColSize + inColIndex;
    try {
        m_vecMatrix.at(m_iOneDIndex) = inVal;
    }
    catch(const std::out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << '\n' 
             << "Error caught in ModifyValueAt() method. Likely because you are trying to access " << inRowIndex * inColIndex << " entries in a for loop, when there are only " << m_vecMatrix.size() << " entries." << '\n' 
             << "EXITING PROGRAM . . ." << '\n';
        exit(1);
    }
}


CPauliMatrix::CPauliMatrix() : CMatrix("I")
/********************************************
 *       Purpose: Default Pauli Constructor creates the Pauli I matrix.                  
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    m_cxPauliFactor = complex<float>(1, 0);
    m_sPauliString = "I";
}


CPauliMatrix::CPauliMatrix(string inPauliID) : CMatrix(inPauliID)
/********************************************
 *       Purpose: Constructor creates Pauli matrix according to 
 *                input pauli_id. Invalid string, will give Identity 
 *                matrix by default.
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    m_cxPauliFactor = complex<float>(1, 0);

    // TODO: Refactor. Ignore letter case sensitivity.
    if (!inPauliID.compare("I") || !inPauliID.compare("i"))
        m_sPauliString = "I";

    else if (!inPauliID.compare("X") || !inPauliID.compare("x"))
        m_sPauliString = "X";
    
    else if ( !inPauliID.compare("Y") || !inPauliID.compare("y") ) 
        m_sPauliString = "Y";
    
    else if ( !inPauliID.compare("Z") || !inPauliID.compare("z") ) 
        m_sPauliString = "Z";

    else {
        cout << "CPauliMatrix(string inPauliID) failed because pauli ID is not valid. Use one of the following: { \"I\", \"X\", \"Y\", \"Z\" }" << endl;
        cout << "Exiting Program . . . " << endl;
        exit(1);
    }
}


CPauliMatrix::CPauliMatrix(unsigned short int inRowSize, unsigned short int inColSize) : CMatrix(inRowSize, inColSize)
/********************************************
 *       Purpose: Square Matrix constructor initializes a 
 *                row_size  x  col_size  matrix with all 0 entries.
 *                This constructor does not produce a Pauli Matrix, 
 *                but is essential to the PauliAlgebraElement class.
 *  Precondition: N/A
 * Postcondition: All entries are initialized to 0.
 *          Note: N/A
********************************************/ 
{
    m_cxPauliFactor = complex<float>(1, 0);
    m_sPauliString = "";
}


string CPauliMatrix::PauliToString() const
/********************************************
 *       Purpose: Returns Pauli String representation.
 *                For Example, -iY returns "-iY". 
 *                For Example,  XY returns  "iZ".
 *  Precondition: N/A
 * Postcondition: Must NOT modify any data members of PauliMatrix Object.
 *          Note: N/A
********************************************/ 
{
    string m_sResult = m_sPauliString;

    if (m_cxPauliFactor == complex<float>(-1, 0))
        m_sResult = "-" + m_sResult;

    else if (m_cxPauliFactor == complex<float>(0, 1))
        m_sResult = "i" + m_sResult;

    else if (m_cxPauliFactor == complex<float>(0, -1))
        m_sResult = "-i" + m_sResult;

    // else pauli factor is +1 so concatenate nothing.

    return m_sResult;
}


CPauliMatrix CPauliMatrix::operator*(const CPauliMatrix &inPauli2) const
/********************************************
 *       Purpose: Multiply two pauli matrices then return the resulting pauli matrix object.
 *
 *              Pauli Matrices are: I, X, Y, Z
 *              IX = XI = X
 *              IY = YI = Y
 *              IZ = ZI = Z
 *              XY = iZ 
 *              XZ = -iY
 *              YX = -iZ
 *              YZ = iX
 *              ZX = iY
 *              ZY = -iX
 *              
 *              Associativity Rule: 
 *              c(AB) = c(A)B = A(cB)
 *              where c is a constant
 *              A and B are matrices.
 * 
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    CPauliMatrix m_pmResult = CPauliMatrix("I");

    // Update member variables
    m_pmResult.m_cxPauliFactor = this->m_cxPauliFactor * inPauli2.m_cxPauliFactor;
    
    if (!this->m_sPauliString.compare("X") && !inPauli2.m_sPauliString.compare("Y")) {
        m_pmResult.m_sPauliString = "Z"; 
        m_pmResult.m_cxPauliFactor = m_pmResult.m_cxPauliFactor * complex<float>(0, 1);
    }
    else if (!this->m_sPauliString.compare("X") && !inPauli2.m_sPauliString.compare("Z")) {
        m_pmResult.m_sPauliString = "Y"; 
        m_pmResult.m_cxPauliFactor = m_pmResult.m_cxPauliFactor * complex<float>(0, -1);
    }
    else if (!this->m_sPauliString.compare("Y") && !inPauli2.m_sPauliString.compare("X")) {
        m_pmResult.m_sPauliString = "Z"; 
        m_pmResult.m_cxPauliFactor = m_pmResult.m_cxPauliFactor * complex<float>(0, -1);
    }
    else if (!this->m_sPauliString.compare("Y") && !inPauli2.m_sPauliString.compare("Z")) {
        m_pmResult.m_sPauliString = "X"; 
        m_pmResult.m_cxPauliFactor = m_pmResult.m_cxPauliFactor * complex<float>(0, 1);
    }
    else if (!this->m_sPauliString.compare("Z") && !inPauli2.m_sPauliString.compare("X")) {
        m_pmResult.m_sPauliString = "Y"; 
        m_pmResult.m_cxPauliFactor = m_pmResult.m_cxPauliFactor * complex<float>(0, 1);
    }
    else if (!this->m_sPauliString.compare("Z") && !inPauli2.m_sPauliString.compare("Y")) {
        m_pmResult.m_sPauliString = "X"; 
        m_pmResult.m_cxPauliFactor = m_pmResult.m_cxPauliFactor * complex<float>(0, -1);
    }
    else { // Both input pauli matrices are the same. Only difference may be a factor of phi.
        m_pmResult.m_sPauliString = "I"; 
    }


    // Matrix Multiplication between first and second matrix.
    for ( unsigned short int r = 0; r < this->m_iRowSize; r++ ) {
        for ( unsigned short int c = 0; c < this->m_iColSize; c++) {
            complex<float> m_cxResult = complex<float>(0, 0);
            for ( unsigned short int s = 0; s < this->m_iRowSize; s++ ) {
                complex<float> m_cxEntry1 = this->GetValueAt(r, s);
                complex<float> m_cxEntry2 = inPauli2.GetValueAt(s, c);
                m_cxResult = m_cxResult + (m_cxEntry1 * m_cxEntry2);
            }
            m_pmResult.ModifyValueAt(r, c, m_cxResult);
        }
    }

    return m_pmResult;
}


CPauliMatrix MultiplyPauli(const CPauliMatrix &inPauli1, const CPauliMatrix &inPauli2)
/********************************************
 *       Purpose: Multiply matrix of PauliMatrix object by matrix of PauliMatrix object, 
 *                then return the resulting PauliMatrix object containing that new matrix.
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
  return inPauli1 * inPauli2;
}


void CPauliMatrix::operator*(const complex<float> inPhi)
/********************************************
 *       Purpose: Multiply a pauli matrix by a factor of phi.
 *  Precondition: N/A
 * Postcondition: input PauliMatrix object must be modified by input phi parameter.
 *          Note: N/A
            TODO: Prevent -0 entries in matrix.  
********************************************/ 
{
    for ( unsigned short int r = 0; r < this->m_iRowSize; r++ ) {
        for ( unsigned short int c = 0; c < this->m_iColSize; c++ ) {
            complex<float> m_cxEntry = this->GetValueAt(r, c);
            // TODO: Prevent -0 entries in matrix.  
            // if (entry.real() != 0 )
            this->ModifyValueAt(r, c, inPhi * m_cxEntry); 
        }
    }

    // Update value of pauli_factor
    this->m_cxPauliFactor *= inPhi;
}


void MultiplyPhase(const complex<float> inPhi, CPauliMatrix &inPauli)
/********************************************
 *       Purpose: Multiply the matrix data member of a PauliMatrix object by a factor of phi.
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    if ( inPhi != complex<float>(1, 0) && inPhi != complex<float>(-1, 0) &&
         inPhi != complex<float>(0, 1) && inPhi != complex<float>(0, -1)) {
         cout << "Function failed because phi is not one of the following: { 1, -1, i, -i }"<< endl;
         cout << "Exiting Program . . ." << endl;
         exit(1);
    }
    else 
        inPauli * inPhi;
}


void TestMultiplyPhase(const complex<float> &inPhi1, const complex<float> &inPhi2)
/********************************************
 *       Purpose: Verify all pauli multiplication by phase is correct.
 *  Precondition: Input phi1 and phi2 parameters must be one of the following: { 1, -1, i, -i }
 * Postcondition: N/A
********************************************/ 
{
    if ( inPhi1 != complex<float>(1, 0) && inPhi1 != complex<float>(-1, 0) &&
         inPhi1 != complex<float>(0, 1) && inPhi1 != complex<float>(0, -1))
         cout << "Function failed because first phi is not one of the following: { 1, -1, i, -i }"<< endl;

    else if ( inPhi2 != complex<float>(1, 0) && inPhi2 != complex<float>(-1, 0) &&
              inPhi2 != complex<float>(0, 1) && inPhi2 != complex<float>(0, -1))
         cout << "Function failed because second phi is not one of the following: { 1, -1, i, -i }"<< endl;

    else {
        cout << "__________________________________" << endl;
        cout << "phi1 = " << inPhi1 << endl;
        cout << "phi2 = " << inPhi2 << endl;

        array<string, 4> m_arrsPauliIDs = { "I", "X", "Y", "Z"};
        for (auto p = m_arrsPauliIDs.begin(); p != m_arrsPauliIDs.end(); ++p){
            cout << "__________________________________" << endl;
            CPauliMatrix m_pmResult = CPauliMatrix(*p);
            cout << "Initial Pauli Matrix: " << m_pmResult.PauliToString() << endl;
            m_pmResult.PrintMatrix();

            MultiplyPhase(inPhi1, m_pmResult);
            cout << "After phi1 multiplication: " << m_pmResult.PauliToString() << endl;
            m_pmResult.PrintMatrix();

            MultiplyPhase(inPhi2, m_pmResult);
            cout << "After phi2 multiplication: " << m_pmResult.PauliToString() << endl;
            m_pmResult.PrintMatrix();
        }
    }
}


void TestPauliIsHermitian()
/********************************************
 *       Purpose: Multiply Pauli objects by themselves to check they're Hermitian. 
 *                The resulting Pauli object should contain an Identity matrix.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{
    // PauliMatrix i_matrix = PauliMatrix("I");
    array<string, 4> m_arrsPauliIDs = { "I", "X", "Y", "Z"};

    for (auto p = m_arrsPauliIDs.begin(); p != m_arrsPauliIDs.end(); ++p){
        CPauliMatrix m_pmPauli1 = CPauliMatrix(*p);
        CPauliMatrix m_pmPauli2 = CPauliMatrix(*p);
        cout << m_pmPauli1.PauliToString() << endl;
        m_pmPauli1.PrintMatrix();


        CPauliMatrix m_pmResult = MultiplyPauli(m_pmPauli1, m_pmPauli2);
        // TODO: Operator Overload for == between two Pauli Matrices.
        // if (p_squared == i_matrix)
        cout << m_pmPauli1.PauliToString() << "^2" << " = " << m_pmResult.PauliToString() << endl;
        m_pmResult.PrintMatrix();
    }

}


void ShortTestMultiplyPauli(const complex<float> &inPhi1, const string &inPauliID1, const complex<float> &inPhi2, const string &inPauliID2)
/********************************************
 *       Purpose: Test Pauli Multiplication.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{

    // Verifying valid input parameters.
    // DELETE. Took care of checking in CPauliMatrix(string inPauliID)
    if (!inPauliID1.compare("X") && !inPauliID1.compare("x") && 
        !inPauliID1.compare("Y") && !inPauliID1.compare("y") &&
        !inPauliID1.compare("Z") && !inPauliID1.compare("z") &&
        !inPauliID1.compare("I") && !inPauliID1.compare("i")) {
        cout << "HelperShortTestMultiplyPauli failed because first pauli ID is not valid. Use one of the following: { \"I\", \"X\", \"Y\", \"Z\" }" << endl;
        cout << "Exiting Program . . . " << endl;
        exit(1);
    }
    // DELETE. Took care of checking in CPauliMatrix(string inPauliID)
    else if (!inPauliID2.compare("X") && !inPauliID2.compare("x") && 
             !inPauliID2.compare("Y") && !inPauliID2.compare("y") &&
             !inPauliID2.compare("Z") && !inPauliID2.compare("z") &&
             !inPauliID2.compare("I") && !inPauliID2.compare("i")) {
        cout << "HelperShortTestMultiplyPauli failed because second pauli ID is not valid. Use one of the following: { \"I\", \"X\", \"Y\", \"Z\" }" << endl;
        cout << "Exiting Program . . . " << endl;
        exit(1);
    }
    else if ( inPhi1 != complex<float>(1, 0) && inPhi1 != complex<float>(-1, 0) &&
              inPhi1 != complex<float>(0, 1) && inPhi1 != complex<float>(0, -1)) {
        cout << "HelperShortTestMultiplyPauli failed because phi1 is not valid. Use one of the following: { 1, -1, i, -i }"<< endl;
        cout << "Exiting Program . . . " << endl;
        exit(1);
    }
    else if ( inPhi2 != complex<float>(1, 0) && inPhi2 != complex<float>(-1, 0) &&
              inPhi2 != complex<float>(0, 1) && inPhi2 != complex<float>(0, -1)) {
        cout << "HelperShortTestMultiplyPauli failed because phi2 is not valid. Use one of the following: { 1, -1, i, -i }"<< endl;
        cout << "Exiting Program . . . " << endl;
        exit(1);
    }

    CPauliMatrix m_pmPauli1 = CPauliMatrix(inPauliID1);
    MultiplyPhase(inPhi1, m_pmPauli1);
    cout << "First Pauli Matrix:  " << m_pmPauli1.PauliToString() << endl;
    m_pmPauli1.PrintMatrix();
    
    CPauliMatrix m_pmPauli2 = CPauliMatrix(inPauliID2);
    MultiplyPhase(inPhi2, m_pmPauli2);
    cout << "Second Pauli Matrix:  " << m_pmPauli2.PauliToString() << endl;
    m_pmPauli2.PrintMatrix();

    CPauliMatrix m_pmResult = MultiplyPauli(m_pmPauli1, m_pmPauli2);
    cout << m_pmPauli1.PauliToString() << "   *   " << m_pmPauli2.PauliToString() << " = " << m_pmResult.PauliToString() << endl;
    m_pmResult.PrintMatrix();
}

void FullTestMultiplyPauli(const string &inPauliID1,  const string &inPauliID2)
/********************************************
 *       Purpose: Test Pauli Multiplication. Given two pauli matrices, 
 *                for example, Z and Z, perform the following 16 tests
 *                and verify they provide the correct resulting matrix.
 *                 Z  x    Z    test 1
 *                 Z  x   -Z    test 2
 *                 Z  x   iZ    test 3
 *                 Z  x  -iZ    test 4
 * 
 *                -Z  x   -Z    test 5
 *                -Z  x    Z    test 6
 *                -Z  x   iZ    test 7
 *                -Z  x  -iZ    test 8
 *                              
 *                iZ  x  iZ     test 9
 *                iZ  x   Z     test 10
 *                iZ  x  -Z     test 11
 *                iZ  x -iZ     test 12
 *  
 *               -iZ  x -iZ     test 13
 *               -iZ  x   Z     test 14
 *               -iZ  x  -Z     test 15
 *               -iZ  x  iZ     test 16
 *                 
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{
    array<complex<float>, 4> m_arrcxPhis = { complex<float>(1, 0), complex<float>(-1, 0), complex<float>(0, 1), complex<float>(0, -1)  };

    for ( unsigned short int r = 0; r < m_arrcxPhis.size(); r++ ) {
        for (unsigned short int c = 0; c < m_arrcxPhis.size(); c++ ) {
            cout << "_________" << endl;
            cout << "Test " << r * m_arrcxPhis.size() + (c + 1) << ": " << endl;
            ShortTestMultiplyPauli(m_arrcxPhis.at(r), inPauliID1, m_arrcxPhis.at(c), inPauliID2);
        }
    }
}


CPauliAlgebraElement::CPauliAlgebraElement(string inPauliID) : CPauliMatrix(inPauliID)
/********************************************
 *       Purpose: Creates a PauliAlgebraElement object. 
 *                The matrix data member Is a 2 x 2 pauli matrix.
 *  Precondition: N/A
 * Postcondition: Must NOT modify any data members of Matrix Object.
********************************************/ 
{
    // Initialize Data Members
    m_cxElementPhase = m_cxPauliFactor;
    m_sElementString = m_sPauliString;    
}


CPauliAlgebraElement::CPauliAlgebraElement(unsigned short int inRowSize, unsigned short int inColSize) : CPauliMatrix(inRowSize, inColSize)
/********************************************
 *       Purpose: Creates a PauliAlgebraElement object that is row_size x col_size. 
 *                All elements are intialized to 0;
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{
    // Initialize Data Members
    m_cxElementPhase = complex<float>(1, 0);
    m_sElementString = "";
}


string CPauliAlgebraElement::PauliAlgebraElementToString() const
/********************************************
 *       Purpose: Returns the Pauli Algebra element as a string.
 *                For Example "(5 + 10i)Z"
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
********************************************/ 
{
    string m_sResult = m_sElementString;

    if (m_cxElementPhase.imag() == 0 )
        m_sResult = to_string((int) m_cxElementPhase.real()) + m_sResult;
    
    else if ( m_cxElementPhase.real() == 0 )
        m_sResult = to_string((int) m_cxElementPhase.imag()) + "i" + m_sResult;

    else if ( m_cxElementPhase.real() != 0 && m_cxElementPhase.imag() != 0 )
        m_sResult = "(" + to_string((int) m_cxElementPhase.real()) + " + " + to_string((int) m_cxElementPhase.imag()) + "i" + ")" + m_sResult;

    return m_sResult;
}


CPauliAlgebraElement CPauliAlgebraElement::operator*(const CPauliAlgebraElement &inPAElement2) const
/********************************************
 *       Purpose: Returns a PauliAlgebraElement object where the matrix data member is
 *                the tensor product between the first input parameter and the second input parameter.
 *                For Example, p1_algebra_matrix @ p2_alebgra_matrix
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{
    unsigned short int m_iNewRowSize = this->m_iRowSize * inPAElement2.m_iRowSize;
    unsigned short int m_iNewColSize = this->m_iColSize * inPAElement2.m_iColSize;
    CPauliAlgebraElement m_paeResult = CPauliAlgebraElement(m_iNewRowSize, m_iNewColSize);
    m_paeResult.m_cxElementPhase = this->m_cxElementPhase * inPAElement2.m_cxElementPhase;
    m_paeResult.m_sElementString = this->m_sElementString + " @ " + inPAElement2.m_sElementString;


    for (unsigned short int r=0; r < this->m_iRowSize; r++){
        for (unsigned short int c=0; c < this->m_iColSize; c++){
            complex<float> m_cxMatrix1Val = this->GetValueAt(r, c); 

            for ( unsigned short int r2=0; r2 < inPAElement2.m_iRowSize; r2++ ) {
                for (unsigned short int c2=0; c2 < inPAElement2.m_iColSize; c2++ ) {
                    complex<float> m_cxMatrix2Val = inPAElement2.GetValueAt(r2, c2);
                    m_paeResult.ModifyValueAt( (r * inPAElement2.m_iRowSize )+r2, ( c * inPAElement2.m_iColSize )+c2, m_cxMatrix1Val * m_cxMatrix2Val );
                }
            }

        }
    }

    return m_paeResult;
}


CPauliAlgebraElement MakePauliAlgebraElement(string inPauliGroupString)
/********************************************
 *       Purpose: Creates a PauliAlgebraElement object from a string.
 *                For example "XYZ" will create a PauliAlgebraElement object 
 *                where the matrix data memebr is the result of taking the tensor product 
 *                between X tensor Y tensor Z. In my notation it would be: X @ Y @ Z
 *                where @ is the tensor product symbol.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{

    if (inPauliGroupString.size() == 0) {
        cout << "Empty String. Try again." << endl;
        cout << "Exiting Program . . . " << endl;
        exit(1);
    }

    CPauliAlgebraElement m_paeResult = CPauliAlgebraElement(string(1, inPauliGroupString.at(0)));

    for ( unsigned short int e = 1; e < inPauliGroupString.size(); e++ ){
        // Verify valid input which must be one of the following: { "I", "X", "Y", "Z" }
        string m_sPauliChar = string(1, inPauliGroupString.at(e));
        if (m_sPauliChar.compare("X") && m_sPauliChar.compare("x") && 
            m_sPauliChar.compare("Y") && m_sPauliChar.compare("y") &&
            m_sPauliChar.compare("Z") && m_sPauliChar.compare("z") &&
            m_sPauliChar.compare("I") && m_sPauliChar.compare("i")) {
            cout << "MakePauliAlgebraElement failed because " << "from your input string " << "\"" << inPauliGroupString << "\"" << "," << "\"" << m_sPauliChar << "\"" << " is not valid. " << "Replace " << "\"" << m_sPauliChar << "\"" << " with one of the following: { \"I\", \"X\", \"Y\", \"Z\" }" << endl;
            cout << "Exiting Program . . . " << endl;
            exit(1);
        }

        m_paeResult = m_paeResult * CPauliAlgebraElement(m_sPauliChar);
    }
    
    return m_paeResult;
}


void CPauliAlgebraElement::operator*(const complex<float> &inZ)
/********************************************
 *       Purpose: Multiply matrix data member of a PauliAlgebraElement object by a 
 *                scalar. The scalar may be a complex number.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{
    // Update value of pauli_factor
    this->m_cxElementPhase = this->m_cxElementPhase * inZ;

    // Update matrix
    for ( unsigned short int r = 0; r < this->m_iRowSize; r++ ) {
        for ( unsigned short int c = 0; c < this->m_iColSize; c++ ) {
            complex<float> m_cxEntry = this->GetValueAt(r, c);
            // TODO: Prevent -0 entries in matrix.  
            // if (entry.real() != 0 )
            this->ModifyValueAt(r, c, inZ * m_cxEntry); 
        }
    }
}


void MultiplyPauliAlgebraByScalar(const complex<float> &inZ, CPauliAlgebraElement &inPAElement)
/********************************************
 *       Purpose: Multiply PauliAlgebraElement by a scalar. Scalar may be a complex number.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/ 
{
    inPAElement * inZ;
}


CPauliAlgebraElement CPauliAlgebraElement::operator+(const CPauliAlgebraElement &inPAElement2) const
/********************************************
 *       Purpose: Add matrix data member entries of first input PauliAlgebraElement object 
 *                with the matrix data member entries of second input PauliAlgebraElement object.
 * 
 *  Precondition: First and Second input PauliAlgebraElement objects may only differ by
 *                a scalar factor. Otherwise, addition fails.
 *                Good, -9XYZ + 7XYZ  =  -1XYZ
 *                 Bad,  4XYZ +  ZZZ  
 * Postcondition: N/A
********************************************/
{
    // Pauli Elements do NOT match. For example: XYZ + XY
    if (this->m_sElementString.compare(inPAElement2.m_sElementString) ||
        this->m_iRowSize * this->m_iColSize != inPAElement2.m_iRowSize * inPAElement2.m_iColSize) {
        cout << "Adding Pauli Elements Failed. Pauli elements do not match: " << this->m_sElementString << " and " << inPAElement2.m_sElementString << endl;
        exit(1);
    }

    // Pauli Elements do match. For example: XYZ + 2XYZ
    CPauliAlgebraElement m_paeResult = CPauliAlgebraElement(this->m_iRowSize, this->m_iColSize);
    m_paeResult.m_cxElementPhase = this->m_cxElementPhase + inPAElement2.m_cxElementPhase;
    m_paeResult.m_sElementString = this->m_sElementString; 


    // Add pauli elements
    for ( unsigned short int r = 0; r < this->m_iRowSize; r++ ) {
        for ( unsigned short int c = 0; c < this->m_iColSize; c++ ) {
            complex<float> m_cxEntry1 = this->GetValueAt(r, c);
            complex<float> m_cxEntry2 = inPAElement2.GetValueAt(r, c);

            // TODO: Prevent -0 entries in matrix.  
            // if (entry.real() != 0 )
            m_paeResult.ModifyValueAt(r, c, m_cxEntry1 + m_cxEntry2); 
        }
    }

    return m_paeResult;
}


CPauliAlgebraElement AddPauliAlgebra(const CPauliAlgebraElement &inPAElement1, const CPauliAlgebraElement &inPAElement2)
/********************************************
 *       Purpose: Add Pauli algebra elements first_pauli_matrix and second_pauli_matrix.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/
{
    return inPAElement1 + inPAElement2;
}


void TestConstructPauliElement( const complex<float> &inZ, const string inPauliGroupString )
/********************************************
 *       Purpose: Test MakePauliAlgebraElement() function.
 *                Test MultiplyPauliAlgebraByScalar() function.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/
{
    CPauliAlgebraElement m_paeResult = MakePauliAlgebraElement(inPauliGroupString);
    cout << "Initial tensor product matrix:" << endl;
    cout << m_paeResult.PauliAlgebraElementToString() << endl;
    m_paeResult.PrintMatrix();


    if (inZ.imag() == 0 )    
        cout << "After Scalar Multiplication by " << "(" + to_string((int) inZ.real()) + ")" << endl;

    else if ( inZ.real() == 0 )
        cout << "After Scalar Multiplication by " << "(" + to_string((int) inZ.imag()) + "i" + ")" << endl;

    else if ( inZ.real() != 0 && inZ.imag() != 0 )
        cout << "After Scalar Multiplication by " << "(" + to_string((int) inZ.real()) + " + " + to_string((int) inZ.imag()) + "i" + ")" << endl;

    MultiplyPauliAlgebraByScalar(inZ, m_paeResult);
    cout << m_paeResult.PauliAlgebraElementToString() << endl;
    m_paeResult.PrintMatrix();


    if (inZ.imag() == 0 )    
        cout << "After Scalar Conjugate Multiplication by " << "(" + to_string((int) conj(inZ).real()) + ")" << endl;

    else if ( inZ.real() == 0 )
        cout << "After Scalar Conjugate Multiplication by " << "(" + to_string((int) conj(inZ).imag()) + "i" + ")" << endl;

    else if ( inZ.real() != 0 && inZ.imag() != 0 )
        cout << "After Scalar Conjugate Multiplication by " << "(" + to_string((int) conj(inZ).real()) + " + " + to_string((int) conj(inZ).imag()) + "i" + ")" << endl;

    MultiplyPauliAlgebraByScalar(conj(inZ), m_paeResult);
    cout << m_paeResult.PauliAlgebraElementToString() << endl;
    m_paeResult.PrintMatrix();
}


void TestAddPauliAlgebra( const complex<float> &inZ1, const string &inPAString1, const complex<float> &inZ2, const string &inPAString2)
/********************************************
 *       Purpose: Test AddPauliAlgebra() function.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/
{
    CPauliAlgebraElement m_paeElement1 = MakePauliAlgebraElement(inPAString1);
    MultiplyPauliAlgebraByScalar(inZ1, m_paeElement1);
    cout << "First Pauli Element: " << m_paeElement1.PauliAlgebraElementToString() << endl;
    m_paeElement1.PrintMatrix();

    CPauliAlgebraElement m_paeElement2 = MakePauliAlgebraElement(inPAString2);
    MultiplyPauliAlgebraByScalar(inZ2, m_paeElement2);
    cout << "Second Pauli Element: " << m_paeElement2.PauliAlgebraElementToString() << endl;
    m_paeElement2.PrintMatrix();

    CPauliAlgebraElement m_paeResult = AddPauliAlgebra(m_paeElement1, m_paeElement2);
    cout << "First plus Second Element: " << "(" << m_paeElement1.PauliAlgebraElementToString() << ")" << " + " << "(" << m_paeElement2.PauliAlgebraElementToString() << ")" << " = " << m_paeResult.PauliAlgebraElementToString() << endl;
    m_paeResult.PrintMatrix();
}

void GetPauliString(const string &inPauliChar1, const string &inPauliChar2, complex<float> &outFactor, string &outPauliChar3)
/********************************************
 *       Purpose: 4th input parameter is modified to the single character string 
 *                representing the resulting matrix of multiplying the first input 
 *                parameter matrix string with the second input parameter matrix.
 *                3rd input parameter is the resulting factor.
 * 
 *                Pauli Matrix Strings are: "I", "X", "Y", "Z"
 *                IX = XI = X
 *                IY = YI = Y
 *                IZ = ZI = Z
 *                XY = iZ 
 *                XZ = -iY
 *                YX = -iZ
 *                YZ = iX
 *                ZX = iY
 *                ZY = -iX
 *              
 *              Associativity Rule: 
 *              c(AB) = c(A)B = A(cB)
 *              where c is a constant
 *              A and B are matrices.
 * 
 *  Precondition: Must not modify 1st and 2nd input parameters.
 * Postcondition: Must modify 3rd and 4th input parameters.
 *          Note: N/A
********************************************/ 
{    
    if (!inPauliChar1.compare("I") && (!inPauliChar2.compare("I")  ||
                                       !inPauliChar2.compare("X")  || 
                                       !inPauliChar2.compare("Y")  ||
                                       !inPauliChar2.compare("Z")))
    {
        outFactor = complex<float>(1, 0);
        outPauliChar3 = inPauliChar2;
    }
    else if (!inPauliChar2.compare("I") && (!inPauliChar1.compare("I")  ||
                                            !inPauliChar1.compare("X")  || 
                                            !inPauliChar1.compare("Y")  ||
                                            !inPauliChar1.compare("Z")))
    {
        outFactor = complex<float>(1, 0);
        outPauliChar3 = inPauliChar1;
    }
    // Both inputs are the same.
    else if (!inPauliChar1.compare(inPauliChar2)) {
        outFactor = complex<float>(1, 0);
        outPauliChar3 = "I";
    }
    else if (!inPauliChar1.compare("X") && !inPauliChar2.compare("Y")) {
        outFactor = complex<float>(0, 1);
        outPauliChar3 = "Z"; 
    }
    else if (!inPauliChar1.compare("X") && !inPauliChar2.compare("Z")) {
        outFactor = complex<float>(0, -1);
        outPauliChar3 = "Y"; 
    }
    else if (!inPauliChar1.compare("Y") && !inPauliChar2.compare("X")) {
        outFactor = complex<float>(0, -1);
        outPauliChar3 = "Z"; 
    }
    else if (!inPauliChar1.compare("Y") && !inPauliChar2.compare("Z")) {
        outFactor = complex<float>(0, 1);
        outPauliChar3 = "X"; 
    }
    else if (!inPauliChar1.compare("Z") && !inPauliChar2.compare("X")) {
        outFactor = complex<float>(0, 1);
        outPauliChar3 = "Y"; 
    }
    else if (!inPauliChar1.compare("Z") && !inPauliChar2.compare("Y")) {
        outFactor = complex<float>(0, -1);
        outPauliChar3 = "X"; 
    }
    else {
        cout << "ERROR: One of your input strings is not a pauli character." << "\n"
             << "Exiting Program . . .";
        exit(1);
    }
}


CPauliAlgebraElement CPauliAlgebraElement::operator%(const CPauliAlgebraElement &inPAElement2) const
/********************************************
 *       Purpose: Add matrix data member entries of first input PauliAlgebraElement object 
 *                with the matrix data member entries of second input PauliAlgebraElement object.
 *                i(Z @ X) * -(Z @ Y) = I @ Z
 *  Precondition: N/A
 * Postcondition: N/A
 *          TODO: - REFACTOR, OPTIMIZE CODE, MAINTAIN DATA ENCAPSULATION.
 *                - Change operator % to something else.
 *                  Operator overloading should be for * operator.
 *                  However, the * operator is already overloaded for 
 *                  PauliAlgebraElement() * PauliAlgebraElement(). 
 *                  Add another parameter to operator overload for *
 *                  that acts as a key to switch between different 
 *                  functionalities.
 *                - Verify valid input parameters.
********************************************/
{
    if (this->m_sElementString.size() != inPAElement2.m_sElementString.size()) {
        cout << "Multiplying Pauli Elements Failed. Pauli elements do not match in size: " << this->m_sElementString << " and " << inPAElement2.m_sElementString << endl;
        exit(1);
    }

    // First Pauli Algebra multiplication between the first two matrices.
    // For example, if the algebra multiplication is i(Z @ X) * -(Z @ Y)
    // then this code below does iZ * -Z = -iI
    string m_sLeftPauChar = string(1, this->m_sElementString.at(0));
    string m_sRightPauChar = string(1, inPAElement2.m_sElementString.at(0));

    complex<float> m_cxPhase;
    string m_sPauliChar;
    GetPauliString(m_sLeftPauChar, m_sRightPauChar, m_cxPhase, m_sPauliChar); // Z * Z = 1I where m_cxPhase = 1, m_sPauliChar = I
    m_cxPhase *= this->m_cxElementPhase * inPAElement2.m_cxElementPhase;      // m_cxPhase = 1 * i * -1 = -i // Only need to do this once for the first algebra element multiplication.
    CPauliAlgebraElement m_paeElement1 = CPauliAlgebraElement(m_sPauliChar);  // m_paeElement1 = I           // Verified m_sPauliChar is valid in the CPauliMatrix(string inPauliID) constructor.
    MultiplyPauliAlgebraByScalar(m_cxPhase, m_paeElement1);                   // m_paeElement1 = -iI


    // Determine the number of Pauli Algebra Multiplications.
    // For Example: Go from "X @ X @ I" to "XXI" which requires cutting out "@" and " ".
    // TODO: Refactor this by using this format, "XXI", rather than this format, "X @ X @ I", for the data member m_sElementString.
    string stripped_pstring = this->m_sElementString;
    stripped_pstring.erase(std::remove(stripped_pstring.begin(), stripped_pstring.end(), '@'), stripped_pstring.end());
    stripped_pstring.erase(std::remove(stripped_pstring.begin(), stripped_pstring.end(), ' '), stripped_pstring.end());

    string stripped_pstring2 = inPAElement2.m_sElementString;
    stripped_pstring2.erase(std::remove(stripped_pstring2.begin(), stripped_pstring2.end(), '@'), stripped_pstring2.end());
    stripped_pstring2.erase(std::remove(stripped_pstring2.begin(), stripped_pstring2.end(), ' '), stripped_pstring2.end());


    for ( unsigned short int e = 1; e < stripped_pstring.size(); e++ ) {
        m_sLeftPauChar = string(1, stripped_pstring.at(e));
        m_sRightPauChar = string(1, stripped_pstring2.at(e));
        
        // Nth Pauli Algebra multiplication between the two matrices.
        // For example, if the algebra multiplication is i(Z @ X) * -(Z @ Y)
        // then this code below does X * Y = iZ
        complex<float> m_cxPhaseN;
        string m_sPauliCharN;
        GetPauliString(m_sLeftPauChar, m_sRightPauChar, m_cxPhaseN, m_sPauliCharN); // X * Y = iZ where m_cxPhase = i, m_sPauliChar = Z
        CPauliAlgebraElement m_paeElement2 = CPauliAlgebraElement(m_sPauliCharN);   // m_paeElement2 = Z  // Verified m_sPauliChar is valid in the CPauliMatrix(string inPauliID) constructor.
        MultiplyPauliAlgebraByScalar(m_cxPhaseN, m_paeElement2);                    // m_paeElement2 = iZ  

        // Update current AlgebraElement. (i.e. update m_paeElement1)
        // Does the tensor product, @,  between two pauli algebra elements.
        // For example, if the algebra multiplication is i(Z @ X) * -(Z @ Y)
        // then this code below does,  -iI @ iZ = 1(I @ Z) = m_paeElement1
        string m_sP3String = m_paeElement1.m_sElementString + m_paeElement2.m_sElementString;
        complex<float> m_cxTempPhase = m_paeElement1.m_cxElementPhase * m_paeElement2.m_cxElementPhase;
        m_paeElement1 = MakePauliAlgebraElement(m_sP3String);
        MultiplyPauliAlgebraByScalar(m_cxTempPhase, m_paeElement1);
    }

    return m_paeElement1;
}


CPauliAlgebraElement MultiplyPauliAlgebra(const CPauliAlgebraElement &inPAElement1, const CPauliAlgebraElement &inPAElement2)
/********************************************
 *       Purpose: Multiply first input Pauli algebra elements with second input Pauli algebra element.
 *  Precondition: N/A
 * Postcondition: N/A
 *          TODO: N/A
********************************************/
{
    return inPAElement1 % inPAElement2;
}


void TestMultiplyPauliAlgebra( const complex<float> &z1, const string &p1_algebra_string, const complex<float> &z2, const string &p2_algebra_string )
/********************************************
 *       Purpose: Test the MultiplyPauliAlgebra() function.
 *  Precondition: N/A
 * Postcondition: N/A
********************************************/
{
    CPauliAlgebraElement p1 = MakePauliAlgebraElement(p1_algebra_string);
    MultiplyPauliAlgebraByScalar(z1, p1);
    cout << "First Pauli Element: " << p1.PauliAlgebraElementToString() << endl;
    p1.PrintMatrix();

    CPauliAlgebraElement p2 = MakePauliAlgebraElement(p2_algebra_string);
    MultiplyPauliAlgebraByScalar(z2, p2);
    cout << "Second Pauli Element: " << p2.PauliAlgebraElementToString() << endl;
    p2.PrintMatrix();

    const CPauliAlgebraElement p3 = MultiplyPauliAlgebra(p1, p2);    
    cout << "Multiplication between pauli elements: " << "(" << p1.PauliAlgebraElementToString() << ")" << " * " << "(" << p2.PauliAlgebraElementToString() << ")" << " = " << p3.PauliAlgebraElementToString() << endl;
    p3.PrintMatrix();
}



void CMatrix::ConjugateTranspose()
/********************************************
 *       Purpose: Take the complex conjugate and transpose of a matrix.
 *  Precondition: N/A
 * Postcondition: Matrix data member must have changed to its conjugate transpose.
 *          TODO: N/A
********************************************/ 
{
    for ( unsigned short int r = 0; r < m_iRowSize; r++ ){
        for ( unsigned short int c = r; c < m_iColSize; c++ ){
            complex<float> m_cxEntry1 = GetValueAt(r, c);

            if (m_cxEntry1.imag() != 0)
                m_cxEntry1 = conj(m_cxEntry1);

            complex<float> m_cxEntry2 = GetValueAt(c, r);

            if (m_cxEntry2.imag() != 0)
                m_cxEntry2 = conj(m_cxEntry2);            
            
            ModifyValueAt(r, c, m_cxEntry2);
            ModifyValueAt(c, r, m_cxEntry1);
        }
    }
}


CMatrix GenerateHermitianMatrix(const unsigned short int inBoundParam, unsigned short int inSideLength)
/********************************************
 *       Purpose: Return a random Hermitian Matrix.
 *  Precondition: boundParam must be a positive real number.
 * Postcondition: Random Hermitian Matrix entries (both real and complex) 
 *                are bounded by the interval [-boundParam, boundParam]
 *          Note: N/A
 *          TODO: - In body, change matrix variable to be a Matrix object type. 
 *                  Update function body accordingly.
********************************************/ 
{
    // Generate a random N for an N x N matrix.
    // TODO: Generate random numbers across EVERY program invocation using std::random_device.
    static default_random_engine generator;
    uniform_int_distribution<int> matrix_length_distribution(1,10); 
    if (inSideLength == 0)
        inSideLength = matrix_length_distribution(generator);
    // cout << matrix_side_length << endl;
    uniform_int_distribution<int> matrix_entry_distribution(-inBoundParam/2, inBoundParam/2);


    CMatrix m_mInitMatrix(inSideLength, inSideLength);


    // Create random complex entries for the N x N matrix.
    for ( int r = 0; r < m_mInitMatrix.GetRowSize(); r++ ){
        for ( int c = 0; c < m_mInitMatrix.GetColSize(); c++ ){
            int real_value = matrix_entry_distribution(generator);
            int imag_value = matrix_entry_distribution(generator);
            complex<float> complex_value = complex<float>(real_value, imag_value);
            m_mInitMatrix.ModifyValueAt(r, c, complex_value);

            // For Debugging. Can Delete.
            // cout << "     real_value: " <<  real_value << endl;
            // cout << "     imag_value: " << imag_value << endl;
            // cout << "  complex_value: " << complex<double>(real_value, imag_value) << endl;
        }
    }


    CMatrix matrix_dagger = m_mInitMatrix;

    // For Debugging. Can Delete.
    // cout << "Random Matrix" << endl;
    // HelperPrintMatrix(matrix);


    // Conjugate Transpose of Matrix
    matrix_dagger.ConjugateTranspose();


    // For Debugging. Can Delete.
    // cout << "Matrix After Conjugate Transpose" << endl;
    // HelperPrintMatrix(matrix_dagger);


    // Hermitian Matrix 
    for ( unsigned short int r = 0; r < matrix_dagger.GetRowSize(); r++ ){
        for ( unsigned short int c = 0; c < matrix_dagger.GetColSize(); c++ ){
            // matrix_dagger.at(k).at(p).real() = matrix_dagger.at(k).at(p).real() + matrix.at(k).at(p).real();
            // complex<double> imag_value = matrix_dagger.at(k).at(p).imag() + matrix.at(k).at(p).imag();
            complex<float> m_cxEntry1 = matrix_dagger.GetValueAt(r, c) + m_mInitMatrix.GetValueAt(r, c); 
            matrix_dagger.ModifyValueAt(r, c, m_cxEntry1);
        }
    }

    // For Debugging. Can Delete.
    // cout << "Hermitian Matrix" << endl;
    // HelperPrintMatrix(matrix_dagger);

    // For Debugging. Can Delete.
    // Inverse of Hermitian Matrix is the conjugate transpose. Which should remain the same.
    // HelperConjugateTranspose(matrix_dagger);

    // For Debugging. Can Delete.
    // cout << "Inverse of Hermitian Matrix" << endl;
    // HelperPrintMatrix(matrix_dagger);


    return matrix_dagger;
}


bool CMatrix::operator==(const CMatrix& inMatrix2)
/********************************************
 *       Purpose: Return true if the data members between both matrices are equal.
 *                   
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: N/A
 *          TODO: N/A
********************************************/
{
    if (this->m_iRowSize != inMatrix2.m_iRowSize || this->m_iColSize != inMatrix2.m_iColSize)
        return false;
    
    for (unsigned short int r = 0; r < this->m_iRowSize; r++) {
        for (unsigned short int c = 0; c < this->m_iColSize; c++) {
            if (this->GetValueAt(r, c) != inMatrix2.GetValueAt(r, c))
                return false;
        }
    }

    return true;
} 

void Goal1Test(unsigned short int inNumOfTests, unsigned short int inBoundParam, bool inWillPrintMatrix)
/********************************************
 *       Purpose: Verify that all random matrices generated, are hermitian.
 *                (R + R_dagger) == (R + R_dagger)_dagger 
 *                      H        ==       H_dagger
 * 
 *                           Random Matrix = R
 *                Conjugate Transpose of R = R_dagger
 *                        Hermitian Matrix = H
 *                   
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: Only set print_matrices to true if num_of_tests
 *                is less than 11. Matrices will be print to terminal.
 *          TODO: - Print out matrices and results to a file rather 
 *                  than the terminal.
********************************************/ 
{
    int hermitian_count = 0;
    int not_hermitian_count = 0;
    cout << "Number of Tests: " << inNumOfTests << endl;
    cout << "Hermitian matrix entries, real and imaginary parts, bounded by the interval: " << "[" << -inBoundParam << ", " << inBoundParam << "]" << endl;


    cout << "Performing Tests . . . " << endl;
    for ( int i = 1; i <= inNumOfTests; i++ ) {

        if ( inWillPrintMatrix )
            cout << "Test " << i << ": " << endl;

        CMatrix m_mMatrix = GenerateHermitianMatrix(inBoundParam);
        CMatrix m_mMatrixDagger = m_mMatrix;
        m_mMatrixDagger.ConjugateTranspose();
        
        if ( m_mMatrix == m_mMatrixDagger ) {
            hermitian_count++;
            if ( inWillPrintMatrix ) {
                cout << "Matrix is Hermitian!" << endl;
                m_mMatrix.PrintMatrix();
            }
        }
        else {
            not_hermitian_count++;
            if ( inWillPrintMatrix ) {
                cout << "Matrix is NOT Hermitian!" << endl;
                m_mMatrix.PrintMatrix();
            }
        }
    }

    cout << "Finished Tests. " << endl;
    cout << "    Total Number of Random Matrices that are Hermitian: " << hermitian_count << endl;
    cout << "Total Number of Random Matrices that are NOT Hermitian: " << not_hermitian_count << endl;
    cout << "      Percentage of Random Matrices that are Hermitian: " << ( hermitian_count / (hermitian_count + not_hermitian_count) ) * 100 << "%" << endl;        
}


complex<float> CMatrix::Trace() const
/********************************************
 *       Purpose: Return the Trace of a matrix
 *  Precondition: N/A
 * Postcondition: Input matrix must not be modified.
 *         Notes: N/A
 *          TODO: - Change parameter type to Matrix object. Update function body accordingly.
********************************************/ 
{
    complex<float> m_cxTrace = 0;
    for ( unsigned short int r = 0; r < this->m_iRowSize; r++ ) {
        for ( unsigned short int c = r; c < r+1; c++ ) {
            m_cxTrace += this->GetValueAt(r, c);
        }
    }

    return m_cxTrace;
}


void CMatrix::operator*(const CMatrix &inMatrix2)
/********************************************
 *       Purpose: Replace each entry of the first CMatrix with each entry of the
 *                resulting matrix multiplication between the firt CMatrix and second CMatrix.
 *  Precondition: Both input matrices are square matrices.
 * Postcondition: First CMatric must be modified.
 *                Input CMatrix parameter must not be modified.
 *         Notes: N/A
 *          TODO: Support matrix multiplication between non-square matrices.
 *                i.e. First CMatrix is M X N, whereas second CMatrix is N x P.
********************************************/ 
{
    if( this->m_iRowSize != inMatrix2.m_iRowSize || this->m_iColSize != inMatrix2.m_iColSize )
        cout << "ERROR: Unable to matrixmultiply. Currently only supports square matrices." << endl;
    else {
        // Create new matrix to store new entries.
        CMatrix m_mResult = CMatrix(m_iRowSize, m_iColSize);

        // Matrix Multiplication between first and second matrix.
        for ( unsigned short int r = 0; r < this->m_iRowSize; r++ ) {
            for ( unsigned short int c = 0; c < this->m_iColSize; c++) {
                complex<float> m_cxResult = complex<float>(0, 0);
                for ( unsigned short int s = 0; s < this->m_iRowSize; s++ ) {
                    complex<float> m_cxEntry1 = this->GetValueAt(r, s);
                    complex<float> m_cxEntry2 = inMatrix2.GetValueAt(s, c);
                    m_cxResult += (m_cxEntry1 * m_cxEntry2);
                }
                m_mResult.ModifyValueAt(r, c, m_cxResult);
            }
        }
        // Use copy constructor to copy entries of new matrix to the original matrix.
        *this = CMatrix(m_mResult);
    }
}

void CMatrix::MatrixMultiply(const CMatrix &inMatrix2)
/********************************************
 *       Purpose: Replace each entry of the first CMatrix with each entry of the
 *                resulting matrix multiplication between the firt CMatrix and second CMatrix.
 *  Precondition: Both input matrices are square matrices.
 * Postcondition: First CMatric must be modified.
 *                Input CMatrix parameter must not be modified.
 *         Notes: N/A
 *          TODO: N/A
********************************************/ 
{
    (*this) * inMatrix2;
}


CMatrix ComposeHermitian(const vector<float> inRealConst)
/********************************************
 *       Purpose: Compose a 2 x 2 Hermitian matrix using 
 *                the input real constants, and the Pauli matrices.
 *                Return the resulting Hermitian matrix.
 *                   
 *  Precondition: Parameter containing the constants must be real numbers. 
 * Postcondition: N/A
 *          Note: N/A
 *          TODO: - Generalize for an N x N matrix. Currently can only make 2 x 2 Hermitian matrix.
 *                - Change return type to a Matrix object. Update function body accordingly. 
 *                - Use PauliMatrix object for Pauli I, X, Y, Z matrices.
********************************************/ 
{
    // Initialize an a 2 * 2 matrix with all 0 entries.
    CMatrix m_mResult = CMatrix(2, 2);

    CPauliAlgebraElement I = CPauliAlgebraElement("I");
    CPauliAlgebraElement X = CPauliAlgebraElement("X");
    CPauliAlgebraElement Y = CPauliAlgebraElement("Y");
    CPauliAlgebraElement Z = CPauliAlgebraElement("Z");

    // Construct the Hermitian matrix from constants and the pauli matrices.
    for ( unsigned short int r = 0; r < m_mResult.GetRowSize(); r++ ) {
        for ( unsigned short int c = 0; c < m_mResult.GetColSize(); c++ ) {
            int m_cxRealVal = 0;
            int m_cxCompVal = 0;

            m_cxRealVal = inRealConst.at(0) * I.GetValueAt(r, c).real() + 
                          inRealConst.at(1) * X.GetValueAt(r, c).real() + 
                          inRealConst.at(2) * Y.GetValueAt(r, c).real() + 
                          inRealConst.at(3) * Z.GetValueAt(r, c).real();

            m_cxCompVal = inRealConst.at(0) * I.GetValueAt(r, c).imag() + 
                          inRealConst.at(1) * X.GetValueAt(r, c).imag() + 
                          inRealConst.at(2) * Y.GetValueAt(r, c).imag() + 
                          inRealConst.at(3) * Z.GetValueAt(r, c).imag();

            m_mResult.ModifyValueAt(r, c, complex<float>(m_cxRealVal, m_cxCompVal));
        }
    }

    return m_mResult;
}


vector<float> CMatrix::PauliDecomposition() const
/********************************************
 *       Purpose: Decompose  a 2 x 2 Hermitian matrix into 
 *                the pauli matrices using the following formula:
 *                H = r0 * I + r1 * X + r2 * Y + r3 * Z
 *                where
 *                r0 = (1/2)Tr(H)
 *                r1 = (1/2)Tr(HX)
 *                r2 = (1/2)Tr(HY)
 *                r3 = (1/2)Tr(HZ)
 * 
 *  Precondition: Must be a 2 x 2 Hermitian Matrix.
 * Postcondition: Input matrix must not be modified. 
 *                Return at list containing the constants r0, r1, r2, r3. 
 *          Note: N/A
 *          TODO: - Generalize deomposition for any N x N Hermitian matrix. Currently can only decompose 2 x 2 Hermitian Matrix.
 *                - Change parameter type and matrix variable in body to a Matrix object. Update function body accordingly.
********************************************/ 
{
    CMatrix m_mMatrix = *this;

    // I
    float r0 = 0.5 * m_mMatrix.Trace().real();

    // X
    CPauliMatrix m_pmX = CPauliMatrix("X");
    m_mMatrix.MatrixMultiply(m_pmX);
    float r1 = 0.5 * m_mMatrix.Trace().real();
    m_mMatrix.MatrixMultiply(m_pmX); // Get the original matrix back.

    // Y
    CPauliMatrix m_pmY = CPauliMatrix("Y");
    m_mMatrix.MatrixMultiply(m_pmY);
    float r2 = 0.5 * m_mMatrix.Trace().real();
    m_mMatrix.MatrixMultiply(m_pmY); // Get the original matrix back.

    // Z
    CPauliMatrix m_pmZ = CPauliMatrix("Z");
    m_mMatrix.MatrixMultiply(m_pmZ);
    float r3 = 0.5 * m_mMatrix.Trace().real();
    m_mMatrix.MatrixMultiply(m_pmZ); // Get the original matrix back.


    vector<float> m_vecRealConst;
    m_vecRealConst.push_back(r0);
    m_vecRealConst.push_back(r1);
    m_vecRealConst.push_back(r2);
    m_vecRealConst.push_back(r3);

    return m_vecRealConst;
}

void Goal2Test(unsigned short int inNumOfTests, unsigned short int inBoundParam, unsigned short int inSideLength)
/********************************************
 *       Purpose: Verify that any 2 x 2 Hermitian matrix can be 
 *                decomposed into the Pauli Matrices.
 *                   
 *  Precondition: N/A
 * Postcondition: N/A
 *          Note: Only set print_matrices to true if num_of_tests
 *                is less than 11. Matrices will be print to terminal.
 *          TODO: - Print out matrices and results to a file rather than the terminal.
 *                - Use PauliMatrix object for Pauli I, X, Y, Z matrices.
********************************************/ 
{
    unsigned short int m_iNumOfSuccDecomp = 0;
    unsigned short int m_iNumOfUnsuccDecomp = 0;

    cout << "Number of Tests: " << inNumOfTests << endl;
    cout << "Hermitian matrix entries, real and imaginary parts, bounded by the interval: " << "[" << -inBoundParam << ", " << inBoundParam << "]" << endl;
    cout << "Using " << inSideLength << " x " << inSideLength << " matrices" << endl;


    cout << "Performing Tests . . . " << endl;
    for ( unsigned short int i = 1; i <= inNumOfTests; i++ ) {
        cout << "Test " << i << ": " << endl;

        CMatrix m_mInputMatrix = GenerateHermitianMatrix(inBoundParam, inSideLength);
        cout << "Input Hermitian Matrix: " << endl;
        m_mInputMatrix.PrintMatrix();

        cout << "Output Decomposition: " << endl;
        vector<float> m_vecRealConst = m_mInputMatrix.PauliDecomposition();
        cout << "(" << m_vecRealConst.at(0) << "I) + " << "(" << m_vecRealConst.at(1) << "X) + " << "(" << m_vecRealConst.at(2) << "Y) + " << "(" << m_vecRealConst.at(3) << "Z)\n" << endl;
        
        cout << "Composed Hermitian Matrix from Decomposition" << endl;
        CMatrix m_mComposedMatrix = ComposeHermitian(m_vecRealConst);
        if (m_mInputMatrix == m_mComposedMatrix) {
            m_iNumOfSuccDecomp++;
            m_mComposedMatrix.PrintMatrix();
        }
        else {
            m_iNumOfUnsuccDecomp++;
            cout << "Matrices do NOT match." << endl;
        }
    }

    cout << "Finished Tests. " << endl;
    cout << "    Total Number of successful Hermitian Matrix Decomposition: " << m_iNumOfSuccDecomp << endl;
    cout << "  Total Number of UNSUCCESSFUL Hermitian Matrix Decomposition: " << m_iNumOfUnsuccDecomp << endl;
    cout << "      Percentage of successful Hermitian Matrix Decomposition: " << ( m_iNumOfSuccDecomp / (m_iNumOfSuccDecomp + m_iNumOfUnsuccDecomp) ) * 100 << "%" << endl; 
}
