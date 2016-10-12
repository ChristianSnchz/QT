/**
    @file retirar.h
    @brief Declaracion de la clase Retirar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef RETIRAR_H
#define RETIRAR_H

#include <QDialog>

namespace Ui {
class Retirar;
}

class Retirar : public QDialog
{
    Q_OBJECT

public:
    explicit Retirar(QWidget *parent = 0);
    ~Retirar();

private slots:
    void on_retirar_clicked();

    void on_abrir_registro_clicked();

private:
    Ui::Retirar *ui;
};

#endif // RETIRAR_H
