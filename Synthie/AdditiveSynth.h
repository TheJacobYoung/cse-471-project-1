//Similar to instrument

#pragma once
#include "Instrument.h"
#include "SineWave.h"
#include "AdditiveFinalSound.h"
#include "AdditiveSynthSoundGenerator.h"


class CAdditiveSynth :
	public CInstrument
{
public:
	CAdditiveSynth();
	virtual ~CAdditiveSynth();

	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote *note);

	void SetDuration(double d) { m_addFinalSound.SetDuration(d); }
	void SetFreq(double f) { m_addSoundGen.SetFreq(f); }
	void SetFadeInDuration(double f) { m_addFinalSound.SetFadeIn(f); }
	void SetFadeOutDuration(double f) { m_addFinalSound.SetFadeOut(f); }

private:
	CAR     m_ar;
	double  m_time;

	CAdditiveSynthSoundGenerator m_addSoundGen;
	CAdditiveFinalSound m_addFinalSound;

	double m_duration = 0;
	double m_fadeIn = 0;
	double m_fadeOut = 0;

	//ASDR components
	double m_attackDur = 0;
	double m_sustainDur = 0;
	double m_decayDur = 0;
	double m_releaseDur = 0;

	//Vibrato components
	double m_vibRate = 0;
	double m_vibFreq = 0;

};

