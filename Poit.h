#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <vector>
using namespace std;
class poit { //класс точки обьекта
private:
    int X;
    int Y;
    float Path;
public: poit(int Xin = 0, int Yin = 0, float Pathin = 0)
{
    X = Xin;
    Y = Yin;
    Path = Pathin;
}
      int set_X(int value) {
          X = value;
      }
      int set_Y(int value) {
          Y = value;
      }
      int get_X() {
          return X;
      }
      int get_Y() {
          return Y;
      }
      float getPath()
      {
          return(Path);
      }
      void printMatrix(int maxsize)
      {
          for (int i = maxsize - 1; i >= 0; i--)
          {
              if (i == Y)
              {
                  for (int j = 0; j < maxsize; j++)
                  {
                      if (j == X)
                      {
                          cout << "*";
                      }
                      else
                      {
                          cout << "x";
                      }
                  }
              }
              else
              {
                  for (int j = 0; j < maxsize; j++)
                  {
                      cout << "x";
                  }
              }
              cout << endl;
          }
          cout << endl;
      }
      void Relocate(int value1, int value2) { //изменить координаты точки
          X += value1;
          Y += value2;
      }
      float Distance(int value1, int value2) { //distance between points
          float distance = sqrt(pow(float(X) - float(value1), 2) + pow(float(Y) - float(value2), 2));
          return distance;
      }
};