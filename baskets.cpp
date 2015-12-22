#include "baskets.h"
#include <QDebug>
Baskets::Baskets()
{

}

QPoint Baskets::getBest()
{
    QPoint best;
    double min = INFINITY;
    for(int i = 0; i < solutions.size(); i++)
    {
        for(int j = 0; j < solutions.at(i).size(); j++)
        {
            if(fabs(f(solutions[i][j]) < min))
            {
                best = {i,j};
                min = f(solutions[i][j]);
            }
        }
    }
    return best;
}

QPoint Baskets::getWrong()
{
    QPoint wrong;
    double max = -INFINITY;
    for(int i = 0; i < solutions.size(); i++)
    {
        for(int j = 0; j < solutions.at(i).size(); j++)
        {
            if(fabs(f(solutions[i][j]) > max))
            {
                wrong = {i,j};
                max = f(solutions[i][j]);
            }
        }
    }
    return wrong;
}

void Baskets::init(int numBesket, int numEggs)
{
    for(;numBesket > 0;numBesket--)
    {
        vector<double> b;
        for(int i = 0;i < numEggs; i++)
        {
            b.push_back(rand() + (rand() % 1000)/1000);
        }
        solutions.push_back(b);
    }
}

void Baskets::printEggs()
{
    for(vector<double> var : solutions)
    {
        QString eggs;
        for(double value : var )
        {
            eggs += QString::number(value) + " ";
        }
        qDebug() << eggs;
    }
}

