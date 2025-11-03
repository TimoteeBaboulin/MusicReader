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
	static void Init();
	static void Play(const char* _path);
	static void Pause();
	static void Resume();
	static void End();

private:
	static bool TryLoadOGG(const char* _path, OGGData* _data);
	static ALuint m_Buffer;
	static ALuint m_Source;
};

