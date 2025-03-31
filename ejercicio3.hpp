#ifndef EJERCICIO3_HPP
#define EJERCICIO3_HPP

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Numero
{
    public:
        virtual unique_ptr<Numero> sumar(const Numero& otro) const = 0;
        /*
        
        */
        virtual unique_ptr<Numero> restar(const Numero& otro) const = 0;
        /*
        
        */
        virtual unique_ptr<Numero> multiplicar(const Numero& otro) const = 0;
        /*
        
        */
        virtual unique_ptr<Numero> dividir(const Numero& otro) const = 0;
        /*
        
        */
        virtual string toString() const = 0;
        /*
        
        */
};

class entero : public Numero
{
    private:

        int numero;

    public:

        entero(int num);
        /*
            contructor que inicializa el valor de numero en funcion del valor num que se le pase
        */

        int getValor() const;
        /*
            devuelve el valor asginado a numero
        */

        unique_ptr<Numero> sumar(const Numero& otro) const override;
        /*
            suma el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        unique_ptr<Numero> restar(const Numero& otro) const override;
        /*
            resta el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        unique_ptr<Numero> multiplicar(const Numero& otro) const override;
        /*
            multiplica el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        unique_ptr<Numero> dividir(const Numero& otro) const override;
         /*
            divide el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        string toString() const override;
        /*
            retorna en valor de numero en formato string
        */
};

class real : public Numero
{
    private:

        double numero;

    public:

        real(double num);
        /*
            constructor que incializa el valor del numero en funcion del valor num(double) que se le pase
        */

        double getValor() const;
        /*
            retorna el valor del numero
        */

        unique_ptr<Numero> sumar(const Numero& otro) const override;
        /*
            suma el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        unique_ptr<Numero> restar(const Numero& otro) const override;
        /*
            resta el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        unique_ptr<Numero> multiplicar(const Numero& otro) const override;
        /*
            multiplica el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        unique_ptr<Numero> dividir(const Numero& otro) const override;
        /*
            divide el valor de numero con otro numero que se le pase como "otro". puede ser entero, real o complejo
        */

        string toString() const override;
        /*
            retorna en valor de numero en formato string
        */
};


class complejo : public Numero
{
    private:
        
        double parte_real;
        double parte_imaginaria;

    public:

        complejo(double real, double imaginaria);
        /*
            constructor que inicializa la parte real y la parte imaginaria del objeto en funcion de los valores que se le pase
            a real(double) e maginario(double)
        */

        double getValor_real() const;
        /*
            retorna el valor de la parte real
        */
        
        double getValor_imaginario() const;
        /*
            retorna el valor de la parte imaginaria
        */

        unique_ptr<Numero> sumar(const Numero& otro) const override;
        /*
            suma el numero complejo con otro numero que se le pase, puede ser entero, real o complejo
        */

        unique_ptr<Numero> restar(const Numero& otro) const override;
        /*
            resta el numero complejo con otro numero que se le pase, puede ser entero, real o complejo
        */

        unique_ptr<Numero> multiplicar(const Numero& otro) const override;
        /*
            multiplica el numero complejo con otro numero que se le pase, puede ser entero, real o complejo
        */

        unique_ptr<Numero> dividir(const Numero& otro) const override;
        /*
            divide el numero complejo con otro numero que se le pase, puede ser entero, real o complejo
        */

        string toString() const override;
        /*
            retorna la parte real y la parte imaginaria del complejo en formato string
        */
};

#endif