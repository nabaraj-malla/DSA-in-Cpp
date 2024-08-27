// Problem statement
// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).

//  Note:
// Change in the input array/list itself.You don't need to return or print the elements.
#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    // Write your code here
    int firstReverseStart = 0, firstReverseEnd = n - 1;
    while (firstReverseStart < firstReverseEnd)
    {
        swap(input[firstReverseStart], input[firstReverseEnd]);
        firstReverseStart++;
        firstReverseEnd--;
    }
    int secondReverseStart = 0, secondReverseEnd = n - d - 1;
    while (secondReverseStart < secondReverseEnd)
    {
        swap(input[secondReverseStart], input[secondReverseEnd]);
        secondReverseStart++;
        secondReverseEnd--;
    }
    int thirdReverseStart = n - d, thirdReverseEnd = n - 1;
    while (thirdReverseStart < thirdReverseEnd)
    {
        swap(input[thirdReverseStart], input[thirdReverseEnd]);
        thirdReverseStart++;
        thirdReverseEnd--;
    }
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}