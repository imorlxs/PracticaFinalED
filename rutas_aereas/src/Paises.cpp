//
// Created by patriiciacoboss on 28/11/23.
//

#include "../include/Paises.h"

void Paises::Insertar(const Pais &P){
    datos.insert(P);
}


void Paises::Borrar(const Pais &P){
    if (this->datos.find(P) != this->datos.end())
        datos.erase(P);
}

/*class const_iterator;
class iterator{
private:
    set<Pais>::iterator p;
public:
    ............
    ..............
    .............
    .	    .........
    friend class Paises;
    friend class const_iterator;
};
class const_iterator{
private:
    set<Pais>::const_iterator p;
public:
    ..........
    ...........
    friend class Paises;

};
 */
iterator Paises::begin(){
    iterator it;
    it.p = datos.begin();
    return it;
}

const_iterator Paises::begin()const{
    const_iterator it;
    it.p = datos.cbegin();
    return it;
}

iterator Paises::end(){
    iterator it;
    it.p = datos.end();
    return it;
}

const_iterator Paises::end()const{
    const_iterator it;
    it.p = datos.cend();
    return it;
}

iterator Paises::find(const Pais &p){
    iterator it;
    set<Pais>::iterator i;
    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
    it.p=i;
    return it;
}

iterator Paises::find(const Punto &p){
    iterator it;
    set<Pais>::iterator i;
    for(i = datos.begin(); i != datos.end() && !((*i.p->GetPunto()) == p); ++i);
    it.p=i->GetPunto();
    return it;
}

friend istream & operator>>(istream & is, Paises & R){
    Paises rlocal;
    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Pais P;
    while (is>>P){
        rlocal.Insertar(P);
    }
    R=rlocal;
    return is;
}
friend ostream & operator<<(ostream & os, const Paises &R){

    Paises::const_iterator it;
    for (it=R.begin(); it!=R.end(); ++it){
        os<<*it<<"\t";
    }
    return os;
}