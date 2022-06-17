#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>
#include <sstream>

class Personaje
{
public:
    /* ---- Constructores ---- */
    Personaje();                         // default
    Personaje(std::string, std::string); // para NPC
    // para protagonista, antagonista y guardia
    Personaje(std::string, double, int, std::string, double, int);

    /* ---- Destructor ---- */
    ~Personaje();

    /* ---- Access Methods ---- */
    std::string get_nombre();
    std::string get_habilidad();

    void set_ataque(double);
    double get_ataque();

    double get_danio_habilidad();
    int get_defensa();

    void set_vida(int);
    int get_vida();

    /* ---- Funciones ---- */
    void ataca_personaje(Personaje &);
    virtual std::string muestra_datos() = 0;

protected:
    std::string nombre, habilidad;
    double ataque, danio_habilidad;
    int defensa, vida = 100;
};

#endif //! PERSONAJE_H