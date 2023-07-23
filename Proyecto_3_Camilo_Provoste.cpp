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

vector<int> selectionSort(vector<int>& vect, bool Asc);

vector<int> bubbleSort(vector<int>& vect, bool Asc);

vector<int> insertionSort(vector<int>& vect, bool Asc);

vector<int> shellSort(vector<int>& vect, bool Asc);

void merge(vector<int>& temp, size_t left, size_t middle, size_t right, bool Asc);

void mergeSortImpl(vector<int>& vect, size_t left, size_t right, bool Asc);

vector<int> mergeSort(vector<int>& vect, bool Asc);

size_t partition(vector<int>& temp, size_t low, size_t high, bool Asc);

void quickSortImpl(vector<int>& temp, size_t low, size_t high, bool Asc);

vector<int> quickSort(std::vector<int>& vect, bool Asc);

void heapify(vector<int>& temp, size_t n, size_t i, bool Asc);

vector<int> heapSort(vector<int> vect, bool Asc);

void printVector(vector<int> vect);


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

    cout << "Selection Sort: " << endl;
    vector<int> selectionS = selectionSort(vect, true);
    printVector(selectionS);

    cout << "Inverted Selection Sort: " << endl;
    vector<int> IselectionS = selectionSort(vect, false);
    printVector(IselectionS);

    cout << "Bubble Sort: " << endl;
    vector<int> bubbleS = bubbleSort(vect, true);
    printVector(bubbleS);

    cout << "Inverted Bubble Sort: " << endl;
    vector<int> IbubbleS = bubbleSort(vect, false);
    printVector(IbubbleS);

    cout << "Insertion Sort: " << endl;
    vector<int> insertionS = insertionSort(vect, true);
    printVector(insertionS);

    cout << "Inverted Insertion Sort: " << endl;
    vector<int> IinsertionS = insertionSort(vect, false);
    printVector(IinsertionS);

    cout << "Shell Sort: " << endl;
    vector<int> shellS = shellSort(vect, true);
    printVector(shellS);

    cout << "Inverted Shell Sort: " << endl;
    vector<int> IshellS = shellSort(vect, false);
    printVector(IshellS);

    cout << "Merge Sort: " << endl;
    vector<int> mergeS = mergeSort(vect, true);
    printVector(mergeS);

    cout << "Inverted Merge Sort: " << endl;
    vector<int> ImergeS = mergeSort(vect, false);
    printVector(ImergeS);

    cout << "Heap Sort: " << endl;
    vector<int> heapS = heapSort(vect, true);
    printVector(heapS);

    cout << "Inverted Heap Sort: " << endl;
    vector<int> IheapS = heapSort(vect, false);
    printVector(IheapS);

    cout << "Quick Sort: " << endl;
    vector<int> quickS = quickSort(vect, true);
    printVector(quickS);

    cout << "Inverted Quick Sort: " << endl;
    vector<int> IquickS = quickSort(vect, false);
    printVector(IquickS);


    return 0;
}

vector<int> selectionSort(vector<int>& vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();

    if(Asc)
    {
        for(size_t i = 0; i < s-1 ; i++)
        {
            size_t min = i;    
            for(size_t j = i+1 ; j < s; j++)
            {
                if(temp[j] < temp[min]) min = j;
            }

            if(min != i) swap(temp[min],temp[i]);
        }
    }
    else
    {
        for(size_t i = 0; i < s-1 ; i++)
        {
            size_t max = i;    
            for(size_t j = i+1 ; j < s; j++)
            {
                if(temp[j] > temp[max]) max = j;
            }

            if(max != i) swap(temp[i],temp[max]);
        }
    }
    return temp;
}

