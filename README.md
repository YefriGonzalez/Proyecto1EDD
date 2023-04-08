Comandos necesarios para ejecutar el programa: 
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev  
sudo apt-get install libsdl2-mixer-dev  
sudo apt-get install libsdl2-ttf-dev  

Comando para compilar: 
g++ -o myprogram main.cpp Cancion.h listacanciones.h playlist.h -lSDL2 -lSDL2_mixer

Comando para ejecutar:
./myprogram