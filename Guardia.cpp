#pragma once

#include "Guardia.h"

/* ---- Constructores ---- */
Guardia::Guardia() : Personaje(), habilidad_unique("None"),
                     danio_unique(0.0){};
Guardia::Guardia(std::string p_nombre, double p_ataque,
                 int p_vida, std::string p_habilidad,
                 double p_danio_habilidad, int p_defensa,
                 std::string p_habil_unique, double p_danio_unique)
    : Personaje(p_nombre, p_ataque, p_vida, p_habilidad,
                p_danio_habilidad, p_defensa),
      habilidad_unique(p_habil_unique), danio_unique(p_danio_unique)
{
    habilidad_gastada = false;
};

/* ---- Access Methods ---- */
std::string Guardia::get_habilidad_unique() { return habilidad_unique; }
double Guardia::get_danio_habilidad_unique() { return danio_unique; }

/* ---- Funciones ---- */
/*
Se encarga de llamar a la guardia nacional.
params: no recibe parametros
*/
void Guardia::llamar_a_policia()
{
    std::cout << "Alo policia ..." << std::endl;
}

/*
Se encarga de pedir ayuda al protagonista de la historia para mejorar sus
habilidades. Al haber llamado esta funcion, permite mejorar sus habilidades
params:
    - protagonista: referencia a un objeto de clase protagonista.
*/
void Guardia::pedir_ayuda(Personaje &protagonista, Personaje &guardia)
{
    char op_ayuda;
    std::cout << "Guardia ha pedido ayuda ..." << std::endl;
    std::cout << "Deseas ayudar (S/N)?" << std::endl;

    if (op_ayuda == 'S' || op_ayuda == 's')
        protagonista.ayudar(guardia);
    else
        std::cout << "Has decidido no ayudar" << std::endl;
}

/*
Se encarga de visualizar todos los datos del objeto personaje seleccionado.
params: no recibe parametros
*/
std::string Guardia::muestra_datos()
{
    std::stringstream datos;

    datos << "Los datos del guardia de la historia" << std::endl
          << "El nombre del personaje es: " << nombre
          << "\nLos base stats del personaje son los siguientes: "
          << "\n- Ataque: " << ataque
          << "\n- Vida: " << vida
          << "\n- Habilidad especial: " << habilidad
          << "\n- Danio de habilidad especial: " << danio_habilidad
          << "\n- Defensa: " << defensa
          << "\n- Habilidad unica: " << habilidad_unique
          << "\n- Danio habilidad unica: " << danio_unique
          << std::endl
          << std::endl;

    return datos.str();
}