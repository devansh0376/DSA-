#include<bits/stdc++.h>
using namespace std;
//object : entity : continst of properties and behavior
class Hero //class : user define data type
{
    private :
    int health=1; //properties
    int level=1;
    public: 
    Hero(int health,int level)
    {
        cout<<"invoke"<<endl;
        this->health=health; // this->health =>current class object and health => parame
        this->level=level;
    }
    void sethealth(int h,int pass)
    { 
        if(pass==492)
        health=h;  
    }
    int gethealth()
    { return health; }
    int getlevel()
    { return level; }
};
// size of class Hero is 4  byte (since health is define in int)
///empty class have 1 byte of memory
int main() {
    Hero h1(15,0);//object : intance of class
    Hero *h2=new Hero(10,1); //dynamically
    Hero h3(h1);
    // (*h2).sethealth(15,492); //or h2->sethealth(15,492)
    // h1.sethealth(10,492);
    cout<<h1.gethealth()<<" "<<h1.getlevel()<< endl;
    //copy construtor
    cout<<h3.gethealth()<<" "<<h3.getlevel()<< endl;
    cout<<h2->gethealth()<<" "<<h2->getlevel()<< endl;
 return 0;
}