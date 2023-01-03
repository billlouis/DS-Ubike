#include "./nthu_bike.h"
#include <fstream>
#include <string>
#include "./vector.cpp"
#include "./graph.h"
#include <sstream>

class bike{
    private :
        int initial_price;
        int type;
        int station;
        int rental_count;
        bool rentable;
    public :
        bike(int init);
        void rent();
        bool exhausted();
      //  ~bike();
};
bike::bike(int init){
    initial_price = init;
    rental_count = 0;
}
bool bike::exhausted(){
    return rentable;
}
void bike::rent(){
    rental_count--;
    if(rental_count == 0){
        rentable = false;
    }
}

void basic(string selectedCase){
    
    double disc_price;
    int rental_limit;
    int vertices_count = 0;
    int m = 1001, n = 1001;
    int** map = new int*[m];
    for (int i = 0; i < m; i++) {
        map[i] = new int[n];
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
            istringstream ss(line);
            while(getline(ss,line, ' ')){
                if(line[0] == 'S' && tmp_count < 2){
                    if(tmp_count == 0){
                        station1 = stoi(line.substr(1));
                        if (station1 > vertices_count)vertices_count = station1;
                        tmp_count++;
                        cout << "s1:" << station1 << " ";
                    }
                    else if(tmp_count == 1){
                        station2 = stoi(line.substr(1));
                        if (station2 > vertices_count)vertices_count = station2;
                        tmp_count++;
                        cout << "s2:" << station2 << " " ;
                    }
                }
                else {
                    map[station1][station2] = stoi(line);
                    map[station2][station1] = stoi(line);
                    tmp_count = 0;
                    cout << "distance:" << map[station1][station2] << endl;
                }
            } 
        }
        maps.close();
    }
    else cout << "gada cok" << endl;
    vertices_count++;   
    dijkstra(map,0,vertices_count);
    if(bike_info.is_open()){
        //Take discount value
        getline(bike_info,line);
        disc_price = stod(line);
     //   cout << disc_price << endl;
        //Take rental limit
        getline(bike_info,line);
        rental_limit = stoi(line);
      //  cout << rental_limit << endl;
        
        while(getline(bike_info,line, ' ')){
        //    cout << line << endl;
        //   if(line[0] == 'B') 
       //    b.push(line);
          // else{

         //  }
        }
        bike_info.close();
    }
    else cout << "gada cok" << endl;

    

}