#pragma once
#include "stdafx.h"
#include "Consts.h"

const int mapHeight = 44;

class Map
{
	std::vector<b2Body*> bodyList;

	//blocks
	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	//ascents
	sf::Sprite rightAscentSprite;
	sf::Texture rightAscentTextureSheet;

	sf::Sprite leftAscentSprite;
	sf::Texture leftAscentTextureSheet;
	
	//rings
	sf::Sprite topRingSprite;
	sf::Sprite catchedTopRingSprite;
	sf::Texture topRingTextureSheet;
	sf::Texture catchedTopRingTextureSheet;

	sf::Sprite bottomRingSprite;
	sf::Sprite catchedBottomRingSprite;
	sf::Texture bottomRingTextureSheet;
	sf::Texture catchedBottomRingTextureSheet;

	std::vector<sf::Vector2f> ringsPositions;

	//Wather
	sf::RectangleShape watherSprite;
	std::vector<sf::Vector2f> watherPositions;
	bool inWather = false;

	//Thorns
	sf::Sprite thornSprite;
	sf::Sprite invertedThornSprite;
	sf::Texture thornTextureSheet;
	std::vector<sf::Vector2f> thornsPositions;

	//Checkpoints
	sf::Sprite checkpointSprite;
	sf::Texture checkpointTextureSheet;

	sf::Sprite catchedCheckpointSprite;
	sf::Texture catchedCheckpointTextureSheet;

	std::vector<sf::Vector2f> checkpointsPositions;

	//Bonus life
	sf::Sprite bonusLifeSprite;
	sf::Texture bonusLifeTextureSheet;

	std::vector<sf::Vector2f> bonusLivesPositions;
	
	//Sounds
	sf::SoundBuffer takeRingBuffer;
	sf::Sound takeRingSound;

	sf::SoundBuffer takeItemBuffer;
	sf::Sound takeItemSound;

	//Interface
	int ringsCounter = 0;

	//Statistics
	int score = 0;
	int maxScore = 0;
	int maxLives = 3;

