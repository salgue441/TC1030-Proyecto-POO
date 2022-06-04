#ifndef NPC_H
#define NPC_H

#include <string>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "personaje.cpp"

class NPC : public Personaje
{
public:
    /* ---- Constructores ---- */
    NPC();
    NPC(std::string, std::string);

    /* ---- Funciones ---- */
    std::string dar_tips();
    std::string pick_random_tip();
    std::string muestra_datos();
    void agrega_personaje_npc(std::string, std::string);

private:
    std::vector<std::string> tips_vec = {
        "Si tomas, no manejes",
        "No hagas enojar a tus amigos",
        "No hagas que te corran de tu casa",
        "No te pongas mala copa en un antro",
        "No te pongas mala copa en tu casa",
        "No pelees con residentes",
        "No pelees con el guardia"};
    int tips_len = sizeof(tips_vec);
};

#endif // !NPC_H