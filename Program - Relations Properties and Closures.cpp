#include <iostream>

using namespace std;

const int gSize = 10;


/*TODO: 
       reflexive closure
       symmetrix closure
       transitive closure
*/


// Function for printing array
void printArray(int array[gSize][gSize], int size)
{
    // For every row
    for (int i = 0; i < size; i++)
    {
        // For every column
        for (int j = 0; j < size; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

// Function for entering ordered pairs
int orderedPairs(int (*array)[gSize])
{
    cout << "You may have up to a 10x10 matrix, entered as a set of ordered pairs one\n"
         << "ordered pair per line. For example, 1 3 results in a 1 in row 1, column 3.\n"
         << "Please enter the matrix as ordered pairs x y (0 0 to end matrix input)" << endl;

    int x = 1;
    int y = 1;
    int size = 0;

    // While user hasn't entered 0 0
    while (x != 0 && y != 0)
    {
        cin >> x >> y;
        while (x > gSize || y > gSize || x < 0 || y < 0) // While (x || y) is greater than 10 or less than 0. Invalid entry.
        {
            cout << "Out of range" << endl;
            cin >> x >> y;
        }
        if (x > 0 && y > 0) // If x & y are greater than 0 
        {
            array[x - 1][y - 1] = 1; // change value of ordered pair positioning to 1

            if (size < x)
                size = x;
            if (size < y)
                size = y;
        }
    }

    cout << '\n';
    return size;
}

// Function for finding the meet of two arrays
void meetFunction(int (*arrayA)[gSize], int (*arrayB)[gSize], int size){
    int arrayC[gSize][gSize] = {0}; // Result array


    for (int i = 0; i < size; i++){ // for each row
        for (int j = 0; j < size; j++){ // For each column
            if (arrayA[i][j] == 1 && arrayB[i][j] == 1){ // If value in array A and B are both 1. 1 in the same position of result array
                arrayC[i][j] = 1;
            }
        }
    }
    cout << '\n';
    printArray(arrayC, size); // "Return" result array
}

// Function for finding the join of two arrays
void joinFunction(int (*arrayA)[gSize], int (*arrayB)[gSize], int size){
   int arrayC[gSize][gSize] = {0}; // Result array

  
   for (int i = 0; i < size; i++){// for each row
    for (int j = 0; j < size; j++){ // for each column
        if (arrayA[i][j] == 1 || arrayB[i][j] == 1){ // If value in array A or B is 1. 1 in the same position of result array
                arrayC[i][j] = 1;
            }
    }
   }
    cout << '\n';
    printArray(arrayC, size); // "Return" result array
}

// Function for finding the boolean product
void booleanProductFunction(int (*arrayA)[gSize], int (*arrayB)[gSize], int size){
    int arrayC[gSize][gSize] = {0}; // Result array

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                arrayC[i][j] = arrayC[i][j] || (arrayA[i][k] && arrayB[k][j]); 
            }
        }
    }
    cout << '\n';
    printArray(arrayC, size); // "Return" result array
}

// Function for finding the complement
void complementFunction(int (*arrayA)[gSize], int size){
    int arrayC[gSize][gSize] = {0}; // Result array

    for (int i = 0; i < size; i++){ 
        for (int j = 0; j < size; j++){ 
            if (arrayA[i][j] == 0){ // if indexed value is 0. 1 in result array
                arrayC[i][j] = 1;
            }
        }
    }
    cout << '\n';
    printArray(arrayC, size); // "Return" result array
}

// Function for finding the tranpose
void transposeFunction(int (*arrayA)[gSize], int size){
    int arrayC[gSize][gSize] = {0}; // Result array

    for (int i = 0; i < size; i++){ 
        for (int j = 0; j < size; j++){ 
            arrayC[j][i] = arrayA[i][j];
        }
    }
    cout << '\n';
    printArray(arrayC, size); // "Return" result array
}

// Function for finding reflexive
string isReflexiveFunction(int (*arrayA)[gSize], int size){
    bool isReflexive = true;
    string result;

    for (int i = 0; i < size; i++){
        if (arrayA[i][i] == 0){
            isReflexive = false;
        }
    }

   if (!isReflexive){
    result = "NOT";
   } else
    result = "";

    return result;
}

// Function for finding symmetry
string isSymmetric(int (*arrayA)[gSize], int size){
    bool isSymmetric = true;
    string result;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arrayA[i][j] != arrayA[j][i]){
                isSymmetric = false;
            }
        }
    }

    if (!isSymmetric){
        result = "NOT";
    }else
        result = "";

    return result;
}

// Function for finding antisymmetry
string isAntiSymmetric(int (*arrayA)[gSize], int size){
    bool isAntiSymmetric = true;
    string result;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (i != j && (arrayA[i][j] == 1 && arrayA[j][i] == 1)){
                isAntiSymmetric = false;
            }
        }
    }

    if(!isAntiSymmetric){
        result = "NOT";
    }else
        result = "";

    return result;
}

// Function for finding transitive
string isTransitive(int (*arrayA)[gSize], int size){
    bool isTransitive = true;
    string result;

    for (int i = 0 ; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arrayA[i][j] == 1){
                for (int k = 0; k < size; k++){
                    if (arrayA[j][k] == 1 && arrayA[i][k] == 0){
                        isTransitive = false;
                    }
                }
            }
        }
    }

    if (!isTransitive){
        result = "NOT";
    }else
        result = "";

    return result;
}


int main()
{
    int arrayA[gSize][gSize] = {0};
    int sizeA = orderedPairs(arrayA);

    cout << "Array A = " << '\n'; // Array A
    printArray(arrayA,sizeA);

    int arrayB[gSize][gSize] = {0};
    int sizeB = orderedPairs(arrayB);

    cout << "Array B = " << '\n'; // Array B
    printArray(arrayB,sizeB);

    cout << '\n';
    cout << "The meet of A and B: "; // meet
    meetFunction(arrayA, arrayB, sizeA);

    cout << '\n';
    cout << "The join of A and B: "; // Join
    joinFunction(arrayA, arrayB, sizeA);

    cout << '\n';
    cout << "The Boolean product of A and B: "; // Boolean product
    booleanProductFunction(arrayA, arrayB, sizeA);

    cout << '\n';
    cout << "The complement of A: "; // Complement
    complementFunction(arrayA, sizeA);

    cout << '\n';
    cout << "The transpose of A: "; // Transpose
    transposeFunction(arrayA, sizeA);

    cout << '\n';
    cout << "Relation A is " << isReflexiveFunction(arrayA, sizeA) << " reflexive" << endl; // Reflexive

    cout << '\n';
    cout << "Relation A is " << isSymmetric(arrayA, sizeA) << " symmetric" << endl; // Symmetric

    cout << '\n';
    cout << "Relation A is " << isAntiSymmetric(arrayA, sizeA) << " antisymmetric" << endl; // Antisymmetric

    cout << '\n';
    cout << "Relation A is " << isTransitive(arrayA, sizeA) << " transitive" << endl; // Transitive

}