
#define REPRODUCCION_H

#include <string>
#include <vector>
#include <cancion.h>

typedef struct Reproduccion Reproduccion;
struct Reproduccion{
    Cancion *nodo;
    Reproduccion *siguiente;
    Reproduccion *anterior;
    void setReproduccion(Cancion *nodo, Reproduccion *s, Reproduccion *a);
};