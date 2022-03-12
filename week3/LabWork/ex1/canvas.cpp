#include "canvas.hpp"
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int lines, int columns)
{
    m = new char*[lines];
    for (int i = 0; i < lines; i++)
    {
        m[i] = new char[columns];
    }
    this->lines = lines;
    this->columns = columns;
    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < lines; i++)
        delete[] m[i];
    delete[] m;
}

void Canvas::SetPoint(int x, int y, char value)
{
    m[x][y] = value;
}

void Canvas::SetPoints(int count, ...)
{
    std::va_list args;
    va_start(args, count);

    int x, y, value;
    for (int i = 0; i < count; i++)
    {
        x     = va_arg(args, int);
        y     = va_arg(args, int);
        value = va_arg(args, int);
        SetPoint(x, y, value);
    }

    va_end(args); 
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char value)
{
    for(int i = left; i <= right; i++)
    {
        SetPoint(top, i, value);
        SetPoint(bottom, i, value);
    }
    for(int i = top; i <= bottom; i++)
    {
        SetPoint(i, left, value);
        SetPoint(i, right, value);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char value)
{
    for(int i = top; i <= bottom; i++)
        for(int j = left; j <= right; j++)
            SetPoint(i, j, value);
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char value)
{
    int dx, dy, p, x, y;
    dx=x2-x1;
    dy=y2-y1;
    x=x1;
    y=y1;
    p=2*dy-dx;
    while(x<x2)
    {
        if(p>=0)
        {
            SetPoint(x,y,value);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            SetPoint(x,y,value);
            p=p+2*dy;
        }
        x=x+1;
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char value)
{
    for(int i = x - ray; i <= x + ray; i++)
    {
       for(int j = y - ray; j <= y + ray; j++)
       {
           int p = (i-ray)*(i-ray) + (j-ray)*(j-ray);
           if(p == ray*ray ||  p == ray*ray - 1 || p == ray*ray - 2)
           {
               SetPoint(i, j, value);
           }
       }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char value)
{
    for(int i = x - ray; i <= x + ray; i++)
    {
       for(int j = y - ray; j <= y + ray; j++)
       {
           if((i-ray)*(i-ray) + (j-ray)*(j-ray) <= ray*ray)
           {
               SetPoint(i, j, value);
           }
       }
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            m[i][j] = ' ';
}

void Canvas::Print() const
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << m[i][j];
        std::cout << std::endl;
    }
}
