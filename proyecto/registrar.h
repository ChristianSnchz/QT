/**
    @file registrar.h
    @brief Declaracion de la clase Registrar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>
#include <artefacto.h>

namespace Ui {
class registrar;
}

class registrar : public QDialog
{
    Q_OBJECT

public:
    explicit registrar(QWidget *parent = 0);
    ~registrar();

private slots:


    void on_guardar_clicked();

private:
    Ui::registrar *ui;
};

#endif // REGISTRAR_H
