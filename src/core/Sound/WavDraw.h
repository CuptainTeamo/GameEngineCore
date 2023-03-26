#ifndef WAV_DRAW_H
#define WAV_DRAW_H

#include "StandardIncludes.h"

class Renderer;
class Asset;

#pragma pack(push, 1) // enable memory packing, set the smallest unit to 1 byte
typedef struct
{
	// RIFF Header
	char RIFFHeader[4];     // Contains "RIFF"
	unsigned int WavSize;   // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
	char WavHeader[4];      // contains "WAVE"

	// Format header
	char FMTHeader[4];				// contains "fmt " (include trailing space)
	unsigned int FMTChunkSize;		// Should be 16 for PCM
	unsigned short AudioFormat;		// Should be 1 for PCM. 3 for IEEE Float
	unsigned short NumChannels;		// 1 - Mono, 2 - Stereo
	unsigned int SampleRate;		// E.g., 44100 samples per second
	unsigned int ByteRate;			// Number of bytes per second. SampleRate * NumChannels * (BitDepth / 8)
	unsigned short SampleAlignment;	// num_channels * Bytes Per Sample
	unsigned short BitDepth;		// Number of bits per sample

	// Data
	char DataHeader[4];		// Contains "data"
	unsigned int DataBytes;	// Number of bytes in data. Number of samples * num_channels * saple byte size
} WAVHeader;
#endif // !WAV_DRAW_H

class WavDraw
{
public:
	// Constructor/Destructor
	WavDraw();
	virtual ~WavDraw();

	// methods
	void DrawWave(Asset* _rawWav, Renderer* _renderer, float _yZoom);

private:
	// Methods
	bool CompareFileExt(string _source, string _ext);
	void IntegrityChecks(Asset* _rawWav);

	//Members
	WAVHeader m_header;
	Asset* m_data;
	Point m_wSize;
	int m_stepSize;
	short* m_wavData;
	int m_xPos;
	Point m_prevLeft;
	Point m_prevRight;
};

