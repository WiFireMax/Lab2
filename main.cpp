#include "Way.h"
using namespace std;
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
    poit Start(start_X, start_Y);
    poit Point1(GetRandomNumber(0, maxsize), GetRandomNumber(0, maxsize)); //create point
    Way Path1; //class where save points
    for (int i = 0; i < steps; i++) { //relocated point in matrix
        Path1.Move(Point1, maxsize, Start);
    }
    getchar();
    return 0;
}