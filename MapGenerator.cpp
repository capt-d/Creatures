#include "MapGenerator.hpp"
#include <QtWidgets/QMessageBox>

MapGenerator::MapGenerator(void)
{
	MapGenerator(0,0);
}

MapGenerator::MapGenerator(unsigned int _cols, unsigned int _rows):cols(_cols),rows(_rows)
{
  if (cols != 0 and rows != 0)
	map_data.reset(new unsigned char[cols * rows]);
  if (!map_data)
		throw std::runtime_error("dupa blada");
  noise_data.gain = 0.14;
  noise_data.octaves = 3;
  noise_data.lacunarity = 0.4;
  noise_data.seedNumber = 0;
}

MapGenerator::~MapGenerator(){}
 
unsigned int MapGenerator::setThreadsCount(unsigned int _count)
{
  if (!threads_creator)
	threads_creator.reset(new ThreadsCreator(cycle_mutex, _count));
  if (threads_creator)
  {	
	setRanges(threads_creator->getThreadsCount());
    return threads_creator->getThreadsCount();
  }
  return 0;
}

std::shared_ptr<unsigned char[]> MapGenerator::generate(void)
{
  noise.randomizeSeed();
  if (threads_data.size())
  {
	if (threads_creator->getThreadsCount())
	{
		std::lock_guard<std::mutex> lock(cycle_mutex);
		for (auto & _data : threads_locks)
			_data.thread_sem->release();
		for (auto & _data : threads_locks)
			_data.main_sem->acquire();
	}
  }
  else
	for (unsigned int i = 0; i < rows; i++)
		for (unsigned int j = 0; j < cols; j++)
			map_data[i * cols + j] = mapToUChar(noise.signedFBM(i / (double) cols , j / (double) rows, noise_data), -1, 1);
  return map_data;
}

void MapGenerator::setNoiseData(SimplexNoise::NoiseData _noise_data)
{
	noise_data.seedNumber = _noise_data.seedNumber;
	noise.setSeed(_noise_data.seedNumber);
	noise_data.octaves = _noise_data.octaves;
	noise_data.lacunarity = _noise_data.lacunarity;
	noise_data.gain = _noise_data.gain;
}

const SimplexNoise::NoiseData& MapGenerator::getNoiseData(void)
{
	return noise_data;
}

void MapGenerator::setRanges(const unsigned int threads_count)
{
 QMessageBox msg;
		msg.setText(QString("threads_count %1").arg(threads_count));
		msg.exec();
 if (threads_count == 0)
	 return;
 try
  {
	  partial_threads_data.reserve(threads_count);
	  threads_locks.reserve(threads_count);
	  threads_data.reserve(threads_count);
  }
  catch (std::bad_alloc &e) 
  {
	  	QMessageBox msg;
		msg.setText("no memory for MapGenerator::ThreadsData");
		msg.exec();
		partial_threads_data.clear();
		threads_locks.clear();
		threads_data.clear();
		return;
  }
  
  msg.setText(QString("threads_count %1, capacity: %2, capacity: %3, capacity: %4").arg(threads_count).arg(partial_threads_data.capacity()).arg(threads_locks.capacity()).arg(threads_data.capacity()));
		msg.exec();
  unsigned int per_thread = (cols * rows) / threads_count;
  unsigned int rest = (cols * rows) % threads_count; 
  msg.setText(QString("per_thread: %1, rest: %2").arg(per_thread).arg(rest));
  msg.exec();
  
QString strg = QString();
for (unsigned int i = 0; i < rest; i++)
  strg += QString("nr: %1, first: %2, last: %3\n").arg(i).arg(i * (per_thread + 1)).arg(i * (per_thread+1) + per_thread);
for (unsigned int i = rest; i < threads_count; i++)
	strg +=QString("nr: %1, first: %2, last: %3\n").arg(i).arg(rest + i * per_thread).arg(rest + i * per_thread + per_thread - 1);
 msg.setText(strg);

msg.exec();
msg.setText(QString("threads_count %1, ptd size: %2, tl size: %3, td size: %4").arg(threads_count).arg(partial_threads_data.size()).arg(threads_locks.size()).arg(threads_data.size()));
 msg.exec(); 
  
  for (unsigned int i = 0; i < rest; i++)
  {
	partial_threads_data.emplace_back(std::shared_ptr<ThreadsData>(new ThreadsData));
	threads_data.emplace_back();
	
	partial_threads_data[i]->first = i * (per_thread + 1);
	partial_threads_data[i]->last = partial_threads_data[i]->first + per_thread;
	std::bind(threads_data[i].threaded_function, &MapGenerator::threaded_function);
	threads_data[i].params = partial_threads_data[i];
  }
  for (unsigned int i = rest; i < threads_count; i++)
  {
	partial_threads_data.emplace_back(std::shared_ptr<ThreadsData>(new ThreadsData));
	threads_data.emplace_back();
	
	partial_threads_data[i]->first = rest + i * per_thread; 
	partial_threads_data[i]->last = partial_threads_data[i]->first + per_thread - 1;
	std::bind(threads_data[i].threaded_function, &MapGenerator::threaded_function);
	threads_data[i].params = partial_threads_data[i];
  } 
  threads_locks = threads_creator->setThreadsParams(threads_data);
msg.setText(QString("threads_count %1, ptd size: %2, tld size: %3, td size: %4").arg(threads_count).arg(partial_threads_data.size()).arg(threads_locks.size()).arg(threads_data.size()));
		msg.exec();
}

void MapGenerator::threaded_function(void *_threads_data)
{
   auto threads_data = reinterpret_cast<ThreadsData*>(_threads_data); 
   for (unsigned int i = threads_data->first; i < threads_data->last; i++)  
	map_data[i] = mapToUChar(noise.signedRawNoise((i % cols) / cols, (i / cols) / rows), -1, 1);
}

unsigned char MapGenerator::mapToUChar(double _value, double _min, double _max) //, unsigned char _min_, unsigned char _max_)
//unsigned char MapGenerator::mapToUChar(double _value, double _min, double _max, unsigned char _min_, unsigned char _max_)
{
//	return (_value - _min) * (_max_ - _min_) / (_max - _min) + _min_;
	return (_value - _min) * 255 / (_max - _min);
}
