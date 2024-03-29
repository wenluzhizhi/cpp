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

void sectionSort(int testAr[], int size) {
   for(int i = 0; i < size; i++) {
      int minValue = 99999;
      int minValueIndex = -1;
      int j = i;
      for(j =i; j < size; j++) {
         if(testAr[j] < minValue) {
            minValue = testAr[j];
            minValueIndex = j;
         }
      }
      testAr[minValueIndex] = testAr[i];
      testAr[i] =  minValue;
   }
}


void createMaxHeap(int testAr[], int size, int s, int e) {
   for(int i = (e-s) / 2 - 1 + s ; i >= s; i--) {
      // cout << i <<endl;
      int left = 2 * (i -s)  + 1 + s;
      int right = 2 * (i -s) + 2 + s;
      if(left <= size - 1 && testAr[i] < testAr[left]) {
          swap(testAr, i, left);
      }
      if(right <= size - 1 && testAr[i] < testAr[right]) {
          swap(testAr, i, right);
      }

   }
}

void createMinHeap(int testAr[], int size, int s, int e)
{
   for (int i = (size - s) / 2 - 1 + s; i >= s; i--)
   {
      int left = 2 * (i - s) + 1 + s;
      int right =2 * (i - s) + 2 + s;
      if (left <= size - 1 && testAr[i] > testAr[left] )
      {
         swap(testAr, left, i);
      }
      if (right <= size - 1 && testAr[i] > testAr[right])
      {
         swap(testAr, right, i);
      }
   }
}

void heapSort(int testAr[], int size) {
    for(int i = 0; i < size; i++) {
      createMinHeap(testAr, size, i, size);
      // createMaxHeap(testAr, size, i, size);
    }
   // createMaxHeap(testAr, size, 0, size);
   // printArray(testAr, size);
   // createMaxHeap(testAr, size, 1, size);
   printArray(testAr, size);
}


int sortOnce(int ar[], int size,  int left, int right) {
   int tempIndex = left;
   int temp = ar[left];
  
   while (left < right)
   {
      while (left <right && ar[right] >=  temp)
      {
         right--;
         
      }
      if(left < right) {
         swap(ar, left, right);
         left++;
      }
      while (left < right && ar[left] < temp)
      {
         left++;
      }

      if(left < right) {
         swap(ar, left, right);
         right--;
      }
      ar[left] = temp;
   }
   return left;
   

}




// find a number, split array into two parts
void fastSort(int ar[], int size) {
    int mid = sortOnce(ar, size, 0, size -1);

    sortOnce(ar, size, 0, mid -1);
    sortOnce(ar, size, mid+1, size -1);
}






int main()
{
   size = sizeof(testAr) / sizeof(testAr[0]);
   //bublleSort(testAr, size);
   //sectionSort(testAr, size);
   //heapSort(testAr, size);
   fastSort(testAr, size);
   printArray(testAr, size);
}