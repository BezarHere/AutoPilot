#include "Application.h"

using namespace std::chrono;
typedef steady_clock::time_point Time_t;

std::thread* _MainLoopThread;
Time_t _LastFrameTime;

void _MainLoop();

void Application::init()
{
	print("init!");
	s_deltaTime = TargetFrameTime;
	_MainLoopThread = new std::thread(_MainLoop);
	SetCursorPos(32, 32);
}

void Application::update(float dt)
{
	s_deltaTime = dt;
	
}

void Application::draw()
{
}

bool Application::isPaused()
{
	return s_paused;
}

void Application::setPaused(bool paused)
{
	s_paused = paused;
}

void _MainLoop()
{
	while (!Application::isPaused())
	{
		Time_t current_frame_time = steady_clock::now();
		// in seconds
		float dt = (float)(duration_cast<microseconds>(current_frame_time - _LastFrameTime).count()) / 1'000'000.0f;
		Application::update(dt);
		_LastFrameTime = current_frame_time;
		Sleep((DWORD)(TargetFrameTime * 1000.0f));
	}
}
