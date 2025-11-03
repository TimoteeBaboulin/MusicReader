#include "Player.h"
#include"Framework.h"
#include "OGGReader.h"
#include "WAVReader.h"

ALuint* Player::m_Source = new ALuint;
ALuint* Player::m_Buffer = new ALuint;

int Player::init() {
	// Initialize Framework
	ALFWInit();
	if (!ALFWInitOpenAL())
	{
		ALFWShutdown();
		return 0;
	}
}

void Player::Play(const char * fileName, const char* extension, float volume)
{
	if (*m_Source == 0 || *m_Buffer == 0)
		return;

	ALint* sourceState = new ALint;
	alGetSourcei(*m_Source, AL_SOURCE_STATE, sourceState);
	if (*sourceState == AL_PLAYING) 
	{
		End();
		alDeleteSources(1, m_Source);
		alDeleteBuffers(1, m_Buffer);
	}

	alGenBuffers(1, m_Buffer);

	if(!strcmp(extension, "OGG"))
	{
		OGGReader::Play(fileName);
	}
	else if (!strcmp(extension, "WAV"))
	{
		WAVReader::Play(fileName);
	}
	alGenSources(1, m_Source);

	alSourcei(*m_Source, AL_BUFFER, *m_Buffer);
	ChangeVolume(volume);
	alSourcePlay(*m_Source);
}

void Player::Pause()
{
	if (*m_Source == 0) return;
	ALint* value = new ALint;
	alGetSourcei(*m_Source, AL_SOURCE_STATE, value);
	if (*value != AL_PLAYING)
		return;

	alSourcePause(*m_Source);
}

void Player::Resume()
{
	if (*m_Source == 0) return;
	ALint* value = new ALint;
	alGetSourcei(*m_Source, AL_SOURCE_STATE, value);
	if (*value != AL_PAUSED)
		return;
	alSourcePlay(*m_Source);
}

void Player::End()
{
	if (*m_Source == 0) return;

	alSourceStop(*m_Source);
}

void Player::ChangeVolume(float value)
{
	alSourcef(*m_Source, AL_GAIN, value);
}
