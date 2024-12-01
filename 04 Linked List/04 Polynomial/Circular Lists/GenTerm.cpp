#include <iostream>
#include <fstream>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding rand() with time
#include <vector>
#include <algorithm> // For sorting
 
using namespace std;

// Structure to represent a term in a polynomial
struct Term {
    int coef; // Coefficient (integer)
    int exp;  // Exponent
}; 

// Function to generate a random polynomial with a given number of terms
void generateRandomPolynomial(ofstream& outFile, int numTerms) {
    vector<Term> polynomial;
 
    // Generate unique exponents
    vector<int> exponents;
    for (int i = 0; i < numTerms; ++i) {
        int exp = rand() % 1000; // Assume a maximum exponent of 1000
        while (find(exponents.begin(), exponents.end(), exp) != exponents.end()) {
            exp = rand() % 1000;
        }
        exponents.push_back(exp);
    }

    // Sort exponents in descending order
    sort(exponents.begin(), exponents.end(), greater<int>());

    // Generate random coefficients and create the polynomial
    for (int i = 0; i < numTerms; ++i) {
        int coef = rand() % 21 - 10; // Random integer between -10 and 10
        polynomial.push_back({coef, exponents[i]});
    }

    // Output the sorted polynomial to the file
    for (const Term& term : polynomial) {
        outFile << term.coef << " " << term.exp << endl;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));

    // Open the .in file for writing
    ofstream outFile("polynomials.in");

    if (!outFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Output the number of terms for the first polynomial
    outFile << "100" << endl;

    // Generate and output the first random polynomial
    generateRandomPolynomial(outFile, 100);

    // Output the number of terms for the second polynomial
    outFile << "100" << endl;

    // Generate and output the second random polynomial
    generateRandomPolynomial(outFile, 100);

    // Close the file
    outFile.close();

    cout << "File 'polynomials.in' generated successfully." << endl;

    return 0;
}
