#include "./vectors.h"

class User{

    public :
        int id;
        vectors<int> bike_want;
        int start_time = 0;
        int end_time;
        int src;
        int dest;
        int flag = 0;
        int used_bike_id = 0;
        int arrival_time = 0;
        int revenue = 0;
        int mover = 0;
        int truck_src = 0 ;
        int truck_dest = 0;
        int truck_start_time =0;
        int truck_end_time = 0;
        int travel_distance = 0;
    public :
        User():id(0),start_time(0),end_time(0),src(0),dest(0) {
        }
        User(int uid, int st, int et, int src, int destination);


};