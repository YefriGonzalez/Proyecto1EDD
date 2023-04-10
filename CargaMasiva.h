#include <iostream>
#include <string>
#include "tinyxml2.h"
#include "Cancion.h"
#include "playlist.h"
using namespace std;
using namespace tinyxml2;
#ifndef CARGAMASIVA_H
#define CARGAMASIVA_H
#endif

class MassiveChargue
{
private:
public:
    MassiveChargue()
    {
    }

    void chargueFile(HandlerSong &handlerS, HandlerPlayList &handlerP)
    {
        XMLDocument doc;
        string path;

        cout << "Ingrese el path del archivo XML: ";
        cin.ignore();
        getline(cin, path);
        doc.LoadFile(path.c_str());
        if (doc.Error())
        { // verificamos si hay errores en la carga del archivo
            cout << "Error al cargar el archivo XML." << endl;
            return;
        }
        XMLElement *insert = doc.FirstChildElement("Insertar");

        while (insert != nullptr)
        {
            XMLElement *song = insert->FirstChildElement("cancion");
            while (song != nullptr)
            {
                string pathSong;
                string nameSong;
                string posSong;
                nameSong = song->FirstChildElement("Nombre")->GetText();
                pathSong = song->FirstChildElement("path")->GetText();
                XMLElement *pos = song->FirstChildElement("Pos");
                if (pos != nullptr)
                {
                    posSong = pos->GetText();
                }

                if (!nameSong.empty() && !pathSong.empty())
                {
                    if (posSong.empty())
                    {
                        handlerS.addSongToFile(nameSong, pathSong);
                    }
                    else
                    {
                        int pos = stoi(posSong);
                        handlerS.addSongToFile(nameSong, pathSong, pos);
                    }
                }
                else
                {
                    cout << "Para crear una cancion es requerido tener nombre y path!!" << endl;
                }
                song = song->NextSiblingElement("cancion");
            }
            XMLElement *list = insert->FirstChildElement("Lista");

            while (list != nullptr)
            {
                string nameList;
                string descriptionList;
                int id;
                nameList = list->FirstChildElement("Nombre")->GetText();
                descriptionList = list->FirstChildElement("Description")->GetText();
                XMLElement *songList = list->FirstChildElement("Canciones");
                if (!nameList.empty() && !descriptionList.empty())
                {
                    id = handlerP.addPlayListToFile(handlerS, nameList, descriptionList);
                    if (songList != nullptr)
                    {
                        XMLElement *pos = songList->FirstChildElement("pos");
                        while (pos != nullptr)
                        {
                            int idSong = pos->IntText();
                            handlerP.addSongToFile(id, idSong, handlerS);
                            pos = pos->NextSiblingElement("pos");
                        }
                    }
                    cout << "PlayList Creada" << endl;
                }
                else
                {
                    cout << "Para crear una lista es requerido tener nombre y descripcion!!" << endl;
                }
                list = list->NextSiblingElement("Lista");
            }
            insert = insert->NextSiblingElement("Insertar");
        }
        XMLElement *delet = doc.FirstChildElement("Eliminar");
        while (delet != nullptr)
        {
            XMLElement *song = delet->FirstChildElement("cancion");
            while (song != nullptr)
            {
                int idSong = 0;
                string nameSong;
                XMLElement *namesongNode = song->FirstChildElement("Nombre");
                XMLElement *idSongNode = song->FirstChildElement("id");
                if (namesongNode != nullptr)
                {
                    nameSong = namesongNode->GetText();
                }
                if (idSongNode != nullptr)
                {
                    idSong = idSongNode->IntText();
                }
                if (!nameSong.empty())
                {
                    handlerS.deleteSongToFile(2, idSong, nameSong);
                }
                else if (idSong != 0)
                {
                    handlerS.deleteSongToFile(1, idSong, " ");
                }
                song = song->NextSiblingElement("cancion");
            }
            XMLElement *list = delet->FirstChildElement("Lista");
            while (list != nullptr)
            {
                int idList = 0;
                string nameList;
                XMLElement *nameListNode = list->FirstChildElement("Nombre");
                XMLElement *idListNode = list->FirstChildElement("id");
                if (nameListNode != nullptr)
                {
                    nameList = nameListNode->GetText();
                }
                if (idListNode != nullptr)
                {
                    idList = idListNode->IntText();
                }

                tinyxml2::XMLElement *songList = list->FirstChildElement("canciones");
                if (!nameList.empty())
                {
                    handlerP.deletePlayListToFile(2, idList, nameList);
                }
                else if (songList != nullptr && idList != 0)
                {
                    XMLElement *pos = songList->FirstChildElement("pos");
                    while (pos != nullptr)
                    {
                        int idSong = pos->IntText();
                        handlerP.deleteSongToFile(idList, idSong);
                        pos = pos->NextSiblingElement("pos");
                    }
                    
                }
                else if (idList != 0 &&songList==nullptr)
                {
                    handlerP.deletePlayListToFile(1, idList, " ");
                }
                list = list->NextSiblingElement("Lista");
            }
            delet = delet->NextSiblingElement("Eliminar");
        }
        cout << "------------------Lectura de archivo terminada------------------" << endl;
    }
};
