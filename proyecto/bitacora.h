/**
    @file bitacora.h
    @brief Declaracion de la clase Bitacora
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef BITACORA_H
#define BITACORA_H

#include <QDialog>

namespace Ui {
class bitacora;
}

class bitacora : public QDialog
{
    Q_OBJECT

public:
    explicit bitacora(QWidget *parent = 0);
    ~bitacora();

private slots:
    void on_Abrir_bitacora_clicked();

private:
    Ui::bitacora *ui;
};

#endif // BITACORA_H
