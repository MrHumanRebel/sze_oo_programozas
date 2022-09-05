#include <iostream>

using namespace std;

class Animal {
  public:
  Animal() { }
  virtual ~Animal() {}
  virtual void speak()= 0;
};

class Cat : public Animal {
public:
  virtual void speak()
  { cout << "Vau" << endl; }
};

class Dog : public Animal {
public:
  virtual void speak()
  { cout << "Miau" << endl; }
};
int main()
{
 Dog animal;
 
 //cat.speak();
 try  {
   Cat& cat = dynamic_cast<Cat&>(animal);
    cat.speak(); }
 catch(bad_cast) { cout << "Hiba!"; }
 //Dog &anim=animal;
 //Dog* anim = new Dog;
 //Cat* cat = dynamic_cast<Cat*>(&anim);
 //Dog* cat = dynamic_cast<Dog*>(&anim);
 //if(cat!=nullptr) cat->speak();
 //else cout << "Hiba!";
 return 0;
}

/****/
