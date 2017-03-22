#pragma once
#include <vector>
//1 second circular delay buffer
using std::vector;
class CircularBuffer
{
private:
	vector<double*> samples;
	int m_begin;
	int m_end;
	int m_size;
	int m_wrloc;
	double* readAt(int idx) {
		if (idx < m_begin) {
			return samples.at(m_size + (idx%m_size));
		}
		else {
			return samples.at(idx % m_size);
		}
	}
public:

	double* read(int delay) {
		return readAt(m_wrloc - delay);
	}
	void write(double* frame) {
		if (m_wrloc < m_begin) {
			samples[m_size + (m_wrloc%m_size)] = frame;
		}
		else {
			samples[m_wrloc%m_size] = frame;
		}
		m_wrloc += 1;
	}
	int* getWrloc()const { return new int(m_wrloc); }

	CircularBuffer() { 
		samples = vector<double*>(44100);
		m_wrloc = 0;
		m_size = 44100;
		m_end = 44100;
		m_begin = 0;

	};
	~CircularBuffer() {};
};

