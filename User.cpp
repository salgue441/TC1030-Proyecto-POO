#pragma once

#include "User.h"

/* ---- Constructor ---- */
// default
User::User(){};

/* ---- Access Methods ---- */
/*
Son referencias para no generar una copia del objeto y modificar los valores
existentes de la clase. En get_npc() se hace un iden + 3 para empezar a contar
los NPC generados desde 0 y no desde la posicion 3.
*/
Protagonista &User::get_protagonista() { return *(Protagonista *)personajes[0]; }
Antagonista &User::get_antagonista() { return *(Antagonista *)personajes[1]; }
Guardia &User::get_guardia() { return *(Guardia *)personajes[2]; }
NPC &User::get_npc(int iden) { return *(NPC *)personajes[iden + 3]; }

/* ---- Funciones ---- */
/*
Se encarga de generar los objetos (personajes iniciales) en Personajes[]
de tipo Protagonista, Antagonista, Guardia y NPC y los guarda en
la variable de instancia en personajes[] (arreglo de Personajes).
params: no recibe parametros
*/
void User::crea_personaje()
{
    personajes[id] = new Protagonista("Nando", 75, 100, "Patada", 39, 67, 100);
    id++;
    personajes[id] = new Antagonista("Berto", 10, 100, "Mala Copa", 12, 30, 5);
    id++;
    personajes[id] = new Guardia("Claudia", 30, 100, "Llamar a poli", 0, 75, "Pedir taxi", 0);
    id++;
    personajes[id] = new NPC("Dan", "Paciencia");
    id++;
    personajes[id] = new NPC("Mady", "Camuflaje");
    id++;
}

/*
Se encarga de imprimir los objetos generados en la funcion
crea_personaje(). Utiliza el arreglo de personajes[] y el id, para
recorrer todo el arreglo imprimiendo cada uno de los objetos con la
funcion muestra_datos()
params: no recibe parametros
*/
void User::muestra_personajes()
{
    for (int i = 0; i < id; i++)
        if (personajes[i] != nullptr)
            std::cout << personajes[i]->muestra_datos();
}

/*
Se encarga de agregas mas objetos de tipo NPC al arreglo de personajes
params:
    - p_nombre: variable de tipo string, es el nombre del objeto (personaje)
    - p_danio: variable de tipo double, es el ataque del personaje
    - p_vida: variable de tipo int, es la vida total del personaje
    - p_habil: variable de tipo string, es el nombre de la habilidad
    - p_habil_d: variable de tipo double, es el danio de la habilidad
        especial del personaje
    - p_habil_unica: variable de tipo string, es el nombre de la habilidad
        unica de este tipo de personaje
    - p_habil_unica_d: variable de tipo double, es el danio de la habilidad
        unica de este personaje
*/
void User::agrega_guardia(std::string p_nombre, double p_danio, int p_vida,
                          std::string p_habil, double p_habil_d,
                          int p_defensa, std::string p_habil_unica,
                          double p_habil_unica_d)
{
    personajes[id] = new Guardia(p_nombre, p_danio, p_vida, p_habil,
                                 p_habil_d, p_defensa, p_habil_unica,
                                 p_habil_unica_d);
    id++;
}

/*
Se encarga de agregas mas objetos de tipo NPC al arreglo de personajes
params:
    - p_nombre: variable de tipo string, es el nombre del objeto (personaje)
    - p_habil: variable de tipo string, es el nombre de la habilidad
*/
void User::agrega_npc(std::string p_nombre, std::string p_habil)
{
    personajes[id] = new NPC(p_nombre, p_habil);
    id++;
}

void User::elimina_personajes_todos()
{
    for (int i = 0; i < id; i++)
    {
        delete personajes[i];
        personajes[i] = nullptr;
    }

    id = 0; // index reset
}
