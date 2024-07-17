#define dim 100
#include <iostream>
using namespace std;

void LlenarArreglo(int A[dim]);
void Quicksort( int A[dim], int primero, int ultimo);
void mostrarArreglo(int A[dim]);
int main(){

    return 0;
}

void LlenarArregloQuickSoert(int A[dim]){
    int tamanio=-1;

    while(tamanio<0||tamanio>100){
    cout<<"Cuantos datos desea ordenar?(Colocar valores positivos)"<<endl;
    cin>>tamanio;
    }

    for(int i=0;i<tamanio;i++){
        cout<<"\nColoque el elemento: "<<i+1;
        cin>>A[i];
    }
    
    cout<<"\nSu arrreglo es:"<<endl;
    mostrarArreglo(A,tamanio);

    Quicksort(A,0,tamanio-1 );

    cout<<"\nSu arrreglo Ordenado es:"<<endl;
    mostrarArreglo(A,tamanio);
}

void Quicksort( int A[dim], int primero, int ultimo){
    int posipivote = (primero + ultimo) / 2;
    int pivote = A[posipivote], i = primero, j = ultimo, aux;

    do
    {
        while (A[i] < pivote)
        {
            i++;
        }
        while (A[j] > pivote)
        {
            j--;
        }
        if (i <= j)
        {
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    } while (i < j);
    i++;
    j--;
    if (j < primero)
    {
        return;
    }
    else if (i == ultimo)
    {
        return;
    }
    else
    {
        Quicksort( A, i, ultimo);
        Quicksort( A, primero, j);
    }
}

void mostrarArreglo(int A[dim], int tamanio)
{

    for (int i = 0; i <= tamanio - 1; i++)
    {
        cout << A[i] <<" ";
    }
}