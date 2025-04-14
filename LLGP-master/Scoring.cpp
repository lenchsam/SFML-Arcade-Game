#include "Scoring.h"
namespace LLGP {
	Scoring::Scoring() {
		Scoring::OnDeath += std::bind(&Scoring::SetScore, this, std::placeholders::_1);
	}
	void Scoring::SetScore(enum ScoreGivers scoreToAdd) {
		currentScore += scores[scoreToAdd];
		std::cout << "new score is " << currentScore << std::endl;
	}
	void Scoring::ResetScore() {
		currentScore = 0;
	}
}
