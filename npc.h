#ifndef NPC_H
#define NPC_H

#include <string>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "personaje.cpp"

class NPC : public Personaje
{
public:
    /* ---- Constructores ---- */
    NPC();
    NPC(std::string, std::string);

    /* ---- Funciones ---- */
    void pick_random_tip();
    std::string muestra_datos();

private:
    std::string tips_arr[7] = {
        "Si tomas, no manejes",
        "No hagas enojar a tus amigos",
        "No hagas que te corran de tu casa",
        "No te pongas mala copa en un antro",
        "No te pongas mala copa en tu casa",
        "No pelees con residentes",
        "No pelees con el guardia"};
};

#endif // !NPC_H