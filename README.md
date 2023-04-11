Author: Yefri Marconi Gonzalez Vicente

Comandos necesarios para ejecutar el programa: 
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev  
sudo apt-get install libsdl2-mixer-dev  
sudo apt-get install libsdl2-ttf-dev  
sudo apt install libtinyxml2-dev 
Comando para compilar: 
g++ -o myprogram main.cpp Cancion.h listacanciones.h playlist.h CargaMasiva.h -lSDL2 -lSDL2_mixer -ltinyxml2
Comando para ejecutar:
./myprogram
