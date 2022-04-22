#ifndef THREADSCREATOR_H
#define THREADSCREATOR_H

#include <thread>
#include <vector>
//#include <utility>
#include <functional>
#include "Semaphore.hpp"

class ThreadsCreator
{
  public:
    ThreadsCreator(std::mutex &cycle_mutex, unsigned int _count = 0);
    ~ThreadsCreator();
    unsigned int setThreadsCount(unsigned int _count);
    unsigned int getThreadsCount(void);
    struct ThreadsData //settings for threads
    {
      std::function<void(std::weak_ptr<void>)> threaded_function = NULL; // called by operator()
      std::shared_ptr<void> params; 
    };
	struct ThreadsLocks // locks for threads and main thread
	{
	  bool stop = false; // end of thread work?
      std::shared_ptr<Semaphore> thread_sem;
	  std::shared_ptr<Semaphore> main_sem;
	};
	const std::vector<ThreadsCreator::ThreadsLocks> setThreadsParams(const std::vector<ThreadsCreator::ThreadsData> &params_vect);
	
  private:
    ThreadsCreator();
    ThreadsCreator(ThreadsCreator const&);
    unsigned int threads_count; //  counting threads
	
    struct ThreadsClass
    {
      void operator()(void); // calls thred_data.threaded_function
      ThreadsData thread_data;
      ThreadsLocks thread_locks;
      std::thread thread;
      ThreadsClass(ThreadsClass*){};
      ThreadsClass(){};
      ThreadsClass(const ThreadsClass&&){};
    };
    std::mutex &cycle_mutex; 
    std::vector<ThreadsClass> threads_classes;
};

#endif //THREADSCREATOR_H
