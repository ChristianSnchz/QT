/**
    @file main.cpp
    @brief Contiene la creacion de la ventana principal (mainWindonw)
           Crea inicialmente los archivos de texto: registro.txt y bitacora.txt

    @author Caceres, Jesus. Sanchez Christian
    @date 07/2015
*/

#include "principal.h"
#include <QApplication>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principal w;
    w.show();

    std::ifstream archivo;
        archivo.open("registro.txt");
        if (!archivo.good())
        {
            std::ofstream nuevo;
            nuevo.open("registro.txt");
            if (!nuevo.good())
            {
                return (1);
            }
            nuevo.close();
        }
        archivo.close();

        std::ifstream bitacora;
        bitacora.open("bitacora.txt");
        if(!archivo.good())
        {
            std::ofstream bita;
            bita.open("bitacora.txt");
            if(!bita.good())
                return 1;

            bita.close();
        }
       bitacora.close();

      return a.exec();
}
