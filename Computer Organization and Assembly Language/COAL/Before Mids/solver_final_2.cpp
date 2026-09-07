#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <vector>
#include <fstream>
#include<cmath>

using namespace std;


void printTable(const string& str, const string& label, vector<int>& yValues, vector<int>& zValues) {
    cout << "\nTable for: " << label << "\n";
    cout << left << setw(10) << "Index" << setw(10) << "X (Hex)" << setw(10) << "Y (X % 2)" << setw(10) << "Z (X % 16)" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (size_t i = 0; i < str.size(); ++i) {
        int decimalValue = static_cast<int>(str[i]);
        int yValue = decimalValue % 2;  
        int zValue = decimalValue % 16; 

        
        yValues.push_back(yValue);
        zValues.push_back(zValue);

        
        cout << left << setw(10) << ("x" + to_string(i))
             << setw(10) << hex << uppercase << decimalValue
             << setw(10) << dec << yValue
             << setw(10) << hex << uppercase << zValue << endl;
    }
}

void saveResults(ofstream& file, const string& address, const string& equation, int decimalResult) {
    file << bitset<8>(decimalResult) << endl;
}

string loadBinRes(int pos, int type=0){
    ifstream file("equations_results.txt");
    string line;
    int i=0;
    while(getline(file,line)){
        if(i==pos){
            break;
        }
        i++;
    }
        return line;

}

vector<int> convertToBinaryVector(const string &binaryStr) {
    vector<int> binVec;
    for (char bit : binaryStr) {
        binVec.push_back(bit - '0'); 
    }
    return binVec;
}

vector<int> loadBinResArr(int pos, const string &type) {
    ifstream file("equations_results.txt");
    vector<string> lines;
    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    int requiredBytes = 0;
    if (type == "byte") requiredBytes = 1;
    else if (type == "word") requiredBytes = 2;
    else if (type == "dWord") requiredBytes = 4;
    else if (type == "qWord") requiredBytes = 8;
    else if (type == "tenB") requiredBytes = 10;

    vector<int> binaryData;
    for (int i = 0; i < requiredBytes; ++i) {
        if (pos + i < lines.size()) {
            
            vector<int> byteData = convertToBinaryVector(lines[pos + i]);
            
            binaryData.insert(binaryData.begin(), byteData.begin(), byteData.end());
        } else {
            
            binaryData.insert(binaryData.begin(), 8, 0);
        }
    }

    return binaryData;
}

