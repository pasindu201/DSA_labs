#include <iostream>
#include <iomanip>
using namespace std;

float median(int Arr[], int n) {
    if (n == 1) {
        return Arr[0];
    }

    else if (n % 2==0) {
        return Arr[n / 2];
    }

    else {

        float ans = (((Arr[n / 2] + Arr[(n / 2) - 1])) * 1.0 / 2);
        return ans;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int A[], int n) {
    cout << "Array is ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < n; j++) {
        insertionSort(A, j + 1);
        for (int k = 0; k < j + 1; k++) {
            cout << A[k] << " ";
        }
        double Median = median(A, j + 1);
        cout << fixed << setprecision(1) << "        " << Median << endl;
    }
    cout << " " << endl;
}
int main() {

    int arr1[4] = { 0 };
    for (int i = 0; i < 4; i++)arr1[i] = rand() % 100;
    print_array(arr1, 4);
    
    int arr2[5] = { 0 };
    for (int i = 0; i < 5; i++)arr2[i] = rand() % 100;
    print_array(arr2, 5);

    int arr3[7] = { 0 };
    for (int i = 0; i < 7; i++)arr3[i] = rand() % 100;
    print_array(arr3, 7);

    int arr4[10] = { 0 };
    for (int i = 0; i < 01; i++)arr4[i] = rand() % 100;
    print_array(arr4, 10);

    int arr5[10] = { 0 };
    for (int i = 0; i < 10; i++)arr5[i] = rand() % 100;
    print_array(arr5, 10);


}
