#include <mutex>
#include <condition_variable>
using namespace std;

class DiningPhilosophers {
private:
    mutex forks[5];

    mutex m;
    condition_variable cv;
    int allowed = 4;

public:
    DiningPhilosophers() {}

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [&] { return allowed > 0; });
            allowed--;
        }

        lock(forks[left], forks[right]);

        lock_guard<mutex> l(forks[left], adopt_lock);
        lock_guard<mutex> r(forks[right], adopt_lock);

        pickLeftFork();
        pickRightFork();

        eat();

        putRightFork();
        putLeftFork();

        {
            lock_guard<mutex> lk(m);
            allowed++;
        }

        cv.notify_one();
    }
};