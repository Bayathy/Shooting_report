#pragma once
#include <map>
#include <set>
#include <string>

class Sound
{
	std::map<std::wstring, std::wstring> sounds;
	std::set<std::wstring> requested;

	// Singleton �p�^�[���p
	// �R���X�g���N�^��private�ɂ���B
	Sound() = default;
	Sound(const Sound&) = delete;
	Sound(Sound&&) = delete;
	Sound& operator=(const Sound&) = delete;
	Sound& operator=(Sound&&) = delete;
	~Sound() = default;

public:

	void init();
	void cleanup();
	void play();

	void registerFile(const std::wstring& file, const std::wstring& alias);
	void request(const std::wstring& alias);

	// Singleton �p�^�[���p
	// �B��̃C���X�^���X�̃|�C���^�𓾂�B
	static Sound* getInstance();
};
