#pragma once

#include "Antagonista.h"

/* ---- Constructores ---- */
Antagonista::Antagonista() : Personaje(), nivel_embriaguez(0.0){};
Antagonista::Antagonista(std::string p_nombre, double p_ataque,
                         int p_vida, std::string p_habilidad,
                         double p_danio_habilidad,
                         int p_defensa, int p_nivel_embriaguez)
    : Personaje(p_nombre, p_ataque, p_vida, p_habilidad, p_danio_habilidad,
                p_defensa),
      nivel_embriaguez(p_nivel_embriaguez){};

/* ---- Access Methods ---- */
void Antagonista::set_nivel_embriaguez(int borracho) { nivel_embriaguez = borracho; }
int Antagonista::get_nivel_embriaguez() { return nivel_embriaguez; }

/* ---- Funciones ---- */
/*
Se encarga de bendecir el lugar de residencia
params: no recibe parametros
*/
std::string Antagonista::bendecir_el_lugar()
{
    return "El antagonista ha bendecido el lugar";
}

/*
Se encarga de visualizar todos los datos del objeto personaje seleccionado.
params: no recibe parametros
*/
std::string Antagonista::muestra_datos()
{
    std::stringstream datos;

    datos << "Los datos del antagonista de la historia: " << std::endl
          << "El nombre del personaje es: " << nombre
          << "\nLos base stats del personaje son los siguientes: "
          << "\n- Ataque: " << ataque
          << "\n- Vida: " << vida
          << "\n- Habilidad especial: " << habilidad
          << "\n- Danio de habilidad especial: " << danio_habilidad
          << "\n- Defensa: " << defensa
          << "\n- Nivel de embriaguez: " << nivel_embriaguez
          << std::endl
          << std::endl;

    return datos.str();
}