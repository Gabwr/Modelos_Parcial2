#define dim 100
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

// Prototipos de funciones
void LlenarArregloQuickSort(int A[dim]);
void Quicksort(int A[dim], int primero, int ultimo);
void mostrarArreglo(int A[dim], int tamanio);
void Menu_Principal();
void gotoxy(int x, int y);
int Menu(const char* titulo, const char* opciones[], int tamanio);
void Induccion();
void CalcularCombinacion();
void BusquedaSecuencial();
unsigned long long factorial(int num);
unsigned long long combinacion(int n, int r);

int main()
{
    Menu_Principal();
    return 0;
}

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para mostrar el menú y manejar la navegación
int Menu(const char* titulo, const char* opciones[], int tamanio)
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
            tecla = _getch();  // Reemplazo de getch() por _getch()
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

// Función principal del menú
void Menu_Principal()
{
    bool seguir = true;

    const char* titulo = "Menu Principal";
    const char* opciones[] = { "Permutacion", "Combinacion", "Recursion", "Induccion", "Ordenacion", "Busqueda", "Salir" };
    int opcion, numop = 7, A[dim];
    do
    {
        opcion = Menu(titulo, opciones, numop);
        switch (opcion)
        {
        case 1:
            // Placeholder para Permutacion
            break;
        case 2:
            CalcularCombinacion();
            break;
        case 3:
            // Placeholder para Recursion
            break;
        case 4:
            Induccion();
            break;
        case 5:
            LlenarArregloQuickSort(A);
            break;
        case 6:
            BusquedaSecuencial();
            break;
        case 7:
            seguir = false;
            break;
        }
        system("pause");
    } while (seguir);
}

// Función para llenar un arreglo y ordenarlo usando QuickSort
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

// Algoritmo de QuickSort para ordenar un arreglo
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

// Función para mostrar un arreglo
void mostrarArreglo(int A[dim], int tamanio)
{
    for (int i = 0; i <= tamanio - 1; i++)
    {
        cout << A[i] << " ";
    }
}

// Ejemplo de función de inducción matemática
void Induccion()
{
    int cont = 0, aux, n;
    bool aprobar;
    cout << "Comprobar que todos los numeros pares pueden ser representados con 2n,\n";
    cout << "donde n son valores naturales desde el -inf hasta el inf";

    cout << "Paso 1, n=1" << endl;
    n = 1;
    cout << "f(1)= 2*1" << endl;
    cout << "f(1)=" << 2 * n << endl;
    cout << "Paso 2, k=n";
    cout << "Paso 3, probar que ";
    cout << "f(k+1)-f(k)" << endl;
    cout << "2(k+1)-2k=2n" << endl;
    cout << "2k+2-2k=2n" << endl;
    cout << "2=2n" << endl;
    cout << "Volviendo al menu principal";
}

// Función para calcular el factorial de un número
unsigned long long factorial(int num)
{
    if (num == 0)
        return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;
    return result;
}

// Función para calcular las combinaciones (nCr)
unsigned long long combinacion(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Función para calcular y mostrar las combinaciones
void CalcularCombinacion()
{
    int n, r;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Ingrese el valor de r: ";
    cin >> r;

    if (r > n || n < 0 || r < 0)
    {
        cout << "Valores invalidos. Asegurese de que n >= r y ambos sean no negativos." << endl;
        return;
    }

    unsigned long long resultado = combinacion(n, r);
    cout << "Las combinaciones de " << n << " sobre " << r << " son: " << resultado << endl;
}

// Función para realizar la búsqueda secuencial en un arreglo
void BusquedaSecuencial()
{
    int A[dim], tamanio, numero, posicion = -1;
    cout << "Ingrese el tamaño del arreglo (1 - 100): ";
    cin >> tamanio;

    if (tamanio < 1 || tamanio > 100) {
        cout << "Tamaño invalido. Volviendo al menu principal." << endl;
        return;
    }

    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> A[i];
    }

    cout << "Ingrese el numero a buscar: ";
    cin >> numero;

    // Búsqueda secuencial
    for (int i = 0; i < tamanio; i++)
    {
        if (A[i] == numero)
        {
            posicion = i;
            break;
        }
    }

    // Mostrar resultado
    if (posicion != -1)
    {
        cout << "El numero " << numero << " se encuentra en la posicion " << posicion + 1 << " del arreglo." << endl;
    }
    else
    {
        cout << "El numero " << numero << " no se encuentra en el arreglo." << endl;
    }
}

