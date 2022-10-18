//
// Created by Alexssandro on 17/10/2022.
//
#include <bits/stdc++.h>
using namespace std;

int binarySearch(float a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void insertionSortWithBinary(float a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        loc = binarySearch(a, selected, 0, j);

        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void insertionSort(float arr[], int n)
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

void printArray(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << (float)arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int n[10];
    int m = rand()%(20-10+1)+10; //15

    //arrayTam
    for(int i = 0; i < 10; i++)
        n[i] = 10 + (rand() % 10000);

    clock_t startInsertion, endInsertion;

    for(int i = 0; i < 10; i++){
        startInsertion = clock();
        cout << "Contagem Insercao Default " << "\n";
        cout << " TAMANHO: " << m << "\n";
        cout << " Iteracao: " << i << "\n";

        float arr[n[i]];

        for(int j = 0; j < m; j++)
            arr[j] = (float) (rand() % ( (2 * n[i] - (-2*n[i]) + 1 ) )+(-2*n[i]));

        int n = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, n);
        //printArray(m, n);
        endInsertion = clock();

        cout << "Array[" << i <<"]" << " com o tempo: "<< "\n";
        double time_taken = double(endInsertion - startInsertion) / double(CLOCKS_PER_SEC);
        cout << "O tempo gasto pelo programa é : " << fixed
             << time_taken << setprecision(5);
        cout << " segundos " << endl;

        cout << "\n";
    }

    clock_t startInsertionBinary, endInsertionBinary;

    for(int i = 0; i < 10; i++){
        startInsertionBinary = clock();
        cout << "Contagem Insercao Binaria " << "\n";
        cout << " TAMANHO: " << m << "\n";
        cout << " Iteracao: " << i << "\n";

        float arr[n[i]];

        for(int j = 0; j < m; j++)
            arr[j] = (float) (rand() % ( (2*n[i] - (-2*n[i]) + 1 ) )+(-2*n[i]));

        int n = sizeof(arr) / sizeof(arr[0]);

        insertionSortWithBinary(arr, n);
        //printArray(m, n);
        endInsertionBinary = clock();

        cout << "Array[" << i <<"]" << " com o tempo: "<< "\n";
        double time_taken = double(endInsertionBinary - startInsertionBinary) / double(CLOCKS_PER_SEC);
        cout << "O tempo gasto pelo programa é : " << fixed
             << time_taken << setprecision(5);
        cout << " segundos " << endl;

        cout << "\n";
    }

    return 0;
}
