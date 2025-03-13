#include<bits/stdc++.h>
using namespace std;
class Human
{
    public: //public protected private
    // int age;
    // int weight;
    // int height;
    // protected://protected protected private
    // int age;
    // int weight;
    // int height;
    //private: //not accessible to any one
    int age;
    int weight;
    int height;


    void setweight(int w)
    {
        this->weight=w;
    }
};
class Male:public Human
//class Male:protected Human
//class Male:private Human
{
    public:
    string colour;
    int getage()
    { return this->age; }
    int getweight()
    { return this->weight; }
    int getheight()
    { return this->height; }
    void sleep()
    {
        cout<<"Male is sleeping"<<endl;
    }
};
int main() {
    Male m1;
    // cout<<m1.age<<endl;
    // cout<<m1.weight<<endl;
    // cout<<m1.height<<endl;
    // cout<<m1.colour<<endl;
    // cout<<m1.getage()<<endl;
    // cout<<m1.getweight()<<endl;
    // cout<<m1.getheight()<<endl;
    // cout<<m1.colour<<endl;
    //m1.sleep();
 return 0;
}