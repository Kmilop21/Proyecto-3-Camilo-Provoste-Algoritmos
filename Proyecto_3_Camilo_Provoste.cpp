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

vector<float> carrera(vector<int> vect, bool Asc, bool skip);

class Data
{
    public:

        Data()
        {
            random_device rd;
            gen = mt19937(rd());
        }
        int getMax(int minR, int maxR)
        {
            uniform_int_distribution<int> dist(minR, maxR);
            return dist(gen);
        }
        void genAscDesc(int max, vector<int>& Ascendant, vector<int>& Descendant)
        {
            //Limpiando en caso de que tengan algo
            Ascendant.clear();
            Descendant.clear();

            //Generando los numeros
            for (int i = 0; i <= max; i++)
            {
                Ascendant.push_back(i);
            }

            //Copiandolo e invirtiendolo
            Descendant = Ascendant;
            reverse(Descendant.begin(), Descendant.end());
        }
        void randomWithDups(int max, vector<int>& RandomDup)
        {
            uniform_int_distribution<int> dist(0, max);

            for(int i = 0; i < max; i++)
            {
                int n = dist(gen);
                RandomDup.push_back(n);
            }
        }

        void randomWithoutDups(int max, vector<int>& RandomUnique)
        {
            RandomUnique.clear(); //En caso de que tenga algo
            for (size_t i = 0; i < static_cast<size_t>(max); i++) //Generando todos los numeros
            {
                RandomUnique.push_back(static_cast<int>(i));
            }
            
            //Usando el algoritmo "Fisher-Yates" para revolver el vector
            for (size_t i = static_cast<size_t>(max) - 1; i > 0; i--) 
            {
                uniform_int_distribution<size_t> dist(0, i);
                size_t j = dist(gen);
                swap(RandomUnique[i], RandomUnique[j]);
            }
        }

        struct Set
        {   
            int minR, maxR, max;
            struct Order
            {
                vector<int> vect;
                vector<float> time;
                vector<string> algorithm = {"Selection","Bubble","Insertion","Shell","Merge","Quick","Heap"};
            };
            Order Ascendant;
            Order Descendant;
            Order RandomDup;
            Order RandomUnique;
        };

        size_t findWinner(const Data::Set::Order& order, bool skip)
        {
            float lowestTime = numeric_limits<float>::max();
            size_t lowestTimeIndex = numeric_limits<size_t>::max();

            for (size_t i = 0; i < order.time.size(); i++)
            {
                if (skip && i == 5)
                {

                }
                else
                {
                    if (order.time[i] < lowestTime)
                    {
                        lowestTime = order.time[i];
                        lowestTimeIndex = i;
                    }
                }
            }
            return lowestTimeIndex;
        }
        
        void getResults(Data::Set::Order& order, bool skip)
        {
            for(size_t i = 0; i < order.time.size(); i++)
            {
                if(skip && i == 5)
                {
                    cout << "Saltado porque causa stack overflow" << endl;
                }
                else
                {
                    cout << "Algoritmo: " << order.algorithm[i] << "Sort " << " -- Tiempo: " << order.time[i] << "ml" << endl;
                }
            }
            
            cout << endl;
            size_t winnerIndex = findWinner(order, skip);
            cout << "***Algoritmo ganador: " << order.algorithm[winnerIndex] << "Sort " << " -- Tiempo: " << order.time[winnerIndex] << "ml" << endl;
            cout << endl << endl;
        }
        void initCarrera(bool Asc)
        {
            cout << "Carrera 1(rango de 90mil a 100mil): " << endl;
            cout << endl;
            cout << "Modo ordenado: " << endl; 
                set1.Ascendant.time = carrera(set1.Ascendant.vect,Asc,true);
                getResults(set1.Ascendant,true);
            cout << "Modo inversamente ordenado: " << endl;
                set1.Descendant.time = carrera(set1.Descendant.vect,Asc,true);
                getResults(set1.Descendant,true);
            cout << "Modo aleatorio con repeticion: " << endl;
                set1.RandomDup.time = carrera(set1.RandomDup.vect,Asc,true);
                getResults(set1.RandomDup,true);
            cout << "Modo aleatorio sin repeticion: " << endl;
                set1.RandomUnique.time = carrera(set1.RandomUnique.vect,Asc,true);
                getResults(set1.RandomUnique,true);

            cout << "Carrera 2(rango de 50mil a 70mil): " << endl;
            cout << endl;
            cout << "Modo ordenado: " << endl; 
                set2.Ascendant.time = carrera(set2.Ascendant.vect,Asc,true);
                getResults(set2.Ascendant,true);
            cout << "Modo inversamente ordenado: " << endl;
                set2.Descendant.time = carrera(set2.Descendant.vect,Asc,true);
                getResults(set2.Descendant,true);
            cout << "Modo aleatorio con repeticion: " << endl;
                set2.RandomDup.time = carrera(set2.RandomDup.vect,Asc,true);
                getResults(set2.RandomDup,true);
            cout << "Modo aleatorio sin repeticion: " << endl;
                set2.RandomUnique.time = carrera(set2.RandomUnique.vect,Asc,true);
                getResults(set2.RandomUnique,true);

            cout << "Carrera 3(rango de 500 a 1000): " << endl;
            cout << endl;
            cout << "Modo ordenado: " << endl; 
                set3.Ascendant.time = carrera(set3.Ascendant.vect,Asc,false);
                getResults(set3.Ascendant,false);
            cout << "Modo inversamente ordenado: " << endl;
                set3.Descendant.time = carrera(set3.Descendant.vect,Asc,false);
                getResults(set3.Descendant,false);
             cout << "Modo aleatorio con repeticion: " << endl;
                set3.RandomDup.time = carrera(set3.RandomDup.vect,Asc,false);
                getResults(set3.RandomDup,false);
            cout << "Modo aleatorio sin repeticion: " << endl;
                set3.RandomUnique.time = carrera(set3.RandomUnique.vect,Asc,false);
                getResults(set3.RandomUnique,false);
        }

