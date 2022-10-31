/* ####Kettesért####
Keszitse el a "Sports(distance, time)", "Swimming(distance,time)", "Cycling(distance,time)", "Running(distance,time)" osztalyokat ugy, hogy az alabbi kod forduljon.

Az argumentum-listakban a tavolsagok meterben, az idok masodpercben vannak megadva.

A képletekben ne literalokat (konkret valtoszamokat, mint 100, vagy 3600), hanem konstans tagvaltozokat hasznaljon!

Az atlagok kiszamitasahoz szukseges kepletek, literalokkal:

    - uszasnal (mp / meter) kiszamitasa: time / (distance / 100)
    - bicajnal (km / ora) kiszamitasa: (distance / 1000) / (time / 3600)
    - futasnal (perc / km) kiszamitasa: (time / 60) / (distance / 1000)

Elvárt kimenet 2 - es jegyert :

Az uszas atlaga: 96.0667 s / 100 m
A kerekparozas atlaga: 29.9938 km / h
A futas atlaga: 4.00167 min / km
*/

/* ####Hármasért####
    - irassa ki az osztalyokban eltarolt atlagokat az alabbi sorrendben:

    Az uszas atlaga: 96.0667 s / 100 m
    A kerekparozas atlaga: 29.9938 km / h
    A futas atlaga: 4.00167 min / km
    96.0667 - 29.9938 - 4.00167
*/

/* ####Négyesért####
- irassa ki mindegyik sportag nevet is az atlagok utan a kovetkezo modon (ez legyen a kimenet):

    Az uszas atlaga: 96.0667 s / 100 m
    A kerekparozas atlaga: 29.9938 km / h
    A futas atlaga: 4.00167 min / km
    Uszas
    Kerekpar
    Futas
*/

//----------------------------------------------------------

#pragma once
const int szaz = 100;
const int ezer = 1000;
const int haromezerhatszaz = 3600;
const int hatvan = 60;

class Sports
{
protected:
  int distance;
  double time;

public:
  Sports(int distance, int time) : distance(distance), time(time) {}
  /*virtual double average() const=0;*/ // HÁRMASÉRT
  /*virtual string getType() const=0;*/ // NÉGYESÉRT
  virtual void computeSaveAndPrintAverage() const = 0;
  virtual ~Sports() = default;
};
class Running : public Sports
{
public:
  Running(int distance, int time) : Sports(distance, time) {}
  ~Running() = default;
  /*  double average() const override { //HÁRMASÉRT
      double result;
      result = (time/hatvan)/(distance/szaz);

      return result;
    }*/
  /*string getType() const override {return "Running";}*/ // NÉGYESÉRT
  void computeSaveAndPrintAverage() const override
  {
    double result;
    result = (time / hatvan) / (distance / szaz);
    cout << "A futás átlaga: " << result << " min / km\n";
  }
};
class Swimming : public Sports
{
public:
  Swimming(int distance, int time) : Sports(distance, time) {}
  ~Swimming() = default;
  /*  double average() const override { //HÁRMASÉRT
      double result;
      result=time/(distance/szaz);

      return result;
    }*/
  /*string getType() const override {return "Swimming";}*/ // NÉGYESÉRT
  void computeSaveAndPrintAverage() const override
  {
    double result;
    result = time / (distance / szaz);
    cout << "Az úszás átlaga: " << result << " mp / meter\n";
  }
};
class Cycling : public Sports
{
public:
  Cycling(int distance, int time) : Sports(distance, time) {}
  ~Cycling() = default;
  /*  double average() const override { //HÁRMASÉRT
      double result;
      result=(distance/ezer)/(time/haromezerhatszaz);

      return result;
    }*/
  /*string getType() const override {return "Cycling";}*/ // NÉGYESÉRT
  void computeSaveAndPrintAverage() const override
  {
    double result;
    result = (distance / ezer) / (time / haromezerhatszaz);
    cout << "A kerékpározás átlaga: " << result << " min / km\n";
  }
};

/*void printAverages(vector<Sports*>pointers){ //HÁRMASÉRT
  for(size_t ind = 0; ind < pointers.size(); ind++){
    cout << pointers[ind]->average();
    if(ind+1 == pointers.size()){
      break;

    }else{
      std::cout << " - ";
    }

  }

  cout << '\n';
};*/

/*void printNamesOfSports(vector<Sports*> pointers) { //NÉGYESÉRT
  for(size_t indi =0; indi<pointers.size(); indi++){
    if(pointers[indi]->getType()=="Swimming"){
      cout<<"Úszás\n";
    }else if(pointers[indi]->getType()=="Cycling"){
      cout<<"Biciklizés\n";
    }else if(pointers[indi]->getType()=="Running"){
      cout<<"Futás\n";}
  }
};*/
