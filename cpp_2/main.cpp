#include <iostream>
using namespace std;

void printArray(int ar[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << ar[i] << endl;
    }
}

int main()
{
    cout << "this is main function" << endl;

    int ar[8] = {6, 9, 3, 56, 34, 1, 898, 2};

    int len = sizeof(ar) / sizeof(ar[0]);
    int gap = len / 2;
    while (gap >= 1)
    {
        //cout << gap << endl;

        for (int i = gap; i < len; i+= gap)
        {
            int curValue = ar[i];
            int preIndex = i;
            while (preIndex >= 1 && curValue < ar[preIndex - gap])
            {
                ar[preIndex] = ar[preIndex - gap];
                preIndex-= gap;
            }
            ar[preIndex] = curValue;
        }

        gap = gap / 2;
    }

    printArray(ar, len);
}
