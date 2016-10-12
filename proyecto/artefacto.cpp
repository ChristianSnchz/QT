/**
    @file artefacto.cpp
    @brief Declaracion de la clase Artefacto
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#include "artefacto.h"

/**
    @brief Constructor por defecto
    @param Ninguno
*/
artefacto::artefacto()
{
    this->codigo = "";
    this->descripcion = "";
    this->estado = 0;
    this->propietario.setNombre("");
    this->propietario.setCedula("");
    this->propietario.setDireccion("");
    this->propietario.setTelefono("");
}

/**
    @brief Observador de codigo.
    @param Ninguno
    @returns El valor del atributo -> codigo
*/
std::string artefacto::verCodigo() const
{
    return (this->codigo);
}

/**
    @brief Observador de Descripcion
    @param Ninguno
    @returns El valor del atributo -> descripcion
*/
std::string artefacto::verDescripcion() const
{
    return (this->descripcion);
}

/**
    @brief Observador de estado
    @param Ninguno
    @returns El valor del atributo -> estado;
*/
int artefacto::verEstado() const
{
    return (this->estado);
}

/**
    @brief Observador de Nombre
    @param Ninguno
    @returns El valor del atributo -> Nombre del propietario
*/
std::string artefacto::verNombre() const
{
    return (this->propietario.verNombre());
}

/**
    @brief Observador de Cedula
    @param Ninguno
    @returns El valor del atributo -> Cedula del propietario
*/
std::string artefacto::verCedula() const
{
    return (this->propietario.verCedula());
}

/**
    @brief Observador de Direccion
    @param Ninguno
    @returns El valor del atributo -> Direccion del propietario
*/
std::string artefacto::verDireccion() const
{
    return (this->propietario.verDireccion());
}

/**
    @brief Observador de Telefono
    @param Ninguno
    @returns El valor del atributo -> Telefono del propietario
*/
std::string artefacto::verTelefono() const
{
    return (this->propietario.verTelefono());
}

/**
    @brief Genera un codigo aleatorio
    @param Ninguno
    @returns El codigo generado aleatoriamente
*/
std::string generarCodigo()
{
    std::string id = "";

    srand (time(NULL));
        for (int i=0;i<4;i++)
        {
        int tipo = 1 +(rand()%3);
                if (tipo==1)
                {
                    char minusculas=(char)(97+rand()%26);
                   id += minusculas;
                }
                else
                {
                    if(tipo==2)
                    {
                        char mayusculas=(char)(65+rand()%26);
                        id += mayusculas;
                    }
                    else
                    {
                        char numeros=(char)(48+rand()%10);
                        id += numeros;
                    }
                }
            }
        return (id);
}

/**
    @brief Asigna el codigo aleatorio al atributo
    @param Ninguno
    @returns 0 en caso exitoso, 1 si hay un error al abrir el archivo
*/
int artefacto::setCodigo()
{
    std::ifstream archivo;
    archivo.open("registro.txt");
    if (!archivo.good())
    {
        return (1);
    }

    std::string buffer, id;

    id = generarCodigo();

    while (!archivo.eof())
    {
        std::getline(archivo, buffer, '_');
        if ( id == buffer )
        {
            id = generarCodigo();
            archivo.seekg(0, std::ios::beg);
        }
        else
        {
            std::getline(archivo, buffer, '\n');
        }
    }
    archivo.close();

    this->codigo = id;
    return (0);
}

/**
    @brief Modifica el codigo de un artefacto
    @param cod Cadena de caracteres (std::string)
*/
void artefacto::setCodigo(std::string cod)
{
    this->codigo = cod;
    return;
}

/**
    @brief Modifica la descripcion de un artefacto
    @param desc Descripcion del artefacto
*/
void artefacto::setDescripcion(std::string desc)
{
    this->descripcion = desc;
    return;
}

/**
    @brief Modifica el estado de un artefacto
    @param e Estado del artefacto (0,1,2,3,4,5)
    @returns 0 en caso exitoso, 1 en caso de un estado invalido
*/
int artefacto::setEstado(int e)
{
    if ( (e >= 0) && (e <= 5) )
    {
        this->estado = e;
        return (0);
    }
    else
    {
        return (1);
    }
}
