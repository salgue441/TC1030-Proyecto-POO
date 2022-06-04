// en caso de tener windows o linux-based system,
// usado para la funcion sleep()
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "User.cpp"

// funciones utilizadas en main
void menu();
void progress_bar();
void mostrar_indicaciones();
void sign_up();
std::string log_in();

int main()
{
    User user1;
    int menu_opt;
    bool running = true;

    while (running)
    {
        std::cout << "---- Bienvenido al juego Les Jabitess ----"
                  << std::endl;

        menu();
        std::cout << "Ingresa el numero de la opcion que deseas realizar: ";
        std::cin >> menu_opt;

        if (menu_opt == 1)
        {
            std::cout << "\nGenerando personajes" << std::endl;
            progress_bar();
            sleep(2);

            // break line
            std::cout << std::endl;

            user1.crea_personaje();

            std::cout << "Los personajes generados son: " << std::endl;
            user1.muestra_personajes();

            // agrega nuevos NPC a la historia
            std::cout << "Agregando nuevos personajes: " << std::endl;
            user1.agrega_npc("Almu", "Mala Suerte");
            user1.agrega_npc("Turbina", "Dormir como nunca");
            user1.agrega_npc("El Doc", "A mimir");
            user1.agrega_npc("Jorge", "Desinteres");

            std::cout << "Se han generado los nuevos NPC" << std::endl;
            progress_bar();

            std::cout << "A continuacion se muestran los nuevos personajes: " << std::endl;
            user1.muestra_personajes();
        }
        else if (menu_opt == 2)
            mostrar_indicaciones();
        else
            running = false;
    }

    return 0;
}

/*
Funcion que muestra el menu principal del juego
params: no recibe parametros
*/
void menu()
{
    std::cout << "Menu principal";
    std::cout << "\n1. Iniciar juego \n2. Mostrar indicaciones"
              << "\n3.Salir del programa"
              << std::endl;
}

/*
Se encarga de generar una progress bar sencilla para mostrar 'visualmente'
al usuario cuando se generan los personajes. Basado en la solucion con
mas upvotes de
https://stackoverflow.com/questions/14539867/how-to-display-a-progress-indicator-in-pure-c-c-cout-printf
params: no recibe parametros
*/
void progress_bar()
{
    float progreso_inicial = 0.0;

    while (progreso_inicial <= 1.0)
    {
        int barWidth = 70;
        std::cout << "[";

        int pos = barWidth * progreso_inicial;

        for (int i = 0; i < barWidth; i++)
        {
            if (i < pos)
                std::cout << "=";
            else if (i == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }

        std::cout << "]" << int(progreso_inicial * 100.0) << " %\r";
        std::cout.flush();

        progreso_inicial += 0.5;
    }

    std::cout << std::endl;
}

/*
Se encarga de mostrar las instrucciones principales del programa al usuario
params: no recibe parametros
*/
void mostrar_indicaciones()
{
    std::cout << "\n\n---- Instrucciones de Uso ----" << std::endl;
    std::cout << "Contexto: El juego consiste en un roleplay, "
              << "siendo el usuario el personaje principal de la historia."
              << "\nA lo largo del juego el usuario tendra la posibilidad"
              << "de escoger diferentes caminos que el juego puede seguir."
              << std::endl
              << std::endl;

    std::cout << "El juego solo corre en la terminal por lo que"
              << " toda la interaccion con el usuario sucede por esta misma."
              << "\nAl momento de dar a escoger al usuario dos posibilidades, "
              << "este podra ingresar una de las dos opciones mostradas "
              << "por la terminal"
              << std::endl
              << std::endl;
}

/* ---- < Las siguientes funciones siguen en proceso > ---- */
/*
Funcion que se encarga de crear un usuario y contrasena.
Al tener los datos, los guarda en el archivo de texto user.txt para
ser leido por la funcion log_in();
params: no tiene parametros.
*/
// void sign_up()
// {
//   std::ofstream usuario_file;
//   std::string username, contra, birth;
//   int age;

//   std::cout << "Sign Up" << std::endl;
//   std::cout << "Username: ";
//   std::cin.ignore();
//   std::getline(std::cin, username);

//   std::cout << "Age: ";
//   std::cin >> age;

//   std::cout << "Fecha de nacimiento: ";
//   std::cin.ignore();
//   std::getline(std::cin, birth);

//   std::cout << "Contrasena: ";
//   std::cin.ignore();
//   std::getline(std::cin, contra);

//   usuario_file.open("usuario.txt", std::ios::in);
//   usuario_file << username << std::endl
//                << contra << std::endl;
//   usuario_file.close();

//   User user1(username, age, birth, contra);
// }

/*
Funcion que se encarga de leer los datos del usuario y los compara
con los datos almacenados en el archivo de texto user.txt.
params: no tiene parametros.
*/
// std::string log_in()
// {
//   /*
//   estructura local. Usada para retornar mas de un valor de la
//   misma funcion.
//   */
//   struct return_values
//   {
//     std::string username, password;
//   };

//   std::string local_username, local_password;

//   std::cout << "---- Log In ----" << std::endl;
//   std::cout << "Username: ";
//   std::cin.ignore();
//   std::getline(std::cin, local_username);

//   std::cout << "Password: ";
//   std::cin.ignore();
//   std::getline(std::cin, local_password);

//   return return_values{local_username, local_password};
// }