	std::string map[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B   P BB                                                 B",
		"B     BB     OC                                          B",
		"B     BBWWWWWBB    l                                     B",
		"B BBB BBWWWWWBB                                          B",
		"B     BBBBBBBBB     BB                                   B",
		"B                                                        B",
		"B                                                        B",
		"B                BB                                      B",
		"B                                                        B",
		"BTTTTTBB                                                 B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelOne[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O        O       O   B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTwo[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B       T   T   T   T   T    O  B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelThree[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B   P                    BBBBBBBBBBBBBBBBBBBBBB",
		"B                        BBBBBBBBBBBBBBBBBBBBBB",
		"B                               BBBBBBBBBBBBBBB",
		"B                          l  O BBBBBBBBBBBBBBB",
		"B                        BBBBBBBBBBBBBBBBBBBBBB",
		"B                        BBBBBBBBBBBBBBBBBBBBBB",
		"B                                             B",
		"B                   C                         B",
		"B                     T    T   T   O      O   B",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B           O    WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B         T   T  WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFour[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBP  BBBBBB          BBB         BB         BBB                   BBB      BB  l   BB               BB         BBB",
		"BB   BBBBBB          BBB                    BB                     BB      BB      BB            O  BB  O      BBB",
		"BB   BBBBBB   BB     BBB         O          BB                     BB  BB  BB  BB  BB  BB       BB  BB  BB     BBB",
		"BB   BBBBBB   BB     BBB  BBBB  BBBB  BBBB  BB          C          BB  BB  BB  BB  BB  BB       BB  BB  BB     BBB",
		"BB            BB          BB     BB     BB                             BB      BB      BB    BBTBB      BBTBB    B",
		"BB       O    BB T        BB  T     T   BB         T  T   T   T        BB  O   BB  O   BB    BBBBB  O   BBBBB  O B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFive[mapHeight] = {
		"                                                                                                               BBBBBBBBBBBBBBBBBBBBBBBB",
		"                                                                                                               BBC                   BB",
		"                                                                                                               BB                    BB",
		"                                                                                                               BB        O           BB",
		"                                                                                                               BBBBBBBBBBBBBB        BB",
		"                                                                                                               BB                    BB",
		"                                                                                                               BB                    BB",
		"                                                                                                               BB   BBBBBBBBBBBBBBBBBBB",
		"                                                                                                               BB                    BB",
		"                                                                                                               BB                    BB",
		"                                                                                                               BBBB      BB  BB      BB",
		"                                                                                                               BBC      BB    BB     BB",
		"                                                                                                               BB      BB      BB    BB",
		"                                                                                                               BB     BB   T    BB   BB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BB",
		"BB       P                BB      BB                           BB   BB       C           BB         BB             BB         BB     BB",
		"BB                    O   BB      BB     O                     BB   BB                   BB         BB         O   BB         BB  O  BB",
		"BB             BBBBBBBBB  BB  BB         BBBBB                 tt   BB        RL         BB   T                BB  BB    BB   BB  BBBBB",
		"BB             BB     BB  BB  BB         BBBBB       RL             BB       RBBL        BB   BB    O          BB  BB  BBBB          BB",
		"BB             BB  l          BB         BBBBB      RBBL                    RBBBBL            BB    BB         BB      l BB          BB",
		"BB           T BB             BB T       BBBBB     RBBBBL   T  TT   O      RBBBBBBL      O    BB    BBBTBTBTBTBBB        BB        T BB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"

		
	};

	std::string levelSix[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBt t   l BBC                               BB                B   BB        BBBBB                                                  l B",
		"BB        BB                                BB      P      O  B   BB        BBBBB                                BB  BB              B",
		"BB        BBL        RBB                                  RBBBB                                                                      B",
		"BB        BBBL      RBBB                    O            RBB      O             O                                  BB       BB   BB  B",
		"BB        BBBBL    RBBBB                   RBB          RB        BB       RBBBBBL    RBBL     RBBBBBBBBBBBBBBBB       BB      BB   B",
		"BB        BBBBBL  RBBBBB                  RBBB         RBB O      BBB     RBBBBBBBL   RBBBBLWWWRBBBBBBBBBBBBBBBBB          BBTT    T B",
		"BBBBB     BBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BB                             BB    BB               t      t BBBBBBBt BBBBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"BB                             BB    BB                         BBBBB    BBBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"BB    BB                                                         BBB      BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"BB    t   BBLWWWWWWWWRBBBBTT   O     O      BBL                   BB      BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"BB        BBBLWWWWWWRBBBBBBB   BB    BB     BBBL                          BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"BB        BBBBLWWWWRBBBBBBBB   BB    BBT   TBBBBL   T   T   T             BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBL     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                     BB                    BB                    BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                     BBBBBBBBBBBBBBBBB     BB                    BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                     BBC                   BB                    BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                     BB                    BB                    BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                     BBBBBBBBBBBBBBBBBBBBBBBB                    BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB C   BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB C   BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB C   BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                 C  B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     BBBBBBBBBBBBBBBBBBWWWBBBBBBBBBBBBBBBBBB                    B",
		"B                                                                 BBB     WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW          T T         B",
		"B                                                                 BBB     OWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWO        BBBB      O  B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

	};

	std::string levelSeven[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                    BBB               BBBBB	                                                                                     ",
		"B                    BBB               BBBBB	                                                                                     ",
		"B                    B                 BBBBB	                                                                                     ",
		"B                    B O               BBBBB	                                                                                     ",
		"B                    BBBL              BBBBB	                                                                                     ",
		"B                    BBBBBBBBBBB          BB	                                                                                     ",
		"B                    BBBBBBBBBBB          BB	                                                                                     ",
		"B                    BB                   BB	                                                                                     ",
		"B                    BB          T        BB	                                                                                     ",
		"B                    BB         BBBBBBBBBBBB	                                                                                     ",
		"BBBBBBBBBBBBBBBBBBBBBBB                   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                      ",
		"BC                                                                                                          BB                      ",
		"B                                                                                                           BB                      ",
		"B                                                 BBL  RBB              O  O          BB                    BB                      ",
		"B                            BBBBBBBBL         R  BBBLRBBB  L           BBBB          BB      BB    BB      BB                      ",
		"B                            BBBBBBBBBL       RB  BB    BB  BL     RT L  BB   RT L    BB      BB    BB      BB                      ",
		"Bl O  T  T  T  T  T  T  T    BBBBBBBBBBL     RBBTTBB    BBTTBBL   RBBBBL T   RBBBBL   BB  T   BB    BB      BB                      ",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"                  B    BB WW  t  WW BB                                                BBBBttBBBB  P BBBBttBBBBC                 C BB",
		"                  B l  BB WW     WW BB                                                BBBBWWBBB      BBBWWBBBB                    BB",
		"                  B    BB WW     WW BB    BB                       BB  BB    BB  BB   BBBBWWBB  RBBL  BBWWBBBBBBBB          BBBBBBBB",
		"                  B    BB WW     WW BB    BB    R    L R   L        BBBB  C   BBBB    BBBBWWB  RBBBBL  BWWBBBBBBBB          BBBBBBBB",
		"                  B       WW     WW       BB   RB    BLB   BL       BBBB      BBBB        WW  RBBBBBBL  WW                      t BB",
		"                  B       WW  T  WW       BB     BBBB   BBB         BBBBBBBBBBBBBB        WW RBBBBBBBBL WW      O   TT  TT   O  T BB",
		"                  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelEight[mapHeight] = {
		"                      BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                      ",
		"                      BB                                           BB                      ",
		"                      BB                                           BB                      ",
		"                      BB   BB  BB  BB  BBBBBBBBBBBBBBBBBBBBBBBBBBWWBB                      ",
		"                      BB               BB   BBBBBBBBBBBBBBBBBBBBBWWBB                      ",
		"                      BB                     BBBBBBBBBWWWWWWWWWWWWWBB                      ",
		"                      BB     T   T   T       BBBBBBBBBWWWWWWWWWWWWWBB                      ",
		"                      BB   BBBBBBBBBBBBBBBBBBBBBBBBBBBWWBBBBBBBBBBBBB                      ",
		"                      BB      B         B    BBBBBBBBBWWBB   BBBBBBBB                      ",
		"                      BB           C         BBBBBBBBBWWB  C  BBBBBBB                      ",
		"                      BB 	            O      WWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB      O        RBL     WWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BBBBBB  BB  BBB   BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB      BB  BBBBBBBBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB      BB  BBBBBBBBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BBB  BB      BB        BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB      BB      O BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB    C BBBBBB  BBBBWWWWWWWWWOWWWWWWWWWWBB                      ",
		"                      BB   BB      BBBBBB  BBBBWWWWWWWBBBWWWWWWWWWWBB                      ",
		"                      BB  BBB      BB      BBBBWWWWWWWWWWWWWWWWOWWWBB                      ",
		"                      BB   BB   BBBBB      BBBBWWWWOWWWWWWWWWBBBWWWBB                      ",
		"                      BB   BB   BBBBB    BBBBBBWWBBBWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB      BB    BBBBBBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BBB  BB      BB        BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB      BB        BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BB      BBBBBB    BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB   BBBB    BBBBBB    BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"                      BB  BBB      BB        BBWWWWWWWWWWWWWWWWWWWWBB                      ",
		"BBBBBBBBBBBBBBBBBBBBBBBB   BB      BB        BBWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBB",
		"BB        BBB        BBB   BB      BB    l   BBWWWWWWWWWWWWWWWWWWWWBB                  BBBB",
		"BB        BB          BBC  BB      BB        BBWWWWWWWWWWWWWWWWWWWWBB    O               BB",
		"BB        BB    O     BBB  BB   BBBBB    RBBLBBWWWWWWWWWWWWWWWWWWWWBB                  O BB",
		"BB   BB   BB          BB   BB    P BBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBBBBBBBBBBBBBBB",
		"BBB  BB        BBBB                BBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWRB       C        BB",
		"BB   BB        BBBB                BBBBBBBBBBBBWWWWTTWWWWWWWWWWTTWWWWWRBB                BB",
		"BB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBB   BB",
		"BB  BBB                                                                                  BB",
		"BB   BB               BBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBLWWWWWWWWWWWWWBB",
		"BB   BB               BBBBTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTBBBBBBBWWWWWWWWWWWWWBB",
		"BBB  BB               BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWBB",
		"BB                 C  BBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BB                    BBl WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BB T BBBBBBBBBBBBBL   BB  WWWWWWTWWWWWTWWWWWTWWWWWTWWWWWTWWWWWTWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"

	};

	std::string levelNine[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBB                                                                                         ",
		"BBl                   BB                                                                                         ",
		"BB                  O BB                                                                                         ",
		"BB                 RBBBB                                                                                         ",
		"BB  O       BB  BBBBBBBB                                                                                         ",
		"BB  BB                BB                                                                                         ",
		"BB                    BB                                                                                         ",
		"BB                    BB                                                                                         ",
		"BB        BB          BB                                                                                         ",
		"BB                    BB                                                                                         ",
		"BB                O   BB                                                                                         ",
		"BB               BB   BB                                                                                         ",
		"BB           BB       BB                                                                                         ",
		"BB                    BB                                                                                         ",
		"BB                    BB                                                                                         ",
		"BB                    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BB                                          BBBBB       P        BBBBBBBB          t          BB       BB      BB",
		"BB               BB                         BBBB                  BBBBBB                      BB       BB  O   BB",
		"BB                         RBBBL   RBBBBL   BBB                    BBBB                   BB  BB       BB  BB  BB",
		"BBBBBBL      BB           RBBBBB   BBl      BB       R      L       BB             C      BB  BB       BB  BB  BB",
		"BBBBBBBL                 RBBBBBB   BB               RB      BL                            BB      BBB      BB  BB",
		"BBBBBBBBL               RBBBBBBBTTTBBBBBB          RBB      BBL          T    T       T   BB      BBB      BBTTBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB      BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBt C        BBBBBB             tt                                                                  tt        BBB",
		"BB           BBBBBB             WW                                                                  WW        CBB",
		"BBT          BBBBBB   BBB  L    WW    R  BBBLWWWWWWWRB  BB  BLWWWWWWRL                              WW         BB",
		"BBBBBBBBBB            BBB  BL   WW   RB  BBBBLWWWWWWBB      BBWWWWWRBBL       RL       BBBBL        WW        OBB",
		"BBBBBBBBBB            BBBTTBBL  WW  RBBTTBBBBBWWWWWWBB      BBWWWWWBC         BB       BBBBBL       WW       RBBB",
		"BBBBBBBBBB            BBBBBBBBL WW RBBBBBBBBBBWWWWWWBB      BBWWWWWB     T  T BB       BBBBBBL T    WW    T RBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTen[mapHeight] = {
		"                    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"                    BBBBBB  B   t t t     C   t                 BB         WWBB   BB                        BB",
		"                    BBBBBB      W   W                           BB       O WWBB   BB                        BB",
		"                    BBBBBB  O   W   W              BBBLWWWWWWWWWBB   BB  BBWWBB   BB                        BB",
		"                    BBBBBB  L   W   W   RBBB       BBBBWWWWWWWWWBB   BB  BBWWBB   BB  BBBBBBBBBB    BBBBBBBBBB",
		"                    BBBBBB  BL  W   W  RBBBB       BBBBWWWWWWWWW     BB  BBWW       C BB         C          BB",
		"                    BBBBBB  BBL W T W RBBBBB  T    BBBBWWWWWWWWWO    BBTBBBWW O       BB  O              O  BB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBB  BB",
		"BBP                 BB                    BB  t               t                     CBBB     tt      tt     BB",
		"BB               O  BB                    BB                                         BBB     WW      WW     BB",
		"BBBB             BBBBB    BBBLWWWWWWWWWWWWBB                          RL        R  BBBBBB    WW      WW    BBB",
		"BBBB                BB    BBBBWWWWWWWWWWWWBB                         RBBL      RB  BBBBB     WW      WW     BB",
		"BB                        BBBBWWWWWWWWWWWW      RL    RL    RL      RBBBBL    RBB  BBBBB     WW      WW     BB",
		"BB O                      BBBBWWWWWWWWWWWO     RBBLT RBBLT RBBL    RBBBBBBL  RBBBTTBBBBBBBL  WW      WW  RBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWBBBBBBBBBBBBBBBBBBB    BBBBBBBBBB",
		"                                                                BBBBBBBBBBBWWBBBBBBBBBBB                    BB",
		"                                                                BBBBBBBBBBBWWBBBBBBBBBBB                    BB",
		"                                                                BBBBBBBBBBBWWBBBBBBBBBBB                    BB",
		"                                                                BBBBBBBBBBBWWBBBBBBBBBBB                    BB",
		"                                                                BBBBBBBB   WW   BBBBBBBB                    BB",
		"                                                                BBBBBBBBl  WWC  BBBBBBBB    RBBBBBBBBBBL    BB",
		"                                                                BBBBBBBB   WW O BBBBBBBB    BBBBBBBBBBBB    BB",
		"                                                                BBBBBBBBBBBWWBBBBBBBBBBB                    BB",
		"                                                                BBBBBBBBBBBWW          BB                  BBB",
		"                                                                BBBBBBBBBBBWW	      	                     BB",
		"                                                                BBBBBBBBBBBWW T   T           BB    BB      BB",
		"                                                                BBBBBBBBBBBWWBBBBBBBBBBB   T  BB    BB T  O BB",
		"                                                                BBBBBBBBBBBTTBBBBBBBBBBBBBBBBBBB l  BBBBBBBBBB",
		"                                                                BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelEleven[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BB                                                                                                          BB",
		"BB                                                                                                          BB",
		"BB                                                                                                          BB",
		"BB                                                    RL                                                    BB",
		"BB                                                   RBBL                                                   BB",
		"BB                                                  RB lBL                                                  BB",
		"BB                                                 RB    BL                                                 BB",
		"BB                                                RB   BBBBL                                                BB",
		"BB                                               RB        BL                                               BB",
		"BB                                              RB  BB      BL                                              BB",
		"BB                                             RB            BL                                             BB",
		"BB                                            RB          BBBBBL                                            BB",
		"BB                                           RB                BL                                           BB",
		"BB                                          RB                  BL                                          BB",
		"BB                                         RB           O        BL                                         BB",
		"BB                                        RB       RWWBBBBBBBBBBBBBL                                        BB",
		"BB                                       RB       RBWWBBBBBBBBBBBBBBL                                       BB",
		"BB                                      RB       RBBWWBBBBBBBBBBBBBBBL                                      BB",
		"BB                                     RB       RBBBWWBBBBBBBBBBBBBBBBL                                     BB",
		"BB                                  P          RBBBBWWBBBBBB t   BBBBBBL                                    BB",
		"BB                                 BBBBB     BBBBBBBWWBBBBB      BBBBBBBLl                                  BB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBB  B  BBBBBBBWWBBB      O BBBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBTTB  BBBBBBBWWBBB  BBBBBBBBBBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBBBBB  BBBBBBBWWBBB  BBBBBBBBBBBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWwWWWWWWWWWRBC     BB  BBBBBBBWWBBB   ttBBBBB     WWBBLWWWWWWWWWwWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRB       BB  BBBBBBBWWBBB           l   WWBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBBBB  BB  BBBBBBBWWBBBB           O  WWBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBBBB       BBBBBBBWWBBBBBB   BBBBBBBBBWWBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWWRBBBBBBBB  BBB  BBBBBBBWWBBB C    BBBBBBBBBWWBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWWRB          BBB  BBBBBBBWWBBB      BBBBBBBBBWWBBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWWRB        O  BBB  BBBBBBBWWBBB  O TTBBBBBBBBBWWBBBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWWRBBBBBBBB BBBBBBB  BBBBBBBWWBBBBBBBBBBBBBBBBBBWWBBBBBBBBBLWWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWWRB                WWBB    BWWBBBBBBBBBBBBBBBBBBWWBB       BLWWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBWWWWWWWWWWWWWWWWWWWWWWRB O   c           WW                           WW          BLWWWWWWWWWWWWWWWWWWWWWWBB",
		"BBTTTTTTTTTTTTTTTTTTTTWRBTTT       T       WW   TT                     OWW   T  T  T BLWTTTTTTTTTTTTTTTTTTTTBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTwelve[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P       t                                        CB",
		"B                                                    B",
		"B       T     T                                    O B",
		"BBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBBBB",
		"BBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWBBBB",
		"B l                                                  B",
		"B                   l                                B",
		"B O                                                  B",
		"BBBBL                    O     O                     B",
		"BBBBBL                                               B",
		"BBBBBBL          T  T  T  T  T  T  T  T  T  T  T  T B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelThirteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BP    CBBBBBBBB       B                                     B",
		"B      BBBBBBBB                                             B",
		"BB     BBBBBBBB       O                            l        B",
		"BB    BBBBBBBBB     BBBBBBB                                 B",
		"BB     BBBBBBBB    BBBBBBBB                                 B",
		"BBT    BBBBBBBBT   tBBBBBBB                                 B",
		"BBBB   BBBBBBBBBB   BBB C                        O    O  O  B",
		"BB     BBBBBBBB     BBB                        BBBBBBBBBBBBBB",
		"BB    TBBBBBBBB    BBBBBBBB                   BBBBBBBBBBBBBBB",
		"BB    BBBBBBBBB     BBBBBBB                  BBBBBBBBBBBBBBBB",
		"BB           t     RBBBBBBB                 BBBBBBBBBBBBBBBBB",
		"BB                RBBBBBBBB                BBBBBBBBBBBBBBBBBB",
		"BBl  T    T   O  RBBBBBBBBB  T   T   T    BBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFourteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBt C        BBBBBB             tt                               P                                   tt                                     BBB",
		"BB           BBBBBB             WW                                                                   WW             O   l   O               CBB",
		"BBT          BBBBBB   BBB  L    WW    R  BBBLWWWWWWWRB       BLWWWWWWRL                              WW         BBBBBBBBBBBBBBBBB            BB",
		"BBBBBBBBBB            BBB  BL   WW   RB  BBBBLWWWWWWBB       BBWWWWWRBBL       RL       BBBBL        WW         WWWWWWWWtWWWWWWWW           OBB",
		"BBBBBBBBBB   O    O   BBBTTBBL  WW  RBBTTBBBBBWWWWWWBB       BBWWWWWBC         BBWWWWWWWBBBBBL       WW         WWWWWWWWWWWWWWWWW          RBBB",
		"BBBBBBBBBB   BBBBBB   BBBBBBBBL WW RBBBBBBBBBBWWWWWWBB T C T BBWWWWWB  O  T  T BBWWWOWWWBBBBBBL T    WW    T    WWTWWTWWOWWTWWTWW         RBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFifeteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P  BBBBBBBBBBBBBBBBBC        B",
		"B     BBBBBBBBBBBBBBBBB  O      B",
		"B     BBBBBBBBBBBBBBBBBBBB      B",
		"B     BBBBBBBBBBBBBBBBB      O  B",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B O   BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"BBB   BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBBBWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBttWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B    TBBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B    BBBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWBBBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWttBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B     BBBBBBBBBBBBBBBBBWWWWWBBBBB",
		"B                      WWWWW   lB",
		"B                      WWWWW    B",
		"BTTT       O T   T   O WWWWW    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelSixteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P                            B",
		"B                  O            B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBB      B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBB      B",
		"B                           O   B",
		"B                               B",
		"B   CBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B    BBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B           t        t          B",
		"Bl                              B",
		"B                               B",
		"B       T    O   T  O   T       B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBB      B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBB      B",
		"B                               B",
		"B                               B",
		"B          O         T       T  B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelSeventeen[mapHeight] = {
		"OBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P       B                                                                                                                                                                                           B",
		"B          B                                                                                                                                                                                           B",
		"B          B                       l                                       C                                      l                                            C                                   l   B",
		"B          B                                                                                                                                                                                           B",
		"B          B     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T     B",
		"B          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   B",
		"B                                                                                                                                                                                                      B",
		"B                                            l                                 C                                                                            C                                          B",
		"B                                                                                                                                                                                                      B",
		"B     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    O     T    OB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelEighteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P                                                               B",
		"B                                                                  B",
		"B                                                                  B",
		"B                                                                  B",
		"B                                                                  B",
		"B                                                                l B",
		"B                                         O                        B",
		"Bl                                                          C      B",
		"B                        O        O     TTTTT                  O   B",
		"B                 LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBB",
		"B                LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   BBBBBBBBBBBB",
		"B               LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    BBBBBBBBBBBB",
		"B              LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBB",
		"B             LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    O BBBBBBBBBBBB",
		"B            LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBBBB",
		"B           LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB        BBBBBBBBBBBB",
		"B          LBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB   O     BBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelNineteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B  P                                                                               B",
		"B          B   B    BBBBB             BBBBB        BBBBB   BBBBB   BBBBB   B       B",
		"B          B  B     B   B             B   B            B   B   B       B   B       B",
		"B          B B      B                B   B            B   B   B       B   B       B",
		"B          BB       BBBB     B   B    B   B        BBBBB   B   B   BBBBB   B       B",
		"B          B B      B   B    B   B    B   B        B       B   B   B       B       B",
		"B          B  B     B   B    B   B    B   B   l    B       B   B   B       B       B",
		"B          B   B    BBBBB    BBBBB    B   B        BBBBB   BBBBB   BBBBB   B       B",
		"B                 O        O        O         O          O       O       O         B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTwenty[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B   P BB                     WW      WW         l        B",
		"B     BB     OC              WW      WW              O   B",
		"B     BBWWWWWBB    l         WW      WWBBBBBBBBBBBBBBBBBB",
		"B BBB BBWWWWWBB              WW      WW                  B",
		"B     BBBBBBBBB              WW      WW               O  B",
		"B                  RL        WW      WW              BB  B",
		"B                 RBBL       WW      WW                  B",
		"B                RBBBBL      WW      WW          BB      B",
		"B               RBBBBBBL     WW      WW                  B",
		"BTTTTTBB       RBBBBBBBBL    WW  TT  WW     T     T      B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	void initTextures();
	void initSprites();
	void initSoundBuffer();
	void initSound();
	
	void createBlock(b2World& World, int x, int y);
	void createRightAscent(b2World& World, int x, int y);
	void createLeftAscent(b2World& World, int x, int y);
	void createRing(b2World& World, int x, int y);
	void createThorn(b2World& World, int x, int y);

	void takeRings(sf::Vector2f playerPosition);
	void checkInWather(sf::Vector2f playerPosition);
	void takeCheckpoints(sf::Vector2f playerPosition);
	void takeBonusLives(sf::Vector2f playerPosition);

public:
	Map();
	void update(sf::Vector2f playerPosition);
	void render(sf::RenderTarget& target);
	void renderTopRings(sf::RenderTarget& target);


	void createBlocks(b2World& World);
	void setMap(int levelNumber);
	void clearWorld(b2World& World);

	
	b2Vec2 getSpawnPosition();
	std::string *getMap();
	int getRingsCounter();
	int getScore();
	bool getInWather();
	std::vector<sf::Vector2f> getThornsPositions();
	std::vector<sf::Vector2f> getBonusLivesPositions();
	int getMaxScore();
	int getMaxLives();
};

