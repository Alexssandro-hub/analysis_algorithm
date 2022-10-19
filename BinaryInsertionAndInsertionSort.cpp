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

int main()
{
    srand(time(NULL));

    int tam;
    int m = rand()%(20-10+1)+10;

    clock_t startInsertion, endInsertion;
    clock_t startInsertionBinary, endInsertionBinary;

    for(int i = 0; i < m; i++){
        tam = 10 + (rand() % 10000);
        cout << "Contagem Insercao Default " << "\n";
        cout << " Iteracao: " << i << "\n";

        float arr[tam];

        for(int j = 0; j < tam; j++)
            arr[j] = (float) (rand() % ( (2 * tam - (-2 * tam) + 1 ) )+(-2 * tam));

        int n = sizeof(arr) / sizeof(arr[0]);
        cout << " TAMANHO: " << tam << "\n";

        startInsertion = clock();
        insertionSort(arr, n);
        endInsertion = clock();

        cout << "ArrayInsertion[" << i <<"]" << " com o tempo: "<< "\n";
        double time_taken = double(endInsertion - startInsertion) / double(CLOCKS_PER_SEC);
        cout << "O tempo gasto pelo programa é : " << fixed
             << time_taken * 1000 << setprecision(5);
        cout << " milisegundos(ms) " << endl;

        cout << "\n";

        startInsertionBinary = clock();
        insertionSortWithBinary(arr, n);
        endInsertionBinary = clock();

        cout << "ArrayBinaryInsertion[" << i <<"]" << " com o tempo: "<< "\n";
        double time_taken_binary = double(endInsertionBinary - startInsertionBinary) / double(CLOCKS_PER_SEC);
        cout << "O tempo gasto pelo programa é : " << fixed
             << time_taken_binary * 1000 << setprecision(5);
        cout << " milisegundos(ms) " << endl;

        cout << "\n";
    }

    return 0;
}
