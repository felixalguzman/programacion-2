#include <iostream>
using std::cout;
using std::endl;

int heuristica(int[][8], int&, int&);
bool probar(int, int, int[][8]);
int cuantos(int, int, int[][8]);
void ponerReina(int, int, int[][8]);

int main()
{
  int tablero[8][8] = {};
  int fila;
  int columna;
  int a, b;

  while(heuristica(tablero, fila, columna) != -1)
  {
    ponerReina(fila, columna, tablero);
  }

  for(int x = 0; x < 8; x++)
  {
    for(int y = 0; y < 8; y++)
    {
      if(tablero[x][y] == 2)
    cout << "O";
      else
    cout << "X";
    }
    cout << endl;
  }

  cout << endl;
  return 0;
}

int heuristica(int tablero[][8], int &fila, int &columna)
{
  int mejor[] = {-1, 0, 0};
  int actual;

  for(int x = 0; x < 8; x++)
  {
    for(int y = 0; y < 8; y++)
    {
      if(tablero[x][y] == 0)
      {
    if(probar(x, y, tablero))
    {
      if(cuantos(x, y, tablero) < mejor[0] || mejor[0] == -1)
      {
        mejor[0] = cuantos(x, y, tablero);
        mejor[1] = x;
        mejor[2] = y;
      }
    }
      }
    }
  }

  fila = mejor[1];
  columna = mejor[2];
  return mejor[0];
}

bool probar(int x, int y, int tablero[][8])
{
  int r = x;
  int s = y;

  if(tablero[x][0] != 0 || tablero[x][1] != 0 || tablero[x][2] != 0 || tablero[x][3] != 0 ||
    tablero[x][4] != 0 || tablero[x][5] != 0 || tablero[x][6] != 0 || tablero[x][7] != 0)
      return false;

  if(tablero[0][y] != 0 || tablero[1][y] != 0 || tablero[2][y] != 0 || tablero[3][y] != 0 ||
    tablero[4][y] != 0 || tablero[5][y] != 0 || tablero[6][y] != 0 || tablero[7][y] != 0)
      return false;

  // Diagonal \ hacia arriba
  r--;
  s--;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[r][s] != 0)
      return false;
    r--;
    s--;
  }

  // Diagonal \ hacia abajo

  r = x+1;
  s = y+1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[r][s] != 0)
      return false;
    r++;
    s++;
  }

  // Diagonal / hacia arriba

  r = x-1;
  s = y+1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[x][y] != 0)
      return false;

    r--;
    s++;
  }

  // Diagonal / hacia abajo

  r = x+1;
  s = y-1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[x][y] != 0)
      return false;

    r++;
    s--;
  }

  return true;
}

int cuantos(int x, int y, int tablero[][8])
{
  int r = x;
  int s = y;
  int total = 0;

  for(int i = 0; i < 8; i++)
  {
    if(tablero[x][i] == 0)
      total++;
  }

  for(int i = 0; i < 8; i++)
  {
    if(tablero[i][y] == 0)
      total++;
  }

  // Diagonal \ hacia arriba
  r--;
  s--;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[r][s] == 0)
      total++;
    r--;
    s--;
  }

  // Diagonal \ hacia abajo

  r = x+1;
  s = y+1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[r][s] == 0)
      total++;
    r++;
    s++;
  }

  // Diagonal / hacia arriba

  r = x-1;
  s = y+1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[x][y] == 0)
      total++;

    r--;
    s++;
  }

  // Diagonal / hacia abajo

  r = x+1;
  s = y-1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    if(tablero[x][y] == 0)
      total++;

    r++;
    s--;
  }

  return total-1;
}

void ponerReina(int x, int y, int tablero[][8])
{
  int r = x;
  int s = y;

  tablero[x][y] = 2;

  for(int i = 0; i < 8; i++)
  {
    if(tablero[x][i] == 0)
      tablero[x][i] = 1;
  }

  for(int i = 0; i < 8; i++)
  {
    if(tablero[i][y] == 0)
      tablero[i][y] = 1;
  }

  // Diagonal \ hacia arriba
  r--;
  s--;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    tablero[r][s] = 1;
    r--;
    s--;
  }

  // Diagonal \ hacia abajo

  r = x+1;
  s = y+1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    tablero[r][s] = 1;
    r++;
    s++;
  }

  // Diagonal / hacia arriba

  r = x-1;
  s = y+1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    tablero[r][s] = 1;
    r--;
    s++;
  }

  // Diagonal / hacia abajo

  r = x+1;
  s = y-1;

  while(r >= 0  && r <= 7 && s >= 0 && s <= 7)
  {
    tablero[r][s] = 1;
    r++;
    s--;
  }
}
