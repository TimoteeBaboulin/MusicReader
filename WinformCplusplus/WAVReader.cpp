#include "WAVReader.h"
#include <string>
#include "MyForm.h"
#include "Player.h"

void WAVReader::Play(const char* path)
{
	if (!ALFWLoadWaveToBuffer((char*)path, *Player::m_Buffer))
	{
		ALFWprintf("Failed to load %s\n", path);
	}
}
