#include "Problems.hpp"

string Problem1(string filename)
{
    // Read the file name from the argv
    ifstream infile(filename);

    // Check the file could be opened successfully if not close the program
    if (infile.bad() || !infile.is_open())
    {
        abort();
        return "";
    }

    string line, longestLine = "";

    // Read the file line by line
    while (getline(infile, line, '\n'))
    {
        // If the length of the current read line is more than the earlier update the longestline with the current line
        if (line.length() > longestLine.length())
        {
            longestLine = line;
        }
    }

    // Close the file stream
    infile.close();

    return longestLine;
}

// Implementing a recursive function to calculate the number of different ways
int Problem2(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        return Problem2(n - 3) + Problem2(n - 2) + Problem2(n - 1);
    }
}
