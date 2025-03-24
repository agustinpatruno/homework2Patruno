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

        int comprobar_hora(int hora)
        {
            return hora <= 24 ? hora : 0;
        }
        int comprobar_minutos_segundos(int numero)
        {
            return numero <= 60 ? numero : 0;
        }
        bool comprobar_momento(string momento)
        {
            return momento == "a.m" || momento == "p.m" ? true : false;
        }
    public:

        //constructores del objeto//

        tiempo()
        {
            Hora = 0;
            Minutos = 0;
            Segundos = 0;
            Momento = "a.m";
        }
        tiempo(int horas)
        {
            Hora = comprobar_hora(horas);
            Minutos = 0;
            Segundos = 0;
            Momento = "a.m";
        }
        tiempo(int horas, int minutos)
        {
            Hora = comprobar_hora(horas);
            Minutos = comprobar_minutos_segundos(minutos);
            Segundos = 0;
            Momento = "a.m";
        }
        tiempo(int horas, int minutos, int segundos)
        {
            Hora = comprobar_hora(horas);
            Minutos = comprobar_minutos_segundos(minutos);
            Segundos = comprobar_minutos_segundos(segundos);
            Momento = "a.m";
        }
        tiempo(int horas, int minutos, int segundos, string momento)
        {
            Hora = comprobar_hora(horas);
            Minutos = comprobar_minutos_segundos(minutos);
            Segundos = comprobar_minutos_segundos(segundos);
            Momento = momento;
        }

        //metodos para leer y cambiar los atributos definidos en private//

        void leer_hora()
        {
            cout << setw(10) <<" hora: " << Hora << endl;
            return;
        }
        void cambiar_hora(int nueva_hora)
        {
            int hora_ant = Hora;
            Hora = comprobar_hora(nueva_hora) == 0 ? hora_ant : nueva_hora;
            return;
        }

        void leer_minutos()
        {
            cout << setw(10) <<" minutos: " << Minutos << endl;
            return;
        }
        void cambiar_minutos(int nuevos_minutos)
        {
            int min_ant = Minutos;
            Minutos = comprobar_minutos_segundos(nuevos_minutos) == 0 ? min_ant : nuevos_minutos;
            return;
        }

        void leer_segundos()
        {
            cout << setw(10) <<" segundos: " << Segundos << endl;
            return;
        }
        void cambiar_segundos(int nuevos_segundos)
        {   
            int seg_ant = Segundos;
            Segundos = comprobar_minutos_segundos(nuevos_segundos) == 0 ? seg_ant : nuevos_segundos;
            return;
        }

        void leer_momento()
        {
            cout << setw(10) <<"el tiempo esta en intervalo: " << Momento << endl;
            return;
        }
        void cambiar_momento(string nuevo_momento)
        {   
            comprobar_momento(nuevo_momento) ? Momento = nuevo_momento : nullptr;
            return;
        }

        void leer_todo()
        {
            cout << setw(10) << "hora: " << Hora << " minutos: " << Minutos << " segundos: " << Segundos << " momento: " << Momento << endl;
            return;
        }

        //metodo para mostrar el tiempo en formato de 0 a 24//

        void mostrar_tiempo_formato_24()
        {
            int hora_convertida = Momento == "p.m" ? Hora + 12 : Hora ;
            cout << setw(10) <<"hora: " << hora_convertida << " minutos: " << Minutos << " segundos: " << Segundos << endl ;
            return;
        }
};

