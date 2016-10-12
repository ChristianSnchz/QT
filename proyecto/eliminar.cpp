/**
    @file eliminar.cpp
    @brief Declaracion de la clase Eliminar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "eliminar.h"
#include "ui_eliminar.h"
#include <QFile>
#include <artefacto.h>


/**
    @brief Constructor de la ventana Eliminar
    @param *parent (QWidget)
*/
eliminar::eliminar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eliminar)
{
    ui->setupUi(this);
}

/**
    @brief Destructor por defecto
    @param Ninguno
*/
eliminar::~eliminar()
{
    delete ui;
}

/**
    @brief Boton abrir eliminar. Abre el archivo registro.txt y lo muestra por pantalla
    @param Ninguno
*/
void eliminar::on_abrir_eliminar_clicked()
{
    QFile entrada("registro.txt");
    entrada.open(QIODevice::ReadOnly);
    ui->lista_eliminar->setText(entrada.readAll());
    entrada.close();

}

/**
    @brief Boton eliminar. Elimina un artefacto especifico de registro.txt
    @param Ninguno
*/
void eliminar::on_eliminar_boton_clicked()
{
    bool error = false;
    QString str;
    std::string clave, buffer;
    str = ui->clave_eliminar->text();
    if ( str.length() != 4)
    {
           ui->lista_eliminar->setText("Introduzca un codigo valido.");
    }
    else
    {
        artefacto item;
        clave = str.toStdString();

         std::ifstream archivo;
         std::string codigo,artefacto,estado,nombre,cedula,telefono,direccion, input;
         archivo.open("registro.txt");
         archivo.seekg(0,std::ios::beg);
                 std::ofstream copia;
                 copia.open("aux1.txt");

            while(!archivo.eof())
            {
                std::getline(archivo, input, '_');
                if ( input.length() != 4)
                {
                    break;
                }

                if ( (input == clave) )
                {
                    std::getline(archivo, input, '\n');
                    error = true;
                }
                else
                {
                    codigo = input;
                    std::getline(archivo,artefacto,'_');
                    std::getline(archivo,estado,'_');
                    std::getline(archivo,nombre,'_');
                    std::getline(archivo,cedula,'_');
                    std::getline(archivo,telefono,'_');
                    std::getline(archivo,direccion,'\n');

                    copia << codigo << '_';
                    copia << artefacto << '_';
                    copia << estado << '_';
                    copia << nombre << '_';
                    copia << cedula << '_';
                    copia << telefono << '_';
                    copia << direccion << '\n';
                }

                if (archivo.eof())
                {
                    break;
                }

            }
            copia.close();
            archivo.close();

           std::ofstream archivo_nuevo;
           archivo_nuevo.open("registro.txt");
           std::ifstream aux2;
           aux2.open("aux1.txt");
           archivo_nuevo.clear();
           archivo_nuevo.seekp(0,std::ios::beg);
           while(!aux2.eof())
           {
               std::getline(aux2,codigo,'_');
               if (codigo.length() != 4)
               {
                   break;
               }
               std::getline(aux2,artefacto,'_');
               std::getline(aux2,estado,'_');
               std::getline(aux2,nombre,'_');
               std::getline(aux2,cedula,'_');
               std::getline(aux2,telefono,'_');
               std::getline(aux2,direccion,'\n');

              archivo_nuevo << codigo <<"_"<<artefacto <<"_"<<estado << "_"<<nombre << "_"<<cedula << "_"<<telefono<<"_" << direccion <<"\n";

           }
           archivo_nuevo.close();
           aux2.close();

          if (error == true)
          {
             ui->lista_eliminar->setText("El registro fue eliminado.");
          }
          else
          {
              ui->lista_eliminar->setText("No hay un artefacto registrado con ese codigo");
          }

        }
}
