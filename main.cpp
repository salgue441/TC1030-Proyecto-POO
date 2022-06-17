/*
Escoge la libreria correspondiente para dispositivos con sistema operativo
Windows (_WIN32) y linux-based systems para utilizar la funcion de sleep().
Al entrar en sistemas con windows, hace un define de NOMINMAX para que la
funcion max() no reciba parametros e incluye la libreria correspondiente
para sleep() en windows. En el caso de ser un linux-based system, incluye
la libreria correspondiente para sleep() y no se necesita definir NOMINMAX
*/
#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <limits>
#include "User.cpp"

// funciones utilizadas en main
void menu();
void progress_bar();
void mostrar_indicaciones();
void show_credits();

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

        /*
        Se encarga de controlar el input del usuario. Si el valor no es numerico,
        muestra al usuario que su entranda no es valida y les pide ingresar
        una nueva entrada. Evita que el programa cicle infinitamente si el
        usuario ingresa un tipo de dato que no es el correcto.
        */
        while (!(std::cin >> menu_opt))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n');

            std::cout << "Entrada invalida, intenta de nuevo: ";
        }

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

            std::cout << std::endl; // break line
            // aumenta el nivel de embriaguez del antagonista
            user1.get_antagonista().set_nivel_embriaguez(15);
            std::cout << "(" << user1.get_antagonista().get_nombre()
                      << " su nuevo nivel de embriaguez es: "
                      << user1.get_antagonista().get_nivel_embriaguez()
                      << ")"
                      << std::endl;

            std::cout << std::endl; // break line

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

            std::cout << "Despues de 15 minutos, "
                      << user1.get_npc(0).get_nombre() << " y "
                      << user1.get_npc(1).get_nombre()
                      << "llegan a Jabitee. Saludan a "
                      << user1.get_protagonista().get_nombre()
                      << " y se despiden (se fueron a dormir). "
                      << std::endl;

            std::cout << std::endl; // break line

            std::cout << "----< Mientras "
                      << user1.get_antagonista().get_nombre()
                      << " se dirige con Don Noveno a Jabitee, "
                      << "algo sucede y hace que Don Noveno deje a "
                      << user1.get_antagonista().get_nombre()
                      << " en la entrada peatonal del Nesquick Factory"
                      << " >----"
                      << std::endl;

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

            std::cout << std::endl; // break line
            std::cout << "Seguir jugando (S/N)? ";
            std::cin >> choice_1;

            if (choice_1 == 'S' || choice_1 == 's')
            {
                std::cout << std::endl; // break line
                std::cout << user1.get_protagonista().get_nombre()
                          << " continuo jugando Destiny por 2 horas"
                          << std::endl;

                std::cout << std::endl; // break line

                std::cout << "Despues de 1 hora y media, "
                          << user1.get_antagonista().get_nombre()
                          << " ha entrado a Jabitee. Se muestra molesto"
                          << " y se dirige hacia nuestro protagonista."
                          << user1.get_protagonista().get_nombre()
                          << " observa que entra pero no le presta mucha"
                          << " importancia. "
                          << "En el mismo instante, "
                          << user1.get_antagonista().get_nombre()
                          << " se queda sentado cerca de "
                          << user1.get_protagonista().get_nombre()
                          << "."
                          << std::endl
                          << std::endl;

                std::cout << "----< Despues de un tiempo >----"
                          << std::endl;

                std::cout << user1.get_antagonista().get_nombre()
                          << " le pregunta a "
                          << user1.get_protagonista().get_nombre()
                          << " si desea ir a tomar al rooftop del edificio. "
                          << user1.get_protagonista().get_nombre()
                          << " oberva que la botella es de Johnny Walker "
                          << " (A "
                          << user1.get_protagonista().get_nombre()
                          << " no le gusta el Whiskey)"
                          << std::endl;

                std::cout << std::endl; // break line
                std::cout << "\nDeseas ir a tomar al rooftop (S/N)? ";
                std::cin >> choice_2;

                if (choice_2 == 'S' || choice_2 == 's')
                {
                    std::cout << std::endl; // break line
                    std::cout << user1.get_protagonista().get_nombre()
                              << " ha decidido ir a tomar al rooftop"
                              << " con "
                              << user1.get_antagonista().get_nombre()
                              << "Por lo que el juego ha terminado"
                              << std::endl;

                    // limpiando la memoria
                    user1.elimina_personajes_todos();
                }
                else
                {
                    std::cout << user1.get_protagonista().get_nombre()
                              << " y "
                              << user1.get_antagonista().get_nombre()
                              << " se quedan en la sala de Jabitee. "
                              << std::endl
                              << user1.get_antagonista().get_nombre()
                              << " ha decidido seguir tomando mientras"
                              << " observa a "
                              << user1.get_protagonista().get_nombre()
                              << " jugar Xbox." << std::endl
                              << std::endl;

                    user1.get_antagonista().set_nivel_embriaguez(30);

                    std::cout << "----< Mientras "
                              << user1.get_protagonista().get_nombre()
                              << " continua jugando Xbox, "
                              << user1.get_antagonista().get_nombre()
                              << " sigue tomando."
                              << " >----" << std::endl;

                    user1.get_antagonista().set_nivel_embriaguez(50);
                    std::cout << "(" << user1.get_antagonista().get_nombre()
                              << " su nuevo nivel de embriaguez es: "
                              << user1.get_antagonista().get_nivel_embriaguez()
                              << ")"
                              << std::endl;

                    std::cout << "Despues de un rato, "
                              << user1.get_protagonista().get_nombre()
                              << " decide ir a lavar sus trastes a la"
                              << " cocina del Departamento. "
                              << user1.get_protagonista().get_nombre()
                              << " camina hacia la cocina y nota que "
                              << user1.get_antagonista().get_nombre()
                              << " lo sigue." << std::endl
                              << "Mientras caminaban hacia la cocina, "
                              << user1.get_antagonista().get_nombre()
                              << " se acerca a "
                              << user1.get_protagonista().get_nombre()
                              << " e intenta llenar el vaso de "
                              << user1.get_protagonista().get_nombre()
                              << " con whiskey, pero falla retundamente."
                              << std::endl;

                    std::cout << "Ambos llegan a la cocina y "
                              << user1.get_protagonista().get_nombre()
                              << " empieza a limpiar sus trastes. Mientras "
                              << user1.get_protagonista().get_nombre()
                              << " lava sus trastes, "
                              << user1.get_antagonista().get_nombre()
                              << " empieza a bendecir las paredes de la cocina"
                              << " y del comedor con el Whiskey. "
                              << std::endl;

                    std::cout << user1.get_antagonista().bendecir_el_lugar();

                    std::cout << "Al ver esto, "
                              << user1.get_protagonista().get_nombre()
                              << " decide terminar con sus trastes y llevar a "
                              << user1.get_antagonista().get_nombre()
                              << " su cuarto para evitar que haga mas "
                              << "danio al lugar" << std::endl;

                    std::cout << std::endl; // break line
                    std::cout << "----< Ambos llegan al cuarto de "
                              << user1.get_antagonista().get_nombre()
                              << " por lo que "
                              << user1.get_protagonista().get_nombre()
                              << " se retira su habitacion >----"
                              << std::endl;

                    std::cout << user1.get_protagonista().get_nombre()
                              << " llega a su habitacion y se prepara "
                              << "para dormir. Se pone su pijama, se lava "
                              << "los dientes y se acuesta. "
                              << std::endl;

                    std::cout << std::endl; // break line
                    std::cout << "----< Pasan 15 minutos y "
                              << user1.get_protagonista().get_nombre()
                              << " escucha que alguien toca a la puerta de "
                              << "su habitacion. "
                              << user1.get_protagonista().get_nombre()
                              << " abre la puerta y ve a "
                              << user1.get_guardia().get_nombre()
                              << user1.get_guardia().get_nombre()
                              << " le pide ayuda a "
                              << user1.get_protagonista().get_nombre()
                              << " para controlar a "
                              << user1.get_antagonista().get_nombre()
                              << ">----"
                              << std::endl;

                    std::cout << user1.get_protagonista().get_nombre()
                              << " y" << user1.get_guardia().get_nombre()
                              << "llegan al cuarto de "
                              << user1.get_antagonista().get_nombre()
                              << ". "
                              << user1.get_antagonista().get_nombre()
                              << " abre la puerta y los saluda"
                              << std::endl;

                    std::cout << "(Se estan un rato en su habitacion,"
                              << " despues de 40 minutos "
                              << user1.get_protagonista().get_nombre()
                              << " y" << user1.get_guardia().get_nombre()
                              << " se retiran de la habitacion.)"
                              << std::endl;

                    // disminuye el nivel de paciencia del protagonista
                    user1.get_protagonista().set_paciencia(50);
                    std::cout << "(El nivel de paciencia de "
                              << user1.get_protagonista().get_nombre()
                              << "es de "
                              << user1.get_protagonista().get_paciencia()
                              << ")"
                              << std::endl;

                    std::cout << std::endl; // break line

                    // agrega nuevos NPCs
                    user1.agrega_npc("El Doc", "A mimir");
                    user1.agrega_npc("The Cooler Dan", "Fuga");

                    std::cout << "----< Perspectiva del "
                              << user1.get_npc(2).get_nombre()
                              << " >----"
                              << std::endl;
                    std::cout
                        << user1.get_npc(2).get_nombre()
                        << " escucha un escandalo en el pasillo. "
                        << user1.get_npc(2).get_nombre()
                        << " escucho que "
                        << user1.get_antagonista().get_nombre()
                        << " buscaba a "
                        << user1.get_npc(3).get_nombre()
                        << " y le decia \"Are you here or are you in "
                        << "la culpable? \""
                        << "Tambien, escucho como "
                        << user1.get_antagonista().get_nombre()
                        << " golpeaba su puerta. Tambien escucho a "
                        << user1.get_protagonista().get_nombre() << " y "
                        << user1.get_guardia().get_nombre()
                        << " hablar con "
                        << user1.get_antagonista().get_nombre()
                        << " por 40 minutos." << std::endl;

                    std::cout << std::endl; // break line

                    std::cout
                        << "----< Volviendo a la historia principal,  "
                        << user1.get_antagonista().get_nombre()
                        << " sigue haciendo desmadre, por lo que "
                        << user1.get_guardia().get_nombre()
                        << " le pide ayuda a "
                        << user1.get_protagonista().get_nombre()
                        << " para controlar al borracho. Ambos suben "
                        << " al cuarto de "
                        << user1.get_antagonista().get_nombre()
                        << " para bajarlo de su habitacion y calmarlo "
                        << "en una de las terrazas del edificio. >----"
                        << std::endl;

                    std::cout << user1.get_protagonista().get_nombre()
                              << ", " << user1.get_antagonista().get_nombre()
                              << " y " << user1.get_guardia().get_nombre()
                              << " se dirigen hacia la terraza interina pequena. "
                              << "Aqui, " << user1.get_antagonista().get_nombre()
                              << " se pone agresivo y empieza atacar a "
                              << user1.get_protagonista().get_nombre()
                              << std::endl;

                    std::cout << std::endl; // break line
                    std::cout << "Deseas defenderte? (S / N) ";
                    std::cin >> choice_3;

                    if (choice_3 == 'S' || choice_3 == 's')
                    {
                        std::cout << std::endl; // break line
                        std::cout << "----< A las 3 AM, ha iniciado una pelea entre"
                                  << user1.get_protagonista().get_nombre()
                                  << " y " << user1.get_antagonista().get_nombre()
                                  << ". De lejos, "
                                  << user1.get_guardia().get_nombre()
                                  << " observa de lejos la pelea >----" << std::endl;
                        std::cout << std::endl;

                        std::cout << user1.get_antagonista().get_nombre()
                                  << " ataca a "
                                  << user1.get_protagonista().get_nombre()
                                  << std::endl;

                        user1.get_antagonista().ataca_personaje(user1.get_protagonista());
                        std::cout << "(La vida del protagonista es de: "
                                  << user1.get_protagonista().get_vida() << ")"
                                  << std::endl;

                        std::cout << std::endl; // break line

                        std::cout << "En defensa, "
                                  << user1.get_protagonista().get_nombre()
                                  << " ataca a "
                                  << user1.get_antagonista().get_nombre()
                                  << std::endl;

                        user1.get_protagonista().ataca_personaje(user1.get_antagonista());
                        std::cout << "(La vida del antagonista es de: "
                                  << user1.get_protagonista().get_vida() << ")"
                                  << std::endl;

                        std::cout << std::endl; // break line

                        std::cout << "----< Siguen atacandose por un rato >----" << std::endl;

                        for (int i = 0; i < 5; i++)
                        {
                            user1.get_antagonista().ataca_personaje(user1.get_protagonista());
                            std::cout << "(La vida del "
                                      << user1.get_protagonista().get_nombre()
                                      << " es de: "
                                      << user1.get_protagonista().get_vida() << ")"
                                      << std::endl;

                            user1.get_protagonista().ataca_personaje(user1.get_antagonista());
                            std::cout << "(La vida del "
                                      << user1.get_antagonista().get_nombre()
                                      << " es de : "
                                      << user1.get_protagonista().get_vida()
                                      << ")"
                                      << std::endl;
                        }

                        std::cout << std::endl; // break line

                        std::cout << "En este punto, "
                                  << user1.get_protagonista().get_nombre()
                                  << " ha decido que ya no quiere pelear, por lo que aplica a"
                                  << user1.get_antagonista().get_nombre()
                                  << " una patada para tumbarlo y mantenerlo quieto."
                                  << std::endl;

                        // patada del protagonista
                        user1.get_protagonista().ataca_personaje(user1.get_antagonista());
                        std::cout << "(La vida del "
                                  << user1.get_antagonista().get_nombre()
                                  << " es de : "
                                  << user1.get_protagonista().get_vida()
                                  << ")"
                                  << std::endl;

                        std::cout << std::endl;

                        std::cout << user1.get_antagonista().get_nombre() << " intenta escapar"
                                  << " de la llave de "
                                  << user1.get_protagonista().get_nombre()
                                  << " pero no puede. "
                                  << user1.get_protagonista().get_nombre()
                                  << " lo mantiene en el suelo hasta que se calma."
                                  << std::endl;

                        std::cout << "En este instante, "
                                  << user1.get_guardia().get_nombre()
                                  << " llama a la policia"
                                  << std::endl;

                        user1.get_guardia().llamar_a_policia();
                        std::cout << "La llamada continua por 7 minutos" << std::endl;

                        // Agregando los nuevos NPC de la historia
                        user1.agrega_npc("Dena", "Mala Suerte");
                        user1.agrega_npc("Turbina", "Dormir como nunca");

                        std::cout << std::endl; // break line

                        std::cout << "----< En el mismo momento que "
                                  << user1.get_protagonista().get_nombre()
                                  << " y "
                                  << user1.get_antagonista().get_nombre()
                                  << "pelean, "
                                  << user1.get_npc(4).get_nombre() << " y "
                                  << user1.get_npc(5).get_nombre()
                                  << " vuelven de una peda en Piruletas Quinto"
                                  << " >----"
                                  << std::endl;

                        std::cout << user1.get_npc(4).get_nombre() << " y "
                                  << user1.get_npc(5).get_nombre()
                                  << " tocan el timbre pero nadie responde, "
                                  << "por lo que llaman a "
                                  << user1.get_npc(1).get_nombre()
                                  << " para que abtra la puerta y los deje entrar"
                                  << std::endl;

                        std::cout << std::endl; // break line

                        user1.agrega_npc("Nitales", "Desinteres");
                        std::cout << "----< Y al mismo tiempo, "
                                  << user1.get_npc(6).get_nombre()
                                  << " pide a "
                                  << user1.get_guardia().get_nombre()
                                  << " que le pida un taxi. >----"
                                  << std::endl;

                        std::cout << std::endl; // break line
                        std::cout << "----< Volviendo a la historia"
                                  << " principal >----"
                                  << std::endl;

                        std::cout << "Llega la policia a Jabitee, "
                                  << " hablan un rato con "
                                  << user1.get_guardia().get_nombre()
                                  << " y " << user1.get_antagonista().get_nombre()
                                  << ". Despues de unas preguntas, la policia se "
                                  << " retira del lugar."
                                  << std::endl;

                        std::cout << "A las 4 AM, "
                                  << user1.get_guardia().get_nombre()
                                  << " logra calmar a "
                                  << user1.get_antagonista().get_nombre()
                                  << ". Al final, "
                                  << user1.get_antagonista().get_nombre()
                                  << " se retira a su habitacion."
                                  << std::endl;

                        std::cout << std::endl; // break line

                        std::cout << "----< En este momento, la paz vuelve"
                                  << " a Jabitee. >----"
                                  << std::endl
                                  << user1.get_protagonista().get_nombre()
                                  << " se va a su habitacion a dormir y "
                                  << user1.get_guardia().get_nombre()
                                  << " regresa a su puesto."
                                  << "Al llegar cada uno a su respectivo puesto, "
                                  << " el juego se ha terminado"
                                  << std::endl;

                        std::cout << std::endl; // break line
                        std::cout << "GAMEOVER" << std::endl;
                    }
                    else
                    {
                        std::cout << user1.get_protagonista().get_nombre()
                                  << " ha decidido no defenderse. "
                                  << "Por lo que ha sido noqueado por "
                                  << user1.get_antagonista().get_nombre()
                                  << std::endl;

                        // El antagonista le pega 9 veces al protagonista
                        for (int i = 0; i <= 9; i++)
                            user1.get_antagonista().ataca_personaje(user1.get_protagonista());

                        std::cout
                            << "La vida de "
                            << user1.get_protagonista().get_nombre()
                            << " ha llegado a "
                            << user1.get_protagonista().get_vida()
                            << ", por lo que GAME OVER" << std::endl;

                    } // fin del condicional de choice_3

                    // limpiando la memoria utilizada
                    user1.elimina_personajes_todos();
                } // fin del condicional de choice_2
            }     // fin del condicional de choice_1
            else
            {
                std::cout << user1.get_protagonista().get_nombre()
                          << " ha decidido irse a dormir. "
                          << "Por lo que el juego ha terminado"
                          << std::endl;

                // limpiando la memoria utiiizda
                user1.elimina_personajes_todos();
            } // fin del condicional de choice_1
            break;

        case 2:
            // muestra las indicaciones de la historia
            mostrar_indicaciones();
            break;

        case 3:
            // muestra todos los personajes de la historia
            // agregando los NPC que se generan al final de la historia

            std::cout << "Muestra los BASE STATS de los personajes" << std::endl;

            // creando & mostrando todos los personajes
            user1.crea_personaje();
            user1.agrega_npc("Dena", "Mala Suerte");
            user1.agrega_npc("Turbina", "Dormir como nunca");
            user1.agrega_npc("El Doc", "A mimir");
            user1.agrega_npc("The Cooler Dan", "Fuga");
            user1.agrega_npc("Nitales", "Desinteres");

            // mostrando los personajes
            user1.muestra_personajes();

            // limpiando la memoria utilizada
            user1.elimina_personajes_todos();
            break;

        case 4: // show credits
            show_credits();
            break;

        case 5:
            std::cout << "Se ha salido con exito!" << std::endl;
            running = false;
            break;

        default:
            break;
        } // fin del switch loop
    }     // fin del while loop
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
              << "\n3. Mostrar personajes \n4. Show Credits"
              << "\n5. Salir del programa"
              << std::endl;
}

/*
Se encarga de generar una progress bar sencilla para mostrar 'visualmente'
al usuario cuando se generan los personajes. Basado en la solucion con
mas upvotes de How to display a progress indicator in pure C/C++
(cout/printf)? (2013, January 26). Stack Overflow.
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
params: no recibe parametro.
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

    std::cout << "Los indicadores '()' son utilizados para mostrar"
              << " informacion relevante al usuario y para no confundir"
              << " con el texto normal al usuario. Son utilizados para mostrar"
              << " stats cambiantes de los diferentes personajes."
              << std::endl
              << std::endl;
}

/*
Se encarga de mostrar los creditos del programa.
params: no recibe parametros
*/
void show_credits()
{
    std::cout << "Author: Carlos Salguero"
              << "\nDirector: Carlos Salguero"
              << "\nWriters: Carlos Salguero"
              << std::endl;
}