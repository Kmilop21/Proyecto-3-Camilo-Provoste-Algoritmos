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

    std::vector<int>::size_type s = temp.size();

    for(std::vector<int>::size_type i = 0; i < s-1 ; i++)
    {
        std::vector<int>::size_type min = i;    
        for(std::vector<int>::size_type j = i+1 ; i < s; j++)
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

    std::vector<int>::size_type s = temp.size();
    bool swapped;
    for (std::vector<int>::size_type i = 0; i < s - 1; i++) {
        swapped = false;
        for (std::vector<int>::size_type j = 0; j < s - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    return temp;
}

vector<int> insertionSort(vector<int> vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    std::vector<int>::size_type s = temp.size();

    for(std::vector<int>::size_type i = 1; i < s; i++)
    {
        int key = temp[i];
        std::vector<int>::size_type j = i-1;

        while(j >= 0 && temp[j] > key)
        {
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = key;
    }

    return temp;
}

vector<int> shellSort(vector<int> vect)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    std::vector<int>::size_type s = temp.size();

    for(std::vector<int>::size_type gap = s/2 ; gap > 0; gap /= 2)
    {
        for(std::vector<int>::size_type i = gap; i < s; i++)
        {
            std::vector<int>::size_type aux = temp[i];
            std::vector<int>::size_type j;

            for(j = i; j >= gap && temp[j-gap] > aux; j -= gap)
            {
                temp[j] = temp[j-gap];
            }
            temp[j] = aux;
        }
    }

    return temp;
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

    for(std::vector<int>::size_type i = 0 ; i < vect.size() ; i++)
    {
        cout << vect[i] << " ";
    }

    cout << "COPIANDO" << endl;

    vector<int> bubbleS = bubbleSort(vect);

    for(std::vector<int>::size_type i = 0; i < bubbleS.size() ; i++)
    {
        cout << bubbleS[i] << " ";
    }

    return 0;
}