class Animal{  //Parent class
    public:
         void speak();
};
class Cat: public Animal{  //Derived or child class
    public:
          void jump();

};
int main(){
    Animal a;
    Cat b;
    a.speak() ; //alllowed
    a.jump(); //not allowed
    b.speak(); //allowed
    b.jump(); //allowed
    return 0;

}