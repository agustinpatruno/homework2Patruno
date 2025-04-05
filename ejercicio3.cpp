#include "ejercicio3.hpp"

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

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
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

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
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

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> entero::dividir(const Numero& otro) const 
{
    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        try
        {
            if (e->getValor() != 0)
            {    
                return make_unique<entero>(numero/e->numero); // Crea un smart pointer
            }
            
            throw logic_error("error, se intento dividir un numero entero por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        try
        {
            if (r->getValor() != 0)
            {
                return make_unique<real>(numero/r->getValor()); // Convertir entero a real y sumar
            }
            throw logic_error("error, se intento dividir un numero entero por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        try
        {
            if (i->getValor_real() != 0 && i->getValor_imaginario() != 0)
            {
                return make_unique<complejo>((numero*i->getValor_real()) / (i->getValor_real()*i->getValor_real()+i->getValor_imaginario()*i->getValor_imaginario()), - (i->getValor_imaginario()*i->getValor_imaginario()) / (i->getValor_real()*i->getValor_real()+i->getValor_imaginario()*i->getValor_imaginario()));
            }
            throw logic_error("error, se intento dividir un numero entero por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

string entero::toString() const {
    return to_string(numero);
}

/////////////////////////// implementacion de los metodos de la clase real //////////////////////////////////

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

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
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

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
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

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> real::dividir(const Numero& otro) const 
{

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        try
        {
            if (r->getValor() != 0)
            {
                return make_unique<real>(numero / r->getValor());
            }
            throw logic_error("error, se intento dividir un numero real por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        try
        {
            if (e->getValor() != 0)
            {
                return make_unique<real>(numero / e->getValor());
            }
            throw logic_error("error, se intento dividir un numero real por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        try
        {
            if (i->getValor_real() != 0 && i->getValor_imaginario() != 0)
            {
                return make_unique<complejo>((numero*i->getValor_real()) / (i->getValor_real()*i->getValor_real()+i->getValor_imaginario()*i->getValor_imaginario()), - (i->getValor_imaginario()*i->getValor_imaginario()) / (i->getValor_real()*i->getValor_real()+i->getValor_imaginario()*i->getValor_imaginario()));
            }
            throw logic_error("error, se intento dividir un numero real por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

string real::toString() const {
    return to_string(numero);
}

/////////////////////////////////// implementacion de los metodos de la clase complejo ///////////////////////////////////

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
        return make_unique<complejo>(parte_real + e->getValor(), parte_imaginaria);
    }

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
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
        return make_unique<complejo>(parte_real - e->getValor(), parte_imaginaria);
    }

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> complejo::multiplicar(const Numero& otro) const 
{

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {
        return make_unique<complejo>(parte_real * i->getValor_real() - parte_imaginaria*i->getValor_imaginario(), parte_imaginaria * i->getValor_real()+ parte_real*i->getValor_imaginario());
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        return make_unique<complejo>(parte_real * r->getValor(), parte_imaginaria);
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        return make_unique<complejo>(parte_real * e->getValor(), parte_imaginaria*e->getValor());
    }

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

unique_ptr<Numero> complejo::dividir(const Numero& otro) const 
{

    const complejo* i = dynamic_cast<const complejo*>(&otro);
    if (i) 
    {   
        try
        {
            if (i->getValor_real() != 0 && i->getValor_imaginario() != 0)
            {
                return make_unique<complejo>((parte_real*i->getValor_real()+parte_imaginaria*i->getValor_imaginario()) / (i->getValor_real()*i->getValor_real()+i->getValor_imaginario()*i->getValor_imaginario()),(parte_imaginaria*i->getValor_real()-parte_real*i->getValor_imaginario()) / (i->getValor_real()*i->getValor_real()+i->getValor_imaginario()*i->getValor_imaginario()));
            }
            throw logic_error("error, se intento dividir un numero complejo por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    const real* r = dynamic_cast<const real*>(&otro);
    if (r) 
    {
        try
        {
            if (r ->getValor() != 0)
            {
                return make_unique<complejo>(parte_real / r->getValor(), parte_imaginaria / r->getValor());
            }
            throw logic_error("error, se intento dividir un numero complejo por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    const entero* e = dynamic_cast<const entero*>(&otro);
    if (e) 
    {
        try
        {
            if (e->getValor() != 0)
            {  
                return make_unique<complejo>(parte_real / e->getValor(), parte_imaginaria);
            }
            throw logic_error("error, se intento dividir un numero complejo por cero");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    }

    if (!e && !r && !i) throw logic_error("Número de tipo desconocido");
    return nullptr;
}

string complejo::toString() const  
{
    return to_string(parte_real) + " + " + to_string(parte_imaginaria) + "i";
}

/*
    comando para ejecutar: 
        make ej3
*/
int main()
{
    unique_ptr<Numero> num1 = make_unique<entero>(5);           // Entero
    unique_ptr<Numero> num12 = make_unique<entero>(9);
    unique_ptr<Numero> num2 = make_unique<real>(3.14);          // Real
    unique_ptr<Numero> num22 = make_unique<real>(15.7);
    unique_ptr<Numero> num3 = make_unique<complejo>(2.0, 3.0);  // Complejo
    unique_ptr<Numero> num33 = make_unique<complejo>(5.0, 8.0); //complejo

    // Suma

    // Suma a enteros

    auto suma1 = num1->sumar(*num12);  // Suma entero + entero
    auto suma2 = num1->sumar(*num33); // suma entero + complejo
    auto suma3 = num1->sumar(*num2);  // Suma entero + real

    //suma a real

    auto suma4 = num2->sumar(*num2);  // suma real + entero
    auto suma5 = num2->sumar(*num22);   // suma real + real
    auto suma6 = num2->sumar(*num3);  // suma real + complejo

    //suma a complejos

    auto suma7 = num3->sumar(*num1); // suma complejo + entero 
    auto suma8 = num3->sumar(*num2);  // Suma complejo + real
    auto suma9 = num3->sumar(*num33); // suma complejo + complejo

    // Imprimir resultados
    cout << " ----------------------sumas : " << endl;
    cout << " --entero : " << endl;
    cout << " entero + entero: " << suma1->toString() << endl;
    cout << " entero + real: " << suma2->toString() << endl;
    cout << " entero + complejo: " << suma3->toString() << endl;
    cout << " --real : " << endl;
    cout << " real + entero: " << suma4->toString() << endl;
    cout << " real + real: " << suma5->toString() << endl;
    cout << " real + complejo: " << suma6->toString() << endl;
    cout << " --complejo : " << endl;
    cout << " complejo + entero: " << suma7->toString() << endl;
    cout << " complejo + real: " << suma8->toString() << endl;
    cout << " complejo + complejo: " << suma9->toString() << endl;

    // Resta
    
    // resta a entero

    auto resta1 = num1->restar(*num12);  // resta entero - entero
    auto resta2 = num1->restar(*num33); // resta entero - complejo
    auto resta3 = num1->restar(*num2);  // resta entero - real

    //resta a real

    auto resta4 = num2->restar(*num2);  // resta real - entero
    auto resta5 = num2->restar(*num22);   // resta real - real
    auto resta6 = num2->restar(*num3);  // resta real - complejo

    //resta a complejos

    auto resta7 = num3->restar(*num1); // resta complejo - entero 
    auto resta8 = num3->restar(*num2);  // resta complejo - real
    auto resta9 = num3->restar(*num33); // resta complejo - complejo

   
    // Imprimir resultados
    cout << " --------------------restas : " << endl;
    cout << " --entero : " << endl;
    cout << " entero - entero: " << resta1->toString() << endl;
    cout << " entero - real: " << resta2->toString() << endl;
    cout << " entero - complejo: " << resta3->toString() << endl;
    cout << " --real : " << endl;
    cout << " real - entero: " << resta4->toString() << endl;
    cout << " real - real: " << resta5->toString() << endl;
    cout << " real - complejo: " << resta6->toString() << endl;
    cout << " --complejo : " << endl;
    cout << " complejo - entero: " << resta7->toString() << endl;
    cout << " complejo - real: " << resta8->toString() << endl;
    cout << " complejo - complejo: " << resta9->toString() << endl;

    // Multiplicación

    // multiplicacion a entero

    auto mul1 = num1->multiplicar(*num12);  // multiplicar entero * entero
    auto mul2 = num1->multiplicar(*num33); // multiplicar entero * complejo
    auto mul3 = num1->multiplicar(*num2);  // multipliar entero * real

    //multiplicar a real

    auto mul4 = num2->multiplicar(*num2);  // multiplicar real * entero
    auto mul5 = num2->multiplicar(*num22);   // multiplicar real * real
    auto mul6 = num2->multiplicar(*num3);  // multiplicar real * complejo

    //multiplicar a complejos

    auto mul7 = num3->multiplicar(*num1); // multiplicar complejo * entero 
    auto mul8 = num3->multiplicar(*num2);  // multiplicar complejo * real
    auto mul9 = num3->multiplicar(*num33); // multiplicar complejo * complejo

   
    // Imprimir resultados

    cout << " -------------------multiplicacion : " << endl;
    cout << " --entero : " << endl;
    cout << " entero * entero: " << mul1->toString() << endl;
    cout << " entero * real: " << mul2->toString() << endl;
    cout << " entero * complejo: " << mul3->toString() << endl;
    cout << " --real : " << endl;
    cout << " real * entero: " << mul4->toString() << endl;
    cout << " real * real: " << mul5->toString() << endl;
    cout << " real * complejo: " << mul6->toString() << endl;
    cout << " --complejo : " << endl;
    cout << " complejo * entero: " << mul7->toString() << endl;
    cout << " complejo * real: " << mul8->toString() << endl;
    cout << " complejo * complejo: " << mul9->toString() << endl;

    // dividir

    // dividir a entero

    auto div1 = num1->dividir(*num12);  // dividir entero / entero
    auto div2 = num1->dividir(*num33); // dividir entero / complejo
    auto div3 = num1->dividir(*num2);  // dividir entero / real

    //dividir a real

    auto div4 = num2->dividir(*num2);  // dividir real / entero
    auto div5 = num2->dividir(*num22);   // dividir real / real
    auto div6 = num2->dividir(*num3);  // dividir real / complejo

    //dividir a complejos

    auto div7 = num3->dividir(*num1); // dividir complejo / entero 
    auto div8 = num3->dividir(*num2);  // dividir complejo / real
    auto div9 = num3->dividir(*num33); // dividir complejo / complejo

    // Imprimir resultados

    cout << " ------------------ dividir : " << endl;
    cout << " --entero : " << endl;
    cout << " entero / entero: " << div1->toString() << endl;
    cout << " entero / real: " << div2->toString() << endl;
    cout << " entero / complejo: " << div3->toString() << endl;
    cout << " --real : " << endl;
    cout << " real / entero: " << div4->toString() << endl;
    cout << " real / real: " << div5->toString() << endl;
    cout << " real / complejo: " << div6->toString() << endl;
    cout << " --complejo : " << endl;
    cout << " complejo / entero: " << div7->toString() << endl;
    cout << " complejo / real: " << div8->toString() << endl;
    cout << " complejo / complejo: " << div9->toString() << endl;

    // casos borde de division por cero //

    unique_ptr<Numero> num10 = make_unique<entero>(0); 

    num3->dividir(*num10); // divido un complejo por cero
    num2->dividir(*num10);  // divido un real por cero
    num1->dividir(*num10);  // divido un entero por cero

    return 0;
}