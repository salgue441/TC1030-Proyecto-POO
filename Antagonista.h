#ifndef ANTAGONISTA_H
#define ANTAGONISTA_H

#include <iostream>
#include "personaje.cpp"

class Antagonista : public Personaje
{
public:
    /* ---- Constructores ---- */
    Antagonista();
    Antagonista(std::string, double, int, std::string, double, int, int);

    /* ---- Access Methods ---- */
    void set_nivel_embriaguez(int);
    int get_nivel_embriaguez();

    /* ---- Funciones ---- */
    void danio_agregado(Antagonista &);
    std::string bendecir_el_lugar(Antagonista &);
    void invitar_a_tomar();
    void tomar(double, Antagonista &);
    std::string muestra_datos();

private:
    double mala_copa;
    int nivel_embriaguez;
};

#endif //! ANTAGONISTA_H