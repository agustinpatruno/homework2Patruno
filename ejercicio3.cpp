#include "ejercicio3.hpp"

class Numero
{
    public:
    virtual unique_ptr<Numero> sumar(const Numero& otro) const = 0;
    virtual unique_ptr<Numero> restar(const Numero& otro) const = 0;
    virtual unique_ptr<Numero> multiplicar(const Numero& otro) const = 0;
    virtual unique_ptr<Numero> dividir(const Numero& otro) const = 0;
    virtual string toString() const = 0;
        
};

/// implementacion de los metodos de la clase entero ///

entero::entero(int num)
{
    numero = num;
}

int entero::getValor() const
{
    return numero;
}

unique_ptr<Numero> entero::sumar(const Numero& otro) const 
{
    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<entero>(numero + e->numero); // Crea un smart pointer
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<real>(numero + r->getValor()); // Convertir entero a real y sumar
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(numero + i->getValor_real(), i->getValor_imaginario());
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> entero::restar(const Numero& otro) const 
{
    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<entero>(numero - e->numero); // Crea un smart pointer
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<real>(numero - r->getValor()); // Convertir entero a real y sumar
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(numero - i->getValor_real(), i->getValor_imaginario());
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> entero::multiplicar(const Numero& otro) const 
{
    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<entero>(numero*e->numero); // Crea un smart pointer
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<real>(numero*r->getValor()); // Convertir entero a real y sumar
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(numero*i->getValor_real(), numero*i->getValor_imaginario());
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> entero::dividir(const Numero& otro) const 
{
    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        if (e->getValor() != 0)
        {    
            return make_unique<entero>(numero/e->numero); // Crea un smart pointer
        }
        
        throw invalid_argument("division por cero");
        return nullptr;
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        if (r->getValor() != 0)
        {
            return make_unique<real>(numero/r->getValor()); // Convertir entero a real y sumar
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        if (i->getValor_real() != 0)
        {
            return make_unique<complejo>(numero/i->getValor_real(), i->getValor_imaginario());
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }
    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

string entero::toString() const {
    return to_string(numero);
}


/// implementacion de los metodos de la clase real ///

real::real(double num)
{
    numero = num;
}

double real::getValor() const
{
    return numero;
}

unique_ptr<Numero> real::sumar(const Numero& otro) const 
{

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<real>(numero + r->getValor());
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<real>(numero + e->getValor());
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(numero + i->getValor_real(), i->getValor_imaginario());
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> real::restar(const Numero& otro) const 
{

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<real>(numero - r->getValor());
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<real>(numero - e->getValor());
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(numero - i->getValor_real(), i->getValor_imaginario());
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> real::multiplicar(const Numero& otro) const 
{

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<real>(numero*r->getValor());
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<real>(numero*e->getValor());
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(numero*i->getValor_real(), numero*i->getValor_imaginario());
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> real::dividir(const Numero& otro) const 
{

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        if (r->getValor() != 0)
        {
            return make_unique<real>(numero / r->getValor());
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        if (e->getValor() != 0)
        {
            return make_unique<real>(numero / e->getValor());
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        if (i->getValor_real() != 0 && i->getValor_imaginario() != 0)
        {
            return make_unique<complejo>(numero / i->getValor_real(), i->getValor_imaginario());
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

string real::toString() const {
    return to_string(numero);
}



/// implementacion de los metodos de la clase complejo ///

complejo::complejo(double real, double imaginaria)
{
    parte_real = real;
    parte_imaginaria = imaginaria;
}

double complejo::getValor_real() const
{
    return parte_real;
}

double complejo::getValor_imaginario() const
{
    return parte_imaginaria;
}

unique_ptr<Numero> complejo::sumar(const Numero& otro) const 
{

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(parte_real + i->getValor_real(),parte_imaginaria + i->getValor_imaginario());
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<complejo>(parte_real + r->getValor(), parte_imaginaria);
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<entero>(parte_real + e->getValor(), parte_imaginaria);
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> complejo::restar(const Numero& otro) const 
{

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(parte_real - i->getValor_real(),parte_imaginaria - i->getValor_imaginario());
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<complejo>(parte_real - r->getValor(), parte_imaginaria);
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<entero>(parte_real - e->getValor(), parte_imaginaria);
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> complejo::multiplicar(const Numero& otro) const 
{

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(parte_real * i->getValor_real(),parte_imaginaria * i->getValor_imaginario());
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<complejo>(parte_real * r->getValor(), parte_imaginaria);
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<entero>(parte_real * e->getValor(), parte_imaginaria);
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> complejo::dividir(const Numero& otro) const 
{

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {   
        if (i->getValor_real() != 0 && i->getValor_imaginario() != 0)
        {
            return make_unique<complejo>(parte_real / i->getValor_real(),parte_imaginaria / i->getValor_imaginario());
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        if (r ->getValor() != 0)
        {
            return make_unique<complejo>(parte_real / r->getValor(), parte_imaginaria);
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        if (e->getValor() != 0)
        {  
            return make_unique<entero>(parte_real / e->getValor(), parte_imaginaria);
        }
        throw invalid_argument("division por cero");
        return nullptr;
    }

    if (!e && !r && !i) throw invalid_argument("Número de tipo desconocido");
    return nullptr;
}

string complejo::toString() const  
{
    return to_string(parte_real) + " + " + to_string(parte_imaginaria) + "i";
}
