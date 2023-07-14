#pragma once
#include "framework.h"
#include <thread>
#include <chrono>

constexpr float TargetFrames{ 30.0f };
constexpr float TargetFrameTime{ 1.0f / TargetFrames };

extern std::thread* _MainLoopThread;

class Application
{
public:
	static void init();
	static void update(float dt);
	static void draw();

	static bool isPaused();
	static void setPaused(bool paused);

private:
	global float s_deltaTime{ 1.0f };
	global bool s_paused;
};
