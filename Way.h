#include "Poit.h"
using namespace std;
int GetRandomNumber(int min, int max) //рандомайзер
{

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);
    return num;
};
class Way
{
public: vector<poit> way_path;
public: void safeState(int X, int Y, float pathLenght)
{
    float sum_path = 0;
    if (way_path.empty() == false) {
        poit pos2 = way_path.back();
        sum_path = pos2.getPath() + pathLenght; //saves way lenght
    }
    poit pos1(X, Y, sum_path);
    way_path.push_back(pos1); //push point
}

      void Move(poit Point, int maxsize, poit StartPoint) {
          int shiftX = GetRandomNumber(-1, 1);
          int shiftY = GetRandomNumber(-1, 1);
          float complete_path = 0;
          if ((Point.get_X() + shiftX > 0 && Point.get_X() + shiftX < maxsize) && (Point.get_Y() + shiftY > 0 && Point.get_Y() + shiftY < maxsize)) {
              Point.Relocate(shiftX, shiftY);
              complete_path = sqrt(pow(shiftX, 2) + pow(shiftY, 2));
          }
          safeState(Point.get_X(), Point.get_Y(), complete_path); //save point in way
          system("cls"); //clear console
          Point.printMatrix(maxsize);
          float dist = Point.Distance(StartPoint.get_X(), StartPoint.get_Y());
          poit DistPoint = way_path.back(); //last saved point
          cout << "distance to point:    " << dist << endl << "pathLenght:         " << DistPoint.getPath() << endl << "cords of dot (X/Y): " << Point.get_X() + 1 << "/" << Point.get_Y() + 1 << endl;
          Sleep(2000);
      }
};