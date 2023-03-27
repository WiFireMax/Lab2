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
class Way : public poit
{
public: vector<poit> way_path;
public: void safeState(int X, int Y, float pathLenght)
{
    float sum_path=0;
    if (way_path.empty() == false) {
        poit pos2 = way_path.back();
        sum_path = pos2.getPath()+pathLenght; //saves way lenght
    }
    poit pos1(X, Y, sum_path);
    way_path.push_back(pos1); //push point
}
};
int GetRandomNumber(int min, int max) //рандомайзер
{

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);

    return num;
};
int main() {
    srand(time(NULL));
    int maxsize;
    cout << "Input size of matrix: "; //size of matrix
    cin >> maxsize;
    int steps;
    cout << "Input steps of relocate: "; //steps of changes coords
    cin >> steps;
    int start_X, start_Y;
    cout << "Input start point, where calculate distance: " << endl << "X point: ";
    cin >> start_X;
    cout << "Y point: ";
    cin >> start_Y;
    poit Point1(GetRandomNumber(0, maxsize), GetRandomNumber(0, maxsize)); //create point
    Way Path1; //class where save points
    for (int i = 0; i < steps; i++) { //relocated point in matrix
        int shiftX = GetRandomNumber(-1, 1);
        int shiftY = GetRandomNumber(-1, 1);
        float complete_path = 0;
        if ((Point1.get_X() + shiftX > 0 && Point1.get_X() + shiftX < maxsize) && (Point1.get_Y() + shiftY > 0 && Point1.get_Y() + shiftY < maxsize)) {
            Point1.Relocate(shiftX, shiftY);
            complete_path = sqrt(pow(shiftX, 2) + pow(shiftY, 2));
        }
        Path1.safeState(Point1.get_X(), Point1.get_Y(), complete_path); //save point in way
        system("cls"); //clear console
        Point1.printMatrix(maxsize);
        float dist = Point1.Distance(start_X, start_Y);
        poit DistPoint = Path1.way_path.back(); //last saved point
        cout << "distance to point:    " << dist << endl << "pathLenght:         " << DistPoint.getPath() << endl << "cords of dot (X/Y): " << Point1.get_X()+1 << "/" << Point1.get_Y()+1 << endl;
        Sleep(2000);
    }
    getchar();
    return 0;
}