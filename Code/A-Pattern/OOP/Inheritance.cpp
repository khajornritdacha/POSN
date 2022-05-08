#include <bits/stdc++.h>
using namespace std;

class slime{
	protected:
		int hp, mp;
		string name, race, color;
	public:
		~slime(){}
		slime(int hp, int mp, string name="noname", string race="Normal_slime", string color="green"){
			this->hp = hp;
			this->mp = mp;
			this->name = name;
			this->race = race;
			this->color = color;
		}
		void pridata() const{
			cout << hp << " " << mp << " " << name << " " << race << " " << color << "\n";
		}
};

class demon_slime : public slime{
	protected:
		int lv;
		string skill;
	public:
		demon_slime(int hp, int mp, int lv, string skill="Devour", string name="noname", string race="Demon_slime", string color="Black") 
		: slime(hp, mp, name, race, color) {

			this->lv = lv;
			this->skill = skill;
		}
		string getskill() const{
			return skill;
		}
		int getlv() const{
			return lv;
		}
};

int main(void){
	slime jom(100, 30, "Jom");
	jom.pridata();

	demon_slime ice(3000, 100, 20, "Freeze", "Ice");
	cout << ice.getskill() << " " << ice.getlv() << "\n";
	ice.pridata();

	return 0;
}