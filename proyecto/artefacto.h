/**
    @file artefacto.h
    @brief Declaracion de la clase Artefacto
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef ARTEFACTO_H
#define ARTEFACTO_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cpersona.h>

class artefacto
{
    private:
        std::string codigo;
        std::string descripcion;
        int estado;

    public:
        cPersona propietario;

        artefacto();
        ~artefacto(){};

    std::string verCodigo() const;
    std::string verDescripcion() const;
    int verEstado() const;
    std::string verNombre() const;
    std::string verCedula() const;
    std::string verDireccion() const;
    std::string verTelefono() const;

    int setCodigo();
    void setCodigo(std::string);
    void setDescripcion(std::string);
    int setEstado(int);

    friend std::string generarCodigo();
};
#endif // ARTEFACTO_H
