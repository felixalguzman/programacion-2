#include <iostream>

using namespace std;



int espalindromico(int n);
int esprimo(int n);

int main()
{
    int p=0, aux=0;
    bool enc = false;

    cout << "Digite un numero para buscar el siguiente primo que tambien sea palindromo: ";
    do
    {
        cin >> p;

        if(p < 1 && p > 1000000)
        {
            cout << "El rango del numero es entre 1 y 1,000,000. Intente de nuevo.";
        }


    }while( p < 1 && p >1000000);

    /*
    if(esprimo(101))
    {
        cout << "Es primo " << endl;
    }
    if(espalindromico(101))
    {
        cout << "Es palindromo";
    }
    */
    aux = p;

   while(!enc && aux < 1000000)
   {
       //cout << "Valor de p: " << aux << endl;
       if(esprimo(aux))
       {
           if(espalindromico(aux))
           {
              cout << "El numero es: " << aux ;
              enc = true;
           }

       }


       aux++;
   }

  cout << endl ;



}


int espalindromico(int n)
{
    int inverso=0;

    for (int i= n; i > 0; i/=10)
    {
        inverso = inverso * 10 + i % 10;

    }

    if(n == inverso)
    {
        return 1;
    }

    return 0;


}

int esprimo(int n)
{
    int cont =0;

    for(int i=1; i <= n; i++)
    {
        if((n % i) == 0)
        {
           cont++;
        }
    }

    if(cont > 2)
    {
        return 0;
    }

    return 1;
}


