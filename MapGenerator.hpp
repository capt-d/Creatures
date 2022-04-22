#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <memory> 


#include "ThreadsCreator.hpp"
#include "SimplexNoise.hpp"

class MapGenerator 
{
  public:
    MapGenerator(void);
    MapGenerator(unsigned int _cols, unsigned int _rows);

    ~MapGenerator();
    
    unsigned int setThreadsCount(unsigned int _count); // optional
    //unsigned int save(ostream &where);
    void setNoiseData(SimplexNoise::NoiseData _noise_data);
    const SimplexNoise::NoiseData& getNoiseData(void);
    std::shared_ptr<unsigned char[]> generate(void);
	
  private:
    MapGenerator(const MapGenerator&);
    void setRanges(const unsigned int threads_count);
    unsigned int cols;   
    unsigned int rows;
    std::mutex cycle_mutex;
    std::unique_ptr<ThreadsCreator> threads_creator;
    std::shared_ptr<unsigned char[]> map_data;
    SimplexNoise noise;
    SimplexNoise::NoiseData noise_data;
    //unsigned char mapToUChar(double _value, double _min, double _max, unsigned char _min_, unsigned char _max_);
    unsigned char mapToUChar(double _value, double _min, double _max);
    void setRanges(void);
    struct ThreadsData
    {
      unsigned int first;
      unsigned int last;
    };
    std::vector<std::shared_ptr<ThreadsData> >partial_threads_data;
	std::vector<ThreadsCreator::ThreadsData> threads_data;
	std::vector<ThreadsCreator::ThreadsLocks> threads_locks; 
    void threaded_function(void  *_threads_data);
}; 

#endif
