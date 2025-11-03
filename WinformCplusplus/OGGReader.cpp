#include "OGGReader.h"
#include <fstream>
#include <vorbis/vorbisfile.h>
#include <stdio.h>


void OGGReader::Init()
{
	alGenBuffers(1, &m_Buffer);
	alGenSources(1, &m_Source);
}

void OGGReader::Play(const char* _path)
{
	OGGData data;
	if (!TryLoadOGG(_path, &data))
	{
		return;
	}

	ALenum format;
	if (data.channels == 1)
		format = AL_FORMAT_MONO16;
	else if (data.channels == 2)
		format = AL_FORMAT_STEREO16;
	else
	{
		// Unsupported number of channels
		delete[] data.data;
		throw gcnew System::NotImplementedException();
	}

	alBufferData(m_Buffer, format, data.data, static_cast<ALsizei>(data.size), static_cast<ALsizei>(data.sampleRate));
	alSourcei(m_Source, AL_BUFFER, m_Buffer);
	alSourcePlay(m_Source);
}

bool OGGReader::TryLoadOGG(const char* _path, OGGData* _data)
{
	//std::ifstream file(_path, std::ios::binary);
	//FILE* file = nullptr;
	//errno_t error = fopen_s(&file, _path, "rb");
	//if (error != 0 || file == nullptr)
	//	return false;
	
	OggVorbis_File oggFile;
	if (ov_fopen(_path, &oggFile) < 0)
		return false;

	vorbis_info* pInfo = ov_info(&oggFile, -1);
	_data->channels = pInfo->channels;
	_data->sampleRate = pInfo->rate;

	// Read the entire OGG file into memory
	_data->data = new char[ov_pcm_total(&oggFile, -1) * _data->channels * 2];
	_data->size = ov_read(&oggFile, _data->data, _data->size, 0, 2, 1, nullptr);
	ov_clear(&oggFile);
	return true;
}
