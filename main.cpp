#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <vector>
#include "StatisticMultiset.h"
#include <math.h>

using namespace std;

int main() {
    StatisticMultiset<float> myStat;
    vector<float> vector1;
    vector1.reserve(5);
    multiset<float> multiset1;
    list<float> list1;

    float j, max, min, ab, un, f, avg;

    //write numbers in multiset
    cout << "Your numbers is: ";
    for (int i = 0; i < 3; i++) {
        j = -50 + rand() % 150 + 0.5f;
        myStat.addNum(j);
        cout << j << " ";
    }
    cout << endl;

    //filling vector and writing vector in multiset
    cout << "Your vector is: ";
    for (int i = 0; i < 3; i++) {
        j = -50 + rand() % 150 + 0.5f;
        vector1.push_back(j);
        cout << j << " ";
    }
    cout << endl;
    myStat.addNum(vector1);

    //filling list and writing list in multiset
    cout << "Your list is: ";
    for (int i = 0; i < 3; i++) {
        j = -50 + rand() % 150 + 0.7f;
        list1.push_back(j);
        cout << j << " ";
    }
    cout << endl;
    myStat.addNum(list1);

    //filling multiset and writing list in multiset
    cout << "Your multiset is: ";
    for (int i = 0; i < 3; i++) {
        j = -50 + rand() % 150 + 0.7f;
        multiset1.insert(j);
        cout << j << " ";
    }
    cout << endl;
    myStat.addNum(multiset1);


    //Wwriting numbers in file in multiset
    cout << "Your file is: ";
    ifstream file;
    file.open("text.txt");
    while (!file.eof()) {
        file >> f;
        cout << f << " ";
    }
    file.close();
    cout << endl;
    myStat.addNumsFromFile("text.txt");


    //myStat.cacheFilling();
    cout << "Your main multiset is: ";
    myStat.printMS();
    cout << endl;


    max = myStat.getMax();
    min = myStat.getMin();
    cout << "min = " << min << endl << "max = " << max << endl;
    avg = myStat.getAvg();
    cout << "avg " << avg;


    int above, under;
    for (int i = 0; i < 3; i++) {
        cout << "Enter a number to get count above it: ";
        cin >> ab;
        above = myStat.getCountAbove(ab);
        cout << "above " << above << endl;

        cout << "Enter a number to get count under it: ";
        cin >> un;
        under = myStat.getCountUnder(un);
        cout << "under " << under << endl;

    }

 /*   for (auto it : myStat.myUnderCache) {
        cout << it.first << ": " << it.second<<endl;
    }
    for (auto it : myStat.myAboveCache) {
        cout << it.first << ": " << it.second<<endl;
    } */

    myStat.addNum(4);
    avg = myStat.getAvg();
    cout << "avg " << avg << endl;


    /*for (auto it : myStat.myUnderCache) {
        cout << it.first << ": " << it.second<<endl;
    }
    for (auto it : myStat.myAboveCache) {
        cout << it.first << ": " << it.second<<endl;
    } */


}
