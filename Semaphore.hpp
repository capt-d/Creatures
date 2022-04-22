#ifndef SEMAPHORE_H
#define SEMAPHORE_H

/*
 * code taken from https://stackoverflow.com/a/4793662
 * author: Maxim Egorushkin
 */

#include <mutex>
#include <condition_variable>

class Semaphore
{
  std::mutex mutex_;
  std::condition_variable condition_;
  unsigned long count_ = 0; // Initialized as locked.

  public:
    Semaphore();
    Semaphore(Semaphore &&); 
    void release();
    void acquire(); 
};

#endif
