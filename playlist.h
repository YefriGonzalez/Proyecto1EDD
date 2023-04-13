#include <string>

#include "listacanciones.h"
#ifndef PLAYLIST_H
#define PLAYLIST_H

struct PlayList
{
    int id;
    string name;
    string description;
    ListSongs *listSongs;
    PlayList *next;
    PlayList(int idP, string nameP, string descriptionP)
    {
        this->id = idP;
        this->name = nameP;
        this->description = descriptionP;
        this->listSongs = new ListSongs();
        this->next = nullptr;
    }
    void addSong(HandlerSong handlerSong)
    {
        int idTmp;
        handlerSong.displaySongs();
        cout << "   Ingrese el id de la cancion que desea agregar o 0 para salir: ";
        cin >> idTmp;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(0, '\n');
        }
        while (idTmp != 0)
        {
            Song *song = handlerSong.findWithId(idTmp);
            if (song != nullptr)
            {
                listSongs->addSong(song);
            }
            else
            {
                cout << "Cancion no encontrada " << endl;
            }
            handlerSong.displaySongs();
            cout << "   Ingrese el id de la cancion que desea agregar o 0 para salir: ";
            cin >> idTmp;
            if (!cin)
            {
                cout << "       Error, no ha ingresado un numero" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                break;
            }
        }
    }

    void addSongToFile(int idSong, HandlerSong handlerSong)
    {
        Song *song = handlerSong.findWithId(idSong);
        if (song != nullptr)
        {
            listSongs->addSong(song);
        }
        else
        {
            cout << "Cancion no encontrada " << endl;
        }
    }
    void deleteSong()
    {
        int idTmp;
        listSongs->displaySongs();
        cout << "   Ingrese el id de la cancion que desea eliminar o presione 0 para salir: ";
        cin >> idTmp;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(0, '\n');
        }
        while (idTmp != 0)
        {
            Song *song = listSongs->findWithId(idTmp);
            if (song != nullptr)
            {
                listSongs->deleteSong(song->nombre);
            }
            else
            {
                cout << "   Cancion no encontrada en la playlist " << endl;
            }
            listSongs->displaySongs();
            cout << "   Ingrese el id de la cancion que desea eliminar o 0 para salir: ";
            cin >> idTmp;
            if (!cin)
            {
                cout << "       Error, no ha ingresado un numero" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }
    }

    void deleteSongToFile(int idSong)
    {
        Song *song = listSongs->findWithId(idSong);
        if (song != nullptr)
        {
            listSongs->deleteSong(song->nombre);
        }
        else
        {
            cout << "   Cancion no encontrada en la playlist " << endl;
        }
    }

    void ediPlayList()
    {
        cout << "   Ingrese el nuevo nombre de la lista: ";
        cin.ignore();
        getline(cin, this->name);
        cout << "   Ingrese la descripcion de la lista: ";
        getline(cin, this->description);
    }
};
class HandlerPlayList
{
    PlayList *start;
    int currentId;

public:
    HandlerPlayList()
    {
        start = nullptr;
        play=nullptr;
        currentId = 0;
    }

