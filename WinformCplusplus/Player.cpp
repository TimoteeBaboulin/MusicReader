#include "Player.h"
#include"Framework.h"
#include "OGGReader.h"

int init() {
	// Initialize Framework
	ALFWInit();
	if (!ALFWInitOpenAL())
	{
		ALFWShutdown();
		return 0;
	}
}

int Play(const char * fileName)
{
	OGGReader ouiPapa;
	ouiPapa.Init();
	ouiPapa.Play(fileName);
	return 0;
}
