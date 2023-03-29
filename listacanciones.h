#define LISTACANCIONES_H

#include <string>
#include <vector>
#include <cancion.h>
typedef struct ListaCanciones ListaCanciones;

struct ListaCanciones{
    Cancion *inicio;
    Cancion *final;
    void addCancion(Cancion * nodo);
    Cancion * findCancion(std::string nombre);
};

std::vector<std::string> explode(std::string& str, const char& ch);
ListaCanciones * CrearCircular();
ListaCanciones * CrearPila();
ListaCanciones * CrearCola();