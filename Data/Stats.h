#pragma once
class stats{
public:
	int level(long double currentExp);
	int vit(int currentLv, int baseStat);
	int str(int currentLv, int baseStat);
	int dex(int currentLv, int baseStat);
	int inte(int currentLv, int baseStat);
	int wis(int currentLv, int baseStat);
	int hp(int currentLv, int baseStat);
	int mp(int currentLv, int baseStat);
	int atk(int currentLv, int baseStat);
	double holyRes(double baseRes);
	double slashingRes(double baseRes);
	double crushingRes(double baseRes);
};

