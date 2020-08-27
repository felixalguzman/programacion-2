#include <iostream>
#include <cstring>

#define size 50
using namespace std;
int main(){

 char cadena[size];
 char palabra[size];
 char *pal;
 int con=0;


 cout << "Digite la cadena 1: ";
 cin >> cadena;
 cout << "Digite la cadena 2: ";
 cin >> palabra;


 pal = strpbrk(cadena,palabra);

 cout << "Cadena encontrada " << pal;
 /*
 for(int i=0; i < cadena[i];i++)
 {
    for(int j=0; j< palabra[j]; j++)
    {
        if(cadena[i] == palabra[j])
        {

        }

    }
 }

*/

}
