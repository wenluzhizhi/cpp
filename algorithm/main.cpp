#include <iostream>
using namespace std;

int testAr[] = {56, 3, 9, 21, 78, 234, 2, 91, 754, 22};
int size = 0;

void swap(int testAr[], int i, int j)
{
   int temp = testAr[i];
   testAr[i] = testAr[j];
   testAr[j] = temp;
}

void printArray(int testAr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << testAr[i] << " ";
   }
   cout << endl;
}

void bublleSort(int testAr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      //cout << testAr[i] << endl;
      for (int j = 0; j < size - 1 - i; j++)
      {
         if (testAr[j] > testAr[j + 1])
         {
            swap(testAr, j, j + 1);
         }
      }
   }
}


void quickSort() {

}

int main()
{
   size = sizeof(testAr) / sizeof(testAr[0]);
   bublleSort(testAr, size);
   printArray(testAr, size);
}