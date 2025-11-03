#pragma once
#include "Framework.h"

static class Player {
public:
	static int init();
	static void Play(const char* fileName, const char* extension, float volume);
	static void Resume();
	static void Pause();
	static void End();
	static void ChangeVolume(float value);
	static ALuint* m_Source;
	static ALuint* m_Buffer;
};



