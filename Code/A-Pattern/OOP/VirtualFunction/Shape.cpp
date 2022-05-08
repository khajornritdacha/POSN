#include <iostream>
using namespace std;

class shape{
	protected:
		double H, W;
	public:
		void getData(double h, double w){
			H = h, W = w;
		}
		virtual void displayArea() = 0;
		// void displayArea(){
		// 	cout << "Area of Nothing!!!\n";
		// }
};

class rectangle : public shape{
	public:
		void displayArea(){
			cout << "Rectangle's Area is " << H*W << "\n";
		}
};

class triangle : public shape{
	public:
		void displayArea(){
			cout << "Triangle's Area is " << H*W/2 << "\n";
		}
};


int main(void){
	rectangle rect;
	triangle tri;

	shape *sh = 0;

	char op; cin >> op;

	switch(op){
		case 'R':
			sh = &rect;
			break;
		case 'T':
			sh = &tri;
			break;
		default:
			cout << "TEST\n";
			break;
	}

	if(sh){
		int h, w; cin >> h >> w;
		sh->getData(h, w);
		sh->displayArea();
	}

	
	return 0;
}