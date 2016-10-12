/**
    @file reparar.h
    @brief Declaracion de la clase Reparar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef REPARAR_H
#define REPARAR_H

#include <QDialog>

namespace Ui {
class reparar;
}

class reparar : public QDialog
{
    Q_OBJECT

public:
    explicit reparar(QWidget *parent = 0);
    ~reparar();

private slots:


    void on_abrirregistro_clicked();

    void on_mandarreparar_clicked();

private:
    Ui::reparar *ui;
};

#endif // REPARAR_H
