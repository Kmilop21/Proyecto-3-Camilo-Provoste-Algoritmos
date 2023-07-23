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

    size_t s = temp.size();

    for(size_t i = 0; i < s-1 ; i++)
    {
        size_t min = i;    
        for(size_t j = i+1 ; i < s; j++)
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

    size_t s = temp.size();
    bool swapped;
    for (size_t i = 0; i < s - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < s - i - 1; j++) {
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

    size_t s = temp.size();

    for(size_t i = 1; i < s; i++)
    {
        int key = temp[i];
        size_t j = i-1;

        while(j != size_t(-1) && temp[j] > key)
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

    size_t s = temp.size();

    for(size_t gap = s/2 ; gap > 0; gap /= 2)
    {
        for(size_t i = gap; i < s; i++)
        {
            int aux = temp[i];
            size_t j;

            for(j = i; j >= gap && temp[j-gap] > aux; j -= gap)
            {
                temp[j] = temp[j-gap];
            }
            temp[j] = aux;
        }
    }

    return temp;
}

void merge(vector<int>& temp, size_t left, size_t middle, size_t right)
{
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    vector<int> L(n1), R(n2);

    for(size_t i = 0; i < n1; i++)
        L[i] = temp[left+1];

    for(size_t j = 0; j < n2; j++)
        R[j] = temp[middle + 1 + j];

    size_t i = 0, j = 0, k = left;

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

vector<int> mergeSort(vector<int>& vect, size_t left, size_t right)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    if(left<right)
    {
        size_t middle = left + (right-left)/2 ;

        mergeSort(temp, left, middle);
        mergeSort(temp, middle+1, right);

        merge(temp, left, middle, right);
    }

    return vect;
}

size_t partition(vector<int>& temp, size_t low, size_t high) 
{
    int pivot = temp[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) 
    {
        if (temp[j] <= pivot)
        {
            i++;
            swap(temp[i], temp[j]);
        }
    }

    swap(temp[i + 1], temp[high]);
    return i + 1;
}

void quickSortImpl(vector<int>& temp, size_t low, size_t high)
{
    if (low < high)
    {
        size_t PaIn = partition(temp, low, high);
        quickSortImpl(temp, low, PaIn - 1);
        quickSortImpl(temp, PaIn + 1, high);
    }
}

vector<int> quickSort(std::vector<int>& vect)
{
    vector<int> temp = vect; 

    quickSortImpl(temp, 0, temp.size() - 1);

    return temp;
}

void heapify(vector<int>& temp, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && temp[left] > temp[largest]) largest = left;

    if(right < n && temp[right] > temp[largest]) largest = right;

    if(largest != i)
    {
        swap(temp[i], temp[largest]);
    }
}

vector<int> heapSort(vector<int> vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();

    for(size_t i = s/2 - 1; i >= 0; i--)
        heapify(temp,s,i);

    for(size_t i = s-1; i > 0; i--)
    {
        swap(vect[0], vect[i]);
        heapify(temp, i, 0);
    }

    return vect;
}

void printVector(vector<int> vect)
{
    for(size_t i = 0 ; i < vect.size() ; i++)
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