#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;
const int NUM_PHILOSOPHERS = 5;

mutex forks[NUM_PHILOSOPHERS];

void philosopher(int id) {
    int left_fork, right_fork;

    // Determine the left and right forks based on philosopher's ID
    if (id % 2 == 0) { // Even philosopher
        left_fork = (id + 1) % NUM_PHILOSOPHERS;
        right_fork = id;
    } else { // Odd philosopher
        left_fork = id;
        right_fork = (id + 1) % NUM_PHILOSOPHERS;
    }
    int i = 100;
    while (i--) {
        // Thinking
        string think = "Philosopher " + to_string(id) + " is thinking.\n";
        cout << think;
        // Pick up forks
        if (id % 2 == 0) { // Even philosopher
            forks[left_fork].lock();
            forks[right_fork].lock();
        } else { // Odd philosopher
            forks[right_fork].lock();
            forks[left_fork].lock();
        }

        // Eating
//        cout << "Philosopher " << id << " is eating." << endl;
        string eat = "Philosopher " + to_string(id) + " is eating.\n";
        cout << eat;
        // Put down forks
        forks[left_fork].unlock();
        forks[right_fork].unlock();
    }
}

int main() {
    vector<thread> philosophers;

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers.emplace_back(philosopher, i + 1);
    }

    // Join philosopher threads
    for (auto &thread: philosophers) {
        thread.join();
    }

    return 0;
}
