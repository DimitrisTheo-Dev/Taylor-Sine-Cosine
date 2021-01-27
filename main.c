//
//  main.c
//  Homework5-1
//
//  Created by Dimitris Theodoropoulos on 5/12/20.
//

#include <stdio.h>
#define Pi 3.14159265358
#include <math.h>

double rad_conver(double r, double de){
    r = (de * Pi / 180);
    return r;
}

double insert_degr(double d) {
    do {
    printf("Δώσε μοίρες: ");
    scanf("%lf", &d);
    } while(d<0 || d>360);
    return d;
}

double check(double *x) {
    do {
        printf("Δώσε αριθμό: ");
        scanf("%lf", x);
    } while(*x < 0 || *x > 360);
    return 0;
}

int check_diff(double dif) {
    if(dif >= 0.000001){
        return 1;
    } else {
        return 0;
    }
}

double sine(double total1, double a, double transf, double dif, double k, int i) {
    double total2 = a;
    total1 = a;
    double total0 = 0;
    dif = 1.0;

    do {
        k = (pow(a, 2)/((2*i-2)*(2*i-1))) * pow(-1,i+1);
        total2 = total1  + k*fabs(total1 - total0);
        dif = fabs(total2- total1);
        total0 = total1;
        total1 = total2;
        i++;
    } while(check_diff(dif));
    return total2;
}

double cosine(double total1, double a, double transf, double dif, double k, int i) {
    double total2 = 1.0;
    total1 = 1.0;
    double total0 = 0;
    dif =1.0;

    do {
        k = (pow(a, 2)/(((2*i)-2)*((2*i)-3))) * pow(-1,i+1);
        total2 = total1 + k*fabs(total1 - total0);
        dif = fabs(total2- total1);
        total0 = total1;
        total1 = total2;
        i++;
    } while(check_diff(dif));
    return total2;
}

int main() {
    double degrees = 0.0, rad = 0.0, k = 0.0, dif = 1.0, transf = 0.0, total = 0, sineRes, cosineRes;
    degrees = insert_degr(degrees);
    rad = rad_conver(rad, degrees);
    int i = 2;
    sineRes = sine(total, rad, transf, dif, k, i);
    printf("sine = %lf\n", sineRes);
    cosineRes = cosine(total, rad, transf, dif, k, i);
    printf("cosine = %lf\n", cosineRes);
    return 0;
}

