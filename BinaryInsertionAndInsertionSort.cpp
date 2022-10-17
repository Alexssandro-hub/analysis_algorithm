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
    //Part: Binary Insertion
    srand(time(NULL));

    int tamanho[20];

    int qtdVetores = rand()%(20-10+1)+10; //qtd de vetores m[] a gerar.
    cout << " Quantidade de Vetores Gerados: " << qtdVetores << "\n";


    for(int i = 1; i <= qtdVetores; i++)
        tamanho[i] = 10 + (rand() % 10000);


    for(int i = 1; i <= qtdVetores; i++){
        cout << "\n";
        cout << " TAMANHO: " << tamanho[i] << "\n";
        cout << " Iteracao: " << i << "\n";

        float m[tamanho[i]];

        for(int j = 0; j < tamanho[i]; j++){
            m[j] = (float) (rand() % ( (2*tamanho[i] - (-2*tamanho[i]) + 1 ) )+(-2*tamanho[i]));
        }

        int n = sizeof(m) / sizeof(m[0]);
        insertionSort(m, n);
        insertionSortWithBinary(m, n);
        printArray(m, n);

        cout << "\n";
        cout << "\n";
        cout << "\n";
    }

    return 0;
}
