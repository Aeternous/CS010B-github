#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
   int arrSize;
   cin >> arrSize;
   if (arrSize > 0) {
      int arr[arrSize];
      for (unsigned int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      const int *minPos = min(arr, arrSize);
      cout << *minPos << endl;
   }   
   return 0;
}