        struct Set set1;
        struct Set set2;
        struct Set set3;

    private:
        mt19937 gen;
};



int main()
{
    //Generando toda la informacion de los sets
    Data info = Data();
    info.set1.minR = 90000; //Rango minimo
    info.set1.maxR = 100000; //Rango maximo
    info.set1.max = info.getMax(info.set1.minR,info.set1.maxR); //Generando maximo
    info.genAscDesc(info.set1.max, info.set1.Ascendant.vect, info.set1.Descendant.vect); //Set ascendiente y descendiente
    info.randomWithDups(info.set1.max,info.set1.RandomDup.vect); //Set random con duplicados
    info.randomWithoutDups(info.set1.max,info.set1.RandomUnique.vect); //Set random sin duplicados

    info.set2.minR = 50000; //Rango minimo
    info.set2.maxR = 70000; //Rango maximo
    info.set2.max = info.getMax(info.set2.minR,info.set2.maxR); //Generando maximo
    info.genAscDesc(info.set2.max, info.set2.Ascendant.vect, info.set2.Descendant.vect); //Set ascendiente y descendiente
    info.randomWithDups(info.set2.max,info.set2.RandomDup.vect); //Set random con duplicados
    info.randomWithoutDups(info.set2.max,info.set2.RandomUnique.vect); //Set random sin duplicados

    info.set3.minR = 500; //Rango minimo
    info.set3.maxR = 1000; //Rango maximo
    info.set3.max = info.getMax(info.set3.minR,info.set3.maxR); //Generando maximo
    info.genAscDesc(info.set3.max, info.set3.Ascendant.vect, info.set3.Descendant.vect); //Set ascendiente y descendiente
    info.randomWithDups(info.set3.max,info.set3.RandomDup.vect); //Set random con duplicados
    info.randomWithoutDups(info.set3.max,info.set3.RandomUnique.vect); //Set random sin duplicados

    int orden;
    bool Asc;

    cout << "Bienvenido a la carrera de algoritmos" << endl;
    cout << "Para elegir un ordenamiento ascendente ingrese 1 y para elegir un ordenamiento descendiente ingrese 2: ";
    cin >> orden;
    while(orden < 1 || orden > 2 )
    {
        cout << "Ingreso incorrecto, presione 1 para orden ascendente o 2 para descendente: ";
        cin >> orden;
    }
    cout << "Opcion elegida: ";
    if(orden == 1) 
    {
        cout << "Ascendente" << endl;
        Asc = true;
    }
    else if(orden == 2) 
    {
        cout << "Descendiente" << endl;
        Asc = false;
    }

    cout << endl;
    
    info.initCarrera(Asc);

    //carrera(info.set3.Ascendant.vect,Asc);

    return 0;
}

vector<int> selectionSort(vector<int>& vect, bool Asc)
{
    vector<int> temp;
    temp.assign(vect.begin(), vect.end());

    size_t s = temp.size();

    if(Asc) //Ascendente
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
    else //Descendente
    {
        for(size_t i = 0; i < s-1 ; i++)
        {
            size_t max = i;    
            for(size_t j = i+1 ; j < s; j++)
            {
                if(temp[j] > temp[max]) max = j; //Cambio en comparacion
            }

            if(max != i) swap(temp[i],temp[max]); //Cambio en swap
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

    if(Asc) //Ascendente
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
    else //Descendente
    {
        for (size_t i = 0; i < s - 1; i++) 
        {
            swapped = false;
            for (size_t j = 0; j < s - i - 1; j++) 
            {
                if (temp[j] < temp[j + 1]) //Cambio en comparacion
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

    if(Asc) //Ascendente
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
    else //Descendente
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

    if(Asc) //Ascendente
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
    else //Descendente
    {
        for(size_t gap = s/2 ; gap > 0; gap /= 2)
        {
            for(size_t i = gap; i < s; i++)
            {
                int aux = temp[i];
                size_t j;

                for(j = i; j >= gap && temp[j-gap] < aux; j -= gap) //Cambio en condicion
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

vector<float> carrera(vector<int> vect, bool Asc, bool skip)
{
    vector<float> times;
    for (int i = 0; i < 7; i++)
    {
        auto start = chrono::system_clock::now();
        switch (i)
        {
            case 0:
            {
                vector<int> selectionS = selectionSort(vect, Asc);
                break;
            }
            
            case 1:
            {
                vector<int> bubbleS = bubbleSort(vect, Asc);
                break;
            }

            case 2:
            {
                vector<int> insertionS = insertionSort(vect, Asc);
                break;
            }

            case 3:
            {
                vector<int> shellS = shellSort(vect, Asc);
                break;
            }

            case 4:
            {
                vector<int> mergeS = mergeSort(vect, Asc);
                break;
            }

            case 5:
            {
                //Quick sort da stack overflow en los primeros 2 sets (los mas grandes)
                if(!skip)
                {
                    vector<int> quickS = quickSort(vect, Asc);
                }
                break;
            }

            case 6:
            {
                vector<int> heapS = heapSort(vect, Asc);
                break;
            }
        }
        auto end = chrono::system_clock::now();

        chrono::duration<float,milli> duration = end - start;
        times.push_back(duration.count());
    }

    return times;
}