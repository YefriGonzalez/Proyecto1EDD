#define PLAYLIST_H
#include <string>
#include <vector>
#include <listacanciones.h>
#include <reproduccion.h>
typedef struct PlayList PlayList;

struct PlayList{
    char *nombre;
    char *descripcion;
    ListaCanciones *listado;
    void dibujar();
    Reproduccion * pop();
};




