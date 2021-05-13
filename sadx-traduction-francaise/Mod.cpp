#include "SADXModLoader.h"
#include <stdio.h>
const char MyString[] = "Ass";

//Arrays
DataArray(TitleCardTexture, SonicTitleCards, 0x91C358, 10);
DataArray(TitleCardTexture, TailsTitleCards, 0x91C3A8, 5);
DataArray(TitleCardTexture, KnucklesTitleCards, 0x91C3D0, 5);
DataArray(TitleCardTexture, AmyTitleCards, 0x91C3F8, 3);
DataArray(TitleCardTexture, BigTitleCards, 0x91C410, 4);
DataArray(TitleCardTexture, GammaTitleCards, 0x91C430, 4);
DataArray(TitleCardTexture, AdventureTitleCards, 0x91C458, 9);
DataArray(TitleCardTexture, SubgameTitleCards, 0x91C4A0, 5);

//Macros
#define ReplacePNG_Common(a) do { \
	_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\pvrs\\index.txt", path); \
	helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)

#define ReplacePNG_StageS(a) do { \
	_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\pvr_stage_fr\\index.txt", path); \
	helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Init stuff
		WriteData((const char**)0x504B5B, "Nouvelle Partie");
		WriteData((const char**)0x5482A8, "Chaos 0");
		WriteData((const char**)0x54CCFE, "Chaos 2");
		WriteData((const char**)0x5509DC, "Chaos 4");
		WriteData((const char**)0x559872, "Chaos 6");
		WriteData((const char**)0x56037F, "Perfect Chaos");
		WriteData((const char**)0x587DA4, "ZERO");
		WriteData((const char**)0x62616D, "MEILLEUR SCORE");
		WriteData((const char**)0x626215, "DOCTEUR EGGMAN");
		WriteData((const char**)0x626279, "COMMENCER");
		WriteData((const char**)0x6262C9, "TEMPS");
		WriteData((const char**)0x6262D8, "COMPTEUR");
		WriteData((const char**)0x626401, "GAME OVER");
		WriteData((const char**)0x626458, "BRAVO");
		WriteData((const char**)0x6264C0, "TU REMPORTES LA PLUME DU GUERRIER");
		WriteData((const char**)0x6264D3, "TU REMPORTES LE GROS MARTEAU");
		WriteData((const char**)0x62652A, "TU AS LE MEILLEUR SCORE");
		WriteData((const char**)0x6283F5, "GAME OVER");
		WriteData((const char**)0x7595DF, "APPUIE SUR A POUR ABANDONNER LE CHAO");
		char pathbuf[MAX_PATH];
		HMODULE HDGUI = GetModuleHandle(L"HD_GUI");
		//PVRs
		ReplacePNG_Common("ST_064S_SCORE");
		ReplacePNG_Common("HYOJI_BALLS_E");
		//Replace stage titlecard filenames
		//Sonic
		SonicTitleCards[0].TextureName = "s_stage01_f";
		SonicTitleCards[1].TextureName = "s_stage02_f";
		SonicTitleCards[2].TextureName = "s_stage03_f";
		SonicTitleCards[3].TextureName = "s_stage04_f";
		SonicTitleCards[4].TextureName = "s_stage05_f";
		SonicTitleCards[5].TextureName = "s_stage06_f";
		SonicTitleCards[6].TextureName = "s_stage07_f";
		SonicTitleCards[7].TextureName = "s_stage08_f";
		SonicTitleCards[8].TextureName = "s_stage09_f";
		SonicTitleCards[9].TextureName = "s_stage10_f";
		//Tails
		TailsTitleCards[0].TextureName = "m_stage01_f";
		TailsTitleCards[1].TextureName = "m_stage02_f";
		TailsTitleCards[2].TextureName = "m_stage03_f";
		TailsTitleCards[3].TextureName = "m_stage04_f";
		TailsTitleCards[4].TextureName = "m_stage05_f";
		//Knackels
		KnucklesTitleCards[0].TextureName = "k_stage01_f";
		KnucklesTitleCards[1].TextureName = "k_stage02_f";
		KnucklesTitleCards[2].TextureName = "k_stage03_f";
		KnucklesTitleCards[3].TextureName = "k_stage04_f";
		KnucklesTitleCards[4].TextureName = "k_stage05_f";
		//Amy
		AmyTitleCards[0].TextureName = "a_stage01_f";
		AmyTitleCards[1].TextureName = "a_stage02_f";
		AmyTitleCards[2].TextureName = "a_stage03_f";
		//Big
		BigTitleCards[0].TextureName = "b_stage01_f";
		BigTitleCards[1].TextureName = "b_stage02_f";
		BigTitleCards[2].TextureName = "b_stage03_f";
		BigTitleCards[3].TextureName = "b_stage04_f";
		//Gamma
		GammaTitleCards[0].TextureName = "e_stage01_f";
		GammaTitleCards[1].TextureName = "e_stage02_f";
		GammaTitleCards[2].TextureName = "e_stage03_f";
		GammaTitleCards[3].TextureName = "e_stage04_f";
		//Adventure Fields
		AdventureTitleCards[0].TextureName = "t_stationsquare_f";
		AdventureTitleCards[1].TextureName = "t_stationsquare_f";
		AdventureTitleCards[2].TextureName = "t_stationsquare_f";
		AdventureTitleCards[3].TextureName = "t_eggcarrier_f";
		AdventureTitleCards[4].TextureName = "t_eggcarrier_f";
		AdventureTitleCards[5].TextureName = "t_eggcarrier_f";
		AdventureTitleCards[6].TextureName = "t_eggcarrier_f";
		AdventureTitleCards[7].TextureName = "t_misticruin_f";
		AdventureTitleCards[8].TextureName = "t_misticruin_f";
		//Subgames
		SubgameTitleCards[0].TextureName = "St_stage03_f";
		SubgameTitleCards[1].TextureName = "St_stage01_f";
		SubgameTitleCards[2].TextureName = "St_stage02_f";
		SubgameTitleCards[3].TextureName = "St_stage04_f";
		SubgameTitleCards[4].TextureName = "St_stage05_f";
		//Replace PVRs with HD PNGs if HD GUI is detected
		//Spanish stage PVRs
		if (HDGUI)
		{
			ReplacePNG_Common("ST_064S_SCORE");
			ReplacePNG_Common("HYOJI_BALLS_E");
			ReplacePNG_StageS("A_STAGE01_F");
			ReplacePNG_StageS("A_STAGE02_F");
			ReplacePNG_StageS("A_STAGE03_F");
			ReplacePNG_StageS("B_STAGE01_F");
			ReplacePNG_StageS("B_STAGE02_F");
			ReplacePNG_StageS("B_STAGE03_F");
			ReplacePNG_StageS("B_STAGE04_F");
			ReplacePNG_StageS("E_STAGE01_F");
			ReplacePNG_StageS("E_STAGE02_F");
			ReplacePNG_StageS("E_STAGE03_F");
			ReplacePNG_StageS("E_STAGE04_F");
			ReplacePNG_StageS("E_STAGE05_F");
			ReplacePNG_StageS("K_STAGE01_F");
			ReplacePNG_StageS("K_STAGE02_F");
			ReplacePNG_StageS("K_STAGE03_F");
			ReplacePNG_StageS("K_STAGE04_F");
			ReplacePNG_StageS("K_STAGE05_F");
			ReplacePNG_StageS("M_STAGE01_F");
			ReplacePNG_StageS("M_STAGE02_F");
			ReplacePNG_StageS("M_STAGE03_F");
			ReplacePNG_StageS("M_STAGE04_F");
			ReplacePNG_StageS("M_STAGE05_F");
			ReplacePNG_StageS("ST_STAGE01_F");
			ReplacePNG_StageS("ST_STAGE02_F");
			ReplacePNG_StageS("ST_STAGE03_F");
			ReplacePNG_StageS("ST_STAGE04_F");
			ReplacePNG_StageS("ST_STAGE05_F");
			ReplacePNG_StageS("S_STAGE01_F");
			ReplacePNG_StageS("S_STAGE02_F");
			ReplacePNG_StageS("S_STAGE03_F");
			ReplacePNG_StageS("S_STAGE04_F");
			ReplacePNG_StageS("S_STAGE05_F");
			ReplacePNG_StageS("S_STAGE06_F");
			ReplacePNG_StageS("S_STAGE07_F");
			ReplacePNG_StageS("S_STAGE08_F");
			ReplacePNG_StageS("S_STAGE09_F");
			ReplacePNG_StageS("S_STAGE10_F");
			ReplacePNG_StageS("T_EGGCARRIER_F");
			ReplacePNG_StageS("T_MISTICRUIN_F");
			ReplacePNG_StageS("T_STATIONSQUARE_F");
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}
