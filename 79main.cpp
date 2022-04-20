#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 2000;
double tab[SIZE][3];

bool jeden(double x, double y, double r) {
  return (abs(x) > r && abs(y) > r);
}

void zad1() {
  cout << "Zad 1:" << endl;

  int licznik1 = 0, licznik2 = 0, licznik3 = 0, licznik4 = 0, licznik0 = 0;

  for (int i = 0; i < SIZE; i++)
   {
    float x = tab[i][0], y = tab[i][1], r = tab[i][2];
            if (jeden(x, y, r))
            {
              if (x > 0 && y > 0) licznik1++;
           
		      if (x < 0 && y > 0) licznik2++;
              if (x < 0 && y < 0) licznik3++;
              if (x > 0 && y < 0) licznik4++;
            }
        else licznik0++;
  }



  cout << "1 cwiartka: " << licznik1 << endl;
  cout << "2 cwiartka: " << licznik2 << endl;
  cout << "3 cwiartka: " << licznik3 << endl;
  cout << "4 cwiartka: " << licznik4 << endl;
  cout << "0: " << licznik0 << endl;
  cout << endl;
}


bool lustra(double x1, double y1, double r1, double x2, double y2, double r2) {
    if (r1 != r2)
    {
        return false;
    }
    if (x1 == x2 && y1 == y2)
    {
        return false;
    }
    if (abs(x1) == abs(x2) && y1 == y2)
    {
        return true;
    }
    if (abs(y1) == abs(y2) && x1 == x2)
    {
        return true;
    }
    else
    {
        return false;
    }

}




void zad2() {
    cout << "Zad 2:" << endl;
    int licznik = 0;

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (lustra(tab[i][0], tab[i][1], tab[i][2], tab[j][0], tab[j][1], tab[j][2]))
             {
                licznik++;
             }
        }
    }
    cout <<"Lustrzane pary  "<< licznik;
}



int main() {

  ifstream in("a.txt");
  double a, b, c;

  for (int i = 0; i < SIZE; i++)
  {
    in >> a >> b >> c;
    tab[i][0] = a;
    tab[i][1] = b;
    tab[i][2] = c;
  }
  in.close();

  zad1();
  zad2();

}
