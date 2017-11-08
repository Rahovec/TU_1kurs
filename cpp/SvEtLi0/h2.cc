#include <iostream>

using namespace std;

int gcd(int number1, int number2) {
    int gcd = number1 < number2 ? number1 : number2;
    while (gcd != 1) {
        if (number2 % gcd == 0 && number1 % gcd == 0) {
            return gcd;
        }
        gcd--;
    }
    return gcd;
}

class rational {
    int numerator_;
    int denominator_;

    public:
 
    rational(int numerator, int denominator) {
        int divisor = gcd(numerator, denominator);
        numerator_ = numerator / divisor;
        denominator_ = denominator / divisor;
    }
    
    int get_numerator() {
        return numerator_;
    }
    
    void set_numerator(int numerator) {
        numerator_ = numerator;
    }

    int get_denominator() {
        return denominator_;
    }
    
    void set_denominator(int denominator) {
        denominator_ = denominator;
    }

	rational& add(const rational& r){
			long nok;
		if(denominator_==r.get_denominator()){
					numerator_+= r.get_numerator();
		}
		else if(denominator_!=r.get_denominator()){
				nok = denominator_*r.get_denominator();
			//umnojavame znamenatelitel1 sus znamenatel2; umnojavame chislitel1 sus znam2 i chislitel2 sus znam1 i subirame chislitelite vrushtaiki stoinost razdelena na znamenatelq koito sega e raven;	
		}
		return *this;
	}




    
    void print() {
        cout << numerator_ << "/" << denominator_ << endl;
    }
    
    bool is_equal(rational other) {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }
    
};

int main() {
  rational r(1, 2), r2(1, 2), r3(2, 4);
  r.print();
  cout << r.is_equal(r2) << endl;
  cout << r.is_equal(r3) << endl;
  return 0;
}
