#include <iostream>

using namespace std;

int prueba1( int val[10], int n, int hor, int minu, int seg);

int main()
{

   int val[10] = {6,2,5,5,4,5,6,3,7,6};

    int n=0, hor=0, minu=0, seg=0, part1h , part2h , part1min, part2min, part1seg, part2seg;

    cout << "Digite la cantidad de segundos:  ";
    cin >> n;


    hor = (int)(n / 3600);
    minu = (int)((n - hor * 3600) / 60);
    seg = n - (hor * 3600 + minu * 60);

    cout << "Horas: " << hor << endl;
    cout << "Minutos: " << minu << endl;
    cout << "Segundos: " << seg << endl;

    part1h =  (hor%100 - hor%10)/10;
    part2h = hor%10;

    part1min = (minu%100 - minu%10)/10;
    part2min = minu%10;

    part1seg = (seg%100 - seg%10) / 10;
    part2seg = seg%10;



    cout << "Parte 1 hora: " << part1h <<endl;
    cout << "Parte 2 hora: " << part2h << endl;
    cout << "Parte 1 minuto: " << part1min << endl;
    cout << "Parte 2 minuto " << part2min << endl;
    cout << "Parte 1 segundo: " << part1seg << endl;
    cout << "Parte 2 segundo: " << part2seg << endl;

    cout << endl;
    cout << endl;


    int p1 = prueba1( val, n, hor, minu, seg );



    cout << endl;
    cout << endl;
    cout << "Los LED'S encendidos hasta " << n << " son: " << p1;

}

int prueba1( int val[10], int n, int hor, int minu, int seg)
{
    int res =0, res1h =0, res2h =0, res1min =0, res2min =0, res1seg =0, res2seg=0, cont=0;
    int part1h=0,  part2h=0,  part1min=0,  part2min=0,  part1seg=0,  part2seg=0;

    while(cont<=n)
    {
        hor = (int)(cont / 3600);
        minu = (int)((cont - hor * 3600) / 60);
        seg = cont - (hor * 3600 + minu * 60);

        part1h =  (hor%100 - hor%10)/10;
        part2h = hor%10;

        part1min = (minu%100 - minu%10)/10;
        part2min = minu%10;

        part1seg = (seg%100 - seg%10) / 10;
        part2seg = seg%10;


        res1h += val[part1h];
        res2h += val[part2h];
        res1min += val[part1min];
        res2min += val[part2min];
        res1seg += val[part1seg];
        res2seg += val[part2seg];





        cout << "Valor de cont: " << cont << endl;
        cont++;

    }





    res = res1h + res2h + res1min + res2min + res1seg + res2seg;






    return res;
}

