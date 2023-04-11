#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <thread>
#include <functional>
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
public:
    NodeSong *head;
    NodeSong *tail;

    bool finishPlay;
    thread tr;
    NodeSong *songPlay;
    NodeSong *songPlayRepeat;
    ListSongs()
    {
        head = NULL;
        tail = NULL;
        songPlay = nullptr;
        finishPlay = false;
        newList = nullptr;
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
        if (songPlay == nullptr && !finishPlay)
        {
            songPlay = head;
        }
        while (songPlay != nullptr)
        {
            Mix_Music *play = Mix_LoadMUS(songPlay->song->path.c_str());
            if (play == nullptr)
            {
                cout << "No se pudo cargar la canción " << songPlay->song->nombre << "! Error: " << Mix_GetError() << endl;
                songPlay = songPlay->siguiente;
                continue;
            }
            // cout << "Reproduciendo " << songPlay->song->nombre << "..." << endl;
            Mix_PlayMusic(play, 1);
            while (Mix_PlayingMusic())
            {
                SDL_Delay(500);
            }
            Mix_FreeMusic(play);
            songPlay = songPlay->siguiente;
        }
        Mix_CloseAudio();
    }

    void playRepeat()
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            cout << "SDL_mixer no pudo inicializar! Error: " << Mix_GetError() << endl;
            return;
        }
        if (songPlayRepeat == nullptr)
        {
            songPlayRepeat = newList->head;
        }
        while (songPlayRepeat != nullptr)
        {

            Mix_Music *play = Mix_LoadMUS(songPlayRepeat->song->path.c_str());
            if (play == nullptr)
            {
                cout << "No se pudo cargar la canción " << songPlayRepeat->song->nombre << "! Error: " << Mix_GetError() << endl;
                songPlayRepeat = songPlayRepeat->siguiente;
                continue;
            }
            // cout << "Reproduciendo " << songPlay->song->nombre << "..." << endl;
            Mix_PlayMusic(play, 1);
            while (Mix_PlayingMusic())
            {
                SDL_Delay(1000);
            }
            Mix_FreeMusic(play);
            songPlayRepeat = songPlayRepeat->siguiente;
        }
        Mix_CloseAudio();
    }

    void nextSong()
    {
        if (songPlay != nullptr)
        {
            if (songPlay->siguiente != nullptr)
            {
                songPlay = songPlay->siguiente;
                finishPlay = false;
                Mix_HaltMusic();
                cout << "Siguiente" << endl;
                play(1);
            }
            else
            {
                songPlay = nullptr;
                Mix_PauseMusic();
                finishPlay = true;
                play(1);
                cout << "      La lista finalizo" << endl;
            }
        }
        else if (songPlayRepeat != nullptr)
        {
            if (songPlayRepeat->siguiente != nullptr)
            {
                songPlayRepeat = songPlayRepeat->siguiente;
                Mix_HaltMusic();
                cout << "Siguiente" << endl;
                play(2);
            }
            else
            {
                songPlayRepeat = nullptr;
                Mix_PauseMusic();
                finishPlay = true;
                play(2);
                cout << "      La lista finalizo" << endl;
            }
        }
        else
        {
            songPlay = nullptr;
            songPlayRepeat = nullptr;
            cout << "      No se esta reproduciendo ninguna lista" << endl;
        }
    }

    void backSong()
    {
        if (songPlay != nullptr)
        {
            if (songPlay->anterior != nullptr)
            {
                songPlay = songPlay->anterior;
                Mix_HaltMusic();
                cout << "Anterior " << endl;
                play(1);
            }
            else
            {
                songPlay = nullptr;
                Mix_PauseMusic();
                finishPlay = true;
                play(1);
                cout << "      La lista finalizo" << endl;
            }
        }
        else if (songPlayRepeat != nullptr)
        {
            if (songPlayRepeat->anterior != nullptr)
            {
                songPlayRepeat = songPlayRepeat->anterior;
                Mix_HaltMusic();
                cout << "Anterior" << endl;
                play(2);
            }
            else
            {
                songPlayRepeat = nullptr;
                Mix_PauseMusic();
                finishPlay = true;
                play(2);
                cout << "      La lista finalizo" << endl;
            }
        }
        else
        {
            songPlay = nullptr;
            songPlayRepeat = nullptr;
            cout << "      No se esta reproduciendo ninguna lista" << endl;
        }
    }

    ListSongs *newList;
    void convertDoubleList(ListSongs *listSong)
    {
        while (tr.joinable())
        {
            tr.detach();
        }
        newList = nullptr;
        songPlay = nullptr;
        songPlayRepeat = nullptr;
        newList = listSong;
        finishPlay = false;
        if (newList->head == nullptr)
        {
            cout << "       La lista de canciones esta vacia" << endl;
            return;
        }
        newList->head->anterior = newList->tail;
        newList->tail->siguiente = newList->head;

        play(2);
    }

    void playSimple()
    {
        while (tr.joinable())
        {
            tr.detach();
        }
        if (newList != nullptr)
        {
            newList->head->anterior = nullptr;
            newList->tail->siguiente = nullptr;
        }
        songPlay = nullptr;
        songPlayRepeat = nullptr;
        newList = nullptr;
        finishPlay = false;
        play(1);
    }

    void play(int type)
    {
        while (tr.joinable())
        {
            tr.detach();
        }
        if (type == 1)
        {
            newList = nullptr;
            songPlayRepeat = nullptr;
            tr = thread(&ListSongs::playNormal, this);
            tr.detach();
        }
        else if (type == 2)
        {
            songPlay = nullptr;
            tr = thread(&ListSongs::playRepeat, this);
            tr.detach();
        }
    }

    void viewPlays()
    {
        NodeSong *repr = songPlay;
        NodeSong *reprR = songPlayRepeat;
        if (repr != nullptr)
        {
            cout << "Cancion en reproduccion: " << repr->song->nombre << endl;
            if (repr->siguiente == nullptr)
            {
                cout << "No hay mas canciones en cola" << endl;
                return;
            }
            else
            {
                repr = repr->siguiente;
            }
            cout << "Canciones en espera: " << endl;

            while (repr != nullptr)
            {
                cout << "Nombre: " << repr->song->nombre << endl;
                repr = repr->siguiente;
            }
        }
        else if (reprR != nullptr)
        {
            if (newList != nullptr)
            {
                cout << "Modo repetitivo, esta lista volvera a reproducirse" << endl;
            }
            NodeSong *ptr = reprR;
            cout << "Cancion en reproduccion: " << reprR->song->nombre << endl;
            if (reprR->siguiente == nullptr)
            {
                cout << "No hay mas canciones en cola" << endl;
                return;
            }
            else
            {
                reprR = reprR->siguiente;
            }
            
            int cicle = 0;
            while (reprR != nullptr && cicle!=1)
            {
                if (ptr ==reprR)
                {
                    ++cicle;
                    if(cicle==1){
                        break;
                    }
                }
                cout << "Nombre: " << reprR->song->nombre << endl;
                reprR = reprR->siguiente;
            }
        }
        else
        {
            cout << "No hay lista en reproduccion" << endl;
            return;
        }
    }
};

#endif