//
// Created by Маргарита on 20.09.2017.
//

#include "StatisticMultiset.h"
#include <set>
#include <list>
#include <map>
#include <fstream>
#include <vector>

using namespace std;


/*template <typename T>
void StatisticMultiset::addNum(const vector<T> &numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        repository.insert(numbers[i]);
    }
}

template <typename T>
void StatisticMultiset::addNum(const list<T> &numbers) {
    for (auto i = numbers.begin(); i != numbers.end(); i++) {
        repository.insert(*i);
    }
}
template <typename T>
void StatisticMultiset::addNum(const multiset<T> &numbers) {
    for (auto i = numbers.begin(); i != numbers.end(); i++) {
        repository.insert(*i);
    }
}

template <typename T>
void StatisticMultiset::addNumsFromFile(const string &filename) {
    ifstream file(filename);
    int j;
        while(!file.eof()){
            file >> j;
            repository.insert(j);

    }
}
*/
/*
int StatisticMultiset::getMax() const {
    auto iterator = --repository.end();
    int mx = *iterator;
    return mx;
}

int StatisticMultiset::getMin() const{
    auto iterator = repository.begin();
    int mn = *iterator;
    return mn;
}

template <typename T>
int StatisticMultiset::getCountAbove (float threshold) const {
    auto iterator = repository.lower_bound(threshold);
    auto iterator2 = repository.end();
    int count = 0;
    for (auto i = iterator; i != iterator2; i++) {
        if (*i != threshold) {
            count++;
        }
    }
    return count;
}
template <typename T>
int StatisticMultiset::getCountUnder (float threshold) const {
    auto iterator = repository.lower_bound(threshold);
    auto iterator2 = repository.begin();
    int count = 0;
    for (auto i = iterator2; i != iterator; i++) {
        if (*i != threshold) {
            count++;
        }
    }
    return count;
}

template <typename T>
float StatisticMultiset::getAvg() const {
    float avg = 0;
    for (auto i = repository.begin(); i != repository.end(); i++) {
        avg += *i;
    }
    avg = avg / repository.size();
    return avg;
}


template <typename T>
void StatisticMultiset::printMS() {

    for (auto i = repository.begin(); i != repository.end(); i++) {
        cout << *i << " ";
    }
}

template <typename T>
void StatisticMultiset::cacheFilling() {
    int it = *repository.begin();
    for (auto i = repository.begin()++; i != repository.end(); i++) {

        myCache[it] = getCountAbove(it);
    }
}
 */