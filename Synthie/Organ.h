#pragma once
#include "instrument.h"
#include "Notes.h"
#include "AR.h"
#include <vector>
#include "OrganEnvelope.h"
#include "OrganWave.h"

using namespace std;

class COrgan:
	public CInstrument
{
public:
	COrgan();
	COrgan(double bpm);
	virtual ~COrgan();
public:
	const double NUM_SECS_IN_MINUTE = 60.0;
	virtual void Start();
	virtual bool Generate();

	void SetLeslieAttackTime(double attack);
	void SetLeslieStartFreq(double startTime) { m_organWave.SetLeslieStartFreq(startTime); }
	void SetLeslieEndFreq(double endTime) { m_organWave.SetLeslieEndFreq(endTime); }
	void SetLeslieReleaseTime(double releaseTime) { m_organWave.SetLeslieReleaseTime(releaseTime); }
	void SetLeslieChanged(bool isChanged) { m_organWave.SetLeslieChanged(isChanged); }
	void SetLeslieRadius(double radius) { m_organWave.SetLeslieRadius(radius); }
	void SetLeslieFreq(double frequency) { m_organWave.SetLeslieFreq(frequency); }
	void SetDrawbars(vector<double> drawbars) { m_organWave.SetDrawbars(drawbars); }
	void SetVibratoFreq(double vfreq) { m_organWave.SetVibratoFreq(vfreq); }
	void SetVibratoMag(double vmag) { m_organWave.SetVibratoMag(vmag); }

	double GetFrame(int i) { return m_frame[i]; }
	virtual void SetNote(CNote *note);
	void COrgan::SetDrawbars(int drawbarNum);

	void SetFreq(double f) { m_organWave.SetFreq(f); }
	void SetAmplitude(double a) { m_organWave.SetAmplitude(a); }
	void SetDuration(double d) { m_envelope.SetDuration(d); m_organWave.SetDuration(d); }
private:
	COrganWave m_organWave;
	double m_duration;
	double m_time;
	CAR m_ar;

	COrganEnvelope m_envelope;
	vector<double> m_drawbars;
	bool m_leslieChanged;
};

