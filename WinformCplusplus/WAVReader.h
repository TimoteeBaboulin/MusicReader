#pragma once
#include"Framework.h"

static class WAVReader {
public:
	static void PlayMusic(const char* path);
	static void PauseMusic();
	static void ResumeMusic();
	static void StopMusic();
	static void ChangeVolume(float value);
private:
	static ALuint* uiBuffer;
	static ALuint* uiSource;
	static ALint* iState;
};