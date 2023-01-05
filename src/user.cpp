#include "./user.h"

User::User(int uid, int st, int et, int source, int destination){
    id = uid;
    start_time = st;
    end_time = et;
    src = source;
    dest = destination;
}