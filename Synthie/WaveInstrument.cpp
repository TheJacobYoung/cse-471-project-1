#include "StdAfx.h"
#include "WaveInstrument.h"

CWaveInstrument::CWaveInstrument(void)
{
}

CWaveInstrument::~CWaveInstrument(void)
{
}


void CWaveInstrument::Start()
{
	m_wavePlayer.SetSampleRate(GetSampleRate());
	m_wavePlayer.Start();
}


void CWaveInstrument::SetNote(CNote *note)
{
}


bool CWaveInstrument::Generate()
{
	bool valid = m_wavePlayer.Generate();

	m_frame[0] = m_wavePlayer.Frame(0);
	m_frame[1] = m_frame[0];
	m_box.processEffects(m_frame);
	return valid;
}