void processEquations(const vector<int>& y1, const vector<int>& y2, const vector<int>& y3,
                      const vector<int>& z1, const vector<int>& z2, const vector<int>& z3,int zi, int zj) {
    cout << "\nTable for Equations (Binary, Decimal, Hexadecimal):\n";
    cout << left << setw(10) << "Address" << setw(25) << "Equation" << setw(20) << "Result (Dec, Hex, Bin)" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    ofstream resultFile("equations_results.txt");
    
    int resultF0 = (y1[1] << 7) | (y1[2] << 6) | (y1[3] << 5) | (y2[0] << 4) | (y2[1] << 3) | (y2[2] << 2) | (y3[0] << 1) | y3[1];
    cout << left << setw(10) << "01F0" << setw(30) << "y1y2y3yi+1yi+2yi+3yj+1yj+2"
         << setw(20) << dec << resultF0 << setw(10) << hex << uppercase << resultF0 << bitset<8>(resultF0) << endl;
    saveResults(resultFile, "01F0", "y1y2y3yi+1yi+2yi+3yj+1yj+2", resultF0);
    int resultF1;
    if(zi<5){
     resultF1 = (y1[1] << 7) | (y1[2] << 6) |(y2[5-zi] << 5) | (y3[0] << 4) | (y3[1] << 3) | (y3[2] << 2) | (y2[0] << 1) | y2[1];
    }else{
     resultF1 = (y1[1] << 7) | (y1[2] << 6) |(y1[5] << 5 )| (y3[0] << 4) | (y3[1] << 3) | (y3[2] << 2) | (y2[0] << 1) | y2[1];
    }

    cout << left << setw(10) << "01F1" << setw(30) << "y1y2y5yj+1yj+2yj+3yi+1yi+2"
         << setw(20) << dec << resultF1 << setw(10) << hex << uppercase << resultF1 << bitset<8>(resultF1) << endl;
    saveResults(resultFile, "01F1", "y1y2y5yj+1yj+2yj+3yi+1yi+2", resultF1);

    int resultF2 = (y2[0] << 7) | (y2[1] << 6) | (y2[2] << 5) | (y1[1] << 4) | (y1[2] << 3) | (y1[3] << 2) | (y3[2] << 1) | y3[1];
    cout << left << setw(10) << "01F2" << setw(30) << "yi+1yi+2yi+3y1y2y3yj+3yj+2"
         << setw(20) << dec << resultF2 << setw(10) << hex << uppercase << resultF2 << bitset<8>(resultF2) << endl;
    saveResults(resultFile, "01F2", "yi+1yi+2yi+3y1y2y3yj+3yj+2", resultF2);

    int resultF3 = (y3[0] << 7) | (y3[1] << 6) | (y3[2] << 5) | (y1[1] << 4) | (y1[2] << 3) | (y1[3] << 2) | (y2[1] << 1) | y2[1];
    cout << left << setw(10) << "01F3" << setw(30) << "yj+1yj+2yj+3y1y2y3yi+2yi+2"
         << setw(20) << dec << resultF3 << setw(10) << hex << uppercase << resultF3 << bitset<8>(resultF3) << endl;
    saveResults(resultFile, "01F3", "yj+1yj+2yj+3y1y2y3yi+2yi+2", resultF3);

    int resultF4 = (z1[1] << 4) | z2[0];
    cout << left << setw(10) << "01F4" << setw(30) << "z1zi+1"
         << setw(20) << dec << resultF4 << setw(10) << hex << uppercase << resultF4 << bitset<8>(resultF4) << endl;
    saveResults(resultFile, "01F4", "z1zi+1", resultF4);

    int resultF5 = (z3[0] << 4) | z3[1];
    cout << left << setw(10) << "01F5" << setw(30) << "zj+1zj+2"
         << setw(20) << dec << resultF5 << setw(10) << hex << uppercase << resultF5 << bitset<8>(resultF5) << endl;
    saveResults(resultFile, "01F5", "zj+1zj+2", resultF5);

    int resultF6 = (z3[1] << 4) | z2[1];
    cout << left << setw(10) << "01F6" << setw(30) << "zj+2zi+2"
         << setw(20) << dec << resultF6 << setw(10) << hex << uppercase << resultF6 << bitset<8>(resultF6) << endl;
    saveResults(resultFile, "01F6", "zj+2zi+2", resultF6);

     int resultF7 = (z1[1] << 4) | z3[0];
    cout << left << setw(10) << "01F7" << setw(30) << "z1zj+1"
         << setw(20) << dec << resultF7 << setw(10) << hex << uppercase << resultF7 << " " << bitset<8>(resultF7) << endl;
    saveResults(resultFile, "01F7", "z1zj+1", resultF7);

    int resultF8 = (z2[1] << 4) | z3[2];
    cout << left << setw(10) << "01F8" << setw(30) << "zi+2zj+3"
         << setw(20) << dec << resultF8 << setw(10) << hex << uppercase << resultF8 << " " << bitset<8>(resultF8) << endl;
    saveResults(resultFile, "01F8", "zi+2zj+3", resultF8);

    int resultF9 = (z3[1] << 4) | z1[1];
    cout << left << setw(10) << "01F9" << setw(30) << "zj+2z1"
         << setw(20) << dec << resultF9 << setw(10) << hex << uppercase << resultF9 << " " << bitset<8>(resultF9) << endl;
    saveResults(resultFile, "01F9", "zj+2z1", resultF9);

    int resultFA = (z2[0] << 4) | z1[1];
    cout << left << setw(10) << "01FA" << setw(30) << "zi+1z1"
         << setw(20) << dec << resultFA << setw(10) << hex << uppercase << resultFA << " " << bitset<8>(resultFA) << endl;
    saveResults(resultFile, "01FA", "zi+1z1", resultFA);

    int resultFB = (z3[2] << 4) | z3[0];
    cout << left << setw(10) << "01FB" << setw(30) << "zj+3zj+1"
         << setw(20) << dec << resultFB << setw(10) << hex << uppercase << resultFB << " " << bitset<8>(resultFB) << endl;
    saveResults(resultFile, "01FB", "zj+3zj+1", resultFB);

    resultFile.close();
}



