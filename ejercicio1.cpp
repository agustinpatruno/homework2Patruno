#include "ejercicio1.hpp"


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



void opciones()
{
    cout << setfill('-') << setw(10) << "1) la hora " << endl;
    cout << setfill('-') << setw(10) << "2) los minutos" << endl;
    cout << setfill('-') << setw(10) << "3) los segundos" << endl;
    cout << setfill('-') << setw(10) << "4) el momento" << endl;
    
    return;
}

void programa_verificacion()
{

    tiempo tiempo_actual;

    while (true)
    {
        int opcion = 0;

        cout << setw(10) << "que quieres hacer :" << endl;
        cout << setfill('-') << setw(5) << "1) cambiar el tiempo" << endl ;
        cout << setfill('-') << setw(5) << "2) leer el tiempo" << endl ;
        cout << setfill('-') << setw(5) << "3) leer el tiempo en formato 24 horas" << endl ;
        cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;
        cin >> opcion ;

        int subopcion = 0;

        int nuevo_tiempo = 0;

        string nuevo_momento;

        /*switch (opcion)
        {
            case -1:
            {
                return;
            }
            case 1:
            {
                cout << setw(10) << "que quieres modificar:" << endl;
                opciones();
                cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;

                cin >> subopcion ;
                
                switch (subopcion)
                {
                    case -1:
                    {   
                        return;
                    }
                    case 1:
                    { 
                        cout << setw(10) << "ingrese la nueva hora :" << endl;
                        cin >> nuevo_tiempo;
        
                        while (nuevo_tiempo > 12 || nuevo_tiempo < 0)
                        {
                            cout << setw(10) << "error, ingrese una hora valida :" << endl;
                            cin >> nuevo_tiempo ;
                        }

                        tiempo_actual.cambiar_hora(nuevo_tiempo);
                        break;
                    }
                    case 2:
                    {
                        cout << setw(10) << "ingrese los nuevos minutos/segundos :" << endl;
                        cin >> nuevo_tiempo;
            
                        while (nuevo_tiempo > 60 || nuevo_tiempo < 0)
                        {
                            cout << setw(10) << "error, ingrese unos minutos/segundos validos :" << endl;
                            cin >> nuevo_tiempo ;
                        }
            
                        tiempo_actual.cambiar_minutos(nuevo_tiempo);
                        break;
                    }
                    case 3:
                    {
                        cout << setw(10) << "ingrese los nuevos minutos/segundos :" << endl;
                        cin >> nuevo_tiempo;
            
                        while (nuevo_tiempo > 60 || nuevo_tiempo < 0)
                        {
                            cout << setw(10) << "error, ingrese unos minutos/segundos validos :" << endl;
                            cin >> nuevo_tiempo ;
                        }
                        tiempo_actual.cambiar_segundos(nuevo_tiempo);
                        break;
                    }
                    case 4:
                    {
                        cout << setw(10) << "ingrese a.m o p.m :" << endl;
                        cin >> nuevo_momento;

                        while (nuevo_momento != "p.m" && nuevo_momento != "a.m")
                        {
                            cout << setw(10) << "error, ingrese un momento valido :" << endl;
                            cin >> nuevo_momento ;
                        }
                        
                        tiempo_actual.cambiar_momento(nuevo_momento);
                        break;
                    }
                    default:
                    {
                        cout << "error, opcion no valida, intentelo nuevamente" << endl;
                        break;
                    }
                }
            }
            case 2:

                cout << setw(10) << "que quieres leer:" << endl;
                opciones();
                cout << setfill('-') << setw(10) << "5) todo en conjunto" << endl;
                cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;

                cin >> subopcion ;

                switch (subopcion)
                {
                    case -1:
                    {
                        return;
                    }    
                    case 1:
                    {
                        tiempo_actual.leer_hora();
                        break;
                    }
                    case 2:
                    {
                        tiempo_actual.leer_minutos();
                        break;
                    }
                    case 3:
                    {
                        tiempo_actual.leer_segundos();
                        break;
                    }
                    case 4:
                    {
                        tiempo_actual.leer_momento();
                        break;
                    }
                    default:
                    {
                        cout << "error, ingrese una opcion valida:" << endl;

                        break;
                    }
                }
    
            case 3:
            {
                tiempo_actual.mostrar_tiempo_formato_24();
                break;
            }
            default:
            {
                cout << "error, ingrese una opcion valida " << endl;
                break;
            }
        }*/

        if (opcion == -1)
        {
            return;
        }
        else if (opcion == 1)
        {
            cout << setw(10) << "que quieres modificar:" << endl;
            cout << setfill('-') << setw(10) << "1) la hora " << endl;
            cout << setfill('-') << setw(10) << "2) los minutos" << endl;
            cout << setfill('-') << setw(10) << "3) los segundos" << endl;
            cout << setfill('-') << setw(10) << "4) el momento" << endl;
            cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;

            cin >> subopcion ;

            if (subopcion == -1)
            {
                return;
            }

            while (subopcion > 4 || subopcion < 0)
            {
                cout << setw(10) << "error, ingrese un numero dentro de las opciones :" << endl;
                cin >> subopcion ;
            }

            if (subopcion == 1)
            {
                
                cout << setw(10) << "ingrese la nueva hora :" << endl;
                cin >> nuevo_tiempo;

                while (nuevo_tiempo > 12 || nuevo_tiempo < 0)
                {
                    cout << setw(10) << "error, ingrese una hora valida :" << endl;
                    cin >> nuevo_tiempo ;
                }
                
                tiempo_actual.cambiar_hora(nuevo_tiempo);

            }
            else if (subopcion == 2 || subopcion == 3)
            {
                cout << setw(10) << "ingrese los nuevos minutos/segundos :" << endl;
                cin >> nuevo_tiempo;

                while (nuevo_tiempo > 60 || nuevo_tiempo < 0)
                {
                    cout << setw(10) << "error, ingrese unos minutos/segundos validos :" << endl;
                    cin >> nuevo_tiempo ;
                }

                if (subopcion == 2)
                {
                    tiempo_actual.cambiar_minutos(nuevo_tiempo);
                }
                else
                {
                    tiempo_actual.cambiar_segundos(nuevo_tiempo);
                }
    
            }
            else if (subopcion == 4)
            {
                string nuevo_momento;
                cout << setw(10) << "ingrese a.m o p.m :" << endl;
                cin >> nuevo_momento;

                while (nuevo_momento != "p.m" && nuevo_momento != "a.m")
                {
                    cout << setw(10) << "error, ingrese un momento valido :" << endl;
                    cin >> nuevo_momento ;
                }
                
                tiempo_actual.cambiar_momento(nuevo_momento);

            }
        }
        else if (opcion == 2)
        {
            cout << setw(10) << "que quieres leer:" << endl;
            cout << setfill('-') << setw(10) << "1) la hora " << endl;
            cout << setfill('-') << setw(10) << "2) los minutos" << endl;
            cout << setfill('-') << setw(10) << "3) los segundos" << endl;
            cout << setfill('-') << setw(10) << "4) el momento" << endl;
            cout << setfill('-') << setw(10) << "5) todo en conjunto" << endl;
            cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;
            cin >> subopcion ;

            if (subopcion == -1)
            {
                return;
            }

            while (subopcion > 5 || subopcion < 0)
            {
                cout << setw(10) << "error, ingrese un numero dentro de las opciones :" << endl;
                cin >> subopcion ;
            }

            if (subopcion == 1)
            {
                tiempo_actual.leer_hora();
            }
            else if (subopcion == 2)
            {
                tiempo_actual.leer_minutos();
            }
            else if (subopcion == 3)
            {
                tiempo_actual.leer_segundos();
            }
            else if (subopcion == 4)
            {
                tiempo_actual.leer_momento();
            }
            else
            {
                tiempo_actual.leer_todo();
            }
        }
        else if (opcion == 3)
        {
            tiempo_actual.mostrar_tiempo_formato_24();
        }
        else
        {
            cout << "error, numero ingresado no valido" << endl ;
        }

    }
}

int main()
{
    tiempo tiempo1(10);
    tiempo1.leer_todo();

    tiempo tiempo2(10,22);
    tiempo2.leer_todo();

    tiempo tiempo3(10,22,53);
    tiempo3.leer_todo();

    tiempo tiempo4(10,22,53,"a.m");
    tiempo4.leer_todo();

    programa_verificacion();
    
    return 0;
}