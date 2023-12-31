#ifndef _KICKLEARNSITUATIONTABLE_H_
#define _KICKLEARNSITUATIONTABLE_H_

#include "situationtable.h"

class KickLearnSituationTable 
  : public SituationTable 
{
  private:
    bool checkIsBallKickable( float plX, 
                              float plY, 
                              float bX, 
                              float bY, 
                              float kickRadius);
    bool checkBallPositionInNextCycle( float ballPosX, float ballPosY,
                                       float ballVelX, float ballVelY,
                                       float playerPosX, float playerPosY,
                                       float playerVelX, float playerVelY,
                                       float playerAng );
  protected:
  public:
      //Konstruktor
  	  KickLearnSituationTable();
       
  	  bool createRandomSituationTable(int rows, bool ball=true, int numPlayers=1);
  	  void createSingleRandomSituation( float *(&tmp), bool ball=true );
};

#endif
