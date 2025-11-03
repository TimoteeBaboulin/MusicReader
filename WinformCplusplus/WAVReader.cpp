#include "WAVReader.h"
#include <string>
#include "MyForm.h"

ALuint* WAVReader::uiBuffer = new ALuint;
ALuint* WAVReader::uiSource = new ALuint;
ALint* WAVReader::iState = new ALint;

void WAVReader::PlayMusic(const char* path)
{
	// Generate an AL Buffer
	alGenBuffers(1, uiBuffer);

	// Load Wave file into OpenAL Buffer
	if (!ALFWLoadWaveToBuffer((char*)path, *uiBuffer))
	{
		ALFWprintf("Failed to load %s\n", path);
	}

	// Generate a Source to playback the Buffer
	alGenSources(1, uiSource);

	// Attach Source to Buffer
	alSourcei(*uiSource, AL_BUFFER, *uiBuffer);
	//pour boucler un son
	alSourcei(*uiSource, AL_LOOPING, 1);
	// Play Source
	alSourcePlay(*uiSource);
}

void WAVReader::PauseMusic()
{
	alSourcePause(*uiSource);
}

void WAVReader::ResumeMusic()
{
	alSourcePlay(*uiSource);
}

void WAVReader::StopMusic()
{
	alSourceStop(*uiSource);
}

void WAVReader::ChangeVolume(float value)
{
	alSourcef(*uiSource, AL_GAIN, value);
}
