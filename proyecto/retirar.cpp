/**
    @file retirar.cpp
    @brief Declaracion de la clase Retirar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "retirar.h"
#include "ui_retirar.h"
#include <QFile>
#include <QTextStream>
#include <artefacto.h>
#include <iostream>
#include <sstream>
#include <ctime>

/**
    @brief Constructor de la ventana Retirar
    @param Ninguno
*/
Retirar::Retirar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Retirar)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
Retirar::~Retirar()
{
    delete ui;
}

/**
    @brief Boton retirar. Retira un artefacto especifico del registro y lo envia a la bitacora.
    @param Ninguno
*/
void Retirar::on_retirar_clicked()
{
    bool existe = false;
    int O =0;
    bool retiro = false;
    QString str;
    std::string clave, buffer;
    int estado = 0;
    str = ui->leerclave->text();
    if ( str.length() != 4)
    {
           ui->artefactosaretirar->setText("Introduzca un codigo valido.");
    }
    else
    {
        artefacto item;
        clave = str.toStdString();
        std::fstream archivo;
        archivo.open("registro.txt", std::ios::in | std::ios::out);

        int pos;


        archivo.clear();
        while (!archivo.eof())
        {
            std::getline(archivo, buffer, '_');
            if ( buffer == clave )
            {
                existe = true;
                std::getline(archivo, buffer, '_');
                item.setDescripcion(buffer);
                std::getline(archivo, buffer, '_');
                estado = atoi(buffer.c_str());
                item.setEstado(estado);
                if ( (buffer == "2") || (buffer == "3") || (buffer == "4"))
                {
                    retiro = true;
                    pos = archivo.tellg();
                    pos = (pos-1) - buffer.length();
                    archivo.seekp(pos);
                    archivo << '5';
                    ui->artefactosaretirar->setText("Se ha retirado el artefacto.");
                    std::getline(archivo, buffer, '_');
                    std::getline(archivo, buffer, '_');
                    item.propietario.setNombre(buffer);
                    std::getline(archivo, buffer, '_');
                    item.propietario.setCedula(buffer);
                    std::getline(archivo, buffer, '_');
                    item.propietario.setTelefono(buffer);
                    std::getline(archivo, buffer, '\n');
                    item.propietario.setDireccion(buffer);

                    break;
                }
                else
                {
                    ui->artefactosaretirar->setText("El artefacto no se encuentra esperando por retirar.");
                    break;
                }
            }
            else
            {
                std::getline(archivo, buffer, '\n');
            }
        }
        archivo.close();
        if (existe == false)
        {
            ui->artefactosaretirar->setText("No hay un artefacto con ese codigo.");
        }

        QString aux = QString::fromStdString(item.propietario.verNombre());
        ui->nombre->setText(aux);


        aux = QString::fromStdString(item.propietario.verTelefono());
        ui->telefono->setText(aux);

        aux = QString::fromStdString(item.propietario.verDireccion());
        ui->direccion->setText(aux);

        aux = QString::fromStdString(item.propietario.verCedula());
        ui->cedula->setText(aux);

        aux = QString::fromStdString(item.verDescripcion());
        ui->artefacto->setText(aux);

        if(item.verEstado() == 2)
        {
            ui->motivo->setText(" El Artefacto no se pudo reparar el daño en el es irreversible");
            O = (100+rand()%500);
            std::string precio;
            std::stringstream string;
            string << O;
            precio = string.str();
            aux = QString::fromStdString(precio);
            ui->precio->setText(aux);
        }
        if(item.verEstado() == 3)
        {
            ui->motivo->setText(" El Artefacto fue reparado de forma exitosa Gracias por preferirnos");
            O = (1000+rand()%5000);
            std::string precio;
            std::stringstream string;
            string << O;
            precio = string.str();
            aux = QString::fromStdString(precio);
            ui->precio->setText(aux);

        }
        if(item.verEstado() == 4)
        {
            ui->motivo->setText(" El Artefacto le hace falta un repuesto y no fue posible encontrarlo.");
            O = (100+rand()%1000);
            std::string precio;
            std::stringstream string;
            string << O;
            precio = string.str();
            aux = QString::fromStdString(precio);
            ui->precio->setText(aux);
        }

        if(retiro == true)
        {
         std::ifstream archivo;
         std::string codigo,artefacto,estado,nombre,cedula,telefono,direccion, input;
         archivo.open("registro.txt");
         archivo.seekg(0,std::ios::beg);
                 std::ofstream copia;
                 copia.open("aux1.txt");

            while(!archivo.eof())
            {
                std::getline(archivo, input, '_');
                if ( input.length() != 4)
                {
                    break;
                }

                if ( (input == clave) )
                {
                    std::getline(archivo, input, '\n');
                }
                else
                {
                    codigo = input;
                    std::getline(archivo,artefacto,'_');
                    std::getline(archivo,estado,'_');
                    std::getline(archivo,nombre,'_');
                    std::getline(archivo,cedula,'_');
                    std::getline(archivo,telefono,'_');
                    std::getline(archivo,direccion,'\n');

                    copia << codigo << '_';
                    copia << artefacto << '_';
                    copia << estado << '_';
                    copia << nombre << '_';
                    copia << cedula << '_';
                    copia << telefono << '_';
                    copia << direccion << '\n';
                }

                if (archivo.eof())
                {
                    break;
                }
            }
            copia.close();
            archivo.close();

           std::ofstream archivo_nuevo;
           archivo_nuevo.open("registro.txt");
           std::ifstream aux2;
           aux2.open("aux1.txt");
           archivo_nuevo.clear();
           archivo_nuevo.seekp(0,std::ios::beg);
           while(!aux2.eof())
           {
               std::getline(aux2,codigo,'_');
               if (codigo.length() != 4)
               {
                   break;
               }
               std::getline(aux2,artefacto,'_');
               std::getline(aux2,estado,'_');
               std::getline(aux2,nombre,'_');
               std::getline(aux2,cedula,'_');
               std::getline(aux2,telefono,'_');
               std::getline(aux2,direccion,'\n');

              archivo_nuevo << codigo <<"_"<<artefacto <<"_"<<estado << "_"<<nombre << "_"<<cedula << "_"<<telefono<<"_" << direccion <<"\n";

           }
           archivo_nuevo.close();
           aux2.close();

            time_t rawtime;
            struct tm * timeinfo;

            time ( &rawtime );
            timeinfo = localtime ( &rawtime );

            std::fstream vita;
            vita.open("bitacora.txt");
            vita.seekp(0,std::ios::end);
            vita << item.propietario.verNombre() << "_";
            vita << item.propietario.verCedula() << "_";
            vita << item.propietario.verTelefono()<< "_";
            vita << item.propietario.verDireccion()<< "_";
            vita << item.verDescripcion()<< "_";
            vita << "Precio: "<< O << "_";
            if(item.verEstado() == 3)
            {

             vita << "motivo: "<< " reparado forma exitosa ";
            }

            if(item.verEstado() == 2)
            {

             vita << "motivo: "<< "no se logro reparar ";
            }
            if(item.verEstado() == 4)
            {

             vita << "motivo: "<< "falta repuesto ";
            }

            vita << "fecha: "<< asctime (timeinfo);

            vita.close();
        }
    }
}

/**
    @brief Boton abrir registro. Abre el archivo registro.txt y lo muestra por pantalla.
    @param Ninguno
*/
void Retirar::on_abrir_registro_clicked()
{
    QFile entrada("registro.txt");
    entrada.open(QIODevice::ReadOnly);
    ui->artefactosaretirar->setText(entrada.readAll());
    entrada.close();
}
