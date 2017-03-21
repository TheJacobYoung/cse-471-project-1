#pragma once
#include "WaveInstrument.h"
#include "InstrumentFactory.h"
#include <vector>

class CWaveInstrumentFactory:public InstrumentFactory
{
public:
	CWaveInstrumentFactory(void);
	~CWaveInstrumentFactory(void);

	void SetNote(CNote *note);
	CWaveInstrument *CreateInstrument();
	bool LoadFile(const char *filename);


private:
	std::vector<short> m_wave;
};