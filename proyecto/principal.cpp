/**
    @file principal.cpp
    @brief Declaracion de la clase principal
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "principal.h"
#include "ui_principal.h"

/**
    @brief Constructor de la ventana principal
    @param *parent (QWidget)
*/
principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
principal::~principal()
{
    delete ui;
}

/**
    @brief Boton registrar. Abre la nueva ventana Registrar
    @param Ninguno
*/
void principal::on_Registrar_clicked()
{
    registrar *ventana1 = new registrar(this);
    ventana1->setModal(true);
    ventana1->show();
}

/**
    @brief Boton reparar. Abre la nueva ventana Reparar
    @param Ninguno
*/
void principal::on_Reparar_clicked()
{
    reparar *ventana2 = new reparar(this);
    ventana2->setModal(true);
    ventana2->show();

}

/**
    @brief Boton cambiar estado. Abre la nueva ventana Cambiar Estado
    @param Ninguno
*/
void principal::on_CambiarEstado_clicked()
{
    cambiarestado *ventana3 = new cambiarestado(this);
    ventana3->setModal(true);
    ventana3->show();

}

/**
    @brief Boton retirar. Abre la nueva ventana Retirar
    @param Ninguno
*/
void principal::on_Retirar_clicked()
{
    Retirar  *ventana4 = new Retirar(this);
    ventana4->setModal(true);
    ventana4->show();
}

/**
    @brief Menu de opciones. Permite ver la bitacora en una ventana nueva.
    @param Ninguno
*/
void principal::on_actionVer_bitacora_triggered()
{
    bitacora *ventana5 = new bitacora(this);
    ventana5->setModal(true);
    ventana5->show();
}

/**
    @brief Menu de opciones. Abre una ventana nueva para eliminar un registro.
    @param Ninguno
*/
void principal::on_actionEliminar_registro_triggered()
{
    eliminar *ventana6 = new eliminar(this);
    ventana6->setModal(true);
    ventana6->show();
}
