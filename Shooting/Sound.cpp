#include <algorithm>
#include <windows.h>
#include <mmsystem.h>
#include "Sound.h"

#pragma comment(lib, "winmm.lib")	// MCI‚ªŠÜ‚Ü‚ê‚Ä‚¢‚é‚Ìƒ‰ƒCƒuƒ‰ƒŠ‚ðƒŠƒ“ƒN‚·‚é

using namespace std;


void Sound::init()
{
	cleanup();
}

void Sound::cleanup()
{
	mciSendString(TEXT("close all"), NULL, 0, NULL);
	sounds.clear();
	requested.clear();
}

void Sound::play()
{
	//	// c++98
	//	for (std::set<std::wstring>::const_iterator it = requested.begin(); it != requested.end(); it++) {
	//		wstring cmd = TEXT("play ") + *it + TEXT(" from 0");
	//		mciSendString(cmd.c_str(), NULL, 0, NULL);
	//	}


	//	// c++11
	//	for (auto it = requested.begin(); it != requested.end(); it++) {
	//		wstring cmd = TEXT("play ") + *it + TEXT(" from 0");
	//		mciSendString(cmd.c_str(), NULL, 0, NULL);
	//	}

	//	// c++11
	//	for (auto& r : requested) {
	//		wstring cmd = TEXT("play ") + r + TEXT(" from 0");
	//		mciSendString(cmd.c_str(), NULL, 0, NULL);
	//	}

		// c++11
	for_each(begin(requested), end(requested),
		[](const wstring& alias) {
			wstring cmd = TEXT("play ") + alias + TEXT(" from 0");
			mciSendString(cmd.c_str(), NULL, 0, NULL);
		});

	requested.clear();
}

void Sound::registerFile(const std::wstring& file, const std::wstring& alias)
{
	sounds[alias] = file;
	wstring cmd = TEXT("open ") + file + TEXT(" alias ") + alias;
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void Sound::request(const std::wstring& alias)
{
	//	// c++98
	//	requested.insert(alias);

		// c++11
	requested.emplace(alias);
}

Sound* Sound::getInstance()
{
	static Sound _instance;

	return &_instance;
}
