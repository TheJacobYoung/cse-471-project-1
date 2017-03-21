#pragma once
#include "Instrument.h"
#include "AR.h"
#include "WavePlayer.h"
#include "DrumEnvelope.h"

#include <string>


class CDrumInstrument :
	public CInstrument
{
public:
	CDrumInstrument();
	virtual ~CDrumInstrument();

	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote *note);

	void SetType(std::wstring type) { }
	void SetDuration(double d) { m_ar.SetDuration(d); }
	void SetFreq(double f) {}

	const double NUM_SECS_IN_MINUTE = 60.0;
	CWavePlayer *GetPlayer() { return &m_wavePlayer; }
	std::wstring GetName() const { return L"Drum"; }

	void GetFrame(double frame[2]) { frame[0] = m_frame[0]; frame[1] = m_frame[1]; }

private:
	CAR m_ar;
	double m_time;
	double m_duration;
	std::wstring m_type;
	CWavePlayer m_wavePlayer;
	CDrumEnvelope m_drumenvelope;
};

