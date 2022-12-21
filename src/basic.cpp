#include "./nthu_bike.h"
#include <fstream>
#include <string>

class bike{
    protected:
        int initial_price;
        int rental_count;
    public :
        bike(int init);
      //  ~bike();
};
bike::bike(int init){
    initial_price = init;
    rental_count = 0;
}

void basic(string selectedCase){
    
    double disc_price;
    int rental_limit;
    string path =  "./testcases/" + selectedCase + "/bike_info.txt";
    string line;


    ifstream myFile(path);
    if(myFile.is_open()){
        getline(myFile,line);
        disc_price = stod(line);
        cout << disc_price << endl;
        getline(myFile,line);
        rental_limit = stoi(line);
        cout << rental_limit << endl;
        while(getline(myFile,line)){
          //  cout << line << endl;
        }
        myFile.close();
    }
    else cout << "gada cok";

}