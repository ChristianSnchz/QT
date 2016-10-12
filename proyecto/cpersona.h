/**
    @file cpersona.h
    @brief Declaracion de la clase cPersona
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef CPERSONA_H
#define CPERSONA_H

#include <string>

class cPersona
{
    private:
        std::string nombre;
        std::string cedula;
        std::string direccion;
        std::string telefono;

    public:
        cPersona();
        ~cPersona(){};

    std::string verNombre() const;
    std::string verCedula() const;
    std::string verDireccion() const;
    std::string verTelefono() const;

    void setNombre(std::string);
    void setCedula(std::string);
    void setDireccion(std::string);
    void setTelefono(std::string);

};

#endif // CPERSONA_H
