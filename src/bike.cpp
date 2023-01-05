#include "./bike.h"
Bike::Bike(int types, int bid, int sid, double rp, int rc){
    id = bid;
    rental_price = rp;
    type = types;
    station = sid;
    rental_count = rc;
    available_time = 0;
}
bool Bike::rent(int start_time, int end_time, int src, int dest){
    if(available_time <= start_time){

    }
    return true;
}
// Bike::Bike (const Bike& rhs): rental_price(rhs.rental_price), 
// type(rhs.type), station(rhs.station), rental_count(rhs.rental_count), 
// available_time(rhs.available_time){
// }