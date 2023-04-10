
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#ifndef SONG_H
#define SONG_H

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

    void addSongToFile(string name, string pathTmp, int pos = 0)
    {
        Song *temp, *ptr;
        temp = (Song *)malloc(sizeof(Song));
        if (temp == nullptr)
        {
            cout << "Sin espacio de memoria" << endl;
            exit(0);
        }
        int id;
        if (pos == 0)
        {
            id = ++currentId;
        }
        else
        {
            id = pos;
            ++currentId;
        }

        if (start == NULL)
        {
            temp = new Song{id, name, pathTmp, NULL};
            start = temp;
            cout << "Cancion Agregada como primera!!" << endl;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next; // Recorremos hasta llegar al ultimo nodo
            }
            if ((ptr->id + 1) == id)
            {
                temp = new Song{id, name, pathTmp, NULL};
                ptr->next = temp; // luego de tener el ultimo nodo el siguiente sera temp
                // y asi se cumple insertar al final
                cout << "Cancion Agregada!!" << endl;
            }
            else if (id <= ptr->id)
            {
                temp = new Song{id, name, pathTmp, NULL};
                ptr = start;
                while (ptr->id != id)
                {
                    ptr = ptr->next;
                }
                if(ptr==start){
                    temp->next=start;
                    start=temp;
                } else {
                    Song* backSong=start;
                    while(backSong->next!=ptr){
                        backSong=backSong->next;
                    }
                    temp->next=ptr;
                    backSong->next=temp;
                }
                //temp->next = ptr->next;
                //ptr->next = temp;
                Song *temp2 =temp->next;
                while (temp2 != nullptr)
                {
                    int id = temp2->id;
                    temp2->id = ++id;
                    temp2 = temp2->next;
                }
                cout << "Cancion Agregada!!" << endl;
            }
            else
            {
                cout << "La posicion: " << id - 1 << " no existe por lo tanto no se puede ingresar una cancion en la posicion: " << id << endl;
            }
        }
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
        cin.ignore();
        getline(cin, name);
        cout << "Ingrese el path de la cancion: ";
        getline(cin, pathTmp);
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
            cout << "Canciones en store: " << endl;
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

    Song *findWithId(int id)
    {
        Song *ptr = start;
        if (start == NULL)
        {
            cout << "   La lista esta vacia" << endl;
            return ptr;
        }

        ptr = start;
        while (ptr != NULL)
        {
            if (ptr->id == id)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
        cout << "Cancion no encontrada " << endl;
        return nullptr;
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
                cout << "   Cancion no encontrada" << endl;
                return;
            }
            if (ptr == start)
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                start = start->next;
            }
            else
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
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
                cout << "       Cancion no encontrada" << endl;
                return;
            }

            if (ptr == start)
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                start = start->next;
            }
            else
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                temp->next = ptr->next;
            }
            delete ptr;
            break;
        default:
            break;
        }
    }

    void deleteSongToFile(int opcion, int id, string nombre)
    {
        if (start == NULL)
        {
            cout << "   Store de canciones esta vacia" << endl;
            return;
        }
        Song *temp, *ptr;
        if (opcion == 1)
        {
            ptr = start;
            while (ptr != NULL && ptr->id != id)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "   Cancion no encontrada" << endl;
                return;
            }
            if (ptr == start)
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                start = start->next;
            }
            else
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                temp->next = ptr->next;
            }
            delete ptr;
        }
        else if (opcion == 2)
        {
            ptr = start;

            while (ptr != NULL && ptr->nombre != nombre)
            {
                temp = ptr;
                ptr = ptr->next;
            }

            if (ptr == NULL)
            {
                cout << "       Cancion no encontrada" << endl;
                return;
            }

            if (ptr == start)
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                start = start->next;
            }
            else
            {
                cout << "       Cancion eliminada: " << ptr->nombre << endl;
                temp->next = ptr->next;
            }
            delete ptr;
        }
    }
    Song *getStart()
    {
        return start;
    }
};
#endif
