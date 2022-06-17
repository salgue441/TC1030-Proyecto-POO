#ifndef USER_H
#define USER_H

#include <string>
#include "personaje.cpp"
#include "Protagonista.cpp"
#include "Antagonista.cpp"
#include "Guardia.cpp"
#include "npc.cpp"

const int MAX = 1000;
class User
{
public:
    /* ---- Constructores ---- */
    User(); // default

    /* ---- Access methods ---- */
    // funciones para interactuar con los personajes
    Protagonista &get_protagonista();
    Antagonista &get_antagonista();
    Guardia &get_guardia();
    NPC &get_npc(int);

    /* ---- funciones ---- */
    void crea_personaje();
    void muestra_personajes();
    void actualizar_datos(User &);

    // composicion
    void agrega_guardia(std::string, double, int, std::string, double, int,
                        std::string, double);
    void agrega_npc(std::string, std::string);
    void elimina_personajes_todos();

private:
    int id;
    Personaje *personajes[MAX];
};

#endif //! USER_H
