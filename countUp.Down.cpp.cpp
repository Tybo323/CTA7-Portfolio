/*
 * countUp.Down.cpp
 *
 *  Created on: Jan 5, 2025
 *      Author: Tyler Butorac
 */
#include <iostream>
#include <thread>

// Function counts up to 20
void countUp() {
    // Performance: Single-thread execution
    for (int i = 1; i <= 20; ++i) {
        std::cout << "Count Up: " << i << std::endl;
    }
}

// Function counts down from 20 to 0
void countDown() {
    // Performance: Single-thread execution
    for (int i = 20; i >= 0; --i) {
        std::cout << "Count Down: " << i << std::endl;
    }
}

int main() {
    // Creating and starting thread1 for up count
    // Analysis: No shared resources, no thread safety issues 
    std::thread thread1(countUp);

    // Joining thread1 to ensure it finish before starting next
    // Analysis: Proper synch avoids race conditions
    thread1.join();

    // Creating and starting thread2 for down count
    // Analysis: Threads run sequentially, no concurrency here
    std::thread thread2(countDown);

    // Joining thread2 ensures completion
    thread2.join();

    // Return success
    return 0;
}





