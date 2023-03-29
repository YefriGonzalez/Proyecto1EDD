
#include <iostream>
#include <stdio.h>
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
            int op = -1;
            while (op != 0)
            {
                cout << "----------------Canciones----------------" << endl;
                cout << "   1.Agregar cancion" << endl;
                cout << "   2.Eliminar cancion" << endl;
                cout << "   3.Buscar por nombre" << endl;
                cout << "   4.Listar canciones" << endl;
                cout << "   0.Regresar" << endl;
                cout << "Ingrese la opcion: ";
                cin >> op;
            }
            break;
        case 2:
            int op = -1;
            while (op != 0)
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
                cin >> op;
            }
            break;
        case 3:
            int op = -1;
            while (op != 0)
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
                cin >> op;
            }
            break;
        case 4:

            break;
        default:
            break;
        }
    }
}