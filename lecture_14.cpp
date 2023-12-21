#include <iostream>
using namespace std;
// Creating an function which can give us the pivot index:
int getPivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
// Creating an function which can give the integer value of an sqrt:
long long int sqrt(int num)
{
    int start = 0;
    int end = num;
    long long int mid = start + (end - start) / 2;
    long long int ans = -1;

    while (start <= end)
    {
        long long int square = mid * mid;
        if (square == num)
        {
            return mid;
        }
        if (square < num)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
// This is the function of sqrt which can give the float value after the integer:
double morePrecision(int num, int precision, int sqrt_num)
{
    double factor = 1;
    double ans = sqrt_num;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < num; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    // finding the PIVOT element using the binary search:
    int size1;
    cout << "Enter the size of an array: ";
    cin >> size1;
    // Creating an array:
    int arr1[100];
    for (int i = 0; i < size1; i++)
    {
        cout << "Value of index " << i << " is: ";
        cin >> arr1[i];
    }
    // Function Calling:
    int ans = getPivot(arr1, size1);
    cout << "The Pivot index is: " << ans << endl;


    // Finding the sqrt root with the float + integer:
    int num;
    cout << "Enter the num value : ";
    cin >> num;
    // Calling function:
    int sqrt_num = sqrt(num);
    cout << "Answer is: " << morePrecision(num, 3, sqrt_num);
}
