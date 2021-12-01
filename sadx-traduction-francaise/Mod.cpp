#include "SADXModLoader.h"
#include <stdio.h>
const char MyString[] = "Ass";

//Arrays
DataArray(TitleCardTexture, SonicTitleCards, 0x91C358, 10);
DataArray(TitleCardTexture, TailsTitleCards, 0x91C3A8, 5);
DataArray(TitleCardTexture, KnucklesTitleCards, 0x91C3D0, 5);
DataArray(TitleCardTexture, AmyTitleCards, 0x91C3F8, 3);
DataArray(TitleCardTexture, BigTitleCards, 0x91C410, 4);
DataArray(TitleCardTexture, GammaTitleCards, 0x91C430, 5);
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
		// Chao Garden Hint Monitor
		WriteData((const char**)0x887738, "QUITTER");
		WriteData((const char**)0x887734, "SUIVANT");
		WriteData((const char**)0x887730, "RETOUR");
		
		// Unlock Chars
		WriteData((const char**)0x916998, "\tTu peux maintenant jouer avec TAILS");
		WriteData((const char**)0x9169AC, "\tTu peux maintenant jouer avec KNUCKLES");
		WriteData((const char**)0x9169D4, "\tTu peux maintenant jouer avec AMY");
		WriteData((const char**)0x9169E8, "\tTu peux maintenant jouer avec E-102");
		WriteData((const char**)0x9169FC, "\tTu peux maintenant jouer avec BIG");
		WriteData((const char**)0x4B5433, "\tTu peux maintenant jouer avec METAL SONIC \ndans la sélection de niveau");
		
		// Game menu messages
		WriteData((const char**)0x917DCC, "Restaurer les commandes par défaut ?"); // fr
		WriteData((const char**)0x917DE4, "Appuie sur ESC pour retourner en arrière"); // fr
		WriteData((const char**)0x917DF8, "Utiliser cette touche ?"); // fr
		WriteData((const char**)0x917E0C, "Appuie sur la touche à utiliser"); // fr
		WriteData((const char**)0x90C4A8, "Cette action mettra fin à la partie et renverra le\npersonnage à l'écran de sélection, continuer ?"); // fr
		WriteData((const char**)0x90C4BC, "Cette action mettra fin au niveau et\nte renverra à l'écran de sélection, continuer ?"); // fr
		WriteData((const char**)0x90C4D0, "Quitter la partie et retourner au Menu\nprincipal. continuer ?"); // fr
		WriteData((const char**)0x4B54DB, "'%s'\na été ajouté à la liste de jeux Game Gear."); // fr
		
		// New lure messages
		WriteData((const char**)0x9818A0, "\aPowerup de l'appât!"); // fr
		WriteData((const char**)0x9818A4, "\aUtilise le pour attraper de\nplus gros poissons !"); // fr
		
		// Keys messages
		WriteData((const char**)0x111C6A8, "\aLa clef flotte..."); // fr
		WriteData((const char**)0x111C680, "\aCela doit être une autre clef..."); // fr
		WriteData((const char**)0x7D3AB1, "\aUne statue en argent...\nElle ressemble à une clef."); // fr
		WriteData((const char**)0x7D3A72, "\aUne statue en or...\nElle ressemble à une clef."); // fr
		WriteData((const char**)0x7D3A2B, "\aLa Wind Stone. On dirait une clef.\nLe motif sur la pierre doit contenir un message."); // fr
		WriteData((const char**)0x7D39E0, "\aL'Ice Stone. On dirait une clef.\nJe pourrais peut être l'utiliser aux Mystic Ruins."); // fr
		WriteData((const char**)0x2BBF538, "\aL'Ice Stone... On dirait une clef.\nJe pourrais peut être l'utiliser aux Mystic Ruins."); // fr
		
		// Deleting file messages	
		WriteData((const char**)0x10D7A44, "\aValider"); // fr
		WriteData((const char**)0x10D7A0C, "\aAnnuler");
		WriteData((const char**)0x10D7A6C, "\aEffacer");
		
		WriteData((const char**)0x10D7954, "\t\tSupprimé."); // ак

		WriteData((const char**)0x10D7968, "\t\tLa suppression a échoué."); // fr
		
		// Monkey Detonator messages
		WriteData((const char**)0x111CB68, '\aÇa dit "destructeur de singes".'); // fr
		WriteData((const char**)0x111CB6C, "\a'Appuyez sur le bouton pour détruire le singe."); // fr
		WriteData((const char**)0x111CB38, "\aInterrupteur activé!"); // fr
		WriteData((const char**)0x111CB10, "\aLe bouton a été pressé,\nmais rien ne s'est passé."); // fr

		// Station Square cards messages
		WriteData((const char**)0x2BC07B8, "\aUne carte d'employé! Je peux l'utiliser\npour entrer dans ce bâtiment."); // fr
		WriteData((const char**)0x2BC07E0, "\aVérification de l'identité"); // fr
		WriteData((const char**)0x2BBF470, "\aUne carte-passe ! Je vais pouvoir faire\nle Twinkle Circuit."); // fr
		WriteData((const char**)0x2BBF468, "\aBienvenue à Twinkle Circuit!"); // fr
		
		// Tikal's messages
		WriteData((const char**)0x88C730, "\aPar ici!"); //  fr
		WriteData((const char**)0x803484, "\aAttention! Il prépare un mauvais coup."); // fr
		// Chaos 0  (when timer is 01:00:00)
		WriteData((const char**)0x7FD51C, "\aSautez et appuyez de nouveau sur le\nbouton de saut pour faire une Homing Attack!");
		// Chaos 2
		WriteData((const char**)0x7FD960, "\aVisez la tête de Chaos\nquand il ne s'y attend pas!");
		WriteData((const char**)0x7FD9B0, "\aPlanez ou utilisez la roulade\nau lieu de le frapper pour le battre!");
		WriteData((const char**)0x7FDA00, "\aFrappez les\nbulles d'eau!");
		// Chaos 4
		WriteData((const char**)0x7FE450, "\aQuand Chaos sort la tête de l'eau,\nattaquez-le.");
		// Chaos 6
		WriteData((const char**)0x7FEBA8, "\aEssayez de trouver un moyen\nde geler Chaos.");
		WriteData((const char**)0x7FEBF8, "Jetez les bombes d'Eggman\ndans la bouche de Chaos.");
		WriteData((const char**)0x7FEC48, "\aVisez la grenouille\npuis lancez votre ligne!"); // fr
		WriteData((const char**)0x7FECA8, "\aLancez votre ligne");
		WriteData((const char**)0x7FECB0, "\aquand Chaos s'approche de vous");
		
		// Egg Walker
		WriteData((const char**)0x801D54, "\aL'Egg Mobile est son point faible.\nAttaquez-la quand elle s'approche de vous.");
		WriteData((const char**)0x802D00, "\aVisez-les jambes\npour qu'il perde l'équilibre.");
		WriteData((const char**)0x802D10, "\aMais ne visez pas que les jambes.\nVisez aussi le cockpit!");

		// Egg Viper
		WriteData((const char**)0x803444, "\aEggman est de l'autre côté\nlà où l'énergie se rassemble.");
		WriteData((const char**)0x803454, "\aFaites plusieurs Homing Attack...");
		WriteData((const char**)0x803464, "\aEt visez le cockpit.");
		
		// if you take damage twice from a spinning thing
		WriteData((const char**)0x803474, "\aMontez sur la toupie à épines\net vous arriverez jusqu'au cockpit.");
		
		// ZERO (when timer is 01:00:00)
		WriteData((const char**)0x8046E4, "\aIl doit bien avoir un point faible.");
		WriteData((const char**)0x8046EС, "\aContinuez de l'attaquer jusqu'à \nce que vous le trouviez!");
		
		// Perfect Chaos
		WriteData((const char**)0x800544, "\aQuand vous atteindrez votre vitesse maximale,\nvous deviendrez une boule électrique.");
		WriteData((const char**)0x80054C, "\aC'est avec ça que vous parviendrez à attaquer Chaos!");

		//Mission tutorial texts
		#region fr
		WriteData((const char**)0x2BC57B8, "Ton but est de trouver ");
		WriteData((const char**)0x2BC57BC, "\"l'enveloppe de mission\"");
		WriteData((const char**)0x2BC57C0, "puis de la compléter");
		WriteData((const char**)0x2BC57C4, "dans le monde du jeu");
		WriteData((const char**)0x2BC57C8, "grâce au conseil affiché.");
		
		WriteData((const char**)0x2BC57CC, "Le conseil s'affichera en");
		WriteData((const char**)0x2BC57D0, "touchant \"l'enveloppe de");
		WriteData((const char**)0x2BC57D4, "mission\". Tu devras alors deviner");
		WriteData((const char**)0x2BC57D8, "l'endroit où il faut aller et");
		WriteData((const char**)0x2BC57DC, "ce qu'il faut faire pour réussir cette mission.");

		WriteData((const char**)0x2BC57E0, "Il existe 60 missions et");
		WriteData((const char**)0x2BC57E4, "6 personnages pour les compléter (Sonic, Tails,");
		WriteData((const char**)0x2BC57E8, "Knuckles, Amy, E-102,");
		WriteData((const char**)0x2BC57EC, "Big).");

		//Init stuff
		WriteData((const char**)0x40BE98, "Sauvegarde...");
		WriteData((const char**)0x40BE09, "Chargement...");
		WriteData((const char**)0x50342D, "Chargement...");
		WriteData((const char**)0x503469, "Chargement...");
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
		GammaTitleCards[4].TextureName = "e_stage05_f";
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
