#include "arreglos.h"

Arreglos::Arreglos()
{

}

Arreglos::Arreglos(int i)
{
    this->F=i;
    this->C=-1;
    this->N=-1;

    this->array=new Objeto[F];
}

Arreglos::Arreglos(int i,int j)
{
    this->F=i;
    this->C=j;
    this->N=-1;
    this->array=new Objeto[F*C];
}

Arreglos::Arreglos(int i,int j,int k)
{
    this->F=i;
    this->C=j;
    this->N=k;
    this->array=new Objeto[F*C*N];
}

/*----------------------Cuando es un arreglo de una posicion------------------------*/

QString Arreglos::setDato1(Objeto nuevo, int i, int tipo){
    QString salida="";
    if(this->tipo_==14 && (tipo==43 || tipo==42)){
        if(this->C==-1 && this->N==-1){
            if(i<this->F && i>-1){
                array[i]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else if(this->tipo_==17 && (tipo==40)){
        if(this->C==-1 && this->N==-1){
            if(i<this->F && i>-1){
                array[i]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }

    }else if(this->tipo_==16 && tipo==41){
        if(this->C==-1 && this->N==-1){
            if(i<this->F && i>-1){
                array[i]=nuevo;
            }else{
                 salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else if(this->tipo_==15 && (tipo==43 || tipo==42)){
        if(this->C==-1 && this->N==-1){
            if(i<this->F && i>-1){
                array[i]=nuevo;
            }else{
                 salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else if(this->tipo_==18 && (tipo==44 || tipo==45) ){
        if(this->C==-1 && this->N==-1){
            if(i<this->F && i>-1){
                array[i]=nuevo;
            }else{
                 salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else{
        salida="Error en los tipos de Datos de Arreglo";
    }
    return salida;
}

/*------------------------ cuando es un arreglo de 2 dimensiones---------------------------*/

QString Arreglos::setDato2(Objeto nuevo, int i, int j, int tipo){
    QString salida="";
    if(this->tipo_==14 && (tipo==43 || tipo==42)){
        if(this->N==-1){
            if(i<this->F && i>-1 && j<this->C && j>-1){
                int posicion=((i)*this->C)+j;
                array[posicion]=nuevo;
            }else{
                 salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else if(this->tipo_==17 && (tipo==40)){
        if(this->N==-1){
            if(i<this->F && i>-1 && j<this->C && j>-1){
                int posicion=((i)*this->C)+j;
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }

    }else if(this->tipo_==16 && tipo==41){
        if(this->N==-1){
            if(i<this->F && i>-1 && j<this->C && j>-1){
                int posicion=((i)*this->C)+j;
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else if(this->tipo_==15 && (tipo==43 || tipo==42)){
        if(this->N==-1){
            if(i<this->F && i>-1 && j<this->C && j>-1){
                int posicion=((i)*this->C)+j;
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else if(this->tipo_==18 && (tipo==44 || tipo==45) ){
        if(this->N==-1){
            if(i<this->F && i>-1 && j<this->C && j>-1){
                int posicion=((i)*this->C)+j;
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }
        }else{
            salida="Dimensiones incorrecta para el arreglo";
        }
    }else{
        salida="Error en los tipos de datos del arreglo";
    }
    return salida;
}


QString Arreglos::setDato3(Objeto nuevo, int i, int j, int k, int tipo){
    QString salida="";
    if(this->tipo_==14 && (tipo==43 || tipo==42)){

            if(i<this->F && i>-1 && j<this->C && j>-1 && k<this->N && k>-1){
                int posicion=((i)*this->C)+j+((this->F*this->C)*(k));

                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }

    }else if(this->tipo_==17 && (tipo==40)){

            if(i<this->F && i>-1 && j<this->C && j>-1 && k<this->N && k>-1){
                int posicion=((i)*this->C)+j+((this->F*this->C)*(k));
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }


    }else if(this->tipo_==16 && tipo==41){

            if(i<this->F && i>-1 && j<this->C && j>-1 && k<this->N && k>-1){
                int posicion=((i)*this->C)+j+((this->F*this->C)*(k));
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }

    }else if(this->tipo_==15 && (tipo==43 || tipo==42)){

            if(i<this->F && i>-1 && j<this->C && j>-1 && k<this->N && k>-1){
                int posicion=((i)*this->C)+j+((this->F*this->C)*(k));
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }

    }else if(this->tipo_==18 && (tipo==44 || tipo==45) ){

            if(i<this->F && i>-1 && j<this->C && j>-1 && k<this->N && k>-1){
                int posicion=((i)*this->C)+j+((this->F*this->C)*(k));
                array[posicion]=nuevo;
            }else{
                salida="Posicion fuera de Alcance";
            }

    }else{
        salida="Error en los tipos de datos";
    }
    return salida;
}


Objeto Arreglos::getDato1(int i){
    Objeto salida=Objeto();
    if(this->C==-1 && this->N==-1){

        if(i<this->F && i>-1){

            salida=array[i];
            return  salida;
        }
        return salida;
    }
    return salida;
}


Objeto Arreglos::getDato2(int i, int j){

    Objeto salida=Objeto();
    if(this->N==-1){
        if(i<this->F && i>-1 && j<this->C && j>-1){
            int posicion=((i)*this->C)+j;
            salida=array[posicion];
            return  salida;
        }
        return salida;
    }
    return salida;
}

Objeto Arreglos::getDato3(int i, int j, int k){
    Objeto salida=Objeto();

    if(i<this->F && i>-1 && j<this->C && j>-1 && k<this->N && k>-1){

        int posicion=((i)*this->C)+j+((this->F*this->C)*(k));
        salida=array[posicion];
        return salida;
    }
    return salida;

}

