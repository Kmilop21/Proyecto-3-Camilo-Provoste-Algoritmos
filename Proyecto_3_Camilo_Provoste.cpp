#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;

vector<int> selectionSort(vector<int>& vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    vector<int>::size_type s = temp.size();

    for(vector<int>::size_type i = 0; i < s-1 ; i++)
    {
        vector<int>::size_type min = i;    
        for(vector<int>::size_type j = i+1 ; i < s; j++)
        {
            if(temp[j] < temp[min]) min = j;
        }

        if(min != i) swap(temp[min],temp[i]);
    }
    return temp;
}

vector<int> bubbleSort(vector<int>& vect) {
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    vector<int>::size_type s = temp.size();
    bool swapped;
    for (vector<int>::size_type i = 0; i < s - 1; i++) {
        swapped = false;
        for (vector<int>::size_type j = 0; j < s - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    return temp;
}

vector<int> insertionSort(vector<int>& vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    vector<int>::size_type s = temp.size();

    for(vector<int>::size_type i = 1; i < s; i++)
    {
        int key = temp[i];
        vector<int>::size_type j = i-1;

        while(j != vector<int>::size_type(-1) && temp[j] > key)
        {
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = key;
    }

    return temp;
}

vector<int> shellSort(vector<int>& vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    vector<int>::size_type s = temp.size();

    for(vector<int>::size_type gap = s/2 ; gap > 0; gap /= 2)
    {
        for(vector<int>::size_type i = gap; i < s; i++)
        {
            int aux = temp[i];
            vector<int>::size_type j;

            for(j = i; j >= gap && temp[j-gap] > aux; j -= gap)
            {
                temp[j] = temp[j-gap];
            }
            temp[j] = aux;
        }
    }

    return temp;
}

void merge(vector<int>& temp, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = temp[left+1];

    for(int j = 0; j < n2; j++)
        R[j] = temp[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            temp[k] = L[i];
            i++;
        }
        else
        {
            temp[k] = R[j];
        }

        k++;
    }

    while (i < n1) 
    {
        temp[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        temp[k] = R[j];
        j++;
        k++;
    }
}

vector<int> mergeSort(vector<int>& vect, int left, int right)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    if(left<right)
    {
        int middle = left + (right-left)/2 ;

        mergeSort(temp, left, middle);
        mergeSort(temp, middle+1, right);

        merge(temp, left, middle, right);
    }

    return vect;
}

int partition(vector<int>& temp, int low, int high)
{
    int pivot = temp[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(temp[j] <= pivot)
        {
            i++;
            swap(temp[i],temp[j]);
        }
    }

    swap(temp[i+1],temp[high]);
    return i+1;
}

vector<int> quickSort(vector<int>& vect, int low, int high)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    if(low < high)
    {
        int PaIn = partition(vect, low, high);
        quickSort(vect, low, PaIn - 1);
        quickSort(vect, PaIn + 1, high);
    }

    return temp;
}

vector<int> heapSort(vector<int> vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    return vect;
}

void printVector(vector<int> vect)
{
    for(vector<int>::size_type i = 0 ; i < vect.size() ; i++)
    {
        cout << vect[i] << " ";
    }
}


int main()
{
    int orden;
    vector<int> vect = {123,2,43,45,65,6,77,0,9,110};

    cout << "Bienvenido a la carrera de algoritmos" << endl;
    cout << "Para elegir un ordenamiento ascendente ingrese 1 y para elegir un ordenamiento descendiente ingrese 2: ";
    cin >> orden;
    while(orden < 1 || orden > 2 )
    {
        cout << "Ingreso incorrecto, presione 1 para orden ascendente o 2 para descendente: ";
        cin >> orden;
    }
    cout << "Opcion elegida: ";
    if(orden == 1) cout << "Ascendente" << endl;
    else if(orden == 2) cout << "Descendiente" << endl;

    printVector(vect);

    cout << "COPIANDO" << endl;

    vector<int> bubbleS = bubbleSort(vect);

    printVector(bubbleS);

    return 0;
}