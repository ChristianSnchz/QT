/**
    @file reparar.cpp
    @brief Declaracion de la clase Reparar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "reparar.h"
#include "ui_reparar.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <string>
#include <fstream>

/**
    @brief Constructor de la ventana Reparar
    @param Ninguno
*/
reparar::reparar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reparar)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
reparar::~reparar()
{
    delete ui;
}

/**
    @brief Boton abrir registro. Abre el archivo registro.txt y lo muestra por pantalla.
    @param Ninguno
*/
void reparar::on_abrirregistro_clicked()
{
    QFile entrada("registro.txt");
    entrada.open(QIODevice::ReadOnly);
    ui->artefactosareparar->setText(entrada.readAll());
    entrada.close();

}

/**
    @brief Boton mandar reparar. Envia un artefacto registrado a reparacion.
    @param Ninguno
*/
void reparar::on_mandarreparar_clicked()
{
        bool existe = false;
        QString str;
        std::string clave, buffer;
        str = ui->leerclave->text();
        if ( str.length() != 4)
        {
               ui->artefactosareparar->setText("Introduzca un codigo valido.");
        }
        else
        {
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
                    std::getline(archivo, buffer, '_');
                    if ( buffer == "0")
                    {
                        pos = archivo.tellg();
                        pos = (pos-1) - buffer.length();
                        archivo.seekp(pos);
                        archivo << '1';
                        ui->artefactosareparar->setText("Se ha enviado el artefacto a reparar.");
                        break;
                    }
                    else
                    {
                        ui->artefactosareparar->setText("El artefacto no se encuentra en revision.");
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
                ui->artefactosareparar->setText("No hay un artefacto con ese codigo.");
            }
        }
}
