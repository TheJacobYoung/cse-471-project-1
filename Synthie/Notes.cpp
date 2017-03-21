#include "stdafx.h"
#include "Notes.h"
#include <map>
#include <string>

using namespace std;

static int g_initialized = false;
static map<wstring, double> g_name2freq;

double NoteToFrequency(const WCHAR *name)
{
    if(!g_initialized)
    {
        for(int i=0;  i<sizeof(notes) / sizeof(Notes);  i++)
        {
            g_name2freq[notes[i].name] = notes[i].freq;
        }

        g_initialized = true;
    }

    map<wstring, double>::iterator f = g_name2freq.find(name);
    if(f == g_name2freq.end())
        return 0;

    return f->second;
}

static map<wstring, int> g_name2pos;

int DrumToPosition(const WCHAR * name)
{
	if (!g_initialized)
	{
		for (int i = 0; i<sizeof(drumsounds) / sizeof(DrumSounds); i++)
		{
			g_name2pos[drumsounds[i].name] = drumsounds[i].pos;
		}

		g_initialized = true;
	}

	map<wstring, int>::iterator fdrums = g_name2pos.find(name);
	if (fdrums == g_name2pos.end())
		return 25;

	g_initialized = false;
	return fdrums->second;
}
