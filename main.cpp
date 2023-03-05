#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
using namespace std;
class poit { //класс точки обьекта
public:
    int X;
    int Y;
    void set_X( int value) {
        X = value;
    }
    void set_Y(int value) {
        Y = value;
    }
};
int GetRandomNumber(int min, int max) //рандомайзер
{

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);

    return num;
}
void PrintMatrix(char** matrix, int size) { //показать матрицу
    for (int i = size-1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            cout << matrix[j][i];
        }
        cout << endl;
    }
}
float Distance(poit start, poit end) { //distance between points
    float distance=sqrt(pow(float(end.X) - float(start.X), 2) + pow(float(end.Y) - float(start.Y), 2));
    return distance;
}
poit Relocate(poit name, int maxsize) { //изменить координаты точки
    int value1 = GetRandomNumber(0 - name.X + 2, maxsize - name.X - 2);
    int value2 = GetRandomNumber(0 - name.Y + 2, maxsize - name.Y - 2);
    name.X += value1;
    name.Y += value2;
    return name;
}
int main() {

    // Установить генератор случайных чисел
    srand(time(NULL));
    int maxsize;
    cout << "Input size of matrix: "; //size of matrix
    cin >> maxsize;
    maxsize += 2;
    char** battlefield = new char* [maxsize];
    for (int i = 0; i <= maxsize; i++) { //create dinamic massive
        battlefield[i] = new char[maxsize];
    }
    for (int i = 0; i <= maxsize; i++) { //empty massive
        for (int j = 1; j <= maxsize; j++) {
            battlefield[i][j] = ' ';

            if ((i == 0) || (i == maxsize-1)) {
                battlefield[i][j] = 'y';
            }
        }
        battlefield[i][0] =  'x';
        battlefield[i][maxsize-1] = 'x';
    }
    int value1 = GetRandomNumber(1, maxsize-2); // create point
    int value2 = GetRandomNumber(1, maxsize-2);
    poit paint;
    paint.set_X(value1);
    paint.set_Y(value2);
    battlefield[paint.X][paint.Y]='*'; //point is "*"
    PrintMatrix(battlefield, maxsize);
    int steps;
    cout << "Input steps of relocate: "; //steps of changes coords
    cin >> steps;
    int *x_array = new  int[steps+1];
    int *y_array = new int[steps+1];
    x_array[0] = paint.X; //array X coords points
    y_array[0] = paint.Y; //array Y coords points
    cout << "coord point: {" << x_array[0] << " ," << y_array[0] << "} " << endl;
    poit start;
    cout << "Input start point, where calculate distance: " << endl << "X point: ";
    cin >> start.X;
    cout << "Y point: ";
    cin >> start.Y;
    cout << "Distance: ";
    float dist = Distance(start, paint);
    cout << dist << endl;
    Sleep(2000);
    for (int i = 0; i < steps; i++) { //prints matrixs and relocated
            system("cls");
            battlefield[paint.X][paint.Y] = ' '; //clear point in matrix
            paint = Relocate(paint, maxsize); //relocate point
            battlefield[paint.X][paint.Y] = '*';
            x_array[i + 1] = paint.X; //save coords
            y_array[i + 1] = paint.Y;
            PrintMatrix(battlefield, maxsize);
            cout << "coord paint: {" << x_array[i + 1] << " ," << y_array[i + 1] << "} " << endl;
            cout << "Distance: ";
            float dist = Distance(start, paint);
            cout << dist << endl;
            Sleep(1500);
    }
    getchar();
    return 0;
}
