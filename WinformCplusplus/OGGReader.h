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
	static void Play(const char* _path);

private:
	static bool TryLoadOGG(const char* _path, OGGData* _data);
};

