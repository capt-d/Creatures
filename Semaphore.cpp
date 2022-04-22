/*
 * code taken from https://stackoverflow.com/a/4793662
 * author: Maxim Egorushkin
 */

#include "Semaphore.hpp"

Semaphore::Semaphore()
{}

Semaphore::Semaphore(Semaphore &&)
{
  std::move(mutex_);
  std::move(condition_);
}

void Semaphore::release(void)
{
  std::lock_guard<decltype(mutex_)> lock(mutex_);
  ++count_;
  condition_.notify_one();
}

void Semaphore::acquire(void) 
{
  std::unique_lock<decltype(mutex_)> lock(mutex_);
  while(!count_) // Handle spurious wake-ups.
    condition_.wait(lock);
  --count_;
}

