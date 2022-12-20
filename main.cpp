#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "sound.h"

using namespace std;

int main()
{
	// defines size of our window using sf class
	sf::RenderWindow window(sf::VideoMode(800, 600), "myWindow");

	sf::SoundBuffer buffer;  // this is our buffer
	vector<sf::Int16> samples; // vector holds all of our samples

	// this generates our samples
	for (int i = 0 ; i < 44100 ; i++)
	{
		samples.push_back(sound::sineWave(i, 440, 0.9)); // sinewave
		samples.push_back(sound::squareWave(i, 440, 0.9)); // square wave
		samples.push_back(sound::noise(0.9)); // white noise
	}

	// load our buffer
	buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	// here our window is open
	while (window.isOpen())
	{
		sf::Event event;

		// allows window to be closed
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
	return(0);
}