#include "mainwindow.h"
#include <QApplication>
#include <math.h>
#include <QDebug>
#include "baskets.h"

#define GAMMA 0.01
#define NoN 3
#define NoB 3
#define ITER 100000
#define PA 0.003
#define MAX_ITER_WITH_EQUAL_Y 100

double func(double v)
{
    return pow(v-2,2) + 10;
}


double randreal()
{
    double value =  rand() + (rand() % 1000)/1000;
    if((rand() % 2) == 1)
        value *= -1;
    return value;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Baskets baskets;
    baskets.f = func;
    baskets.init(NoN,NoB);

    QPoint salution;

    int iter = 0;
    int countLoop = 0;
    double lastFitness;
    while(++iter < ITER)
    {
        QPoint bestPoint = baskets.getBest();
        QPoint wrongPoint = baskets.getWrong();

        baskets.printEggs();
        double fitnes = func(baskets.solutions[bestPoint.rx()][bestPoint.ry()]);
        if(fitnes == lastFitness)
            countLoop ++;
        else
        {
            countLoop = 0;
            lastFitness = fitnes;
        }
        w.addData(fitnes);
        qDebug() <<  "Best x =   "<< baskets.solutions[bestPoint.rx()][bestPoint.ry()];
        qDebug() <<  " with y = " << fitnes ;

        if( fabs(fitnes) < PA || countLoop >= MAX_ITER_WITH_EQUAL_Y)
        {
            salution = bestPoint;
            break;
        }

        QPoint randPoint;
        do{
        randPoint = {rand() % NoN, rand() % NoB};
        }while(randPoint == bestPoint);

        double v1;
        if(floor((baskets.solutions[wrongPoint.rx()][wrongPoint.ry()])) > 0)
            v1 = rand() % (int)floor((baskets.solutions[wrongPoint.rx()][wrongPoint.ry()]));
        else v1 = 1;
        double v = GAMMA*(v1);
        if(v == 0)
            v = 1;
        if(rand() % 2 == 1 )
            v *= -1;
        baskets.solutions[randPoint.rx()][randPoint.ry()] +=  v;

        double beta = 3/2;
        double sigma = pow((tgamma(1.0+beta) * sin(M_PI*beta/2.0) / ((tgamma(1.0+beta)/2.0) * beta * (pow(2.0,((beta-1.0)/2.0))))),(1.0/beta));

        for (int i = 0; i < NoN; i++){
           for (int j = 0; j < NoB; j++){
               if(QPoint{i,j} == bestPoint || (rand() % 100) < 30)
                   continue;
               double step = (randreal()*sigma) / pow(fabs(randreal()),(1/beta));
               double stepsize = 0.01 * step * (baskets.solutions[bestPoint.rx()][bestPoint.ry()]);
               double inc = stepsize;
               baskets.solutions[i][j] = baskets.solutions[bestPoint.rx()][bestPoint.ry()] + inc;
           }
        }
    }

    w.show();
    w.showGraph();

    int gag = rand();
    gag ++;

    return a.exec();
}
