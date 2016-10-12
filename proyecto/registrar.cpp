/**
    @file registrar.cpp
    @brief Declaracion de la clase Registrar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "registrar.h"
#include "ui_registrar.h"
#include <QString>

/**
    @brief Constructor de la ventana Registrar
    @param Ninguno
*/
registrar::registrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrar)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
registrar::~registrar()
{
    delete ui;
}

/**
    @brief Boton guardar. Registra un nuevo artefacto en el archivo.
    @param Ninguno
*/
void registrar::on_guardar_clicked()
{
    artefacto item;
    QString buffer;

    std::fstream archivo;
    archivo.open("registro.txt");


   item.setCodigo();
   buffer = ui->leerartefacto->text();
   item.setDescripcion(buffer.toStdString());
   buffer = ui->lleernombre->text();
   item.propietario.setNombre(buffer.toStdString());
   buffer = ui->leercedula->text();
   item.propietario.setCedula(buffer.toStdString());
   buffer = ui->leertelefono->text();
   item.propietario.setTelefono(buffer.toStdString());
   buffer = ui->leerdireccion->text();
   item.propietario.setDireccion(buffer.toStdString());

   archivo.seekp(0, std::ios::end);
   archivo << item.verCodigo() << '_';
   archivo << item.verDescripcion() << '_';
   archivo << item.verEstado() << '_';
   archivo << item.propietario.verNombre() << '_';
   archivo << item.propietario.verCedula() << '_';
   archivo << item.propietario.verTelefono() << '_';
   archivo << item.propietario.verDireccion() << '\n';
   archivo.close();

}
