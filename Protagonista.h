#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H

#include "personaje.cpp"

class Protagonista : public Personaje
{
public:
    /* ---- Constructores ---- */
    Protagonista(); // default
    Protagonista(std::string, double, int, std::string, double, int, int);

    /* ---- Access Methods ---- */
    void set_paciencia(int);
    int get_paciencia();

    /* ---- Funciones ---- */
    std::string muestra_datos();
    std::string recoger_xbox();

private:
    int paciencia;
    bool jugando_xbox = true;
};

#endif