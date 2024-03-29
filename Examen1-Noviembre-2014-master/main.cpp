#include "Evaluador.h"
#include <iostream>
#include <math.h>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve true si todas las letras de palabra (dado) son minusculas
//Sugerencia, usar string.length() para saber la longitud de la palabra
bool sonMinusculas(string palabra)
{
    for(int i=0;i<palabra.length();i++){
        char c=palabra[i];
        if (c>=65 && c<91)
            return false;
    }

    return true;
}

//Devuelve el promedio de los elementos de arreglo (dado) tomando en cuenta el tamano (dado)
double getPromedio(double* arreglo,int tamano)
{
    double acum=0;
    for(int x=0;x<tamano;x++)
    {
        acum+=(arreglo)[x];
    }

    double promedio=(acum/tamano);
    return promedio;
}

//Devuelve true si num (dado) es primo, de lo contrario devuelve false
bool esPrimo(int num)
{

for(int x=2;x<num;x++)
{
    if(num%x==0)
        return false;
}

    return true;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las clases Personaje, Guerrero y Arquero dado el diagrama de clases adjunto

//Todas las clases:
//Los contructores inicializan los atributos de la clase

//Guerrero
//El poder especial multiplica su ataque por dos y divide su vida entre dos

//Arquero
//El operador + se sobrecarga para aumentar su variable flechas de acuerdo al paramentro
//Regenerar vida esta sobreescrita para sumar 20 a su vida
//El poder especial suma 5 a su ataque y establece en 0 a sus flechas







class Personaje
{
public:
    int ataque;
    int vida;
    Personaje()
    {

    }
    Personaje(int ataque, int vida)
    {
    }

    virtual void regenerarVida()
    {
        this->vida += 10;
    }
    virtual void poderEspecial()=0;
};


class Guerrero : public Personaje
{
public:
    Guerrero(int ataque, int vida )
    {
        this->ataque=ataque;
        this->vida=vida;
    }
    void poderEspecial()
    {
        this->ataque=ataque*2;
        this->vida=vida/2;
    }
};


class Arquero : public Personaje
{
public:
    int flechas;
    Arquero(int ataque, int vida,int flechas)
    {
        this->ataque=ataque;
        this->vida=vida;
        this->flechas=flechas;

    }
    int operator+=(int b)
    {
        flechas+=b;
    }

    void regenerarVida()
    {
        vida+=20;
    }

    void poderEspecial()
    {
        flechas=0;
        ataque+=5;
    }
};


///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();


    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////

void evaluar2()
{
    double nota = 0;
    int _a,_v,_f;

    cout<<"Test Guerrero"<<endl;

    cout<<"Constructor:\t\t";
    Guerrero g(10,100);
    if(g.ataque == 10
        && g.vida == 100
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Regenerar vida:\t\t";

    _a=g.ataque;
    _v=g.vida;
    g.regenerarVida();
    if(g.ataque == _a
        && g.vida == _v+10
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Poder especial:\t\t";
    _a=g.ataque;
    _v=g.vida;
    g.poderEspecial();
    if(g.ataque == _a*2
        && g.vida == _v/2
        )
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<endl<<"Test Arquero"<<endl;
    cout<<"Constructor:\t\t";
    Arquero a(5,50,10);

    if(a.ataque == 5
        && a.vida == 50
        && a.flechas == 10
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Sobrecarga de op.:\t";
    _a=a.ataque;
    _v=a.vida;
    _f=a.flechas;
    a+=10;
    if(a.ataque == _a
        && a.vida == _v
        && a.flechas == _f+10
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Regenerar vida:\t\t";
    _a=a.ataque;
    _v=a.vida;
    _f=a.flechas;
    a.regenerarVida();
    if(a.ataque == _a
        && a.vida == _v+20
        && a.flechas == _f
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"Poder especial:\t\t";
    _a=a.ataque;
    _v=a.vida;
    _f=a.flechas;
    a.poderEspecial();
    if(a.ataque == _a+5
        && a.vida == _v
        && a.flechas == 0
        )
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/9"<<endl;
}
