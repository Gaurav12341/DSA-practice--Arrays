#include <iostream>

using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
 int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
 
    while (true){
        while (i <= j && A[i] <= pivot){
            i++;
        }
        while (A[j] >= pivot && j >= i){
            j--;
        }
        if (j < i){
            break;
        } else {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}
 
void QuickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}
int main(){

    int C[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n=sizeof(C)/sizeof(C[0]);
 
    QuickSort(C, 0, n-1);
    cout<<"Sorted C: ";
    for (int i=0;i<n;i++)
     cout<<C[i]<<" ";
 
    return 0;
}