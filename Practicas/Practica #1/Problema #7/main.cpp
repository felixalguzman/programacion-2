#include <iostream>
#include <stdio.h>

#define size 50
using namespace std;

int main()
{
    char carac[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char cadena[size];
    int valor[26] = {  2, 22, 222, 3, 33, 333, 4, 44, 444, 5, 55, 555, 6, 66, 666, 7, 77, 777, 7777, 8, 88, 888, 9, 99, 999, 9999};
    char ant, nue, siguient, ant1;
    int val=0, valnuev=0;


    cout << "Digite una cadena para saber su valor en numeros: ";
    gets(cadena);


    for(int i=0; cadena[i] != '\0' ; i++)
    {
        if(cadena[i] >= 'a' && cadena [i] <= 'z')
        {
            cadena[i] -=32;
        }

        if(cadena[i] != ' ')
        {
              for(int j=0; j < 26; j++)
            {
                    ant = cadena[i];
                    nue = cadena[i-1];
                    siguient = cadena[i-1];
                    siguient = siguient -1;
                    ant1 = cadena[i];
                    ant1 = ant1 ;



                    if(ant == nue && cadena[i] == carac[j])
                    {


                            cout << ' ' <<valor[j] ;

                    }
                    else if(cadena[i] == carac[j])
                    {
                        cout << valor[j];
                    }


            }
        }
        else
        {
            cout << ' ';
        }

    }


    cout << endl;
    //cout << ant;
    cout << ant1<< endl;
     cout << siguient;
   // cout << nue;





}