vector<int> bubbleSort(vector<int>& vect, bool Asc) 
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();
    bool swapped;

    if(Asc)
    {
        for (size_t i = 0; i < s - 1; i++) 
        {
            swapped = false;
            for (size_t j = 0; j < s - i - 1; j++) 
            {
                if (temp[j] > temp[j + 1]) 
                {
                    swap(temp[j], temp[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    else
    {
        for (size_t i = 0; i < s - 1; i++) 
        {
            swapped = false;
            for (size_t j = 0; j < s - i - 1; j++) 
            {
                if (temp[j] < temp[j + 1]) 
                {
                    swap(temp[j], temp[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    return temp;
}

vector<int> insertionSort(vector<int>& vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();

    if(Asc)
    {
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
    }
    else
    {
        for(size_t i = 1; i < s; i++)
        {
            int key = temp[i];
            size_t j = i-1;

            while(j != size_t(-1) && temp[j] < key)
            {
                temp[j+1] = temp[j];
                j--;
            }
            temp[j+1] = key;
        }
    }
    return temp;
}

vector<int> shellSort(vector<int>& vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();

    if(Asc)
    {
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
    }
    else
    {
        for(size_t gap = s/2 ; gap > 0; gap /= 2)
        {
            for(size_t i = gap; i < s; i++)
            {
                int aux = temp[i];
                size_t j;

                for(j = i; j >= gap && temp[j-gap] < aux; j -= gap)
                    temp[j] = temp[j-gap];

                temp[j] = aux;
            }
        }
    }

    return temp;
}

void merge(vector<int>& vect, size_t left, size_t middle, size_t right, bool Asc)
{
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    vector<int> L(n1), R(n2);

    for(size_t i = 0; i < n1; i++)
        L[i] = vect[left + i];

    for(size_t j = 0; j < n2; j++)
        R[j] = vect[middle + 1 + j];

    size_t i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if((Asc && (L[i] <= R[j])) || (!Asc && L[i] >= R[j]))
        {
            vect[k] = L[i];
            i++;
        }
        else
        {
            vect[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) 
    {
        vect[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        vect[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortImpl(vector<int>& vect, size_t left, size_t right, bool Asc)
{
    if(left<right)
    {
        size_t middle = left + (right-left)/2 ;

        mergeSortImpl(vect, left, middle, Asc);
        mergeSortImpl(vect, middle+1, right, Asc);

        merge(vect, left, middle, right, Asc);
    }
}

vector<int> mergeSort(vector<int>& vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    mergeSortImpl(temp, 0, temp.size() - 1, Asc);

    return temp;
}

size_t partition(std::vector<int>& temp, size_t low, size_t high, bool Asc)
{
    int pivot = temp[high];
    size_t i = low;

    for (size_t j = low; j < high; j++)
    {
        if(Asc)
        {
            if (temp[j] <= pivot)
            {
                swap(temp[i], temp[j]);
                i++;
            }
        }
        else
        {
            if (temp[j] >= pivot)
            {
                swap(temp[i], temp[j]);
                i++;
            }
        }
    }

    swap(temp[i], temp[high]);
    return i;
}

void quickSortImpl(vector<int>& temp, size_t low, size_t high, bool Asc)
{
    if (low < high)
    {
        size_t PaIn = partition(temp, low, high, Asc);
        if (PaIn > 0)
            quickSortImpl(temp, low, PaIn - 1, Asc);
        quickSortImpl(temp, PaIn + 1, high, Asc);
    }
}

vector<int> quickSort(std::vector<int>& vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    quickSortImpl(temp, 0, temp.size() - 1, Asc);
    return temp;
}

void heapify(vector<int>& temp, size_t n, size_t i, bool Asc)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if((left) < n && ((Asc && temp[left] > temp[largest]) || (!Asc && temp[left] < temp[largest]))) 
        largest = left;

    if((right) < n && ((Asc && temp[right] > temp[largest]) || (!Asc && temp[right] < temp[largest])))
        largest = right;

    if(largest != i)
    {
        swap(temp[i], temp[largest]);
        heapify(temp, n, largest, Asc);
    }
}

vector<int> heapSort(vector<int> vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();

    for(size_t i = s/2 - 1; i > 0; i--)
        heapify(temp, s, i - 1, Asc);

    for(size_t i = s-1; i > 0; i--)
    {
        swap(temp[0], temp[i]);
        heapify(temp, i, 0, Asc);
    }

    return temp;
}

void printVector(vector<int> vect)
{
    for(size_t i = 0 ; i < vect.size() ; i++)
    {
        cout << vect[i] << " ";
    }

    cout << endl;
}