    void addPlayList(HandlerSong handlerSong)
    {
        string n;
        string descri;
        PlayList *ptr;
        cout << "   Ingrese el nombre de la playlist: ";
        cin.ignore();
        getline(cin, n);
        cout << "   Ingrese la descripcion de la playlist: ";
        getline(cin, descri);
        int id = ++currentId;
        PlayList *list = new PlayList(id, n, descri);
        int opcion;
        cout << "   Desea agregar canciones? 1.Si      2.No: ";
        cin >> opcion;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            return;
        }
        if (opcion == 1)
        {
            list->addSong(handlerSong);
        }
        if (start == nullptr)
        {
            start = list;
        }
        else
        {
            ptr = start;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = list;
        }
    }

    int addPlayListToFile(HandlerSong handlerSong, string n, string d)
    {
        PlayList *ptr;
        int id = ++currentId;
        PlayList *list = new PlayList(id, n, d);
        if (start == nullptr)
        {
            start = list;
        }
        else
        {
            ptr = start;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = list;
        }
        return id;
    }
    void displayListSimple()
    {
        PlayList *ptr;
        ptr = start;
        if (start == nullptr)
        {
            cout << "   No hay playlists" << endl;
            return;
        }
        cout << "PlayLists : " << endl;
        while (ptr != NULL)
        {
            cout << "       Indice: " << ptr->id << ", Nombre: " << ptr->name << ", Descripcion: " + ptr->description << endl;
            ptr = ptr->next;
        }
    }
    void displayLists()
    {
        PlayList *ptr;
        if (start == nullptr)
        {
            cout << "   No hay playlists" << endl;
            return;
        }
        int option;

        cout << "   1.Ver PlayLists" << endl;
        cout << "   2.Ver canciones de una Playlist" << endl;
        cout << "   0.Regresar" << endl;
        cout << "   Ingrese la opcion: ";
        cin >> option;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            return;
        }

        if (option == 1)
        {
            this->displayListSimple();
        }
        else if (option == 2)
        {
            ptr = start;
            while (ptr != NULL)
            {
                cout << "       Indice: " << ptr->id << ", Nombre: " << ptr->name << ", Descripcion: " + ptr->description << endl;
                ptr = ptr->next;
            }
            int idTmp;
            cout << "       Ingrese el id de la Playlist para ver sus canciones: ";
            cin >> idTmp;
            if (!cin)
            {
                cout << "       Error, no ha ingresado un numero" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                return;
            }
            ptr = start;
            while (ptr != NULL && ptr->id != idTmp)
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "PlayList no encontrada" << endl;
                return;
            }
            if (ptr == start)
            {
                start->listSongs->displaySongs();
            }
            else
            {
                ptr->listSongs->displaySongs();
            }
        }
    }

    void deletePlayList()
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        PlayList *ptr = start;
        PlayList *temp;
        int id;
        this->displayListSimple();
        cout << "       Ingrese el id de la Play List que desea eliminar: ";
        cin >> id;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (ptr != NULL && ptr->id != id)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (ptr == start)
        {
            cout << "       PlayList eliminada: " << ptr->name << endl;
            start = start->next;
        }
        else
        {
            cout << "       PlayList eliminada: " << ptr->name << endl;
            temp->next = ptr->next;
        }
        delete ptr;
    }

    void deletePlayListToFile(int option, int idPlayList, string namePlayList)
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        PlayList *ptr = start;
        PlayList *temp;
        if (option == 1)
        {
            while (ptr != NULL && ptr->id != idPlayList)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "       PlayList no encontrada" << endl;
                return;
            }
            if (ptr == start)
            {
                cout << "       PlayList eliminada: " << ptr->name << endl;
                start = start->next;
            }
            else
            {
                cout << "       PlayList eliminada: " << ptr->name << endl;
                temp->next = ptr->next;
            }
            delete ptr;
        }
        else if (option == 2)
        {
            while (ptr != NULL && ptr->name != namePlayList)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "       PlayList no encontrada" << endl;
                return;
            }
            if (ptr == start)
            {
                cout << "       PlayList eliminada: " << ptr->name << endl;
                start = start->next;
            }
            else
            {
                cout << "       PlayList eliminada: " << ptr->name << endl;
                temp->next = ptr->next;
            }
            delete ptr;
        }
    }
    void editPlayList()
    {
        if (start == NULL)
        {
            cout << "   La lista esta vacia" << endl;
            return;
        }
        int id;
        this->displayListSimple();
        cout << "       Ingrese el id de la Play List que desea editar: ";
        cin >> id;
        PlayList *ptr;
        ptr = start;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (ptr != NULL && ptr->id != id)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (ptr == start)
        {
            start->ediPlayList();
        }
        else
        {
            ptr->ediPlayList();
        }
    }

    void addSongs(HandlerSong handlerSong)
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        int id;
        this->displayListSimple();
        cout << "       Ingrese el id de la Play List que desea agregar canciones: ";
        cin >> id;
        PlayList *ptr;
        ptr = start;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (ptr != NULL && ptr->id != id)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (ptr == start)
        {
            start->addSong(handlerSong);
        }
        else
        {
            ptr->addSong(handlerSong);
        }
    }

    void addSongToFile(int idPlayList, int idSong, HandlerSong handlerSong)
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        PlayList *ptr;
        ptr = start;
        while (ptr != NULL && ptr->id != idPlayList)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (ptr == start)
        {
            start->addSongToFile(idSong, handlerSong);
        }
        else
        {
            ptr->addSongToFile(idSong, handlerSong);
        }
    }

    void deleleteSongs()
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        int id;
        this->displayListSimple();
        cout << "       Ingrese el id de la Play List que desea eliminar canciones: ";
        cin >> id;
        PlayList *ptr;
        ptr = start;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        while (ptr != NULL && ptr->id != id)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (ptr == start)
        {
            start->deleteSong();
        }
        else
        {
            ptr->deleteSong();
        }
    }

    void deleteSongToFile(int idPlayList, int idSong)
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        PlayList *ptr;
        ptr = start;
        while (ptr != NULL && ptr->id != idPlayList)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (ptr == start)
        {
            start->deleteSongToFile(idSong);
        }
        else
        {
            ptr->deleteSongToFile(idSong);
        }
    }
    PlayList *play;
    void playToList(int type)
    {
        if (start == NULL)
        {
            cout << "       La lista esta vacia" << endl;
            return;
        }
        if (play != nullptr)
        {
            cout<<"entro aqui"<<endl;
            if (play->listSongs != nullptr)
            {
                if (play->listSongs->newList != nullptr)
                {
                    play->listSongs->newList->head->anterior = nullptr;
                    play->listSongs->tail->siguiente = nullptr;
                }
            }
        }
        
        int id;
        this->displayListSimple();
        cout << "       Ingrese el id de la Play List que desea reproducir: ";
        cin.ignore();
        cin.clear();
        cin >> id;
        play = nullptr;
        play = start;
        while (play != NULL && play->id != id)
        {
            play = play->next;
        }
        if (play == NULL)
        {
            cout << "       PlayList no encontrada" << endl;
            return;
        }
        if (type == 1)
        {
            play->listSongs->songPlay = nullptr;
            play->listSongs->songPlayRepeat = nullptr;
            play->listSongs->newList = nullptr;
            play->listSongs->playSimple();
        }
        else if (type == 2)
        {
            play->listSongs->songPlay = nullptr;
            play->listSongs->newList = nullptr;
            play->listSongs->songPlayRepeat = nullptr;
            ListSongs *temp = play->listSongs;
            play->listSongs->convertDoubleList(temp);
        }
    }

    void viewPlays()
    {
        if (play == nullptr)
        {
            cout << "No hay lista en reproduccion" << endl;
            return;
        }
        play->listSongs->viewPlays();
    }

    void nextSong()
    {
        if (play == nullptr)
        {
            cout << "No hay lista en reproduccion" << endl;
            return;
        }
        play->listSongs->nextSong();
    }

    void backSong()
    {
        if (play == nullptr)
        {
            cout << "No hay lista en reproduccion" << endl;
            return;
        }

        play->listSongs->backSong();
    }
};
#endif
