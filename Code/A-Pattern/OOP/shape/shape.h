#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class shape{
    protected:
        double H,W;
    public:
        virtual void getData(double h, double w = 0){
            H = h, W = w;
        }
        virtual double getArea() = 0;
};

class rectangle : public shape{
    public:
        double getArea(){
            return H*W;
        }
};

class triangle : public shape{
    public:
        double getArea(){
            return H*W/2;
        }
};

class circle : public shape{
    static double PI; 
    public:        
        double getArea(){
            return PI*H*H;
        }
};

double circle::PI = acos(-1);


#endif