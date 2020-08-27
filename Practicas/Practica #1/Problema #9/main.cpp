#include <iostream>

using namespace std;

int main()
{
    int n=0, cont=0;

    cout << "Digite el tama\xA4o de la matriz: ";
    do
    {
        cin >>n;

        if(n < 5 )
        {
            cout << "El numero debe ser mayor a 5. Intente de nuevo : ";

        }


    }while(n < 5 );


    int mat[n][n];


    for(int i=0; i < n; i++)
    {
        for(int j=0; j < n; j++)
        {
            mat[n][n] = 0;
        }
    }


    int x= n/2, vx, vy;
    int y=0, limite = n*n, limitex = n-1, limitey = n-1;

    for(int i=1; i < limite;i++)
    {
        mat[x][y] = i;

        vx = x;
        vy = y;

        x++;

        if(x > limitex)
        {
            x=0;
        }

        y--;

        if(y < 0)
        {
            y = limitey;
        }

        if(mat[y][x] > 0)
        {
            x = vx;
            y=vy +1;
        }


    }

    cout << endl;
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < n; j++)
        {
            cout << " " << mat[x][y] << " " ;
        }
        cout << endl;
    }







}
