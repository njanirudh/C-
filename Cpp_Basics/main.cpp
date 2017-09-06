#include <iostream>
#include <ostream>

using namespace std;

class Point{

public:
    Point();

    //Constructor
    Point(int x1, int y1)
    {
        x = x1 ;
        y = y1 ;
    }

    //Copy Constructor
    Point(const Point & _point )
    {
        x = _point.x;
        y = _point.y;
    }

    //Overloading the extraction operator
    friend std::ostream& operator<< (std::ostream &out, const Point &point)
    {
        out << "Point(" << point.x << ", " << point.y << ")"<<std::endl;
        return out;
    }

    //Overloading the insertion operator
    friend std::istream &operator>>( istream  &input, Point &point ) {
        input >> point.x >> point.y;
        return input;
    }

    int x;
    int y;

};


int main(int argc, char *argv[])
{
    Point point(5,7);
    Point newPnt = point;
    Point inPnt;

    std::cout<<point; //Printing the point
    std::cout<<newPnt; // Copied Points

    return 0;
}
