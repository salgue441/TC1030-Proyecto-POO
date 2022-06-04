#pragma once

#include "npc.h"

/* ---- Constructores ---- */
NPC::NPC() : Personaje(){};
NPC::NPC(std::string p_name, std::string p_habil) : Personaje(p_name, p_habil){};

/* ---- Funciones ---- */
/*
Se encarga de escoger aleatoriamente uno de los tips guardados
en el vector tips_vec[]. Utiliza la funcion rand() para generar
los indices aleatorios.
params: no recibe parametros
return: el indice aleatorio generado
*/
std::string NPC::pick_random_tip()
{
    return tips_vec[rand() % tips_len];
}

/*
Se encarga de mostrar el tip aleatorio en la consola. Esta funcion
sirve para mostrar tips al usuario al momento de jugar el videojuego.
params: no recibe parametros
return:
*/
std::string NPC::dar_tips()
{
    std::string new_tip;
    return new_tip;
}

/*
Se encarga de visualizar todos los datos del objeto personaje seleccionado.
params: no recibe parametros
*/
std::string NPC::muestra_datos()
{
    std::stringstream datos;

    datos << "Los datos de los NPC de la historia: " << std::endl
          << "El nombre del personaje es: " << nombre
          << "\nLos base stats del personaje son los siguientes: "
          << "\n- Habilidad especial: " << habilidad
          << std::endl
          << std::endl;

    return datos.str();
}