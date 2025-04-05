#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// definicion de la clase tiempo

class tiempo
{
    private:

        int Hora;
        int Minutos;
        int Segundos;
        string Momento;

        int comprobar_hora(int hora);
        /*
            retorna la hora pasado por parametro si esta dentro del rango de la hora. caso contrario retorna -1.
        */
        int comprobar_minutos_segundos(int numero);
        /*
            retorna los minutos/segundos pasado por parametro si esta dentro de minutos/segundos. caso contrario retorna -1.
        */

        bool comprobar_momento(string momento);
        /*
            retorna true si el momento pasado por parametro es "a.m" o "p.m". caso contrario retorna false.
        */

    public:

        //constructores del objeto//

        tiempo();
        /*
            inicializa un objeto en hs, mm, ss en cero y momento en "a.m"
        */

        tiempo(int horas);
        /*
            inicializa un objeto en hs con el parametro que se le pase, caso de excederse se incializa en cero. 
            mm, ss en cero y momento en "a.m". 
        */

        tiempo(int horas, int minutos);
        /*
            inicializa un objeto en Hs y Mm con el parametro que se les pase, caso de que se excedan, se incializaran en cero. 
            Ss en cero y momento en "a.m"
        */

        tiempo(int horas, int minutos, int segundos);
        /*
            inicializa un objeto en Hs, Mm y Ss con el parametro que se les pase, caso de excederse se incializaran en cero. 
            El momento en "a.m"
        */

        tiempo(int horas, int minutos, int segundos, string momento);
        /*
            inicializa un objeto en Hs, Mm, Ss y el momento con el parametro que se les pase. caso de que se exceda algun parametro 
            se incizializa en cero. caso del momento, se incializa en "a.m"
        */

        //metodos para leer y cambiar los atributos definidos en private//

        void leer_hora();
        /*
            imprime por consola la hora del objeto
        */

        void cambiar_hora(int nueva_hora);
        /*
            cambia la hora del objeto con el parametro que se le pase
        */

        void leer_minutos();
        /*
            imprime por consola los minutos del objeto
        */

        void cambiar_minutos(int nuevos_minutos);
        /*
            cambia los minutos del objeto con el parametro que se le pase
        */

        void leer_segundos();
        /*
            imprime por consola los segundos del objeto
        */

        void cambiar_segundos(int nuevos_segundos);
        /*
            cambia los segundos del objeto con el parametro que se le pase
        */

        void leer_momento();
        /*
            imprime por consola los segundos del objeto ( a.m o p.m )
        */

        void cambiar_momento(string nuevo_momento);
        /*
            cambia el momento del objeto con el parametro que se le pase
        */

        void leer_todo();
        /*
            imprime por consola el horario total del objeto
        */

        //metodo para mostrar el tiempo en formato de 0 a 24//

        void mostrar_tiempo_formato_24();
        /*
            imprime por consola el horario total del objeto pero en formato de 24 horas
        */

};

void opciones();
/*
    imprime por consola la opcion de hora, los minutos, los segundos o el momento
*/

void programa_verificacion();
/*
    interfaz con el usuario para mostrar la hora por separado, la hora en conjunto, la hora en formato 24 horas o modificar el tiempo.
*/
