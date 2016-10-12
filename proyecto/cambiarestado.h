/**
    @file cambiarestado.h
    @brief Declaracion de la clase cambiarestado
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef CAMBIARESTADO_H
#define CAMBIARESTADO_H

#include <QDialog>

namespace Ui {
class cambiarestado;
}

class cambiarestado : public QDialog
{
    Q_OBJECT

public:
    explicit cambiarestado(QWidget *parent = 0);
    ~cambiarestado();

private slots:


    void on_abrir_registro_clicked();

    void on_nosepudoreparar_clicked();

    void on_sereparo_clicked();

    void on_faltaderepuestos_clicked();

private:
    Ui::cambiarestado *ui;
};

#endif // CAMBIARESTADO_H
