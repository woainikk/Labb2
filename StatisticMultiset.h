#pragma once

#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>


template<class T>
class StatisticMultiset {
public:
    void addNum(const T &num) {
        repository.insert(num);
        cleanCashes();
    }

    void addNum(const std::multiset<T> &numbers) {
        for (auto i : numbers) {
            repository.insert(i);
        }
        cleanCashes();
    }

    void addNum(const std::vector<T> &numbers) {
        for (int i : numbers) {
            repository.insert(i);
        }
        cleanCashes();
    }

    void addNum(const std::list<T> &numbers) {
        for (auto i : numbers) {
            repository.insert(i);
        }
        cleanCashes();
    }

    void addNumsFromFile(const std::string &filename) {
        std::ifstream file(filename);
        int j;
        while (!file.eof()) {
            file >> j;
            repository.insert(j);
        }
        cleanCashes();
    }

    T getMax() const {
        T mx = *(--repository.end());
        return mx;
    }

    T getMin() const {
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
            if (i < threshold) {
                count++;
            }
        }
        this->myUnderCache.insert(std::pair<float, int>(threshold, count));
        return count;
    }

    int getCountAbove(float threshold) const {
        int count = 0;
        for (auto i : repository) {
            if (i > threshold) {
                count++;
            }
        }
        this->myAboveCache.insert(std::pair<float, int>(threshold, count));
        return count;
    }

    void printMS() {
        for (auto i : repository) {
            std::cout << i << " ";
        }
    }



private:
    std::multiset<T> repository;
    mutable std::map<float, int> myUnderCache;
    mutable std::map<float, int> myAboveCache;
    void cleanCashes (){
        myAboveCache.clear();
        myUnderCache.clear();
    };
};

