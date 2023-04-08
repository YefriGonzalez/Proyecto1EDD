#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <stdio.h>
#include "playlist.h"
#include "Cancion.h"

using namespace std;
void menu();
int main()
{
    menu();
    return 0;
}

void menu()
{
    int opcion = -1;
    HandlerSong handlerSong;
    HandlerPlayList handlerPlayList;
    while (opcion != 0)
    {
        cout << "----------------Menu----------------" << endl;
        cout << "   1.Canciones" << endl;
        cout << "   2.PlayList" << endl;
        cout << "   3.Reproduccion" << endl;
        cout << "   4.Carga masiva" << endl;
        cout << "   0.Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        if (!cin)
        {
            cout << "       Error, no ha ingresado un numero" << endl;
            cin.clear();
            cin.ignore(5, '\n');
            break;
        }
        switch (opcion)
        {
        case 1:
        {
            int opC = -1;
            while (opC != 0)
            {
                cout << "----------------Canciones----------------" << endl;
                cout << "   1.Agregar cancion" << endl;
                cout << "   2.Eliminar cancion" << endl;
                cout << "   3.Buscar por nombre" << endl;
                cout << "   4.Listar canciones" << endl;
                cout << "   0.Regresar" << endl;
                cout << "Ingrese la opcion: ";
                cin >> opC;
                if (!cin)
                {
                    cout << "       Error, no ha ingresado un numero" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    break;
                }
                switch (opC)
                {
                case 1:
                    handlerSong.addSong();
                    break;
                case 2:
                    handlerSong.deleteCancion();
                    break;
                case 3:
                    handlerSong.findWithName();
                    break;
                case 4:
                    handlerSong.displaySongs();
                    break;
                default:
                    break;
                }
            }
        }

        break;
        case 2:
        {
            int opP = -1;
            while (opP != 0)
            {
                cout << "----------------PlayList----------------" << endl;
                cout << "   1.Crear playlist" << endl;
                cout << "   2.Eliminar playlist" << endl;
                cout << "   3.Editar playlist" << endl;
                cout << "   4.Listar playlists" << endl;
                cout << "   5.Agregar cancion" << endl;
                cout << "   6.Eliminar cancion" << endl;
                cout << "   0.Regresar" << endl;
                cout << "Ingrese la opcion: ";
                cin >> opP;
                if (!cin)
                {
                    cout << "       Error, no ha ingresado un numero" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    break;
                }
                switch (opP)
                {
                case 1:
                    handlerPlayList.addPlayList(handlerSong);
                    break;
                case 2:
                    handlerPlayList.deletePlayList();
                    break;
                case 3:
                    handlerPlayList.editPlayList();
                    break;
                case 4:
                    handlerPlayList.displayLists();
                    break;
                case 5:
                    handlerPlayList.addSongs(handlerSong);
                    break;
                case 6:
                    handlerPlayList.deleleteSongs();
                default:
                    break;
                }
            }
        }
        break;
        case 3:
        {
            int opR = -1;
            while (opR != 0)
            {
                cout << "----------------Reproduccion----------------" << endl;
                cout << "   1.Normal" << endl;
                cout << "   2.Repetir" << endl;
                cout << "   3.Siguiente" << endl;
                cout << "   4.Anterior" << endl;
                cout << "   5.Ver lista de reproduccion" << endl;
                cout << "   6.Agregar cancion a la lista" << endl;
                cout << "   0.Regresar" << endl;
                cout << "Ingrese la opcion: ";
                cin >> opR;
                switch (opR)
                {
                case 1:
                    handlerPlayList.playToList(1);
                    break;
                case 2:
                    handlerPlayList.playToList(2);
                    break;
                default:
                    break;
                }
            }
        }
        break;

        case 4:
        {
        }
        break;

        default:
        {
        }
        break;
        }
    }
}
