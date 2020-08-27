#include <iostream>


using namespace std;

int main()
{
    int totalvacas=0, pesocamion =0, valsum=0, cant1=0, menorvaca=0, sum=0, menorlech =0, menorindice=0;

    cout << "Digite la cantidad de Vacas a la venta: ";
    cin >> totalvacas;

    cout << endl;
    cout << "Digite el peso total que el camion puede llevar: ";
    cin >> pesocamion;

    int peso[totalvacas],leche[totalvacas], listselvac[cant1],  listlech[cant1], indice[totalvacas];

    for(int i=0; i < totalvacas; i++)
    {

        cout << "Digite el peso en kilogramos para la vaca #" <<i+1 << ": ";
        cin >> peso[i];

        cout << "Digite la produccion de leche en litros por dia para la vaca #" << i+1 <<": ";
        cin >> leche[i];

        indice[i] = i+1;

    }

    for(int j =0; j <totalvacas ;j++)
    {

        for(int ind =j+1;ind < totalvacas; ind ++)
        {
            if(peso[j] > peso[ind])
            {
                menorvaca = peso[j];
                peso[j] = peso[ind];
                peso[ind] = menorvaca;

                menorlech = leche[j];
                leche[j] = leche[ind];
                leche[ind] = menorlech;

                menorindice = indice[j];
                indice[j] = indice [ind];
                indice[ind] = menorindice;

            }
        }
    }

    float prom=0, prom1=0;
    for(int j =0; j <totalvacas ;j++)
    {

        for(int ind =j+1;ind < totalvacas; ind ++)
        {
            prom = leche[j] / peso[j];
            prom1 = leche[ind] / peso[ind];

            if(prom < prom1)
            {
                menorvaca = peso[j];
                peso[j] = peso[ind];
                peso[ind] = menorvaca;

                menorlech = leche[j];
                leche[j] = leche[ind];
                leche[ind] = menorlech;

                menorindice = indice[j];
                indice[j] = indice [ind];
                indice[ind] = menorindice;

            }
        }
    }

    for(int ind = 0; ind < totalvacas; ind++)
    {
        valsum += peso[ind];

        if(valsum <= pesocamion)
        {

            listselvac[cant1] = peso[ind];
            listlech[cant1] = leche[ind];

            cant1++;


        }

    }



    cout << endl;
    cout << "  -- Vacas seleccionadas --" << endl;
    for(int i =0; i < cant1; i++)
    {
        sum += listlech[i];
        cout << "Vaca #" << indice[i] << " con peso: " << listselvac[i] << " y produccion de leche por dia: " << listlech[i] << endl;

    }
    cout << "La cantidad maxima que se puede obtener de leche es: " << sum;
    cout << endl << endl;

    cout << "Promedios " << endl;


    for(int i=0; i < totalvacas; i++)
    {
        prom = leche[i] / peso[i];
        cout <<  prom << endl;
    }
}
