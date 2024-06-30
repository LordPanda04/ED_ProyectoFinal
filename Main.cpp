#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

//NO MOD - Movilidad del menú
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

//Estructura de nuestro inventario
typedef struct{
    std::string nombre;
    float precio;
    int cantidad;
}ARTICULO;

// Plantilla de funciones
void MenuPrincipal();
void hora(int x, int y);
int menu(const char* titulo, string opciones[], int n);
void Administrador(vector<ARTICULO> &);

//NO MOD - Función para los colores en las opciones
void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//NO MOD- Función para la posición de la impresión
void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

//NO MOD - Funcion para validar solo numeros
float validar(){
    int tecla;
    float real;
    bool flag = true;
    string valor = "", aux;    
    do{
        tecla = getch();
        switch(tecla){
            case 48:
                aux = "0";
                valor += aux; cout<<aux;
                break;
            case 49:
                aux = "1";
                valor += aux; cout<<aux;
                break;
            case 50:
                aux = "2";
                valor += aux; cout<<aux;
                break;
            case 51:
                aux = "3";
                valor += aux; cout<<aux;
                break;
            case 52:
                aux = "4";
                valor += aux; cout<<aux;
                break;
            case 53:
                aux = "5";
                valor += aux; cout<<aux;
                break;
            case 54:
                aux = "6";
                valor += aux; cout<<aux;
                break;
            case 55:
                aux = "7";
                valor += aux; cout<<aux;
                break;
            case 56:
                aux = "8";
                valor += aux; cout<<aux;
                break;
            case 57:
                aux = "9";
                valor += aux; cout<<aux;
                break;
            case 46:
                aux = ".";
                valor += aux; cout<<aux;
                break;
            case ENTER:
                flag = false;
                break;
        }
    }while(flag);

    if(valor == ""){
        cout<<"0";
        valor = "0";
    }
    real = std::stof(valor);
    return real;
}

//NO MOD - Main
int main() {
    MenuPrincipal();
    return 0;
}

//NO MOD - Función para los menús en común
int menu(const char* titulo, string opciones[], int n) {
    int opcion = 1;
    int tecla;
    bool flag = true;

    do {
        system("cls");
        color(10);
        gotoxy(42, 12);
        for (int i = 0; i < strlen(titulo) + 2; i++) {
            cout << "*";
        }

        gotoxy(43, 13);
        cout << titulo;

        gotoxy(42, 14);
        for (int i = 0; i < strlen(titulo) + 2; i++) {
            cout << "*";
        }

        color(7);
        for (int i = 0; i < n; i++) {
            if (15 + i == 14 + opcion) {
                color(10);
            }
            if (i + 1 == n) {
                gotoxy(38, 15 + i);
                cout << "[0] " << opciones[i];
            }
            else {
                gotoxy(38, 15 + i);
                cout << "[" << i + 1 << "] " << opciones[i];
            }
            color(7);
        }
        color(10);
        gotoxy(34, 14 + opcion);
        cout << "~>";

        color(7);
        do {
            tecla = getch();
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

        switch (tecla) {
        case ARRIBA: {
            opcion--;
            if (opcion == 0) {
                opcion = n;
            }
        } break;

        case ABAJO: {
            opcion++;
            if (opcion > n) {
                opcion = 1;
            }
        } break;

        case ENTER: {
            flag = false;
        } break;

        }

    } while (flag);
    return opcion;
}

// Implementación básica de MenuPrincipal
void MenuPrincipal() {
    vector<ARTICULO> items;
    short opcion;
    const char* titulo = "GESTION DE TIENDA";
    string opciones[] = { "Ingresar como ADMINISTRADOR", "Ingresar como TRABAJADOR", "Salir"};

    do {
        opcion = menu(titulo, opciones, 3);
        switch (opcion) {
        case 1: // Llamar función de Administrador
            Administrador(items);
            break;
        case 2: // Llamar función de Trabajador
            //Trabajador();
            break;
        case 3:
            system("cls");
            exit(0); // Salir del programa
            break;
        }
    } while (true);
}

void Administrador(vector<ARTICULO> &items){
    //Variables para el menú
    const char* titulo = "ADMINISTRADOR";
    string opciones[] = {"Agregar Productos", "Eliminar Productos", "Modificar Productos", 
    "Mostrar Productos", "Mostrar Historial de ventas", "Actualizar permisos de Trabajadores", "Regresar"};

    //Variables para el switch
    ARTICULO aux;
    int op;
    short opcion;
    do{
        opcion = menu(titulo, opciones, 7);
        switch(opcion){
            case 1:
                system("cls");
                color(10);
                gotoxy(15,1);
                cout<<"INGRESA LOS DATOS DEL ITEM"<<endl;
                gotoxy(15,2);
                cout<<"---------------------------"<<endl;

                gotoxy(10,4);
                cout<<" NOMBRE del ITEM: ";
                color(7);
                getline(cin, aux.nombre);

                gotoxy(10,5);
                color(10);
                cout<<" PRECIO del ITEM: ";
                color(7);
                aux.precio = validar();

                gotoxy(10,6);
                color(10);
                cout<<" STOCK del ITEM: "; 
                color(7);
                aux.cantidad = validar();

                items.push_back(aux);
        }

    }while(opcion != 7);
}