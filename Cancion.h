
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#ifndef CANCION_H
#define CANCION_H

#endif
struct Song
{
    int id;
    string nombre;
    string path;
    Song *next;
};
class HandlerSong
{
private:
    Song *start;
    int currentId;

public:
    HandlerSong()
    {
        start = NULL;
        currentId = 0;
    }
    void addSong()
    {
        Song *temp, *ptr;
        string name;
        string pathTmp;
        temp = (Song *)malloc(sizeof(Song));
        if (temp == nullptr)
        {
            cout << "Sin espacio de memoria" << endl;
            exit(0);
        }

        cout << "Ingrese el nombre de la cancion: ";
        cin >> name;
        cout << "Ingrese el path de la cancion: ";
        cin >> pathTmp;
        int id = ++currentId;
        temp = new Song{id, name, pathTmp, NULL};
        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next; // Recorremos hasta llegar al ultimo nodo
            }
            ptr->next = temp; // luego de tener el ultimo nodo el siguiente sera temp
            // y asi se cumple insertar al final
        }
    }

    void displaySongs()
    {
        Song *ptr;
        if (start == NULL)
        {
            cout << "   La lista esta vacia" << endl;
            return;
        }
        else
        {
            ptr = start;
            cout << "Canciones: " << endl;
            while (ptr != NULL)
            {
                cout << " Indice: " << ptr->id << ", Nombre: " << ptr->nombre << ", Path: " + ptr->path << endl;
                ptr = ptr->next;
            }
        }
    }

    void findWithName()
    {
        Song *ptr;
        string name;
        if (start == NULL)
        {
            cout << "   La lista esta vacia" << endl;
            return;
        }
        else
        {
            cout << "   Ingrese el nombre que desea buscar: ";
            cin >> name;
            ptr = start;
            while (ptr != NULL)
            {
                if (ptr->nombre == name)
                {
                    cout << "Cancion encontrada " << endl;
                    cout << "Indice: " << ptr->id << ", Nombre: " << ptr->nombre << ", Path: " + ptr->path << endl;
                    return;
                }
                ptr = ptr->next;
            }
            cout << "Cancion no encontrada " << endl;
        }
    }

    void deleteCancion()
    {
        if (start == NULL)
        {
            cout << "   La lista esta vacia" << endl;
            return;
        }
        int opcion = 0;
        Song *temp, *ptr;
        string n;
        cout << "   1.Eliminar por id" << endl;
        cout << "   2.Eliminar por nombre" << endl;
        cout << "   3.Regresar" << endl;
        cout << "   Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            int pos;

            cout << "       Ingrese el id: ";
            cin >> pos;
            if (!cin)
            {
                cout << "       Error, no ha ingresado un numero" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                return;
            }

            ptr = start;
            while (ptr != NULL && ptr->id != pos)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "Cancion no encontrada" << endl;
                return;
            }
            if (ptr == start)
            {
                cout << "Cancion eliminada: " << ptr->nombre << endl;
                start = start->next;
            }
            else
            {
                cout << "Cancion eliminada: " << ptr->nombre << endl;
                temp->next = ptr->next;
            }

            delete ptr;

            break;
        case 2:

            cout << "       Ingrese el nombre: ";
            cin >> n;
            ptr = start;

            while (ptr != NULL && ptr->nombre != n)
            {
                temp = ptr;
                ptr = ptr->next;
            }

            if (ptr == NULL)
            {
                cout << "Cancion no encontrada" << endl;
                return;
            }

            if (ptr == start)
            {
                cout << "Cancion eliminada: " << ptr->nombre << endl;
                start = start->next;
            }
            else
            {
                cout << "Cancion eliminada: " << ptr->nombre << endl;
                temp->next = ptr->next;
            }
            delete ptr;
            break;
        default:
            break;
        }
    }
};