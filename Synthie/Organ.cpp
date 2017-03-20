#include "stdafx.h"
#include "Organ.h"
#include "Notes.h"

COrgan::COrgan()
{
	m_duration = 0.1;
}

// Constructor to set the beats per minute
COrgan::COrgan(double bpm)
{
	m_drawbars.resize(9, 0.0); // 9 tonewheels
	m_leslieChanged = true; // initialize to true so that the leslie can get set
	m_bpm = bpm;
}

COrgan::~COrgan()
{
}

void COrgan::Start()
{
	/*	m_sinewave.SetSampleRate(GetSampleRate());
	m_sinewave.Start();
	m_time = 0; */

	m_time = 0;
	m_organWave.SetSampleRate(GetSampleRate());
	m_organWave.Start();
	
	m_envelope.SetSource(&m_organWave);
	m_envelope.SetSampleRate(GetSampleRate());
	m_envelope.Start();
}


bool COrgan::Generate()
{

	/*	// Tell the component to generate an audio sample
	m_sinewave.Generate();

	// Read the component's sample and make it our resulting frame.
	m_frame[0] = m_sinewave.Frame(0);
	m_frame[1] = m_sinewave.Frame(1);

	// Update time
	m_time += GetSamplePeriod();

	// We return true until the time reaches the duration.
	return m_time < m_duration; */

	// Tell the organ to generate an audio 
	m_organWave.Generate();

	// use the envelope
	bool valid = m_envelope.Generate();
	m_frame[0] = m_envelope.Frame(0);
	m_frame[1] = m_envelope.Frame(1);
	m_time += GetSamplePeriod();

	return valid;
}

void COrgan::SetDrawbars(int drawbarNum)
{
	// this sets up how the waves are generated
	int digit = 0;
	double sample = 0.0;
	for (int i = 0; i < 9; i++) // 9 tonewheels
	{
		// parse  through the numbers
		digit = drawbarNum % (int)pow((double)10, (9 - i));
		digit = digit / (int)pow((double)10, (8 - i));
		if (digit != 0)
		{
			m_drawbars[i] = pow(10.0, (((8 - (double)digit) * -3) / 20));
		}
	}

}

void COrgan::SetLeslieAttackTime(double leslieAttack)
{
	// only set attack time if leslie has changed
	if (m_leslieChanged)
	{
		m_organWave.SetLeslieAttackTime(leslieAttack);
		m_leslieChanged = false;
	}
}

void COrgan::SetNote(CNote *note)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i<len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		// Get the value of the attribute.  A CComVariant is a variable
		// that can have any type. It loads the attribute value as a
		// string (UNICODE), but we can then change it to an integer 
		// (VT_I4) or double (VT_R8) using the ChangeType function 
		// and then read its integer or double value from a member variable.
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "duration")
		{
			value.ChangeType(VT_R8);
			SetDuration(value.dblVal);
		}
		else if (name == "note")
		{
			SetFreq(NoteToFrequency(value.bstrVal));
		}
		else if (name == "leslieAttackTime")
		{
			value.ChangeType(VT_R8);
			SetLeslieAttackTime(value.dblVal);
		}
		else if (name == "leslieReleaseTime")
		{
			value.ChangeType(VT_R8);
			SetLeslieReleaseTime(value.dblVal);
		}
		else if (name == "leslieFreq")
		{
			value.ChangeType(VT_R8);
			SetLeslieFreq(value.dblVal);
			SetLeslieChanged(true);
		}
		else if (name == "leslieEndFreq")
		{
			value.ChangeType(VT_R8);
			SetLeslieEndFreq(value.dblVal);
		}
		else if (name == "leslieRadius")
		{
			value.ChangeType(VT_R8);
			SetLeslieRadius(value.dblVal);
		}
		else if (name == "vibratoMag")
		{
			value.ChangeType(VT_R8);
			SetVibratoMag(value.dblVal);
		}
		else if (name == "vibratoFreq")
		{
			value.ChangeType(VT_R8);
			SetVibratoFreq(value.dblVal);
		}
		else if (name == "attack")
		{
			value.ChangeType(VT_R8);
			m_envelope.SetAttack(value.dblVal);
		}
		else if (name == "decay")
		{
			value.ChangeType(VT_R8);
			m_envelope.SetDecay(value.dblVal);
		}
		else if (name == "release")
		{
			value.ChangeType(VT_R8);
			m_envelope.SetRelease(value.dblVal);
		}
		else if (name == "amplitude")
		{
			value.ChangeType(VT_R8);
			SetAmplitude(value.dblVal);
		}
		else if (name == "drawbar")
		{
			value.ChangeType(VT_I4);
			SetDrawbars(value.intVal);
		}
	}

}