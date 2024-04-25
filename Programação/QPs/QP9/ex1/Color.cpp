#include "Color.h"
#include <iostream>

// using namespace std_color;

using namespace std;

const Color Color::RED = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE = Color(0, 0, 255);
const Color Color::BLACK = Color(0, 0, 0); 
const Color Color::WHITE = Color(255, 255, 255);

Color::Color(unsigned char red, unsigned char green, unsigned char blue): _red(red), _green(green), _blue(blue)
{
    //this->_red = red;
    //this->_green = green;
    //this->_blue = blue;
}

Color::Color(const Color& c)
{
     this->_red = c._red;
     this->_blue = c._blue;
     this->_green = c._green;
}

bool Color::operator==(const Color& other) const
{
     return (other._red == this->_red && other._blue == this->_blue && other._green == this->_green);
}

bool Color::equal_to(const Color& other) const
{
     return *this == other; // ou (other._red == this->_red && other._blue == this->_blue && other._green == this->_green);
}

void Color::invert()
{
     this->_red = 255 - this->_red;
     this->_blue = 255 - this->_blue;
     this->_green = 255 - this->_green;
}

unsigned char Color::red() const
{
     return this->_red;
}
unsigned char Color::blue() const
{
     return this->_blue;
}
unsigned char Color::green() const
{
     return this->_green;
}

int main()
{
{ Color c (1, 2, 3);
  const Color& r = c;
  cout << (int) r.red() << ' '  
       << (int) r.green() << ' '  
       << (int) r.blue() << ' '
       << boolalpha << r.equal_to(r) << '\n'; }
       { cout << boolalpha 
       << Color::WHITE.equal_to(Color::WHITE) << ' '
       << Color::BLACK.equal_to(Color::RED) << ' '
       << Color::BLUE.equal_to(Color::GREEN) << '\n'; }
       { Color c(Color::WHITE); 
  cout << (int) c.red() << ' ' 
       << (int) c.green() << ' '  
       << (int) c.blue() << ' '
       << boolalpha << c.equal_to(Color::WHITE) << ' '
       << c.equal_to(Color::BLACK) << '\n'; }
       { Color c(Color::WHITE); 
  c.invert();
  cout << (int) c.red() << ' '  
       << (int) c.green() << ' '  
       << (int) c.blue() << ' ' 
       << boolalpha << c.equal_to(Color::WHITE) << ' '
       << c.equal_to(Color::BLACK) << '\n'; }
       { Color c(255, 128, 12); 
  c.invert();
  Color c2(c);
  c2.invert();
  cout << (int) c.red() << ' ' 
       << (int) c.green() << ' '  
       << (int) c.blue() << ' ' 
       << boolalpha << c.equal_to({ 0, 127, 243 }) << ' '
       << (int) c2.red() << ' ' 
       << (int) c2.green() << ' '  
       << (int) c2.blue() << ' ' 
       << boolalpha << c2.equal_to({ 255, 128, 12 }) << '\n'; }
    return 0;
}
