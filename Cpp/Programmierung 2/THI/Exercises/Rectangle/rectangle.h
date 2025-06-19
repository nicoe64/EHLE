#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
    private:
        float height;
        float width;        
    public:
        static int number;
        Rectangle(const float pHeight, const float pWidth);
        Rectangle(const Rectangle& rect);                       // Copy-Konstruktor
        float getHeight() const;
        float getWidth() const;
        void setHeight(const float pHeight);
        void setWidth(const float pWidth);
        float compArea() const;
};

#endif // RECTANGLE_H