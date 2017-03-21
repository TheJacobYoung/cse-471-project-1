#include "stdafx.h"
#include "DrumInstrumentFactory.h"
#include "Notes.h"



CDrumInstrumentFactory::CDrumInstrumentFactory()
{
	LoadFile("drum_1.wav");
	LoadFile("drum_2.wav");
	LoadFile("drum_3.wav");
	LoadFile("drum_4.wav");
	LoadFile("drum_5.wav");
	LoadFile("drum_6.wav");
	LoadFile("drum_7.wav");
	LoadFile("drum_8.wav");
	LoadFile("drum_9.wav");
	LoadFile("drum_10.wav");
	LoadFile("drum_11.wav");
	LoadFile("drum_12.wav");
	LoadFile("drum_13.wav");
	LoadFile("drum_14.wav");
	LoadFile("drum_15.wav");
	LoadFile("drum_16.wav");
	LoadFile("drum_17.wav");
	LoadFile("drum_18.wav");
	LoadFile("drum_19.wav");

	SyntheticDrum();	//counts for drum #20
}


CDrumInstrumentFactory::~CDrumInstrumentFactory()
{
}

void CDrumInstrumentFactory::SyntheticDrum(void)
{
	m_wave.clear();

	m_ar.SetAttack(0.1);
	m_ar.SetDecay(0.3);
	m_ar.SetDuration(0.01);
	m_ar.SetRelease(0.01);
	m_ar.SetSustain(0.1);

	m_ar.Start();
	for (int i = 0; i < (.75 * 44100); i++)
	{
		short newSound = short(rand() & 32768);
		m_wave.push_back(newSound);
	}

	m_table.push_back(m_wave);
	
	
}

void CDrumInstrumentFactory::SetNote(CNote * note)
{
	m_ar.Start();
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);
	for (int i = 0; i<len; i++)
	{
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);
		CComBSTR name;
		attrib->get_nodeName(&name);
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "note")
		{
			m_wave = m_table.at(DrumToPosition(value.bstrVal));
		}

		if (name == "pitch")
		{
			std::vector<short> temp;
			value.ChangeType(VT_I4);
			int t = value.intVal;
			for (unsigned i = 0; i < m_wave.size(); i++)
			{
				if (t > 3)
				{
					temp.push_back(m_wave.at(i));
					temp.push_back(m_wave.at(i));
				}
				else
				{
					if ((i % 2) == 1)
					{
						temp.push_back(m_wave.at(i));
					}
				}
			}
			m_wave = temp;
		}
		else if (name == "attack")
		{
			value.ChangeType(VT_R8);
			m_ar.SetAttack(value.dblVal);
		}
		else if (name == "decay")
		{
			value.ChangeType(VT_R8);
			m_ar.SetDecay(value.dblVal);
		}
		else if (name == "release")
		{
			value.ChangeType(VT_R8);
			m_ar.SetRelease(value.dblVal);
		}

	}
}

bool CDrumInstrumentFactory::LoadFile(const char * filename)
{
	m_wave.clear();

	CDirSoundSource m_file;
	if (!m_file.Open(filename))
	{
		CString msg = L"Unable to open audio file: ";
		msg += filename;
		AfxMessageBox(msg);
		return false;
	}

	for (int i = 0; i<m_file.NumSampleFrames(); i++)
	{
		short frame[2];
		m_file.ReadFrame(frame);
		m_wave.push_back(frame[0]);
	}

	// almost forgot to put in wavetable.... oops
	m_table.push_back(m_wave);

	m_file.Close();
	return true;
}

CDrumInstrument * CDrumInstrumentFactory::CreateInstrument()
{
	CDrumInstrument *instrument = new CDrumInstrument();
	instrument->GetPlayer()->SetSamples(&m_wave[0], (int)m_wave.size());

	return instrument;
}
