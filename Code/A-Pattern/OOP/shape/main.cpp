#include <iostream>
#include <cmath>
using namespace std;

#include "shape.h"

int main(void){
	int n; cin >> n;
	shape *sh[n];
	for(int i = 0; i < n; i++){
		sh[i] = 0;
		char op; cin >> op;
		if(op == 'R'){
			sh[i] = new rectangle;
		} else if(op == 'T'){
			sh[i] = new  triangle;
		} else if(op == 'C'){
			sh[i] = new circle;
			double r; cin >> r;
			sh[i]->getData(r);
		}

		if(op == 'R' or op == 'T'){
			double h, w; cin >> h >> w;
			sh[i]->getData(h, w);
		}
	}

	for(int i = 0; i < n; i++){
		cout << sh[i]->getArea() << "\n";
	}

	return 0;
}