#include <iostream>
#include <cstring>
#include <cstddef>
#include <stdio.h>
#include <vector>
#include <sstream>

#define size1 100

using namespace std;


vector<string> split(string str, char delimiter);
int revisar(string n, vector<string> nombrereyes);
int cantidad (int n, vector<string> suc, string nombre);
int indice(vector <string> nombrerey, string nombresuc);

int main()
{

    int r =0, contval=0, s=0;
    string reyes, sucesores;



    cout << "Digite la cantidad de Reyes de una dinastia: ";
    cin >> r;




    cout << "Digite los nombres de los Reyes: ";
    fflush(stdin);

    getline(std:: cin,reyes);

    cout << endl;
    vector<string> rey = split(reyes, ' ');


    for(int i = 0; i < rey.size(); ++i)
    {

        for(int j=i+1; j < rey.size(); j++)
        {
            if((rey[i].compare(rey[j])) != 0 )
            {
                contval++;
            }
        }
        contval =0;

    }
    if(contval > 20)
    {
        cout << "Debe haber menos de 20 nombres distintos" << endl;
        return 0;
    }


    cout << "Digite la cantidad de Sucesores: ";
    fflush(stdin);


    cin >> s;

    int contr =0, conts=0;
    string nombrere[20];
    vector <string> nombrereyes;
    vector <int> cantreyes;



    cout << "Digite los nombres de los Sucesores: ";
    fflush(stdin);
    getline(std:: cin,sucesores);


    vector<string> suce = split(sucesores, ' ');

    for(int i = 0; i < rey.size(); ++i)
    {
        for(int j=0; j < rey.size(); j++)
        {
            if((rey[i].compare(rey[j])) == 0 )
            {
                contr++;
            }


        }


        if(revisar(rey[i], nombrereyes) == 0)
        {
            nombrereyes.push_back(rey[i]);
            cantreyes.push_back(contr);


        }
        contr =0;

    }

    cout << endl;
    for(int i=0; i < nombrereyes.size(); i++)
    {
        cout << "Nombre: " << nombrereyes[i] << " cant: " << cantreyes[i] << endl;
    }


    cout << endl;

    vector <string> nombresuce;
    vector <int> cantsucerores;



    for(int i=0; i < s; i++)
    {

        for(int j=0; j < s; j++)
        {
            if((suce[i].compare(suce[j])) == 0 )
            {
                conts++;
            }


        }


        if(revisar(suce[i],nombresuce) == 0)
        {


            nombresuce.push_back(suce[i]);
            cantsucerores.push_back(conts);


        }

        conts=0;

    }
    bool si = false;

    for(int i = 0; i < suce.size(); ++i)
    {

        if(indice(nombrereyes, suce[i]) == 0 )
        {
            int n = indice(nombrereyes, suce[i]);
            if(i == (suce.size()-1))
            {
                cout << cantreyes[n] + cantidad(i, nombresuce, suce[i])+1 << endl;
            }
            else
                cout << cantreyes[n] + cantidad(i, nombresuce, suce[i]) << endl;

        }
        else
            cout << cantidad(i,nombresuce,suce[i]) << endl;






    }







}

int indice(vector <string> nombrerey, string nombresuc)
{

    for(int i=0; i < nombrerey.size(); i++)
    {
        if(nombresuc.compare(nombrerey[i]) == 0)
        {
            return i;
        }

    }

    return -1;
}

int cantidad (int n, vector<string> suc, string nombre)
{

    int cont=0;
    cout << "Funcion Cantidad" << endl;
    for(int i=0; i < suc.size(); i++)
    {
        if(suc[i].compare(nombre) == 0)
        {

            cont++;

        }
        cout << "Nombre: " << nombre << " cont: " << cont << " valor de i: " << i << endl ;

    }

    return cont;
}


int revisar(string n, vector<string> nombres)
{
    int val = 0;
    for(int i=0; i < nombres.size();i++)
    {
        if(n.compare(nombres[i]) == 0)
        {
            val++;

        }
    }

    if(val != 0)
    {
        return 1;
    }


    return 0;

}






vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

