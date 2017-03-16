#include "stdafx.h"
#include "DrumInstrument.h"


CDrumInstrument::CDrumInstrument()
{
	m_ar.SetSampleRate(GetSampleRate());
	m_ar.Start();
	m_time = 0;
}


CDrumInstrument::~CDrumInstrument()
{
}

void CDrumInstrument::Start()
{
}

bool CDrumInstrument::Generate()
{
	bool valid = m_ar.Generate();

	m_frame[0] = m_ar.Frame(0);
	m_frame[1] = m_ar.Frame(1);

	m_time += GetSamplePeriod();
	return valid;
}

void CDrumInstrument::SetNote(CNote * note)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
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
			// SetDuration(value.dblVal); // play the note for the duration in terms of seconds
			m_ar.SetDuration(value.dblVal * (NUM_SECS_IN_MINUTE / m_bpm));

		}
		else if (name == "type")
		{
			SetType(value.bstrVal);
		}
	}
}
