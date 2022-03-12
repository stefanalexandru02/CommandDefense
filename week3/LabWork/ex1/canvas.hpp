//
//  canvas.hpp
//  w3
//
//  Created by Stefan Alexandru on 12.03.2022.
//

#ifndef canvas_hpp
#define canvas_hpp

#include <stdio.h>
class Canvas {
    int lines, columns;
    char** m;
public:
    Canvas(int width,int height);
    ~Canvas();
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void SetPoints(int count, ...);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print() const;
    void Clear(); // clears the canvas
};
#endif /* canvas_hpp */
