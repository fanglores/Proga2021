#include <iostream>
using namespace std;

/*
1. Для класса Image реализовать:
class Image 
{
  int* img;
  int mx,int my;
public:
  Image(int tmx, int tmy):mx(tmx),my(tmy)
  {
    img = new int[mx*my]();
  }
  vitual ~Image(); // Реализовать
  int get(int x,int y) 
  {
  // Добавить обработку ошибок при помощи исключений - выбрасывать целочисленное исключение при выходе за границы массива
    return img[y*my+x];
  } 
  int set(int x,int y,int color) 
  { 
  // Добавить обработку ошибок при помощи исключений  - выбрасывать целочисленное исключение при выходе за границы массива
    img[y*my+x]=color;
  }
  friend std::ostream& operator<<(std::ostream& out, const Image &d1);     // Реализовать  для варианта 2
};
2. Реализовать перегрузку одной из операций
3. Реализовать функцию main и показать использование класса Image
Вариант 2 оператор вывода в поток <<, 
*/

class Image {
    int* img;
    int mx, my;

public:
    Image(int tmx, int tmy)
    {
        mx = tmx;
        my = tmy;
        img = new int[mx * my];
    }

    virtual ~Image()
    {
        delete[] img;
    }

    int get(int x, int y) 
    {
        if (x >= mx || y >= my || x < 0 || y < 0) throw 404;
        return img[y * mx + x];
    }

    int set(int x, int y, int color) 
    { 
        if(x >= mx || y >= my || x < 0 || y < 0) throw 404;
        img[y * mx + x] = color;
    }

    friend ostream& operator<<(ostream&, const Image&);     // Реализовать  для варианта 2
    Image& operator=(const Image& im)
    {
        if (&im == this) return *this;

        mx = im.mx;
        my = im.my;
        img = new int[mx * my];

        for (int i = 0; i < mx * my; i++) img[i] = im.img[i];

        return *this;
    }
};

ostream& operator<<(ostream& out, const Image& d1)
{
    for (int i = 0; i < d1.my; i++)
    {
        for (int j = 0; j < d1.mx; j++)
            out << d1.img[i*d1.mx + j] << ' ';
        out << endl;
    }

    return out;
}


int main()
{
    try
    {
        Image i(2, 3);
        i.set(0, 0, 1); i.set(1, 0, 2);
        i.set(0, 1, 3); i.set(1, 1, 4);
        i.set(0, 2, 5); i.set(1, 2, 6);

        cout << i << endl;

        Image i1(0, 0); i1 = i;
        cout << i1 << endl;

        cout << i.get(0, 1) << endl;
        cout << i.get(-1, 0);
    }
    catch (int e)
    {
        if (e == 404) cout << "Error 404. Array element not found." << endl;
    }
}
