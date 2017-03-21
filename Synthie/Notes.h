//
// Name :         Notes.h
// Description :  Header file with consts for notes to frequency conversions.
//

#pragma once

struct Notes
{
   const TCHAR *name;
   double freq;
};

const Notes notes[] = {{TEXT("A0"), 27.5}, {TEXT("A#0"), 29.1352}, {TEXT("Bb0"), 29.1352}, {TEXT("B0"), 30.8677},
{TEXT("C1"), 32.7032}, {TEXT("C#1"), 34.6478}, {TEXT("Db1"), 34.6478}, {TEXT("D1"), 36.7081}, {TEXT("D#1"), 38.8909}, 
{TEXT("Eb1"), 38.8909}, {TEXT("E1"), 41.2034}, {TEXT("F1"), 43.6535}, {TEXT("F#1"), 46.2493}, {TEXT("Gb1"), 46.2493}, 
{TEXT("G1"), 48.9994}, {TEXT("G#1"), 51.9131}, {TEXT("Ab1"), 51.9131}, {TEXT("A1"), 55.0}, {TEXT("A#1"), 58.2705}, 
{TEXT("Bb1"), 58.2705}, {TEXT("B1"), 61.7354}, {TEXT("C2"), 65.4064}, {TEXT("C#2"), 69.2957}, {TEXT("Db2"), 69.2957}, 
{TEXT("D2"), 73.4162}, {TEXT("D#2"), 77.7817}, {TEXT("Eb2"), 77.7817}, {TEXT("E2"), 82.4069}, {TEXT("F2"), 87.3071}, 
{TEXT("F#2"), 92.4986}, {TEXT("Gb2"), 92.4986}, {TEXT("G2"), 97.9989}, {TEXT("G#2"), 103.826}, {TEXT("Ab2"), 103.826}, 
{TEXT("A2"), 110.0}, {TEXT("A#2"), 116.541}, {TEXT("Bb2"), 116.541}, {TEXT("B2"), 123.471}, {TEXT("C3"), 130.813}, 
{TEXT("C#3"), 138.591}, {TEXT("Db3"), 138.591}, {TEXT("D3"), 146.832}, {TEXT("D#3"), 155.563}, {TEXT("Eb3"), 155.563}, 
{TEXT("E3"), 164.814}, {TEXT("F3"), 174.614}, {TEXT("F#3"), 184.997}, {TEXT("Gb3"), 184.997}, {TEXT("G3"), 195.998}, 
{TEXT("G#3"), 207.652}, {TEXT("Ab3"), 207.652}, {TEXT("A3"), 220.0}, {TEXT("A#3"), 233.082}, {TEXT("Bb3"), 233.082}, 
{TEXT("B3"), 246.942}, {TEXT("C4"), 261.626}, {TEXT("C#4"), 277.183}, {TEXT("Db4"), 277.183}, {TEXT("D4"), 293.665}, 
{TEXT("D#4"), 311.127}, {TEXT("Eb4"), 311.127}, {TEXT("E4"), 329.628}, {TEXT("F4"), 349.228}, {TEXT("F#4"), 369.994}, 
{TEXT("Gb4"), 369.994}, {TEXT("G4"), 391.995}, {TEXT("G#4"), 415.305}, {TEXT("Ab4"), 415.305}, {TEXT("A4"), 440.0}, 
{TEXT("A#4"), 466.164}, {TEXT("Bb4"), 466.164}, {TEXT("B4"), 493.883}, {TEXT("C5"), 523.251}, {TEXT("C#5"), 554.365}, 
{TEXT("Db5"), 554.365}, {TEXT("D5"), 587.33}, {TEXT("D#5"), 622.254}, {TEXT("Eb5"), 622.254}, {TEXT("E5"), 659.255}, 
{TEXT("F5"), 698.456}, {TEXT("F#5"), 739.989}, {TEXT("Gb5"), 739.989}, {TEXT("G5"), 783.991}, {TEXT("G#5"), 830.609}, 
{TEXT("Ab5"), 830.609}, {TEXT("A5"), 880.0}, {TEXT("A#5"), 932.328}, {TEXT("Bb5"), 932.328}, {TEXT("B5"), 987.767}, 
{TEXT("C6"), 1046.5}, {TEXT("C#6"), 1108.73}, {TEXT("Db6"), 1108.73}, {TEXT("D6"), 1174.66}, {TEXT("D#6"), 1244.51}, 
{TEXT("Eb6"), 1244.51}, {TEXT("E6"), 1318.51}, {TEXT("F6"), 1396.91}, {TEXT("F#6"), 1479.98}, {TEXT("Gb6"), 1479.98}, 
{TEXT("G6"), 1567.98}, {TEXT("G#6"), 1661.22}, {TEXT("Ab6"), 1661.22}, {TEXT("A6"), 1760.0}, {TEXT("A#6"), 1864.66}, 
{TEXT("Bb6"), 1864.66}, {TEXT("B6"), 1975.53}, {TEXT("C7"), 2093.0}, {TEXT("C#7"), 2217.46}, {TEXT("Db7"), 2217.46}, 
{TEXT("D7"), 2349.32}, {TEXT("D#7"), 2489.02}, {TEXT("Eb7"), 2489.02}, {TEXT("E7"), 2637.02}, {TEXT("F7"), 2793.83}, 
{TEXT("F#7"), 2959.96}, {TEXT("Gb7"), 2959.96}, {TEXT("G7"), 3135.96}, {TEXT("G#7"), 3322.44}, {TEXT("Ab7"), 3322.44}, 
{TEXT("A7"), 3520.0}, {TEXT("A#7"), 3729.31}, {TEXT("Bb7"), 3729.31}, {TEXT("B7"), 3951.07}, {TEXT("C8"), 4186.01}};

double NoteToFrequency(const WCHAR *name);

struct DrumSounds
{
	const TCHAR *name;
	int pos;
};

const DrumSounds drumsounds[] = { { TEXT("drum_1"), 0 },{ TEXT("drum_2"), 1 },{ TEXT("drum_3"), 2 },
{ TEXT("drum_4"), 3 },{ TEXT("drum_5"), 4 },{ TEXT("drum_6"), 5 },{ TEXT("drum_7"), 6 },
{ TEXT("drum_8"), 7 },{ TEXT("drum_9"), 8 },{ TEXT("drum_10"), 9 },{ TEXT("drum_11"), 10 },{ TEXT("drum_12"), 11 },
{ TEXT("drum_13"), 12 },{ TEXT("drum_14"), 13 },{ TEXT("drum_15"), 14 },
{ TEXT("drum_16"), 15 },{ TEXT("drum_17"), 16 },{ TEXT("drum_18"), 17 },{ TEXT("drum_19"), 18 },
{ TEXT("drum_20"), 19 }
};

int DrumToPosition(const WCHAR *name);