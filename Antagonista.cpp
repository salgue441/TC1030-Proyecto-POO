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
Se encarga de modificar el danio del antagonista solo si su nivel de
embriaguez es mayor que 40.
params:
    - ant: referencia a objeto de tipo antagonista
*/
void Antagonista::danio_agregado(Antagonista &ant)
{
    double extra_danio = 10, nuevo_total;

    if (ant.get_nivel_embriaguez() > 40)
    {
        nuevo_total = ant.get_ataque() * 10;
        ant.set_ataque(nuevo_total);
    }
}

/*
Se encarga de bendecir el lugar de residencia
params: no recibe parametros
*/
std::string Antagonista::bendecir_el_lugar(Antagonista &ant)
{
    return "El antagonista ha bendecido el lugar";
}

/*
Se encarga de preguntar al usuario si se quiere unir a tomar
params: no recibe parametros
*/
void Antagonista::invitar_a_tomar()
{
    char opt;
    std::cout << "Quieres tomar? (S/N)";
    std::cin >> opt;

    if (opt == 'S' || opt == 's')
    {
        std::cout << "Te has unido a tomar" << std::endl;
    }
    else
        std::cout << "No te has unido a tomar" << std::endl;
}

/*
Se encarga de modificar el nivel de embriaguez del antagonista
params:
    - bebida: tipo de dato 'double'.
    - ant: referencia a objeto de tipo Antagonista. Usado para modificar
        el valor de nivel de embriaguez
*/
void Antagonista::tomar(double bebida, Antagonista &ant)
{
    double multiplicador = bebida / 7.5, nuevo_nivel;

    nuevo_nivel = ant.get_nivel_embriaguez() * multiplicador;
    ant.set_nivel_embriaguez(nuevo_nivel);
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