#ifndef COLOR_H
#define COLOR_H

class Color
{
    
    private:

        unsigned char _red, _green, _blue;

    public:

        Color(unsigned char red, unsigned char green, unsigned char blue);

        // um char tem um byte e por ser unsigned vai de 0 a 255 bits
        
        Color(const Color& c);

        bool operator==(const Color& other) const;

        static const Color RED, GREEN, BLACK, BLUE, WHITE;

        bool equal_to(const Color& other) const;

        void invert();

        unsigned char red() const;
        unsigned char green() const;
        unsigned char blue() const;

};

#endif

// namespace std_color
// {
//     static const Color RED = Color(255, 0, 0), GREEN = Color(0, 255, 0), BLUE = Color(0, 0, 255), BLACK = Color(0, 0, 0), WHITE = (255, 255, 255);
// }

