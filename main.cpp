
#include <iostream>
#include <stdio.h>
#include "Cancion.h"
using namespace std;
void menu();
int main(int argc, const char **argv)
{
    menu();
    return 0;
}

void menu()
{
    int opcion = -1;
    
    Cancion *start=new Cancion();
    
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
                switch (opC)
                {
                case 1:
                    start->insertCancion();
                    break;
                case 2:
                    start->deleteCancion();
                    break;
                case 3:
                    start->findWithName();
                    break;
                case 4:
                    start->displaySongs();
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
                cout << "   4.Eliminar cancion" << endl;
                cout << "   0.Regresar" << endl;
                cout << "Ingrese la opcion: ";
                cin >> opP;
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
