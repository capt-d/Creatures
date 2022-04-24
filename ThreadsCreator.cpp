#include "ThreadsCreator.hpp"
//#include <cmath>


ThreadsCreator::ThreadsCreator(std::mutex &_cycle_mutex, unsigned int _count):cycle_mutex(_cycle_mutex)
{
  threads_count = 0;
  setThreadsCount(_count);
}

ThreadsCreator::~ThreadsCreator() {}

unsigned int ThreadsCreator::setThreadsCount(unsigned int _count)
{
  if (_count == threads_count)
    return threads_count; 
  if(threads_count)
  {
    std::lock_guard<std::mutex> lock(cycle_mutex);
    for (auto & _data : threads_classes)
    {
      _data.thread_locks.stop = true;
      _data.thread_locks.main_sem->acquire();
    }
    threads_classes.clear();
	threads_count = 0;
  }
  if(_count == 0)
    return 0; 
  std::lock_guard<std::mutex> lock(cycle_mutex);
  try
  {
    threads_classes.reserve(_count);
    for (unsigned int i = 0; i < _count; i++)
      threads_classes.emplace_back(new ThreadsClass);

    threads_count = _count;
  }
  catch(std::exception &e)
  {
    threads_classes.clear();
    threads_count = 0;
  }  
  return threads_count; 
}

const std::vector<ThreadsCreator::ThreadsLocks> ThreadsCreator::setThreadsParams(const std::vector<ThreadsCreator::ThreadsData> &_params_vect)
{
  if (_params_vect.size() != threads_count)
    throw std::runtime_error("wrong size");
  
  for(unsigned int i = 0; i < threads_count; i++)
       threads_classes[i].thread_data = _params_vect[i];
  std::vector<ThreadsCreator::ThreadsLocks> locks;
  locks.reserve(threads_count);
  for (auto & _data : threads_classes)
    locks.emplace_back(_data.thread_locks);
  return locks;
}

void ThreadsCreator::ThreadsClass::operator()(void)
{
  while(true)
  {
    thread_locks.thread_sem->acquire();
    if (thread_locks.stop)
	{
     thread_locks.main_sem->release();
     break;
    }
    if (thread_data.threaded_function != NULL)
        thread_data.threaded_function(thread_data.params);
    thread_locks.main_sem->release();
  }
}

unsigned int ThreadsCreator::getThreadsCount(void)
{
	return threads_count;
}
