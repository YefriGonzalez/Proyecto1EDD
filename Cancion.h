
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#ifndef CANCION_H
#define CANCION_H

#endif

struct Cancion
{
    string nombre;
    string path;
    int pos;
    Cancion *siguiente;
    Cancion *start=nullptr;


    void insertCancion()
    {
        static int posGen=0;
        int posTmp=posGen;        
        Cancion *temp, *ptr;
        
        ptr=new Cancion();
        string nombre;
        string path;
        temp = (Cancion *)malloc(sizeof(Cancion));
        if (temp == nullptr)
        {
            cout << "Sin espacio de memoria" << endl;
            exit(0);
        }
        cout << "Ingrese el nombre de la cancion: ";
        cin >> nombre;
        cout << "Ingrese el path de la cancion: ";
        cin >> path;
        temp=new Cancion{nombre,path,posTmp,nullptr};
        posGen++;
        if (start == nullptr)
        { 
            start = temp;
        }
        else
        {
            ptr = start;
            while (ptr->siguiente != nullptr)
            {
                ptr = ptr->siguiente; // Recorremos hasta llegar al ultimo nodo
            }
            ptr->siguiente = temp; // luego de tener el ultimo nodo el siguiente sera temp
            // y asi se cumple insertar al final
        }
    }

    void deleteCancion()
    {
        int opcion = 0;
        cout << "   1.Eliminar por id" << endl;
        cout << "   2.Eliminar por nombre" << endl;
        cout << "   3.Regresar" << endl;
        cout << "   Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // int id;
            cout << "   Ingrese el id: " << endl;

            break;
        case 2:
            cout << "   Ingrese el nombre: " << endl;
            break;
        case 3:
            break;
        default:
            break;
        }
    }
    void displaySongs()
    {
        Cancion *ptr;
        if (start == nullptr)
        {
            cout << "   La lista esta vacia"<<endl;
            return;
        }
        else
        {
            ptr = start;
            cout << "Canciones: " << endl;
            while (ptr != nullptr)
            {
                cout <<" Posicion: "+ptr->pos ;
                cout <<", Nombre: "+ ptr->nombre;
                cout <<", Path: "+ ptr->path << endl;
                ptr = ptr->siguiente;
            }
        }
    }

    void findWithName(){
        Cancion *ptr;
        string nombre;
        if (start == nullptr)
        {
            cout << "   La lista esta vacia"<<endl;
            return;
        }
        else
        {
            cout << "   Ingrese el nombre que desea buscar: ";
            cin >> nombre;
            ptr = start;
            while (ptr != nullptr)
            {
                if (ptr->nombre==nombre)
                {
                    cout <<"Cancion encontrada "<<endl;
                    cout <<"Nombre: "+ ptr->nombre;
                    cout <<", Path: "+ ptr->path << endl; 
                    return;   
                }
                ptr = ptr->siguiente;
            }
            cout <<"Cancion no encontrada "<<endl;
        }
    }
};
