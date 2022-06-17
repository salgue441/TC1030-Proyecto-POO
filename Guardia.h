#ifndef GUARDIA_H
#define GUARDIA_H

#include <string>
#include "personaje.cpp"

class Guardia : public Personaje
{
public:
    /* ---- Constructores ---- */
    Guardia();
    Guardia(std::string, double, int, std::string, double, int,
            std::string, double);

    /* ---- Access Methods ---- */
    std::string get_habilidad_unique();
    double get_danio_habilidad_unique();

    /* ---- Funciones ---- */
    void llamar_a_policia();
    std::string muestra_datos();

private:
    std::string habilidad_unique;
    double danio_unique;
    bool habilidad_gastada = false;
};

#endif //! GUARDIA_H