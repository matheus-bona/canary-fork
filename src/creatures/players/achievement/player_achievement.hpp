/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2024 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#pragma once

class Player;
class KV;

struct Achievement {
	Achievement() { }

	std::string name;
	std::string description;

	bool secret = false;

	uint8_t grade = 0;
	uint8_t points = 0;

	uint16_t id = 0;
};

class PlayerAchievement {
public:
	explicit PlayerAchievement(Player &player);
	bool add(uint16_t id, bool message = true, uint32_t timestamp = 0);
	bool remove(uint16_t id);
	bool isUnlocked(uint16_t id) const;
	uint16_t getPoints() const;
	void addPoints(uint16_t toAddPoints);
	void removePoints(uint16_t toRemovePoints);
	std::vector<std::pair<uint16_t, uint32_t>> getUnlockedAchievements() const;
	void sendUnlockedSecretAchievements();
	const std::shared_ptr<KV> &getUnlockedKV();

private:
	// {achievement ID, time when it was unlocked}
	std::shared_ptr<KV> m_unlockedKV;
	std::vector<std::pair<uint16_t, uint32_t>> m_achievementsUnlocked;
	Player &m_player;
};
