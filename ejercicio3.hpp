#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Numero
{
    public:
    virtual unique_ptr<Numero> sumar(const Numero& otro) const = 0;
    virtual unique_ptr<Numero> restar(const Numero& otro) const = 0;
    virtual unique_ptr<Numero> multiplicar(const Numero& otro) const = 0;
    virtual unique_ptr<Numero> dividir(const Numero& otro) const = 0;
    virtual string toString() const = 0;
        
    Numero(/* args */);
    virtual ~Numero() = default;
};
Numero::Numero(/* args */)
{
}
Numero::~Numero()
{
}

class entero : public Numero
{
    private:

        int numero;

    public:

        entero(int num)
        {
            numero = num;
        }

        unique_ptr<Numero> sumar(const Numero& otro) const override 
        {
            const entero* e = dynamic_cast<const entero*>(&otro);
            if (e) {
                return make_unique<entero>(numero + e->numero); // Crea un smart pointer
            }

            const real* r = dynamic_cast<const real*>(&otro);
            if (r) {
                return make_unique<real>(numero + r->getValor()); // Convertir entero a real y sumar
            }

            const complejo* i = dynamic_cast<const complejo*>(&otro);
            if (i) 
            {
                return make_unique<complejo>(numero + i->getValor_real(), i->getValor_imaginario());
            }

            cout << "error, numero de ningun tipo" << endl;
            return nullptr;
        }

        unique_ptr<Numero> restar(const Numero& otro) const override 
        {
            const entero* e = dynamic_cast<const entero*>(&otro);
            if (e) {
                return make_unique<entero>(numero - e->numero); // Crea un smart pointer
            }

            const real* r = dynamic_cast<const real*>(&otro);
            if (r) {
                return make_unique<real>(numero - r->getValor()); // Convertir entero a real y sumar
            }

            const complejo* i = dynamic_cast<const complejo*>(&otro);
            if (i) 
            {
                return make_unique<complejo>(numero - i->getValor_real(), i->getValor_imaginario());
            }

            cout << "error, numero de ningun tipo" << endl;
            return nullptr;
        }

        unique_ptr<Numero> multiplicar(const Numero& otro) const override 
        {
            const entero* e = dynamic_cast<const entero*>(&otro);
            if (e) {
                return make_unique<entero>(numero*e->numero); // Crea un smart pointer
            }

            const real* r = dynamic_cast<const real*>(&otro);
            if (r) {
                return make_unique<real>(numero*r->getValor()); // Convertir entero a real y sumar
            }

            const complejo* i = dynamic_cast<const complejo*>(&otro);
            if (i) 
            {
                return make_unique<complejo>(numero*i->getValor_real(), i->getValor_imaginario());
            }

            cout << "error, numero de ningun tipo" << endl;
            return nullptr;
        }

        unique_ptr<Numero> dividir(const Numero& otro) const override 
        {
            const entero* e = dynamic_cast<const entero*>(&otro);
            if (e) {
                return make_unique<entero>(numero/e->numero); // Crea un smart pointer
            }

            const real* r = dynamic_cast<const real*>(&otro);
            if (r) {
                return make_unique<real>(numero/r->getValor()); // Convertir entero a real y sumar
            }

            const complejo* i = dynamic_cast<const complejo*>(&otro);
            if (i) 
            {
                return make_unique<complejo>(numero/i->getValor_real(), i->getValor_imaginario());
            }

            cout << "error, numero de ningun tipo" << endl;
            return nullptr;
        }

        string toString() const override {
            return to_string(numero);
        }
};

class real : public Numero
{
    private:

        double numero;

    public:

        real(double num)
        {
            numero = num;
        }

        double getValor() const
        {
            return numero;
        }

        string toString() const override {
            return to_string(numero);
        }
};


class complejo : public Numero
{
    private:
        
        double parte_real;
        double parte_imaginaria;

    public:

        complejo(double real, double imaginaria)
        {
            parte_real = real;
            parte_imaginaria = imaginaria;
        }

        double getValor_real() const
        {
            return parte_real;
        }
        
        double getValor_imaginario() const
        {
            return parte_imaginaria;
        }

        string toString() const override 
        {
            return to_string(parte_real) + " + " + to_string(parte_imaginaria) + "i";
        }
};