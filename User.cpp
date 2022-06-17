#pragma once

#include "User.h"

/* ---- Constructor ---- */
// default
User::User() : nombre("None"), fecha_de_nacimiento("None"),
               edad(18), direccion("None"), contrasena("None"){};

// para comparar en la funcion log_in()
User::User(std::string p_name, std::string p_pass)
    : nombre(p_name), contrasena(p_pass){};

// creacion de objetos
User::User(std::string p_name, int p_age, std::string p_pass,
           std::string nacimiento) : nombre(p_name), edad(p_age),
                                     contrasena(p_pass),
                                     fecha_de_nacimiento(nacimiento){};

/* ---- Access Methods ---- */
void User::set_name(std::string nom) { nombre = nom; }
std::string User::get_nombre() { return nombre; }

int User::get_edad() { return edad; }
std::string User::get_fecha_de_nacimiento() { return fecha_de_nacimiento; }

void User::set_direccion(std::string dir) { direccion = dir; }
std::string User::get_direccion() { return direccion; }

void User::set_password(std::string password) { contrasena = password; }
std::string User::get_password() { return contrasena; }

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
    personajes[id] = new Antagonista("Berto", 15, 100, "Mala Copa", 12, 30, 5);
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
Se encarga de editar los valores guardados en los objetos de usuario
params:
    - usuario: referencia a objeto de tipo usuario.
    Se modifican los valores guardados dentre de este objeto
*/
void User::actualizar_datos(User &usuario)
{
    int opt;
    std::string new_name, new_direccion, new_password;

    std::cout << "Que elemento quieres modificar: "
              << "\n1. Nombre"
              << "\n2. Direccion"
              << "\n3. Contrasena"
              << std::endl;
    std::cin >> opt;

    switch (opt)
    {
    case 1: // nombre
        std::cout << "Ingresa el nuevo nombre: ";
        std::cin.ignore();
        std::getline(std::cin, new_name);
        usuario.set_name(new_name);
        break;

    case 2: // direccion
        std::cout << "Ingresa la nueva direccion: ";
        std::cin.ignore();
        std::getline(std::cin, new_direccion);
        usuario.set_direccion(new_direccion);
        break;

    case 3: // contrasena
        std::cout << "Ingresa la nueva contrasena: ";
        std::cin.ignore();
        std::getline(std::cin, new_password);
        usuario.set_password(new_password);
        break;

    default:
        break;
    } // fin del switch
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

/*
Se encarga de eliminar los objetos que ya no son necesarios para el
desarrollo del juego.
params:
    iden: variable de tipo int, es el numero identificador del objeto a
    eliminar
*/
void User::elimina_personaje(int iden)
{
    delete personajes[iden];
    personajes[iden] = nullptr;
    id = id - iden;
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

/*
Se encarga de mostrar los datos de los objetos de usuario.
params: no recibe parametros
*/
std::string User::mostrar_datos()
{
    std::stringstream datos;

    datos << "Datos del usuario: "
          << "\nNombre: " << nombre
          << "\nDireccion: " << direccion
          << "\nFecha de nacimiento" << fecha_de_nacimiento
          << "\nEdad: " << edad
          << std::endl
          << std::endl;

    return datos.str();
}