void Q1Pa(){
    cout << "\nQuestion 1 Part A\n\n";

    cout<<"1. "<<loadBinRes(3)<<" "<<loadBinRes(2)<<endl;
    cout<<"2. "<<loadBinRes(9)<<" "<<loadBinRes(8)<<endl;
    cout<<"3. "<<loadBinRes(4)<<" "<<loadBinRes(3)<<endl;
    cout<<"4. "<<loadBinRes(2)<<" "<<loadBinRes(1)<<endl;
    cout<<"5. "<<loadBinRes(6)<<" "<<loadBinRes(5)<<" "<<loadBinRes(4)<<" "<<loadBinRes(3)<<" "<<loadBinRes(2)<<" "<<loadBinRes(1)<<" "<<loadBinRes(0)<<" 00000000"<<endl;
    cout<<"6. "<<"00000000 "<<"00000000 "<<loadBinRes(11)<<" "<<loadBinRes(10)<<endl;
    cout<<"7. "<<"00000000 "<<"00000000 "<<loadBinRes(11)<<" "<<loadBinRes(10)<<" "<<loadBinRes(9)<<" "<<loadBinRes(8)<<" "<<loadBinRes(7) <<" "<<loadBinRes(6)<<endl;
    cout<<"8. "<<loadBinRes(8) <<" "<<loadBinRes(7) <<" "<<loadBinRes(6)<<" "<<loadBinRes(5)<<endl;
    cout<<"9. "<<"00000000 "<<loadBinRes(11)<<" "<<loadBinRes(10)<<" "<<loadBinRes(9)<<" "<<loadBinRes(8) <<" "<<loadBinRes(7)<<" "<<loadBinRes(6)<<" "<<loadBinRes(5)<<endl;
    cout<<"10. "<<loadBinRes(7)<<" "<<loadBinRes(6)<<" "<<loadBinRes(5)<<" "<<loadBinRes(4)<<" "<<loadBinRes(3)<<" "<<loadBinRes(2)<<" "<<loadBinRes(1)<<" "<<loadBinRes(0)<<endl;


}

void Q1Pb() {
    cout << "\nQuestion 1 Part B\n\n";
    vector<int> arr;

    arr = loadBinResArr(2, "byte");
    cout << "1. Bit-7 of byte 01F2: " << arr[0] << endl;

    arr = loadBinResArr(3, "word");
    cout << "2. Bit-0 of word 01F3: " << arr[15] << endl;

    arr = loadBinResArr(2, "byte");
    cout << "3. Bit-7 of byte 01F2 (repeated): " << arr[0] << endl;

    arr = loadBinResArr(2, "word");
    cout << "4. Bit-11 of word 01F2: " << arr[4] << endl;

    arr = loadBinResArr(2, "byte");
    cout << "5. Low nibble of byte 01F2: ";
    for (int i = 4; i < 8; ++i) cout << arr[i];
    cout << endl;

    arr = loadBinResArr(3, "byte");
    cout << "6. High nibble of byte 01F3: ";
    for (int i = 0; i < 4; ++i) cout << arr[i];
    cout << endl;

    arr = loadBinResArr(6, "dWord");
    cout << "7. Bit-20 of dWord at 01F6: " << arr[11] << endl;

    arr = loadBinResArr(6, "qWord");
    cout << "8. Bit-31 of qWord at 01F6: " << arr[32] << endl;

    arr = loadBinResArr(2, "tenB");
    cout << "9. High nibble of ten byte at 01F2: ";
    for (int i = 0; i < 4; i++) cout << arr[i];
    cout << endl;

    arr = loadBinResArr(6, "qWord");
    cout << "10. Bit-41 of qWord at 01F6: " << arr[22] << endl;
}



