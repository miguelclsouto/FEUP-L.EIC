#include <iostream>
#include <string>
// #include "fraction_aux.h"
#include <math.h>

using namespace std;

class Fraction
{
    private:

        int numerator_;

        int denominator_;


    public:

        Fraction()
        {
            this->numerator_= 0;
            this->denominator_ = 1;

        }

        Fraction(int num, int den)
        {
            this->numerator_= num;
            this->denominator_ = den;


            if (num * den < 0)
            {
                this->numerator_ = - abs(this->numerator_);
            }
            else
                this->numerator_ = abs(this->numerator_);


            this->denominator_ = abs(this->denominator_);


            this->normalise(); 
            
        }

        int gcd(int a, int b) 
        {
            while (b != 0)
            {
                int tmp = a;
                a = b;
                b = tmp % b;
            }

            return a;
        }

        void normalise() 
        {
            int g = gcd(numerator_, denominator_);

            numerator_ /= g;

            denominator_ /= g;

            if (denominator_ < 0) 
            {
                numerator_ = - numerator_;
                denominator_ = - denominator_;
            }

        }

        void write() const 
        {
            cout << this->numerator_ << '/' << this->denominator_;
        }

        Fraction sum(const Fraction& right)
        {
            Fraction temp;

            temp.numerator_ = this->numerator_ * right.denominator_ + right.numerator_ * this->denominator_;
            temp.denominator_ = this->denominator_ * right.denominator_;

            temp.normalise(); 

            return temp;
        }

        Fraction sub(const Fraction& right)
        {
            Fraction temp;

            temp.numerator_ = this->numerator_ * right.denominator_ - right.numerator_ * this->denominator_;
            temp.denominator_ = this->denominator_ * right.denominator_;

            temp.normalise(); 

            return temp;
        }

        Fraction mul(const Fraction& right)
        {

            Fraction temp;

            temp.numerator_ = this->numerator_ * right.numerator_;
            temp.denominator_ = this->denominator_ * right.denominator_;

            temp.normalise();

            return temp;
        }

        Fraction div(const Fraction& right)
        {

            Fraction temp(this->numerator_, this->denominator_);

            if (right.numerator_ == 0 || this->numerator_ == 0)
            {
                return Fraction(); // Fraction(0, 1)
            }

            // temp.normalise(); 

            return temp.mul({right.denominator_, right.numerator_}); // pois a mult ja chama a funcao normalized

        }
    
};

int main()
{
{ Fraction().sum({2, 4}).write(); cout << ' ';
  Fraction(1,1).sum({2, 4}).write(); cout << ' ';
  Fraction(2,4).sum({3, 9}).write(); cout << ' ';
  Fraction(-2,4).sum({1, 2}).write(); cout << ' ';
  Fraction(3,27).sum({-27, 81}).write(); cout << '\n'; }
  { Fraction().sub({2, 4}).write(); cout << ' ';
  Fraction(1,1).sub({2, 4}).write(); cout << ' ';
  Fraction(2,4).sub({3, 9}).write(); cout << ' ';
  Fraction(-2,4).sub({1, 2}).write(); cout << ' ';
  Fraction(3,27).sub({-27, 81}).write(); cout << '\n'; }
  { Fraction().mul({2, 4}).write(); cout << ' ';
  Fraction(1,1).mul({2, 4}).write(); cout << ' ';
  Fraction(2,4).mul({3, 9}).write(); cout << ' ';
  Fraction(-2,4).mul({1, 2}).write(); cout << ' ';
  Fraction(3,27).mul({-27, 81}).write(); cout << '\n'; }
  { Fraction().div({2, 4}).write(); cout << ' ';
  Fraction(1,1).div({2, 4}).write(); cout << ' ';
  Fraction(2,4).div({3, 9}).write(); cout << ' ';
  Fraction(-2,4).div({1, 2}).write(); cout << ' ';
  Fraction(3,27).div({-27, 81}).write(); cout << '\n'; }
    return 0;
}