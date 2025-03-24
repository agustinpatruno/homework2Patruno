#include "ejercicio1.hpp"


void programa_verificacion()
{

    tiempo tiempo_actual;

    while ( true)
    {
        int opcion = 0 ;
        cout << setw(10) << "que quieres hacer :" << endl;
        cout << setfill('-') << setw(5) << "1) cambiar el tiempo" << endl ;
        cout << setfill('-') << setw(5) << "2) leer el tiempo" << endl ;
        cout << setfill('-') << setw(5) << "3) leer el tiempo en formato 24 horas" << endl ;
        cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;
        cin >> opcion ;

        int subopcion = 0;

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

            int nuevo_tiempo = 0;

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
    programa_verificacion();
    return 0;
}