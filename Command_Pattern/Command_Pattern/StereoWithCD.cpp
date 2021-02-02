#include "StereoOnWithCD.h"

StereoOnWithCD::StereoOnWithCD(const std::shared_ptr<Stereo>& stereo)
	:stereo(stereo)
{

}


void StereoOnWithCD::execute()
{
	stereo->on();
	stereo->setCD();
	stereo->setVolume(11);
	// just 11 no reason
}

void StereoOnWithCD::undo()
{
	stereo->off();
}