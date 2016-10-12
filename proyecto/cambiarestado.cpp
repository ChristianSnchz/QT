/**
    @file cambiarestado.cpp
    @brief Declaracion de la clase cambiarestado
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "cambiarestado.h"
#include "ui_cambiarestado.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <string>
#include <fstream>

/**
    @brief Constructor de la ventana Cambiar Estado
    @param *parent (QWidget)
*/
cambiarestado::cambiarestado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cambiarestado)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
cambiarestado::~cambiarestado()
{
    delete ui;
}


/**
    @brief Boton Abrir Registro. Abre el archivo registro.txt y lo muestra por pantalla.
    @param Ninguno
*/
void cambiarestado::on_abrir_registro_clicked()
{
    QFile entrada("registro.txt");
    entrada.open(QIODevice::ReadOnly);
    ui->cambiarestado_2->setText(entrada.readAll());
    entrada.close();
}

/**
    @brief Cambio de estado de un artefacto. Define que el artefacto no se pudo reparar.
    @param Ninguno
*/
void cambiarestado::on_nosepudoreparar_clicked()
{
    bool existe = false;
    int pos = 0;
    QString str;
    std::string clave, buffer;

    str = ui->leerclave->text();
    if (str.length() != 4)
    {
        ui->cambiarestado_2->setText("Introduzca un codigo valido.");
    }
    else
    {
         clave = str.toStdString();

            std::fstream archivo;
         archivo.open("registro.txt");

            archivo.clear();
            while (!archivo.eof())
            {
                std::getline(archivo, buffer, '_');
                if ( buffer == clave )
                {
                    existe = true;
                    std::getline(archivo, buffer, '_');
                    std::getline(archivo, buffer, '_');
                    if ( buffer == "1")
                    {
                        pos = archivo.tellg();
                        pos = (pos-1) - buffer.length();
                        archivo.seekp(pos);
                        archivo << '2';
                        ui->cambiarestado_2->setText("Se ha cambiado el estado del artefacto.");
                        break;
                    }
                    else
                    {
                        ui->cambiarestado_2->setText("El artefacto no se encuentra en reparacion.");
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
                ui->cambiarestado_2->setText("No hay un artefacto con ese codigo");
            }
    }
}

/**
    @brief Cambio de estado de un artefacto. Define que el artefacto se reparo completamente.
    @param Ninguno
*/
void cambiarestado::on_sereparo_clicked()
{
    bool existe = false;
    int pos = 0;
    QString str;
    std::string clave, buffer;

    str = ui->leerclave->text();
    if (str.length() != 4)
    {
        ui->cambiarestado_2->setText("Introduzca un codigo valido.");
    }
    else
    {
         clave = str.toStdString();

            std::fstream archivo;
         archivo.open("registro.txt");

            archivo.clear();
            while (!archivo.eof())
            {
                std::getline(archivo, buffer, '_');
                if ( buffer == clave )
                {
                    existe = true;
                    std::getline(archivo, buffer, '_');
                    std::getline(archivo, buffer, '_');
                    if ( buffer == "1")
                    {
                        pos = archivo.tellg();
                        pos = (pos-1) - buffer.length();
                        archivo.seekp(pos);
                        archivo << '3';
                        ui->cambiarestado_2->setText("Se ha cambiado el estado del artefacto.");
                        break;
                    }
                    else
                    {
                        ui->cambiarestado_2->setText("El artefacto no se encuentra en reparacion.");
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
                ui->cambiarestado_2->setText("No hay un artefacto con ese codigo");
            }
    }
}

/**
    @brief Cambio de estado de un artefacto. Define que el artefacto no se reparo por falta de repuestos.
    @param Ninguno
*/
void cambiarestado::on_faltaderepuestos_clicked()
{
    bool existe = false;
    int pos = 0;
    QString str;
    std::string clave, buffer;

    str = ui->leerclave->text();
    if (str.length() != 4)
    {
        ui->cambiarestado_2->setText("Introduzca un codigo valido.");
    }
    else
    {
         clave = str.toStdString();

            std::fstream archivo;
         archivo.open("registro.txt");

            archivo.clear();
            while (!archivo.eof())
            {
                std::getline(archivo, buffer, '_');
                if ( buffer == clave )
                {
                    existe = true;
                    std::getline(archivo, buffer, '_');
                    std::getline(archivo, buffer, '_');
                    if ( buffer == "1")
                    {
                        pos = archivo.tellg();
                        pos = (pos-1) - buffer.length();
                        archivo.seekp(pos);
                        archivo << '4';
                        ui->cambiarestado_2->setText("Se ha cambiado el estado del artefacto.");
                        break;
                    }
                    else
                    {
                        ui->cambiarestado_2->setText("El artefacto no se encuentra en reparacion.");
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
                ui->cambiarestado_2->setText("No hay un artefacto con ese codigo");
            }
    }
}
