#include "./nthu_bike.h"
#include <fstream>
#include <string>
#include "./vector2.cpp"
#include "./graph.h"
#include <sstream>
#include "./bike.h"


void basic(string selectedCase){
    
    double disc_price;
    int rental_limit;
    int vertices_count = 0;
    int m = 1001;
    int** map = new int*[m];
    int** djik = new int*[m];
    int *bike_type_initial = new int[m];
    vectors<Bike> sepeda[50];
    for (int i = 0; i < m; i++) {
        map[i] = new int[m];
        djik[i] = new int[m];
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
    //for(int i =0; i < vertices_count; i++){
    //    djik[i] = dijkstra(map, i, vertices_count);
    //}
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
                // cout << sepeda[bid].type << " " <<
                // sepeda[bid].station << " " <<
                // sepeda[bid].rental_price << " " <<
                // sepeda[bid].rental_count << " " <<
                // endl;
               // cout << type << " " << bid << " " << sid << " " << rp << " " << rc << endl;
        }
    }
    
    if(users.is_open()){
        while(getline(users,line)){
            
        }
    }
    

}