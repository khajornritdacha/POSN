#include <bits/stdc++.h>
using namespace std;

class animal{
	public:
		virtual void make_sound(){
			cout << "Animal!\n";
		}
		virtual void walk() = 0; //without definition
};

class dog : public animal{
	public:
		void make_sound(){
			cout << "Bog Bog\n";
		}
};

class cat : public animal{
	public:
		void make_sound(){
			cout << "Meow Meow1\n";
		}
		void walk(){
			cout << "This is cat walk!\n";
		}
};

int main(void){
	animal *an = new cat;

	an->make_sound();
	an->walk();

	
	return 0;
}