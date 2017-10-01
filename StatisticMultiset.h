//
// Created by Маргарита on 20.09.2017.
//

#ifndef OOP2_STATISTICMULTISET_H
#define OOP2_STATISTICMULTISET_H

#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

template<class T>
class StatisticMultiset {
public:
    void addNum(const T &num) {
        repository.insert(num);
        this->myAboveCache.clear();
        this->myUnderCache.clear();
    }

    void addNum(const multiset<T> &numbers) {
        for (auto i = numbers.begin(); i != numbers.end(); i++) {
            repository.insert(*i);
        }
        this->myAboveCache.clear();
        this->myUnderCache.clear();
    }

    void addNum(const vector<T> &numbers) {
        for (int i = 0; i < numbers.size(); i++) {
            repository.insert(numbers[i]);
        }
        this->myAboveCache.clear();
        this->myUnderCache.clear();
    }

    void addNum(const list<T> &numbers) {
        for (auto i = numbers.begin(); i != numbers.end(); i++) {
            repository.insert(*i);
        }
        this->myAboveCache.clear();
        this->myUnderCache.clear();
    }

    void addNumsFromFile(const string &filename) {
        ifstream file(filename);
        int j;
        while (!file.eof()) {
            file >> j;
            repository.insert(j);
        }
        this->myAboveCache.clear();
        this->myUnderCache.clear();
    }

    T getMax() const {
        auto iterator = --repository.end();
        T mx = *iterator;
        return mx;
    }

    T getMin() const {
        auto iterator = repository.begin();
        T mn = *iterator;
        return mn;
    }

    float getAvg() const {
        float avg = 0;
        for (auto i = repository.begin(); i != repository.end(); i++) {
            avg += *i;
        }
        avg = avg / repository.size();
        return avg;
    }

    int getCountUnder(float threshold) const {
        auto iterator = repository.lower_bound(threshold);
        auto iterator2 = repository.begin();
        int count = 0;
        for (auto i = iterator2; i != iterator; i++) {
            if (*i != threshold) {
                count++;
            }
        }
        this->myUnderCache.insert(pair<float, int>(threshold, count));
        return count;
    }

    int getCountAbove(float threshold) const {
        auto iterator = repository.upper_bound(threshold);
        auto iterator2 = repository.end();
        int count = 0;
        for (auto i = iterator; i != iterator2; i++) {
            if (*i != threshold) {
                count++;
            }
        }
        this->myAboveCache.insert(pair<float, int>(threshold, count));
        return count;
    }

    void printMS() {
        for (auto i = repository.begin(); i != repository.end(); i++) {
            cout << *i << " ";
        }
    }

    mutable map<float, int> myUnderCache;
    mutable map<float, int> myAboveCache;



    /*void cacheFilling(){
        int it = *repository.begin();
        for (auto i = repository.begin()++; i != repository.end(); i++) {

            myCache[it] = getCountAbove(it);
        }
    }*/


private:
    multiset<T> repository;

};


#endif //OOP2_STATISTICMULTISET_H