void calcAddress(const vector<int>& z1, const vector<int>& z2, const vector<int>& z3, int zi, int zj) {
    int offset = z3[0]*pow(16,3)+z3[1]*pow(16,2)+z2[1]*pow(16,1)+z2[2]*pow(16,0);
    int physical = z2[1]*pow(16,4)+z3[1]*pow(16,3)+z2[1]*pow(16,2)+z2[0]*pow(16,1)+z1[3]*pow(16,0);
    int segment=(physical-offset)/16;
    cout<<"\nQ2. Find Segment Address\n\n";
    cout<<"Offset: "<<offset<<endl;
    cout<<"Physical: "<<physical<<endl;
    cout<<"\tSegment address: "<<segment;


        segment=z1[zi]*pow(16,3)+z2[zi]*pow(16,2)+z1[zi-2]*pow(16,1)+z1[zi-3]*pow(16,0);


    //segment=z1[zi]*pow(16,3)+z1[zj]*pow(16,2)+z1[zi-2]*pow(16,1)+z1[zi-3]*pow(16,0);
    offset=z1[2]*pow(16,3)+z3[1]*pow(16,2)+z2[1]*pow(16,1)+z1[3]*pow(16,0);
    physical=(segment*16)+offset;
    cout<<"\n\nQ3. Find Physical Address\n\n";
    cout<<"Offset: "<<offset<<endl;
    cout<<"Segment: "<<segment<<endl;
    cout<<"\tPhysical address: "<<physical;

    segment=z1[zi-2]*pow(16,3)+z2[zj-2]*pow(16,2)+z2[1]*pow(16,1)+z1[zi-1]*pow(16,0);
    physical=z2[1]*pow(16,4)+z3[1]*pow(16,3)+z2[1]*pow(16,2)+z2[0]*pow(16,1)+z1[3]*pow(16,0);
    offset=abs(physical-(segment*16));
    cout<<"\n\nQ4. Find Offset Address\n\n";
    cout<<"Segment: "<<segment<<endl;
    cout<<"Physical: "<<physical<<endl;
    cout<<"\tOffset Address: "<< offset;

}



int main() {

    cout<<"\t\tWelcome to the assignment solver!\n";
    cout<<"made by- Muhammad Ahmad"<<endl;
    string fullName;
    cout << "Enter your full name( In the Format -> Muhammad Ahmad Muhammad ): ";
    getline(cin, fullName);

    vector<string> nameParts;
    string part;
    for (char ch : fullName) {
        if (ch == ' ') {
            nameParts.push_back(part);
            part.clear();
        } else {
            part += ch;
        }
    }
    nameParts.push_back(part);  

    vector<int> y1, z1, y2, z2, y3, z3;

   
    if (nameParts.size() > 0) printTable(nameParts[0], "First Part", y1, z1);
    if (nameParts.size() > 1) printTable(nameParts[1], "Second Part", y2, z2);
    if (nameParts.size() > 2) printTable(nameParts[2], "Third Part", y3, z3);

    int zi = z1.size() - 1;  
    int zj = z3.size() - 1;  

    processEquations(y1, y2, y3, z1, z2, z3,zi,zj);

    Q1Pa();
    Q1Pb();


    calcAddress(z1,z2,z3,zi,zj);

    cout<<"\n\n Use at your OWN RISK, i will not be held responsible for any inaccuracy (I have tested this in many ways but some undefined behaviours could be unavoidable)\n\n I have run out of paitence to code the solution for the flag problems so good luck!! ";

    return 0;
}