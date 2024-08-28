// Problem statement
// Amit has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.

// The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.

// For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

int *stockSpan(int *price, int size)
{
    // Write your code here
    int output[size];
    stack<int> s;

    output[0] = 1;
    s.push(0);
    for (int i = 1; i < size; i++)
    {
        if (price[i] < price[s.top()])
        {
            s.push(i);
            output[i] = 1;
        }
        else
        {
            while (s.top() != NULL && price[i] > price[s.top()])
            {
                s.pop();
            }
            if (s.top() == NULL)
                output[i] = i + 1;
            else
                output[i] = i - s.top();

            s.push(i);
        }
    }
    for (int i = 0; i < size; i++)
    {
        price[i] = output[i];
    }
    return price;
}