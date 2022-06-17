#pragma once

#include "Protagonista.h"

/* ---- Constructores ---- */
Protagonista::Protagonista() : Personaje(), paciencia(0)
{
    jugando_xbox = true;
};

Protagonista::Protagonista(std::string p_nombre, double p_ataque,
                           int p_vida, std::string p_habil,
                           double p_danio_hab, int p_defensa,
                           int p_paciencia)
    : Personaje(p_nombre, p_ataque, p_vida, p_habil,
                p_danio_hab, p_defensa),
      paciencia(p_paciencia)
{
    jugando_xbox = true;
};

/* ---- Access Methods ---- */
void Protagonista::set_paciencia(int n_paciencia) { paciencia = n_paciencia; }
int Protagonista::get_paciencia() { return paciencia; }

/* ---- Funciones ---- */
/*
Se encarga de visualizar todos los datos del objeto personaje seleccionado.
params:
    - personaje: referencia de objeto de tipo Personaje.
*/
std::string Protagonista::muestra_datos()
{
    std::stringstream datos;

    datos << "Los datos del protagonista de la historia: " << std::endl
          << "El nombre del personaje es: " << nombre
          << "\nLos base stats del personaje son los siguientes: "
          << "\n- Ataque: " << ataque
          << "\n- Vida: " << vida
          << "\n- Habilidad especial: " << habilidad
          << "\n- Danio de habilidad especial: " << danio_habilidad
          << "\n- Defensa: " << defensa
          << "\n- Paciencia: " << paciencia
          << std::endl
          << std::endl;

    return datos.str();
}

/*
Se encarga de simular el momento en que el protagonista recoge su xbox
para sacarlo del peligro.
params: no recibe parametros
*/
std::string Protagonista::recoger_xbox()
{
    std::stringstream xbox;
    jugando_xbox = false;

    xbox << "El Xbox se ha recogido exitosamente";

    return xbox.str();
};