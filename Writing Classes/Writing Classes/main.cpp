#include <iostream>
#include <cmath>

class point
{
    double x_;
    double y_;
public:
    point() = default;
    
    point(double x, double y)
    : x_{x}, y_{y}
    {}
    
    point(point const& pt) = default;
    
    double distance() {
        return std::sqrt(x_*x_ + y_*y_);
    }
    double angle() {
        return std::atan2(y_, x_);
    }
    
    void offset(double off) {
        offset(off, off);
    }
    
    void offset(double xoff, double yoff) {
        x_ = x_ + xoff;
        y_ = y_ + yoff;
    }
    
    void scale(double mult) {
        scale(mult, mult);
    }
    
    void scale(double xmult, double ymult) {
        x_ = x_ * xmult;
        y_ = y_ * ymult;
    }
    
    /*
     use =default to get the compiler's implicit definition.
     use =delete to suppress that function.
     If you don't want anyone copies a class you can write...
     
     struct dont_copy
     {
        dont_copy(dont_copy const&= =  delete;
     }
     */
    
};

int main(int argc, const char * argv[]) {
    point origin{}, unity{};
    return 0;
}
