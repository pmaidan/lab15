// Polina Maidanova
// Programming Fundamentals
// CS 1436
// 005
// Due Date: 10/28/2024
// Date Completed: 10/24/2024
// Date Submitted: 10/24/2024


#include <iostream> // Header file allowing the use of input/output objects.
#include <cstdlib>  // Header file allowing the use of random functions.
#include <ctime>    // Header file allowig to work with time.
#include <fstream>  // Header file allowing to work with files.
#include <iomanip>  // Header file allowing to manipulate the output.
using namespace std;    // Use standard namespace.

int main()  // Main function is the starting point of the program execution.
{
    // initialize the constants for generating two random numbers for the minimum and maximum values of iProgramNumber.
    const int MIN1 = 1, MAX1 = 100, MIN2 = 500, MAX2 = 5000;

    // Initialize the constants for generating a sequence of random numbers iRandNum.
    const int MIN3 = 100, MAX3 = 2000;

    /* Declare the variables to store the minimum and maximum values for iProgramNumber, 
    a sequence of random numbers, and the amount of random numbers in a sequence. */
    int iMin, iMax, iRandNum, iProgramNumber;

    // Declare the variable for the numbers' average.
    double fAverage;

    /* Initialize the variables for the amount of numbers in the input file, the numbers' total,
    the smallest number and the largest number. */
    int iInputCount = 0, iTotal = 0, iSmallestNum = 2000, iLargestNum = 100;

    // Open and connect the output text file with the ofstream object outfile.
    ofstream outfile;
    outfile.open("random.txt");

    // Seed the random number generator.
    unsigned seed = time(0);
    srand(seed);

    // Generate two random numbers for the minimum and maximum values of iProgramNumber.
    iMin = rand() % (MAX1 - MIN1 + 1) + MIN1;
    iMax = rand() % (MAX2 - MIN2 + 1) + MIN2;

    // Generate a random number for the amount of random numbers to be created in a sequence.
    iProgramNumber = rand()%(iMax - iMin + 1) + iMin;

    // Generate a sequence of random numbers and write them to the output text file.
    for (int iRandNumCount = 0; iRandNumCount < iProgramNumber; iRandNumCount++)
    {
        iRandNum = rand() % (MAX3 - MIN3 + 1) + MIN3;   // Generate a random number.
        outfile << iRandNum << endl;    // Write the number to the output file.
    }
    outfile.close();    // Close the output file.

    // Open and connect the input text file with the ifstream object inputfile.
    ifstream inputfile;
    inputfile.open("random.txt");

    if (inputfile)  // If the file opened successfully, process it.
    {
        // Read the numbers from the input text file.
        while (inputfile >> iRandNum)
        {
            if (iRandNum < iSmallestNum)    // Check if the number in the input file is smaller than the smallest number.
                iSmallestNum = iRandNum;    // Update the smallest number.

            if (iRandNum > iLargestNum) // Check if the number in the input file is larger than the largest number.
                iLargestNum = iRandNum; // Update the largest number.

            iInputCount++;  // Increment the count of numbers in the input file.
            iTotal += iRandNum; // Accumulate the total sum of the numbers in the input file.
        }
    }
    else
    {
        cout << "Error. Couldn't open the file." << endl;   // Display the error message.
        return 1;   // Return 1 if the file couldn't be opened.
    }

    inputfile.close();  // Close the input file.

    if (iInputCount > 0)
        fAverage = (double) iTotal / (double) iInputCount;  // Calculate the average of the numbers in the input file.
    else
    {
        cout << "No numbers in the file." << endl;   // Display a message if there are no numbers in the file.
        return 2;   // Return 2 if there are no numbers in the file.
    }

    // Display the results.
    cout << "There are " << iInputCount << " numbers in the file\n";    // Display the count of numbers in the file.
    cout << "The smallest number is " << iSmallestNum << endl;  // Display the smallest number in the file.
    cout << "The largest number is " << iLargestNum << endl;    // Display the largest number in the file.
    cout << "The total of the numbers is " << iTotal << endl;   // Display the total sum of the numbers in the file.
    cout << setprecision(3) << fixed;   // Display the average to 3 decimal places.
    cout << "The average of the numbers is " << fAverage << endl;   // Display the average of the numbers in the file.

    return 0;   // Return 0 to indicate that the program completed successfully.
}
