#define CANCION_H
#include <string>
#include <vector>

typedef struct Cancion Cancion;

struct Cancion{
    char *Nombre;
    char *path;
    Cancion *siguiente;
    void setCancion(std::string n, std::string p, Cancion * s);
};