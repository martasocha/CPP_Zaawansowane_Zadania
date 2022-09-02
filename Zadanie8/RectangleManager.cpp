#include "RectangleManager.hpp"
#include "RectangleGenerator.hpp"
#include "Rectangle.hpp"
#include <vector>
#include <algorithm>


bool printEachRecatngle(Rectangle rect)
{
    std::cout << "bok1 = " << rect.getSide1() << ", bok2 = " << rect.getSide2() << ", pole = " << rect.getField() << std::endl;
    return true;
}

bool lessThen(Rectangle rect1, Rectangle rect2)
{
    return (rect1.getField() < rect2.getField());
}


RectangleManager::RectangleManager(int howMany)
{

    RectangleGenerator generator(0, 10);

    for (unsigned int i = 0; i < 100; ++i)
    {
        vectOfRectangles.push_back(generator.generateRectangle());
    }
}

void RectangleManager::printRectangles()
{
    std::for_each(vectOfRectangles.begin(), vectOfRectangles.end(), printEachRecatngle);
}


size_t RectangleManager::countRectangleBiggerThen(int area)
{
    size_t n = std::count_if(vectOfRectangles.begin(), vectOfRectangles.end(), [&](Rectangle rect) {return (rect.getField() > area); });
    return n;
}

std::vector<Rectangle> RectangleManager::getRectangles()
{
    return vectOfRectangles;
}

std::vector<Rectangle> RectangleManager::copyRectangles()
{
    std::vector<Rectangle> newVectOfRectangles;
    std::copy_if(vectOfRectangles.begin(), vectOfRectangles.end(),
        std::back_inserter(newVectOfRectangles),
        [](Rectangle rect) { return (rect.getSide1() == rect.getSide2()); });


    std::for_each(newVectOfRectangles.begin(), newVectOfRectangles.end(), printEachRecatngle);

    return newVectOfRectangles;
}

void RectangleManager::sortAreaDescending()
{
    std::sort(vectOfRectangles.begin(), vectOfRectangles.end(), lessThen);
}


//void RectangleManager::deleteInvalid()
//{
//
//    auto deleteSideZero = [](Rectangle* rect)
//    {
//        if ((*rect).getSide1() == 0 || (*rect).getSide2() == 0)
//        {
//            delete rect;
//        }
//    };
//
//    std::for_each(getRectangles().begin(), getRectangles().end(), deleteSideZero);
//}
