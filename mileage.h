#ifndef MILEAGE_H
#define MILEAGE_H

/*
    Calculates the priority of the passegers on the waiting list for overbooked flights.
    @param 
    A the customer's total mileage in the past year,
    B the number of years in his or her frequent flyer program,
    C the sequence number of the customer in the waiting list

    @return
    The priority of the customer
*/
int getPriority(int A, int B, int C);

#endif