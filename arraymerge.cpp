#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    // TODO:
    // Create temporary arrays

    // I had to use pointers because I got a C++
    // error that they weren't constants.
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* bufferL = new int[leftSize];
    int* bufferR = new int[rightSize];

    // Copy data
    for (int i = 0; i < leftSize; i++) {
        bufferL[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++) {
        bufferR[j] = arr[mid + 1 + j];
    }

    // Merge sorted halves back into arr
    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < leftSize && j < rightSize) {
        if (bufferL[i] <= bufferR[j]) {
            arr[k] = bufferL[i];
            i++;
        }
        else {
            arr[k] = bufferR[j];
            j++;
        }
        k++;
    }
    
    // Since in the previous while loop one side
    // stops before the other, the following ensures
    // anything leftover isn't missed
    while (i < leftSize) {
        arr[k++] = bufferL[i++];
    }

    while (j < rightSize) {
        arr[k++] = bufferR[j++];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // TODO:
        // Find middle
        int mid;
        mid = (left + right) / 2;

        // Recursively sort left half
        mergeSort(arr, left, mid);
        
        // Recursively sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    return 0;
}
