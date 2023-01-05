#ifndef bike_h
#define bike_h 1
#include "iostream"
using namespace std;
class Bike{

    public :
        int type;
        int id;
        int station;
        double rental_price;
        int rental_count;
        int available_time;// Bike_Type, Bike_Id, Station_Id, Rental_Price, and Rental_Count
    public :
        Bike () : id(0), rental_price(0), type(0), station(0), rental_count(0), available_time(0){}
        Bike(int type, int id, int station_id, double rental_price, int rental_count);
        bool rent(int start_time, int end_time,  int src, int dest);
        bool exhausted();
      //  ~bike();
};
class Station{
    private :
        int id;
        Bike *bike;
    public :
        int getDistance(int src, int destination);

};




#endif