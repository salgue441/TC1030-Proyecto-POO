#pragma once

#include "personaje.h"

/* ---- Constructores ---- */
// constructor default
Personaje::Personaje() : nombre("None"), habilidad("None")
{
    ataque = 0.0;
    defensa = 0;
    danio_habilidad = 0.0;
};

// para los NPC
Personaje::Personaje(std::string p_name, std::string p_habil)
    : nombre(p_name), habilidad(p_habil)
{
    ataque = 0.0;
    defensa = 0;
    danio_habilidad = 0.0;
};

// para protagonista, antagonista y guardia
Personaje::Personaje(std::string p_name, double p_ataque,
                     int p_vida, std::string p_habilidad,
                     double p_danio_hab, int p_defensa)
    : nombre(p_name), habilidad(p_habilidad)
{
    ataque = p_ataque;
    vida = p_vida;
    danio_habilidad = p_danio_hab;
    defensa = p_defensa;
};

/* ---- Destructor ---- */
Personaje::~Personaje()
{
    vida = 0;
}

/* ---- Access Methods ---- */
std::string Personaje::get_nombre() { return nombre; }
std::string Personaje::get_habilidad() { return habilidad; }

void Personaje::set_ataque(double p_ataque) { p_ataque = ataque; }
double Personaje::get_ataque() { return ataque; }

int Personaje::get_defensa() { return defensa; }
double Personaje::get_danio_habilidad() { return danio_habilidad; }

void Personaje::set_vida(int p_vida) { vida = p_vida; }
int Personaje::get_vida() { return vida; }

/* ---- Funciones ---- */
/*
Se encarga de restar la vida de un personaje con el danio del ataque
de otro personaje.
params:
    - personaje_atacado: referencia a un objeto de tipo personaje. Es el
        objeto que recibe el danio.
    - personaje_atacante: referencia a un objeto de tipo personaje. Es el
        objeto que hace el danio.
*/
void Personaje::ataca_personaje(Personaje &receptor)
{
    double danio_total;

    danio_total = abs(ataque - receptor.get_vida());

    receptor.set_vida(danio_total);

    if (receptor.get_vida() <= 0)
        receptor.set_vida(0);
}

/*
Se encarga de mejorar el ataque de los personajes en un unico instante.
params: no recibe parametros
*/
void Personaje::ataque_especial(Personaje &receptor)
{
    double multiplicador_especial = 3, ataque_unico;
    ataque_unico = ataque * multiplicador_especial;

    receptor.set_ataque(ataque_unico);
}

/*
Se encarga de visualizar todos los datos del objeto personaje seleccionado.
params:
    - personaje: referencia de objeto de tipo Personaje.
*/
std::string Personaje::muestra_datos()
{
    std::stringstream datos;

    datos << "El nombre del personaje es: " << nombre
          << "\nLos base stats del personaje son los siguientes: "
          << "\n- Ataque: " << ataque
          << "\n- Vida: " << vida
          << "\n- Habilidad especial: " << habilidad
          << "\n- Danio de habilidad especial: " << danio_habilidad
          << "\n- Defensa: " << defensa
          << std::endl
          << std::endl;

    return datos.str();
}

void Personaje::ayudar(Personaje &ayudado)
{
    int multiplier = 0.10;
    double ataque_ayuda;

    ataque_ayuda = ataque * multiplier;
    ayudado.set_ataque(ataque_ayuda);
}