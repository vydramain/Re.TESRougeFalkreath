//
// Created by vydra on 7/23/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
#define TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_

#include <BearLibTerminal.h>
#include "./inputKey.h"
#include "logicParts/map.h"
#include "logicParts/player.h"
#include "logicParts/npcs.h"

class renderGame {
 private:
  const int screenBorderX = 100;
  const int screenBorderY = 40;
  const int mapBorderY = 40;
  const int mapBorderX = 66;

  char nationality[32];

 public:
  renderGame();
  explicit renderGame(bool gameMode);
  renderGame(const renderGame &old) {}
  ~renderGame();
  renderGame &operator=(const renderGame &old) {
    return *this;
  }

  unsigned questRender = 0;

  void createPlayerScreen(char *NameOfGG, unsigned &race);

  // void WOW();
  // void clearWOW();
  void clearALL();
  void goRender(const map &currentMap, const player &GG, const npcs &NPCS);
  bool menuChoiser(unsigned &nonshoise, unsigned pointMuch);
  unsigned headMenu();
  bool inputQuestion(const char *zagolovok, unsigned zagolovokSize, char *GGName);
  unsigned inputChoose(const char **listMenu, const unsigned &menuPoint, const char *zagolovok, unsigned zagolovokSize);

  void symColor(char mapSym);
  void showMap(const map &currentLocation, int, int);
  void showPlayer(const player &GG);
  void showNPCS(const npcs &NPC,  int xPlayer, int yPlayer);
  void showHud(const map &CurrentMap, const player &GG, npcs NPC);
  void showDialog(const map &CurrentMap, const player &GG, npcs NPC);

  unsigned npcDialog(npcs);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_RENDERGAME_H_
