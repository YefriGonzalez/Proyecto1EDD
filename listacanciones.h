#include "SDL2/SDL.h"
#include <SDL2/SDL_mixer.h>
#include "Cancion.h"
#ifndef SONGSLIST_H

#define SONGSLIST_H

struct NodeSong
{
    Song *song;
    NodeSong *anterior;
    NodeSong *siguiente;

    NodeSong(Song *songP)
    {
        this->song = songP;
        this->anterior = nullptr;
        this->siguiente = nullptr;
    }
};
class ListSongs
{
private:
    NodeSong *head;
    NodeSong *tail;

public:
    ListSongs()
    {
        head = NULL;
        tail = NULL;
    }
    void addSong(Song *song)
    {
        NodeSong *node = new NodeSong(song);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->anterior = tail;
            tail->siguiente = node;
            tail = node;
        }
    }

    void displaySongs()
    {
        if (head == nullptr)
        {
            cout << "       La lista de canciones esta vacia" << endl;
            return;
        }
        NodeSong *ptr = head;
        cout << "       Canciones de Playlist: " << endl;
        while (ptr != nullptr)
        {
            cout << "       Id: " << ptr->song->id << ", Nombre: " << ptr->song->nombre << ", Path: " << ptr->song->path << endl;
            ptr = ptr->siguiente;
        }
    }
    Song *findWithId(int id)
    {
        if (head == nullptr)
        {
            cout << "       La lista de canciones esta vacia" << endl;
            return nullptr;
        }
        this->displaySongs();
        NodeSong *ptr;
        ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->song->id == id)
            {
                return ptr->song;
            }
            ptr = ptr->siguiente;
        }
        return nullptr;
    }
    void deleteSong(string nombre)
    {
        if (head == NULL)
        {
            cout << "       La lista de canciones esta vacia" << endl;
            return;
        }
        NodeSong *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->song->nombre == nombre)
            {
                if (ptr == head)
                {
                    head = ptr->siguiente;
                }
                else
                {
                    ptr->anterior->siguiente = ptr->siguiente;
                }

                if (ptr == tail)
                {
                    tail = ptr->anterior;
                }
                else
                {
                    ptr->siguiente->anterior = ptr->anterior;
                }
                cout << "       Cancion eliminada de la lista: " << ptr->song->nombre << endl;
                delete ptr;
                return;
            }
            ptr = ptr->siguiente;
        }

        cout << "       Cancion no encontrada en la lista" << endl;
    }

    void playNormal()
    {
        if (head == NULL)
        {
            cout << "       La lista de canciones esta vacia" << endl;
            return;
        }
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            cout << "SDL_mixer no pudo inicializar! Error: " << Mix_GetError() << endl;
            return;
        }
        NodeSong *ptr = head;
        while (ptr != nullptr)
        {
            Mix_Music *play = Mix_LoadMUS(ptr->song->path.c_str());
            if (play == nullptr)
            {
                cout << "No se pudo cargar la canción " << ptr->song->nombre << "! Error: " << Mix_GetError() << endl;
                ptr = ptr->siguiente;
                continue;
            }
            cout << "Reproduciendo " << ptr->song->nombre << "..." << endl;
            Mix_PlayMusic(play, 1);
            while (Mix_PlayingMusic())
            {
                SDL_Delay(1000);
            }
            Mix_FreeMusic(play);
            ptr = ptr->siguiente;
        }
        Mix_CloseAudio();
    }

    void playRepeat()
    {
        if (head == NULL)
        {
            cout << "       La lista de canciones esta vacia" << endl;
            return;
        }
    }
};

#endif