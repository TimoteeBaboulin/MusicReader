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

	ALsizei size = static_cast<ALsizei>(data.size);
	ALsizei freq = static_cast<ALsizei>(data.sampleRate);

	alBufferData(m_Buffer, format, data.data, static_cast<ALsizei>(data.size), static_cast<ALsizei>(data.sampleRate));
	alSourcei(m_Source, AL_BUFFER, m_Buffer);
	alSourcePlay(m_Source);
}

bool OGGReader::TryLoadOGG(const char* _path, OGGData* _data)
{
    OggVorbis_File oggFile;
    int result = ov_fopen(_path, &oggFile);
    if (result < 0)
        return false;

    vorbis_info* pInfo = ov_info(&oggFile, -1);
    if (!pInfo)
    {
        ov_clear(&oggFile);
        return false;
    }

    _data->channels = pInfo->channels;
    _data->sampleRate = pInfo->rate;

    // Get total PCM samples (per channel)
    ogg_int64_t totalSamples = ov_pcm_total(&oggFile, -1);
    if (totalSamples <= 0)
    {
        ov_clear(&oggFile);
        return false;
    }

    // bytes = samples * channels * 2 (16-bit)
    size_t bufferSize = static_cast<size_t>(totalSamples) * static_cast<size_t>(_data->channels) * 2u;

    _data->data = new char[bufferSize];
    if (!_data->data)
    {
        ov_clear(&oggFile);
        return false;
    }

    size_t totalRead = 0;
    int bitstream = 0;
    while (totalRead < bufferSize)
    {
        // ov_read takes an int length; clamp to INT_MAX if necessary
        long toRead = static_cast<long>(bufferSize - totalRead);
        if (toRead > INT_MAX) toRead = INT_MAX;

        long ret = ov_read(&oggFile, _data->data + totalRead, static_cast<int>(toRead), 0, 2, 1, &bitstream);
        if (ret < 0)
        {
            // read error
            delete[] _data->data;
            _data->data = nullptr;
            _data->size = 0;
            ov_clear(&oggFile);
            return false;
        }
        if (ret == 0)
            break; // EOF

        totalRead += static_cast<size_t>(ret);
    }

    _data->size = totalRead;
    ov_clear(&oggFile);
    return true;
}
