#include "./vector2.h"
class User{

    public :
        int id;
        vectors<int> bike_want;
        int start_time;
        int end_time;
        int src;
        int dest;
    public :
        User():id(0),start_time(0),end_time(0),src(0),dest(0) {}
        User(int uid, int st, int et, int src, int destination);


};