#ifndef SOUND_H
#define SOUND_H

#include <math.h>

namespace sound
{
	#define TWOPI 6.283185307

	short sineWave(double time, double freq, double amp)
	{
		short result;
		double tpc = 44100 / freq; // ticks per cycle
		double cycles = time / tpc; // cycle count
		double rad = TWOPI * cycles; // gives the radian of the wave
		short amplitude = 32767 * amp;
		result = amplitude * sin(rad);
		return result;
	}

	short squareWave(double time, double freq, double amp)
	{
		short result = 0;
		int tpc = 44100 / freq; // ticks per cycle
		int cyclepart = int(time) % tpc;
		int halfcycle = tpc / 2;
		short amplitude = 32767 * amp;
		if (cyclepart < halfcycle)
		{
			result = amplitude;
		}
		return result;
	}

	short noise(double amp)
	{
		short result = 0;
		short amplitude = 32767 * amp;
		result = rand() % amplitude;
		return result;
	}
}

#endif // SOUND_H