#define dim 100
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <math.h>
using namespace std;
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

void LlenarArregloQuickSort(int A[dim]);
void Recursion();
void Permuta();
void Quicksort(int A[dim], int primero, int ultimo);
void mostrarArreglo(int A[dim], int tamanio);
void Menu_Principal();
void gotoxy(int x, int y);
int Menu(const char *titulo, const char *opciones[], int tamanio);
void Induccion();

int main()
{
    Menu_Principal();
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Menu(const char *titulo, const char *opciones[], int tamanio)
{
    int opcionSelec = 1, tecla;
    bool seguir = true;
    do
    {
        system("cls");
        gotoxy(5, 3 + opcionSelec);
        cout << ">";

        gotoxy(20, 2);
        cout << titulo;
        for (int i = 0; i < tamanio; i++)
        {
            gotoxy(10, 4 + i);
            cout << i + 1 << ") " << opciones[i];
        }
        do
        {
            tecla = getch();
        } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

        switch (tecla)
        {
        case TECLA_ARRIBA:
            opcionSelec--;
            if (opcionSelec < 1)
            {
                opcionSelec = tamanio;
            }
            break;
        case TECLA_ABAJO:
            opcionSelec++;
            if (opcionSelec > tamanio)
            {
                opcionSelec = 1;
            }
            break;
        case ENTER:
            seguir = false;
            break;
        }
    } while (seguir);
    return opcionSelec;
}

void Menu_Principal()
{
    bool seguir = true;

    const char *titulo = "Menu Principal";
    const char *opciones[] = {"Permutacion", "Combinacion", "Recursion", "Induccion", "Ordenacion", "Busqueda", "Salir"};
    int opcion, numop = 7, A[dim];
    do
    {
        opcion = Menu(titulo, opciones, numop);
        switch (opcion)
        {
        case 1:
            Permuta();
            break;
        case 2:

            break;
        case 3:
            Recursion();
            break;
        case 4:
            Induccion();
            break;
        case 5:
            LlenarArregloQuickSort(A);
            break;
        case 6:

            break;
        case 7:
            seguir = false;
            break;
        }
    } while (seguir);
}

void LlenarArregloQuickSort(int A[dim])
{
    int tamanio = -1;

    while (tamanio < 0 || tamanio > 100)
    {
        cout << "Cuantos datos desea ordenar?(Colocar valores positivos)" << endl;
        cin >> tamanio;
    }

    for (int i = 0; i < tamanio; i++)
    {
        cout << "\nColoque el elemento: " << i + 1;
        cin >> A[i];
    }

    cout << "\nSu arrreglo es:" << endl;
    mostrarArreglo(A, tamanio);

    Quicksort(A, 0, tamanio - 1);

    cout << "\nSu arrreglo Ordenado es:" << endl;
    mostrarArreglo(A, tamanio);
}

void Quicksort(int A[dim], int primero, int ultimo)
{
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
        Quicksort(A, i, ultimo);
        Quicksort(A, primero, j);
    }
}

void mostrarArreglo(int A[dim], int tamanio)
{
    for (int i = 0; i <= tamanio - 1; i++)
    {
        cout << A[i] << " ";
    }
}

void Induccion()
{
    int  cont = 0,aux,n;
    bool aprobar;
    cout << "Comprobar que todos los numeros pares pueden ser representados con 2n,\n";
    cout << "donde n son valores naturales desde el -inf hasta el inf";

        cout<<"Paso 1, n=1"<<endl;
        n=1;
        cout<<"f(1)= 2*1"<<endl;
        cout<<"f(1)="<<2*n<<endl;
        cout<<"Paso 2, k=n";
        cout<<"Paso 3, probar que ";
        cout<<"f(k+1)-f(k)"<<endl;
        cout<<"2(k+1)-2k=2n"<<endl;
        cout<<"2k+2-2k=2n"<<endl;
        cout<<"2=2n"<<endl;
        cout<<"Volviendo al menu principal";
        system("pause");
}


// Función recursiva para calcular el n-ésimo número de Fibonacci
long long fibonacci(int n) {
    if (n == 0) return 0; // Caso base 1
    if (n == 1) return 1; // Caso base 2
    return fibonacci(n - 1) + fibonacci(n - 2); // Paso recursivo
}

void Recursion() {
    int n;
    cout << "Ingrese el valor de n para calcular el n-ésimo número de Fibonacci: ";
    cin >> n;

    // Verificar que el usuario ingrese un número no negativo
    if (n < 0) {
        cout << "Por favor, ingrese un número no negativo." << std::endl;
    } else {
        cout << "El " << n << "-ésimo número de Fibonacci es: " << fibonacci(n) << endl;
    }
}

// Función para calcular factorial
long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
// Permutaciones normales
long long permutacionNormal(int n, int r) {
    return factorial(n) / factorial(n - r);
}
// Permutaciones circulares
long long permutacionCircular(int n) {
    return factorial(n - 1);
}
// Permutaciones con repetición
long long permutacionConRepeticion(int n, int r) {
    return pow(n, r);
}

void Permuta() {
    int opcion, n, r;

    std::cout << "Seleccione el tipo de permutación:\n";
    std::cout << "1. Normal\n2. Circular\n3. Con repetición\n";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            std::cout << "Ingrese n y r: ";
            std::cin >> n >> r;
            std::cout << "Permutación normal: " << permutacionNormal(n, r) << std::endl;
            break;
        case 2:
            std::cout << "Ingrese n: ";
            std::cin >> n;
            std::cout << "Permutación circular: " << permutacionCircular(n) << std::endl;
            break;
        case 3:
            std::cout << "Ingrese n y r: ";
            std::cin >> n >> r;
            std::cout << "Permutación con repetición: " << permutacionConRepeticion(n, r) << std::endl;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
    }
}