#include "./nthu_bike.h"
#include <fstream>
#include <string>
#include "./vectors.h"
#include "./graph.h"
#include <sstream>
#include "./bike.h"
#include <iostream>
#include <climits>
//#include "./user.h"

void basic(string selectedCase){
    
    double disc_price;
    int rental_limit;
    int vertices_count = 0;
    int m = 1001;
    int** map = new int*[m];
    
    int *bike_type_initial = new int[m];
    vectors<Bike> sepeda[50];
    vectors<User> usr;
    for (int i = 0; i < m; i++) {
        map[i] = new int[m];
        //djik[i] = new int[m];
        bike_type_initial[i] = 0;
    }
    
    string path_bike_info =  "./testcases/" + selectedCase + "/bike_info.txt";
    string path_map = "./testcases/" + selectedCase + "/map.txt";
    string path_user = "./testcases/" + selectedCase + "/user.txt";
    string path_bike = "./testcases/" + selectedCase + "/bike.txt";
    string line;
    ifstream bike_info(path_bike_info);
    ifstream maps(path_map);
    ifstream users(path_user);
    ifstream bikes(path_bike);
    ofstream outStation("result/" + selectedCase + "/station_status.txt");
    ofstream outUser("result/" + selectedCase + "/user_result.txt");
    ofstream outTransfer("result/" + selectedCase + "/transfer_log.txt");
   // vectors<bike> b;
    if(maps.is_open()){
        int tmp_count = 0;
        int station1 = 0;
        int station2 = 0;
        while(getline(maps,line)){
            for(int i = 0; i < line.length(); i++) 
                if (line[i] == 'S')
                    line[i] = ' ';
            istringstream ss(line);
            ss >> station1 >> station2 >> tmp_count;
            map[station1][station1] = 0;
            map[station1][station2] = tmp_count;
            map[station2][station1] = tmp_count;
            if(station1 > vertices_count) vertices_count = station1;
            else if(station2 > vertices_count) vertices_count =station2;
        }
        maps.close();
        vertices_count++;
    }
    else cout << "gada cok" << endl;
    // int** djik = new int*[vertices_count];
    // for(int i =0; i < vertices_count; i++){
        
    //    dijkstra(map, i, vertices_count);
    //    for(int j = 0; j < vertices_count; j++){
    //     cout << map[i][j] << " ";
    //    }
    //    cout << endl;
    //    //free(djik[i]);
    // }
    floydWarshall(map, vertices_count);

    // for(int i =0; i < vertices_count; i++){
    //     for(int j = 0; j < vertices_count; j++){
    //         cout << djik[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "-------------" << endl;
    // for(int i =0; i < vertices_count; i++){
    //     for(int j = 0; j < vertices_count; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(bike_info.is_open()){
        getline(bike_info,line);
        disc_price = stod(line);
        getline(bike_info,line);
        rental_limit = stoi(line);
        int type = 0;
        int initial_cost = 0;
        int i = 0;
        while(getline(bike_info,line)){
            istringstream ss(line);
            while(getline(ss,line, ' ')){
                if(line[0] == 'B') type = stoi(line.substr(1));
                else bike_type_initial[type] = stoi(line);
            }
          //  cout << "Bike Type : " << type << " Initial Cost : " << bike_type_intial[type] << endl;
        }
        bike_info.close();
    }
    else cout << "gada cok" << endl;
    if(bikes.is_open()){
        while(getline(bikes,line)){
            int type;//bike type
            int bid; //bike id
            int sid;// station id
            double rp;// rent price
            int rc; // rent count
            for(int i = 0; i < line.length(); i++)
                if(line[i] == 'B' || line[i] == 'S') line[i] = ' ';
            istringstream ss(line);
                ss >> type >> bid >> sid >> rp >> rc;
                sepeda[type].push(Bike(type,bid,sid,rp,rc));
                //cout << type << " " << bid << " " << sid << " " << rp << " " << rc << endl;
        }
    }
    
    if (users.is_open())
    {
        while (getline(users, line))
        {
            int uid;
            int st;
            int et;
            int src;
            int dest;
            string bike_accept;
            for (int i = 0; i < line.length(); i++)
                if (line[i] == 'S' || line[i] == 'U')
                    line[i] = ' ';
            istringstream ss(line); 

            ss >> uid >> bike_accept >> st >> et >> src >> dest ;
            User usr_temp(uid, st, et, src, dest);
            //   cout << usr_temp.id << " " << bike_accept << " " << usr_temp.start_time << " " << usr_temp.end_time<< " " << 
            //   usr_temp.src << " " << usr_temp.dest << endl;
            for(int i = 0; i < bike_accept.length(); i++)
                if(bike_accept[i] == 'B' || bike_accept[i] == ',') bike_accept[i] = ' ';
            
            istringstream ss2(bike_accept);
            while(getline(ss2,line,' ')){
                istringstream ss3(line);
                while(getline(ss3,line)){
                int temp = stoi(line); 
                usr_temp.bike_want.push(temp);
                }
            }
            usr.push(User(uid,st,et,src,dest));
            usr[usr.Size()-1].bike_want = usr_temp.bike_want;
        }
    }
    mergeSortUser(usr,0,usr.Size()-1);
    //    for(int i = 0; i < usr.Size()-1; i++){
    //        cout << usr[i].id << " " << usr[i].start_time << " " << usr[i].end_time << endl;
    //    }
    vectors<User> final_user;
    for(int i = 0; i < usr.Size(); i++){
        int bike_id = INT_MAX;
        int flag = 0;
        int revenue = 0;
        int max_revenue = INT_MIN;
        int final_bike;
        double max_rental_price = INT_MIN;
        int final_k;
        int travel_time = map[usr[i].src][usr[i].dest];
        
        if(travel_time < (usr[i].end_time -usr[i].start_time)){
            for(int j = 0; j < usr[i].bike_want.Size(); j++){
                int bike = usr[i].bike_want[j];
                for(int k = 0; k < sepeda[bike].Size(); k++){
                    if (sepeda[bike][k].station == usr[i].src 
                    && sepeda[bike][k].available_time <= usr[i].start_time
                    && sepeda[bike][k].rental_count < rental_limit
                    && sepeda[bike][k].rental_price > 0
                    && sepeda[bike][k].rental_price >= max_rental_price){
                        if(!flag){
                            bike_id = sepeda[bike][k].id;
                            flag = 1;
                            final_bike = bike;
                            final_k = k;
                            max_rental_price = sepeda[bike][k].rental_price;
                        }else{
                            if(max_rental_price == sepeda[bike][k].rental_price){
                                if(sepeda[bike][k].id < bike_id) {
                                    bike_id = sepeda[bike][k].id;
                                    final_bike = bike;
                                    final_k = k;
                                    max_rental_price = sepeda[bike][k].rental_price;
                                }
                            }
                            else {
                                max_rental_price = sepeda[bike][k].rental_price;
                                final_bike = bike;
                                final_k = k;
                                bike_id = sepeda[bike][k].id;
                            }
                        }
                        
                        revenue = travel_time * max_rental_price;
                    }
                }
            }
        }
        if(flag){
            final_user.push(User(usr[i].id,usr[i].start_time,usr[i].end_time,usr[i].src,usr[i].dest));
            final_user[final_user.Size()-1].flag = 1;
            final_user[final_user.Size()-1].used_bike_id= bike_id;
            final_user[final_user.Size()-1].arrival_time = travel_time + usr[i].start_time ;
            final_user[final_user.Size()-1].revenue = revenue;
            // outUser << "U" << usr[i].id << " " << flag << " " << bike_id << " " << usr[i].start_time << " " << travel_time + usr[i].start_time << " " << revenue<< endl; 
            // outTransfer << bike_id << " S" << usr[i].src << " S" << usr[i].dest << " " << usr[i].start_time << " " << travel_time + usr[i].start_time << " U" << usr[i].id << endl;
            sepeda[final_bike][final_k].rental_price -= disc_price;
            sepeda[final_bike][final_k].rental_count++;
            sepeda[final_bike][final_k].station = usr[i].dest;
            sepeda[final_bike][final_k].available_time = usr[i].start_time + travel_time;
        }
        else{
            final_user.push(User(usr[i].id,0,0,0,0));
            // outUser << "U" << usr[i].id << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
        }
    }
    
    vectors<Bike> final_bike;
    
    for(int i = 0; i <50; i++){
        for(int j = 0; j < sepeda[i].Size(); j++){
            final_bike.push(sepeda[i][j]);
        }
    }
    mergeSortBike(final_bike,0,final_bike.Size()-1);
    mergeSortUOutput(final_user,0,final_user.Size()-1);
    for(int i = 0; i < final_bike.Size(); i++){
        outStation << "S" << final_bike[i].station << " " << final_bike[i].id << " B" << final_bike[i].type << " " << final_bike[i].rental_price << " " << final_bike[i].rental_count << "\n";
    }
      for(int i = 0; i < final_user.Size(); i++){
         outUser << "U" << final_user[i].id << " " << final_user[i].flag << " " << final_user[i].used_bike_id << " " << final_user[i].start_time << " " << final_user[i].arrival_time << " " << final_user[i].revenue<< "\n"; 
         if(final_user[i].flag)outTransfer << final_user[i].used_bike_id << " S" << final_user[i].src << " S" << final_user[i].dest << " " << final_user[i].start_time << " " << final_user[i].arrival_time << " U" << final_user[i].id << "\n";
        
     }
    outStation.close();
    outTransfer.close();
    outUser.close();
    // for(int i = 0; i <2 ;i ++){
    //     for(int j =0; j < sepeda[i].Size(); j++){
    //         cout << sepeda[i][j].type << " " <<
    //             sepeda[i][j].id << " " <<
    //             sepeda[i][j].station << " " <<
    //             sepeda[i][j].rental_price << " " <<
    //             sepeda[i][j].rental_count << " " <<
    //             endl;
    //     }
    // }


}