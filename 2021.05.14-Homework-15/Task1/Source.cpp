#include <iostream>

using namespace std;

void FillArray(int* a, int b)
{
    for (int i = 0; i < b; ++i)
    {
        a[i] = rand() % 100;
    }
}

void CountingSort(int* a, int* c, int n, int k)
{
    for (int i = 0; i < k; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < k; j++) {
        while (c[j] != 0) {
            a[i] = j;
            c[j]--;
            i++;
        }
    }
}

int main()
{
    int n = 10;
    int* a = new int[n];
    int k = 100;
    int* c = new int[k];

    FillArray(a, n);

    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    CountingSort(a, c, n, k);

    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    
    return 0;
}