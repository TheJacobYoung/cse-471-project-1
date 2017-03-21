//Similar to instrument

#include "stdafx.h"
#include "Notes.h"
#include "AdditiveSynth.h"
#include <string>
#include <vector>

using namespace std;


CAdditiveSynth::CAdditiveSynth()
{
}


CAdditiveSynth::~CAdditiveSynth()
{
}

void CAdditiveSynth::Start()
{
	m_addFinalSound.SetSource(&m_addSoundGen);
	m_addFinalSound.SetSampleRate(GetSampleRate());
	m_addFinalSound.Start();
}


void CAdditiveSynth::SetNote(CNote *note)
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

		CComVariant value;
		attrib->get_nodeValue(&value);

		//Effect finder section
		if (name == "duration")
		{
			value.ChangeType(VT_R8);
			SetDuration(value.dblVal);
		}
		else if (name == "note")
		{
			SetFreq(NoteToFrequency(value.bstrVal));
		}

		/*else if (name == "attack")
		{
			value.ChangeType(VT_R8);
			m_ar.SetAttack(value.dblVal);
		}
		else if (name == "release")
		{
			value.ChangeType(VT_R8);
			m_ar.SetRelease(value.dblVal);
		}*/

		else if (name == "FadeIn")
		{
			value.ChangeType(VT_R8);
			SetFadeInDuration(value.dblVal * m_duration);
		}

		else if (name == "FadeOut")
		{
			value.ChangeType(VT_R8);
			SetFadeOutDuration(value.dblVal * m_duration);
		}

		//Harmonic finder section
		else if (name == "a1")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(0, value.dblVal);
		}
		else if (name == "a2")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(1, value.dblVal);
		}
		else if (name == "a3")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(2, value.dblVal);
		}
		else if (name == "a4")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(3, value.dblVal);
		}
		else if (name == "a5")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(4, value.dblVal);
		}

		//Attack, sustain, decay, release section
		else if (name == "A_D_S_R")
		{
			//Create ASDR components
			wstring wide(value.bstrVal);
			//Initialize string of ASDR from XML wide string
			string ASDRstring(wide.begin(), wide.end());

			string component;
			vector<string> adsrComponents;
			for (int i = 0; i <= ASDRstring.size(); i++)
			{
				if (ASDRstring[i] != ' ')
				{
					component += ASDRstring[i];
				}
				else if (component.size() >= 1 && ASDRstring[i] == ' ')
				{
					adsrComponents.push_back(component);
					component.clear();
				}
			}

			if (component.size() >= 1)
			{
				adsrComponents.push_back(component);
				component.clear();
			}

			//String to float operators
			m_attackDur = stof(adsrComponents[0]);
			m_decayDur = stof(adsrComponents[1]);
			m_sustainDur = stof(adsrComponents[2]);
			m_releaseDur = stof(adsrComponents[3]);

			m_addFinalSound.SetAttack(m_attackDur);
			m_addFinalSound.SetRelease(m_releaseDur);
			m_addFinalSound.SetDecay(m_decayDur);
			m_addFinalSound.SetSustain(m_sustainDur);

		}

		else if (name == "vibrato")
		{
			wstring wide(value.bstrVal);
			string vibString(wide.begin(), wide.end());

			string component;
			vector<string> vibComponents;
			for (int i = 0; i <= vibString.size(); i++)
			{
				if (vibString[i] != ' ')
				{
					component += vibString[i];
				}
				else if (vibString[i] == ' ' && component.size() >= 1)
				{
					vibComponents.push_back(component);
					component.clear();
				}
			}

			if (component.size() >= 1)
			{
				vibComponents.push_back(component);
				component.clear();
			}

			m_vibRate = stof(vibComponents[0]);
			m_vibFreq = stof(vibComponents[1]);

			m_addSoundGen.SetVibratoRate(m_vibRate);

			m_addSoundGen.SetVibratoFreq(m_vibFreq);
		}

		/*else if (name == "a1")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(0, value.dblVal);
		}
		else if (name == "a3")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(1, value.dblVal);
		}
		else if (name == "a5")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(2, value.dblVal);
		}
		else if (name == "a7")
		{
			value.ChangeType(VT_R8);
			m_addSoundGen.SetAmplitude(3, value.dblVal);
		}*/

	}

}


bool CAdditiveSynth::Generate()
{
	//m_addSoundGen.Generate();

	bool valid = m_addFinalSound.Generate();

	m_frame[0] = m_addFinalSound.Frame(0);
	m_frame[1] = m_addFinalSound.Frame(1);

	m_time += GetSamplePeriod();
	return valid;
}