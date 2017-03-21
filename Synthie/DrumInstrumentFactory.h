#pragma once
#include "DrumInstrument.h"
#include "audio/DirSoundSource.h"
#include "DrumEnvelope.h"
#include "WavePlayer.h"
#include "AR.h"
#include <vector>

class CDrumInstrumentFactory
{
public:
	CDrumInstrumentFactory();
	virtual ~CDrumInstrumentFactory();


	void SyntheticDrum();
	void SetNote(CNote *note);
	

	bool CDrumInstrumentFactory::LoadFile(const char *filename);

	CDrumInstrument *CreateInstrument();

	std::vector<short> Vect(int Z) { return m_table.at(Z); }


private:
	std::vector<short> m_wave;
	std::vector<short> m_vec;
	std::vector< std::vector<short> > m_table;


	CDrumEnvelope m_ar;
	CWavePlayer m_wp;
	double m_duration;
	double m_time;
};

