#include <iostream>
using namespace std;

int reverse(int n)
{
    int reverseNo = 0;
    while (n > 0)
    {
        reverseNo = reverseNo * 10 + (n % 10);
        n /= 10;
    }
    return reverseNo;
}

int addBinaryNo(int a, int b)
{

    // taking it as 1 in starting and after reversing dividing by 10, if we take it as 0 then it considers 110000 as 11
    // taking 1 results ans of 110000 as 1100001 and then dividing by 10 gives 110000
    int ans = 1;
    int previousCarry = 0;

    while (a > 0 && b > 0)
    {

        if (a % 2 == 0 && b % 2 == 0)
        {

            ans = ans * 10 + previousCarry;
            previousCarry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {

            if (previousCarry == 0)
            {
                ans = ans * 10 + 1;
                previousCarry = 0;
            }
            else if (previousCarry == 1)
            {
                ans = ans * 10 + 0;
                previousCarry = 1;
            }
        }
        else if (a % 2 == 1 && b % 2 == 1)
        {

            ans = ans * 10 + previousCarry;
            previousCarry = 1;
        }

        a /= 10;
        b /= 10;
    }

    while (a > 0)
    {

        if (previousCarry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2);
            previousCarry = 0;
        }

        a /= 10;
    }

    while (b > 0)
    {

        if (previousCarry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2);
            previousCarry = 0;
        }

        b /= 10;
    }

    if (previousCarry == 1)
    {
        ans = ans * 10 + 1;
    }

    ans = reverse(ans);
    ans /= 10;
    return ans;
}

int main()
{

    int a, b;
    cin >> a >> b;

    cout << addBinaryNo(a, b) << endl;

    return 0;
}