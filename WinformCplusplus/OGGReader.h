#pragma once

#include "Framework.h"

struct OGGData
{
	int channels;
	long sampleRate;
	char* data;
	size_t size;
};

class OGGReader
{
public:
	void Init();
	void Play(const char* _path);
private:
	bool TryLoadOGG(const char* _path, OGGData* _data);
	ALuint m_Buffer;
	ALuint m_Source;
};

