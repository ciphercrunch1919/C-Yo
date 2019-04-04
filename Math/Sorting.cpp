#include <iostream>
#include <algorithm>
using namespace std;

void SelectionSort(int A[], int n){
        for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                        if(A[j] < A[i]){
                                swap(A[j],A[i]);
                        }
                }
        }
}

void BubbleSort(int A[], int n){
        for(int i = 0; i < n; ++i){
                for(int j = 0; j < n-i-1; ++j){
                        if(A[j] > A[j+1]){
                                A[j] = A[j]+A[j+1];
                                A[j+1] = A[j]-A[j+1];
                                A[j] = A[j]-A[j+1];
                        }
                }
        }
}

void InsertionSort(int A[], int n){
        for(int i = 1; i < n; i++){
                int j = i;
                while(j > 0 && A[j-1] > A[j]) {
                        swap(A[j],A[j-1]);
                        j--;
                }
        }
}

void Merge(int *a,int l, int h,int m){
        int i,j,k, temp[h-l+1];
        i = l;
        k = 0;
        j = m + 1;
        while(i <= m && j <= h){
                if(a[i] < a[j]){
                        temp[k] = a[i];
                        k++;
                        i++;
                }
                else{
                        temp[k] = a[j];
                        k++;
                        j++;
                }
        }
        while(i <= m){
                temp[k] = a[i];
                k++;
                i++;
        }
        while(j<=h){
                temp[k] = a[j];
                k++;
                j++;
        }
        for(i = l; i <= h; i++){
                a[i] = temp[i-l];
        }
}

void MergeSort(int *a,int l,int h){
        int m;
        if(l<h){
                m = (l+h)/2;
                MergeSort(a,l,m);
                MergeSort(a,m+1,h);
                Merge(a,l,h,m);
        }
}

int Partition(int *A, int start, int end) {
        int pivot = A[end];
        int pIndex = (start-1);
        for(int i = start; i <= end-1; i++){
                if(A[i] <= pivot){
                        pIndex++;
                        swap(A[i], A[pIndex]);
                }
        }
        swap(A[pIndex+1], A[end]);
        return (pIndex+1);
}

void QuickSort(int *A, int start, int end) {
        if(start < end){
                int pIndex = Partition(A, start, end);
                QuickSort(A,start, pIndex-1);
                QuickSort(A, pIndex+1, end);
        }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    cout << "Selection Sorting..." << endl;
    SelectionSort(A, 6);
    for (int i=0; i<6; i++)
        cout << A[i] << " ";
    cout << endl << endl;

    int B[] = {12, 17, 14, 11, 15, 13};
    cout << "Bubble Sorting..." << endl;
    BubbleSort(B, 6);
    for (int i=0; i<6; i++)
        cout << B[i] << " ";
    cout << endl << endl;

    cout << "Insertion Sorting..." << endl;
    int C[] = {22, 27, 24, 21, 25, 23};
    InsertionSort(C, 6);
    for (int i=0; i<6; i++)
        cout << C[i] << " ";
    cout << endl << endl;

    cout << "Merge Sorting..." << endl;
    int D[] = {22, 27, 24, 21, 25, 23, 26, 28};
    MergeSort(D, 0, 7);
    for (int i=0; i<8; i++)
        cout << D[i] << " ";
    cout << endl << endl;

    cout << "Quick Sorting..." << endl;
    int E[] = {32, 37, 34, 31, 35, 33, 36, 38};
    QuickSort(E, 0, 7);
    for (int i=0; i<8; i++)
        cout << E[i] << " ";
    cout << endl << endl;

    return 0;
}
