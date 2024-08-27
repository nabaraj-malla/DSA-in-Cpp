/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;
    // default constructor
    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }
    // copy constructor
    Polynomial(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    // copy assaignment constructor
    void operator=(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    // setCoefficient function
    void setCoefficient(int degree, int coefficient)
    {
        while (degree >= capacity)
        {
            int *newDegCoeff = new int[2 * capacity];
            for (int i = 0; i < (2 * capacity); i++)
            {
                newDegCoeff[i] = 0;
            }
            for (int i = 0; i < this->capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity = 2 * capacity;
        }
        degCoeff[degree] = coefficient;
    }
    // print function
    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
    // overloading '+' operator
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial temp;
        int i = 0;
        while (i < this->capacity && i < p.capacity)
        {
            temp.setCoefficient(i, this->degCoeff[i] + p.degCoeff[i]);
            i++;
        }
        while (i < this->capacity)
        {
            temp.setCoefficient(i, this->degCoeff[i]);
            i++;
        }
        while (i < p.capacity)
        {
            temp.setCoefficient(i, p.degCoeff[i]);
            i++;
        }
        return temp;
    }
    // overloading '-' operator
    Polynomial operator-(Polynomial const &p)
    {
        Polynomial temp;
        int i = 0;
        while (i < this->capacity && i < p.capacity)
        {
            temp.setCoefficient(i, this->degCoeff[i] - (p.degCoeff[i]));
            i++;
        }
        while (i < this->capacity)
        {
            temp.setCoefficient(i, this->degCoeff[i]);
            i++;
        }
        while (i < p.capacity)
        {
            temp.setCoefficient(i, -p.degCoeff[i]);
            i++;
        }
        return temp;
    }
    // overloading '*' operator
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial temp;
        // temp.capacity=capacity+p.capacity;
        //    temp.degCoeff=new int[temp.capacity];
        // for(int i=0;i<temp.capacity;i++){
        //     temp.degCoeff[i]=0;
        // }
        for (int i = 0; i < this->capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                while ((i + j) >= temp.capacity)
                {
                    int *newdeg = new int[2 * temp.capacity];
                    for (int i = 0; i < 2 * temp.capacity; i++)
                    {
                        newdeg[i] = 0;
                    }
                    for (int i = 0; i < temp.capacity; i++)
                    {
                        newdeg[i] = temp.degCoeff[i];
                    }
                    delete[] temp.degCoeff;
                    temp.degCoeff = newdeg;
                    temp.capacity = 2 * (temp.capacity);
                }
                temp.setCoefficient(i + j, temp.degCoeff[i + j] + (this->degCoeff[i] * p.degCoeff[j]));
            }
        }
        return temp;
    }
};

// Driver program to test above functions
int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
