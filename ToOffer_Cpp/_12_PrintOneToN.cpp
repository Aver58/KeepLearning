#include "_12_PrintOneToN.h"
#include "string.h"

PrintOneToN::PrintOneToN() {}

void PrintOneToN::Print1ToMaxDigit(int n)
{
    int number = 1;
    for (int i = 0; i < n; i++) {
        number *= 10;
    }
    for (int i = 0; i < number; i++) {
        cout << i;
    }
}

void PrintNumber(char* number) {
    int size = strlen(number);
    bool isBeginWith0 = true;
    for (int i = 0; i < size; i++)
    {
        if (number[i] != '0' && isBeginWith0)
            isBeginWith0 = false;

        if (!isBeginWith0)
            printf("%c", number[i]);
    }
    printf("/t");
}

// mmp 看不懂
bool Increase(char* number) {
    bool isOverflow = false;
    int takeOver = 0;
    int length = strlen(number);

    for (int i = length - 1; i >= 0; i--)
    {
        int sum = number[i] - '0' + takeOver;
        if (i == length - 1)
            sum++;
        if (sum >= 10)
        {
            if (i == 0)
            {
                isOverflow = true;
            }
            else
            {
                sum -= 10;
                takeOver = 1;
                number[i] = '0' + sum;
            }
        }
        else
        {
            number[i] = '0' + sum;
            break;
        }
    }
    return isOverflow;
}

void PrintOneToN::Print1ToMaxDigit_1(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    for (int i = 0; i < n; i++)
    {
        number[i] = '0';
    }
    while (!Increase(number)) {
        PrintNumber(number);
    }

    delete[] number;
}


void PrintNumRecursive(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = '0' + i;
        PrintNumRecursive(number, length, index + 1);
    }
}

void PrintOneToN::Print1ToMaxDigit_2(int n)
{
    if (n <= 0) return;
    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[i] = '0' + i;
        PrintNumRecursive(number, n, 0);
    }

    delete[] number;
}



