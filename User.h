#ifndef USER_H
#define USER_H

#include <string>
#include <sstream>
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
    // para comparar en la funcion log_in()
    User(std::string, std::string);
    User(std::string, int, std::string, std::string);

    /* ---- Access methods ---- */
    void set_name(std::string);
    std::string get_nombre();

    int get_edad();
    std::string get_fecha_de_nacimiento();

    void set_direccion(std::string);
    std::string get_direccion();

    void set_password(std::string);
    std::string get_password();

    void set_personaje(Personaje);
    Personaje get_personaje();

    /* ---- funciones ---- */
    void crea_personaje();
    void muestra_personajes();
    void actualizar_datos(User &);
    // composicion
    void agrega_guardia(std::string, double, int, std::string, double, int,
                        std::string, double);
    void agrega_npc(std::string, std::string);
    std::string mostrar_datos();

private:
    std::string nombre, direccion, contrasena, fecha_de_nacimiento;
    int edad, id;
    Personaje *personajes[MAX], personaje;
};

#endif //! USER_H
