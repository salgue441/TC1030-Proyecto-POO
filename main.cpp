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
    char choice_1, choice_2, choice_3, choice_4;
    bool running = true;

    while (running)
    {
        std::cout << std::endl
                  << "BIENVENIDO AL JUEGO LES JABITESS"
                  << std::endl;

        menu();
        std::cout << "Ingresa el numero de la opcion que deseas realizar: ";
        std::cin >> menu_opt;

        switch (menu_opt)
        {
        case 1:
            std::cout << "\nGenerando personajes" << std::endl;

            sleep(1);
            progress_bar();
            sleep(1);

            // break line
            std::cout << std::endl;
            user1.crea_personaje();

            // parte inicial de la historia
            std::cout << "La historia comienza en el cumpleanos de "
                      << user1.get_antagonista().get_nombre()
                      << std::endl
                      << "Este dia "
                      << user1.get_antagonista().get_nombre()
                      << " celebra sus 26 anios con "
                      << user1.get_npc(0).get_nombre() << " y "
                      << user1.get_npc(1).get_nombre()
                      << " en el antro Jepe la Vaca." << std::endl;

            std::cout << "En el antro "
                      << user1.get_antagonista().get_nombre()
                      << " toma dos botellas de Tequila mientras disfruta"
                      << " de la cancion Norwegian Reggaeton y otros temazos. "
                      << std::endl;

            // aumenta el nivel de embriaguez del antagonista
            user1.get_antagonista()
                .set_nivel_embriaguez(20);

            std::cout
                << user1.get_antagonista().get_nombre()
                << ", " << user1.get_npc(0).get_nombre() << " y "
                << user1.get_npc(1).get_nombre()
                << " siguen disfrutando hasta las 03:30 de la manana."
                << " A esta hora, deciden pedir que Don Noveno los"
                << " recoga a esa hora. "
                << std::endl;

            std::cout << std::endl
                      << "----< Don Noveno recoge al trio >----"
                      << std::endl;

            std::cout << user1.get_antagonista().get_nombre() << ", "
                      << user1.get_npc(0).get_nombre() << " y "
                      << user1.get_npc(1).get_nombre()
                      << "se dirigen a Jabitee para descansar. "
                      << "Durante su venida, "
                      << user1.get_antagonista().get_nombre()
                      << " empieza a molestar a "
                      << user1.get_npc(0).get_nombre() << " y "
                      << user1.get_npc(1).get_nombre() << ". "
                      << "Despues de un tiempo, "
                      << user1.get_npc(0).get_nombre() << " y "
                      << user1.get_npc(1).get_nombre()
                      << " deciden bajarse del coche y dejar que "
                      << "Don Noveno lleve a "
                      << user1.get_antagonista().get_nombre()
                      << " Jabitee. " << std::endl
                      << std::endl;

            std::cout << "----< Mientras "
                      << user1.get_antagonista().get_nombre()
                      << " se dirige con Don Noveno a Jabitee, "
                      << "algo sucede y hace que Don Noveno deje a "
                      << user1.get_antagonista().get_nombre()
                      << " en la entrada peatonal del Nesquick Factory"
                      << " >----"
                      << std::endl;
            std::cout << std::endl; // break line

            // perspectiva del antagonista
            std::cout << "----< Perspectiva de Berto >---- "
                      << std::endl;

                        std::cout << "" << std::endl;

            std::cout << std::endl; // break line

            // perspectiva del protagonista
            std::cout
                << "----< Perspectiva de Nando >---- " << std::endl
                << "Al mismo tiempo, nuestro protagonista "
                << user1.get_protagonista().get_nombre()
                << " se encuentra jugando Destiny Two"
                << " \nen su Xbox One en la sala de Jabitee."
                << "De repente, " << user1.get_protagonista().get_nombre()
                << " se pregunta si irse a \ndormir o seguir jugando."
                << std::endl;

            std::cout << "Seguir jugando (S/N)?" << std::endl;
            std::cin >> choice_1;

            if (choice_1 == 'S' || choice_1 == 's')
            {
                std::cout << user1.get_protagonista().get_nombre()
                          << " continuo jugando Destiny por 2 horas"
                          << std::endl;

                std::cout << std::endl; // break line
                std::cout << "Despues de 1 hora y media, "
                          << user1.get_antagonista().get_nombre()
                          << " ha entrado a Jabitee. Se muestra molesto"
                          << " y se dirige hacia nuestro protagonista."
                          << "\n"
                          << user1.get_protagonista().get_nombre()
                          << " observa que entra pero no le presta mucha"
                          << " importancia" << std::endl;

                std::cout << "----< Despues de un tiempo >----"
                          << std::endl;

                std::cout << user1.get_antagonista().get_nombre()
                          << " le pregunta a "
                          << user1.get_protagonista().get_nombre()
                          << " si desea ir a tomar al rooftop del edificio."
                          << user1.get_protagonista().get_nombre()
                          << " oberva que la botella es de Johnny Walker "
                          << " (A "
                          << user1.get_protagonista().get_nombre()
                          << " no le gusta el Whiskey)"
                          << std::endl;

                std::cout << "Deseas ir a tomar al rooftop (S/N)?";
                std::cin >> choice_2;

                if (choice_2 == 'S' || choice_2 == 's')
                {
                    std::cout << user1.get_protagonista().get_nombre()
                              << " ha decidido ir a tomar al rooftop"
                              << " con "
                              << user1.get_antagonista().get_nombre()
                              << "Por lo que el juego ha terminado"
                              << std::endl;
                }
                else
                {
                    std::cout << user1.get_protagonista().get_nombre() << " y "
                              << user1.get_antagonista().get_nombre()
                              << " se quedan en la sala de Jabitee. "
                              << std::endl
                              << user1.get_antagonista().get_nombre()
                              << " ha decidido seguir tomando mientras observa a "
                              << user1.get_protagonista().get_nombre()
                              << " jugar Xbox." << std::endl;

                    user1.get_antagonista().get_nivel_embriaguez() + 10;

                    // agrega nuevos NPC a la historia,
                    // son utilizados en el desarrollo de la historia
                    user1.agrega_npc("Almu", "Mala Suerte");
                    user1.agrega_npc("Turbina", "Dormir como nunca");
                    user1.agrega_npc("El Doc", "A mimir");
                    user1.agrega_npc("Jorge", "Desinteres");

                    std::cout << std::endl; // break line

                    // usado para liberar la memoria
                    user1.elimina_personaje(4);
                }
            }
            else
            {
                std::cout << user1.get_protagonista().get_nombre()
                          << " ha decidido irse a dormir. "
                          << "Por lo que el juego ha terminado"
                          << std::endl;
            }
            break;

        case 2:
            // muestra las indicaciones de la historia
            mostrar_indicaciones();
            break;

        case 3:
            // muestra todos los personajes de la historia
            // agregando los NPC que se generan al final de la historia
            user1.agrega_npc("Almu", "Mala Suerte");
            user1.agrega_npc("Turbina", "Dormir como nunca");
            user1.agrega_npc("El Doc", "A mimir");
            user1.agrega_npc("Jorge", "Desinteres");

            // mostrando los personajes
            user1.muestra_personajes();
            break;

        case 4:
            std::cout << "Se ha salido con exito!" << std::endl;
            running = false;
            break;

        default:
            break;
        }
    }
    return 0;
}

/*
Funcion que muestra el menu principal del juego
params: no recibe parametros
*/
void menu()
{
    std::cout << "\nMenu principal";
    std::cout << "\n1. Iniciar juego \n2. Mostrar indicaciones"
              << "\n3. Mostrar personajes \n4. Salir del programa"
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

    std::cout << "Los indicadores '----< >----' muestran el paso del"
              << " tiempo, comentarios generales o las diferentes perspectivas"
              << " de los peresonajes. "
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
