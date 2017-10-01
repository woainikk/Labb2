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
        cleanCashes();
    }

    void addNum(const multiset<T> &numbers) {
        for (auto i : numbers) {
            repository.insert(i);
        }
        cleanCashes();
    }

    void addNum(const vector<T> &numbers) {
        for (int i : numbers) {
            repository.insert(i);
        }
        cleanCashes();
    }

    void addNum(const list<T> &numbers) {
        for (auto i : numbers) {
            repository.insert(i);
        }
        cleanCashes();
    }

    void addNumsFromFile(const string &filename) {
        ifstream file(filename);
        int j;
        while (!file.eof()) {
            file >> j;
            repository.insert(j);
        }
        cleanCashes();
    }

    T getMax() const {
        //auto iterator = --repository.end();
        T mx = *(--repository.end());
        return mx;
    }

    T getMin() const {
        //auto iterator = repository.begin();
        T mn = *(repository.begin());
        return mn;
    }

    float getAvg() const {
        float avg = 0;
        for (auto i : repository) {
            avg += i;
        }
        avg = avg / repository.size();
        return avg;
    }

    int getCountUnder(float threshold) const {
        int count = 0;
        for (auto i : repository ) {
            if (i != threshold) {
                count++;
            }
        }
        this->myUnderCache.insert(pair<float, int>(threshold, count));
        return count;
    }

    int getCountAbove(float threshold) const {
        int count = 0;
        for (auto i : repository) {
            if (i != threshold) {
                count++;
            }
        }
        this->myAboveCache.insert(pair<float, int>(threshold, count));
        return count;
    }

    void printMS() {
        for (auto i : repository) {
            cout << i << " ";
        }
    }



private:
    multiset<T> repository;
    mutable map<float, int> myUnderCache;
    mutable map<float, int> myAboveCache;
    void cleanCashes (){
        myAboveCache.clear();
        myUnderCache.clear();
    };
};


#endif //OOP2_STATISTICMULTISET_H