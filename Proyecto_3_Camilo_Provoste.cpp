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

    std::vector<int>::size_type n = temp.size();

    for(std::vector<int>::size_type i = 0; i < n-1 ; i++)
    {
        std::vector<int>::size_type min = i;    
        for(std::vector<int>::size_type j = i+1 ; i < n; j++)
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




int main()
{
    int orden;
    vector<int> vect = {1,2,3,4,5,6,7,8,9,10};

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