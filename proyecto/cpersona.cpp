/**
    @file cpersona.cpp
    @brief Declaracion de la clase cPersona
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "cpersona.h"

/**
    @brief Constructor de la clase cPersona
    @param Ninguno
*/
cPersona::cPersona()
{
    this->nombre = "";
    this->cedula = "";
    this->direccion = "";
    this->telefono = "";
}

/**
    @brief Observador de Nombre
    @param Ninguno
    @returns El valor del atributo -> nombre
*/
std::string cPersona::verNombre() const
{
    return (this->nombre);
}

/**
    @brief Observador de Cedula
    @param Ninguno
    @returns El valor del atributo -> cedula
*/
std::string cPersona::verCedula() const
{
    return (this->cedula);
}

/**
    @brief Observador de Direccion
    @param Ninguno
    @returns El valor del atributo -> direccion
*/
std::string cPersona::verDireccion() const
{
    return (this->direccion);
}

/**
    @brief Observador de Telefono
    @param Ninguno
    @returns El valor del atributo -> telefono
*/
std::string cPersona::verTelefono() const
{
    return (this->telefono);
}

/**
    @brief Modifica el nombre de la persona
    @param nom Nombre de la persona
*/
void cPersona::setNombre(std::string nom)
{
    this->nombre = nom;
    return;
}

/**
    @brief Modifica la cedula de la persona
    @param ced Cedula de la persona
*/
void cPersona::setCedula(std::string ced)
{
    this->cedula = ced;
    return;
}

/**
    @brief Modifica la direccion de la persona
    @param dir Direccion de la persona
*/
void cPersona::setDireccion(std::string dir)
{
    this->direccion = dir;
    return;
}

/**
    @brief Modifica el telefono de la persona
    @param tlf Telefono de la persona
*/
void cPersona::setTelefono(std::string tlf)
{
    this->telefono = tlf;
    return;
}
