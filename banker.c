/*
 * Banker's Algorithm for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Samina Rahmanyar, Matthew Rabski
 * All rights reserved.
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include "banker.h"

// Put any other macros or constants here using #define
// May be any values >= 0
#define NUM_CUSTOMERS 5
#define NUM_RESOURCES 3


// Put global environment variables here
// Available amount of each resource
int available[NUM_RESOURCES];

// Maximum demand of each customer
int maximum[NUM_CUSTOMERS][NUM_RESOURCES];

// Amount currently allocated to each customer
int allocation[NUM_CUSTOMERS][NUM_RESOURCES];

// Remaining need of each customer
int need[NUM_CUSTOMERS][NUM_RESOURCES];


// Define functions declared in banker.h here
//bool request_res(int n_customer, int request[]) 
//{
//}

// Release resources, returns true if successful
// bool release_res(int n_customer, int release[])
// {
//      
// }

int cc; //global customer counter
void cust_init() //Initialize customer resources
{ //A has 10, B has 5, C has 7
    for (int i = 0; i<NUM_RESOURCES; i++){
        maximum[cc][0] = rand() % 10;
        maximum[cc][1] = rand() % 5;
        maximum[cc][2] = rand() % 7; 
    }
     for (int i = 0; i<NUM_RESOURCES; i++){
        allocation[cc][0] = rand() % 10;
        allocation[cc][1] = rand() % 5;
        allocation[cc][2] = rand() % 7; 
    }
   
     for (int i = 0; i<NUM_RESOURCES; i++){
        need[cc][0] = rand() % 10;
        need[cc][1] = rand() % 5;
        need[cc][2] = rand() % 7; 
    }
};


int main(int argc, char *argv[])
{
    // Read in arguments from CLI, NUM_RESOURCES is the number of arguments 
    // Allocate the available resources  
    available[0] = atoi(argv[1]);
    available[1] = atoi(argv[2]);
    available[2] = atoi(argv[3]);
    printf("Available %d, Maximum %d, Allocation %d\n", available[0], available[1], available[2]);

    // Initialize the pthreads, locks, mutexes, etc.
    pthread_t customer[NUM_CUSTOMERS];
    for (cc = 0; cc<NUM_CUSTOMERS; cc++)
    {
        printf("ENTER customer %d\n", cc);
        pthread_create(&customer[cc], NULL, &cust_init, (void *)cc);
    }

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    // Run the threads and continually loop

    // The threads will request and then release random numbers of resources    // Allocate the available resources

    // If your program hangs you may have a deadlock, otherwise you *may* have
    // implemented the banker's algorithm correctly
    
    // If you are having issues try and limit the number of threads (NUM_CUSTOMERS)
    // to just 2 and focus on getting the multithreading working for just two threads

    pthread_exit(NULL);
    return EXIT_SUCCESS;
}
