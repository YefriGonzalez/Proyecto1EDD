

#include <vector>
#include "Cancion.h"
#define REPRODUCCION_H


typedef struct Reproduccion Reproduccion;
struct Reproduccion{
    Cancion *nodo;
    Reproduccion *siguiente;
    Reproduccion *anterior;
    void setReproduccion(Cancion *nodo, Reproduccion *s, Reproduccion *a);
};