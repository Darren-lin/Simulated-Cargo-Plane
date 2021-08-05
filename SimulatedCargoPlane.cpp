#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
/*
Darren Lin
Summer 2021
Lab 5.1
Problem 5.2.4
Description of Problem: 
Uses user input to display an output message.
User runs the program and is prompted by a message.
*/
class Cargo {
    protected:
        string uldtype;
        string abbrev;
        string uldid;
        int aircraft;
        double weight;
        string destination;
    public:
        Cargo();
        Cargo(const string &uldtype, const string &abbrev, const string &uldid, const int &aircraft, const double &weight, const string &destination);
        Cargo(const Cargo &unit);
        ~Cargo();
        void setuldtype(string type){
            uldtype = type;
        }
        void setabbrev(string abbreviation){
            abbrev = abbreviation;
        }
        void setuldid(string id){
            uldid = id;
        }
        void setaircraft(int airCraftNum){
            aircraft = airCraftNum;
        }
        void setweight(double weightNum){
            weight = weightNum;
        }
        
        void setdestination(string dest){
            destination = dest;
        }

        string getuldtype() const {return uldtype;}
        string getabbrev() const {return abbrev;}
        string getuldid() const{return uldid;}
        int getaircraft() const{return aircraft;}
        double getweight() const{return weight;}
        string getdestination() const{return destination;}


        void output();
};
class Boeing737 : public Cargo{
    private:
        int total737wt;
    public:
        Boeing737();
        Boeing737(const string &uldtype, const string &abbrev, const string &uldid, const int &aircraft, const double &weight, const string &destination);
        ~Boeing737(){};
        void maxweight();
};
class Boeing767 : public Cargo{
    private:
        int total767wt;
    public:
        Boeing767();
        Boeing767(const string &uldtype, const string &abbrev, const string &uldid, const int &aircraft, const double &weight, const string &destination);
        ~Boeing767(){};
        void maxweight();
};

void input();
void vectorprint(vector <Boeing737> vector737, vector<Boeing767> vector767, double weight737, double weight767);

int main() {
    input();
    return 0;
}
Cargo::Cargo(){
    uldtype = "none";
    abbrev = "---";
    uldid = "99999";
    aircraft = 000;
    weight = -1;
    destination = "???";
}
Cargo::Cargo(const string &uld, const string &abrv, const string &id, const int &craft, const double &wt, const string &dest){
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = craft;
    weight = wt;
    destination = dest;
}
Cargo::Cargo(const Cargo &unit1){
    uldtype = unit1.uldtype;
    abbrev = unit1.abbrev;
    uldid = unit1.uldid;
    aircraft = unit1.aircraft;
    weight = unit1.weight;
    destination = unit1.destination;
}
Cargo::~Cargo(){

}

Boeing737::Boeing737(const string &uld, const string &abrv, const string &id, const int &craft, const double &wt, const string &dest){
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = craft;
    weight = wt;
    destination = dest;
}
Boeing767::Boeing767(const string &uld, const string &abrv, const string &id, const int &craft, const double &wt, const string &dest){
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = craft;
    weight = wt;
    destination = dest;
}
void load737(vector<Boeing737> &vector737, const string type, const string abbreviation, const string id, const int airCraftNum, const double weightNum, const string dest){
    Boeing737 plane(type, abbreviation, id, airCraftNum, weightNum, dest);
    vector737.push_back(plane);
    //plane.output();
}
void load767(vector<Boeing767> &vector767, const string type, const string abbreviation, const string id, const int airCraftNum, const double weightNum, const string dest){
    Boeing767 plane(type, abbreviation, id, airCraftNum, weightNum, dest);
    vector767.push_back(plane);
    //plane.output();
}
void Cargo::output(){
    cout << fixed << showpoint << setprecision(2);
    cout << setw(19) << "uld - " << getuldtype() << endl;
    cout << setw(19) << "abbreviation - " << getabbrev() << endl;
    cout << setw(19) << "uldid - " << getuldid() << endl;
    cout << setw(19) << "aircraft - " << getaircraft() << endl;
    cout << setw(19) << "weight - " << weight << " pounds" << endl;
    cout << setw(19) << "destination - " << getdestination() << endl;
    cout << endl;
}
void input(){
    string type;
    string abbreviation;
    string id;
    int airCraftNum;
    double weightNum;
    string dest;
    int weight737 = 0;
    int weight767 = 0;
    string datafile;
    vector<Boeing737> vector737;
    vector<Boeing767> vector767;
    
    ifstream inputFile;
    inputFile.open("lab5data.txt");
    if(!inputFile.is_open()){
        cout << "Failed to open the file\n";
        main();
    }
    while (inputFile.peek() != EOF){
        while(inputFile.peek() == ' '){
            inputFile.get();
        }
        inputFile >> type;
        inputFile >> abbreviation;
        inputFile >> id;
        inputFile >> airCraftNum;
        inputFile >> weightNum;
        inputFile >> dest;
        if (airCraftNum == 737){
            if (!(weight737 + weightNum > 46000)){
                weight737 += weightNum;
                load737(vector737, type, abbreviation, id, airCraftNum, weightNum, dest);
            }
        }
        else if (airCraftNum == 767 && (abbreviation == "AKE" || abbreviation == "APE" ||abbreviation == "AKC" ||abbreviation == "AQP" ||abbreviation == "AQF" ||abbreviation == "AAP" ||abbreviation == "P1P" ||abbreviation == "P6P")){
            if (!(weight767 + weightNum > 116000)){
                weight767 += weightNum;
                load767(vector767, type, abbreviation, id, airCraftNum, weightNum, dest);
            }
        }
        inputFile.get();
    }
    inputFile.close();
    cout << endl;
    vectorprint(vector737, vector767, weight737, weight767);
}

void vectorprint(vector<Boeing737> vector737,vector<Boeing767> vector767, double weight737, double weight767){
    cout << "Printing all 737 units" << endl;
    for (int i = 0; i < vector737.size(); ++i){
        cout << "737 unit number " << i + 1 << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << setw(19) << "uld - " << vector737[i].getuldtype() << endl;
        cout << setw(19) << "abbreviation - " << vector737[i].getabbrev() << endl;
        cout << setw(19) << "uldid - " << vector737[i].getuldid() << endl;
        cout << setw(19) << "aircraft - " << vector737[i].getaircraft() << endl;
        cout << setw(19) << "weight - " << vector737[i].getweight() << " pounds" << endl;
        cout << setw(19) << "destination - " << vector737[i].getdestination() << endl;
        cout << endl;
    }
    cout << "total 737 unit weight: " << weight737 << " pounds" << endl;
    cout << endl;
    cout << "Printing all 767 units" << endl;
    for (int i = 0; i < vector767.size(); ++i){
        cout << "767 unit number " << i + 1 << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << setw(19) << "uld - " << vector767[i].getuldtype() << endl;
        cout << setw(19) << "abbreviation - " << vector767[i].getabbrev() << endl;
        cout << setw(19) << "uldid - " << vector767[i].getuldid() << endl;
        cout << setw(19) << "aircraft - " << vector767[i].getaircraft() << endl;
        cout << setw(19) << "weight - " << vector767[i].getweight() << " pounds" << endl;
        cout << setw(19) << "destination - " << vector767[i].getdestination() << endl;
        cout << endl;
    }
    cout << "total 767 unit weight: " << weight767 << " pounds" << endl;
    cout << endl;
}
