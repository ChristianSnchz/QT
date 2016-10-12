/**
    @file bitacora.cpp
    @brief Declaracion de la clase Bitacora
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "bitacora.h"
#include "ui_bitacora.h"
#include <QFile>
#include <QTextStream>

/**
    @brief Constructor de la ventana Bitacora
    @param *parent (QWidget)
*/
bitacora::bitacora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bitacora)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
bitacora::~bitacora()
{
    delete ui;
}

/**
    @brief Boton abrir bitacora. Abre el archivo bitacora.txt y lo muestra por pantalla.
    @param Ninguno
*/
void bitacora::on_Abrir_bitacora_clicked()
{
    QFile entrada("bitacora.txt");
    entrada.open(QIODevice::ReadOnly);
    ui->allbitacora->setText(entrada.readAll());
    entrada.close();

}
