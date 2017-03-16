#pragma once
#include "Instrument.h"
#include "AR.h"

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

private:
	CAR m_ar;
	double m_time;
	std::wstring m_type;
};

