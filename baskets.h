#ifndef BASKETS_H
#define BASKETS_H

#include<vector>
#include <QPoint>

using namespace std;

class Baskets
{
public:
    Baskets();
    vector<vector<double>> solutions;
    QPoint getBest();
    QPoint getWrong();
    double (*f)(double v);
    void init(int numBesket, int numEggs);
    void printEggs();

};

#endif // BASKETS_H
